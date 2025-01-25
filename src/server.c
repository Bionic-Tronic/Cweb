#include "../include/cweb.h"

int open_server (server * server){
    server->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->server_socket < 0){
        perror("open_server()");
        return ERROR;
    }
    server->server_addr.sin_family = AF_INET;
    server->server_addr.sin_addr.s_addr = INADDR_ANY;
    server->server_addr.sin_port = htons(server->port);
    if (bind(server->server_socket, (struct sockaddr *)&server->server_addr, sizeof(server->server_addr)) < 0){
        perror("open_server()");
        close(server->client_socket);
        return ERROR;
    }
    if (listen(server->server_socket, server->listen) < 0){
        perror("open_server()");
        close(server->client_socket);
        return ERROR;
    }
    server->is_error = OK;
    return OK;
}

int accept_conections (server * server){
    server->client_addr_len = sizeof(server->client_addr);
    server->client_socket = accept(server->server_socket, (struct sockaddr *)&server->client_addr, &server->client_addr_len);
    if (server->client_socket < 0){
        perror("accept_conections()");
        close(server->client_socket);
        return ERROR;
    }
    server->is_error = OK;
    return OK;
}

string get (String palabra, string texto, char caracterLimite){
    char palabra_copy[MAX];
    snprintf(palabra_copy, MAX, "%s", palabra);
    char *encontrado = strstr(texto, palabra_copy);
    if (encontrado != EMPTY){
        size_t posicionFinal = encontrado - texto + strlen(palabra_copy);
        const char *limite = strchr(texto + posicionFinal, caracterLimite);
        if (limite != EMPTY){
            size_t longitud = limite - (texto + posicionFinal);
            char *subcadena = (char *)malloc(longitud + 1);
            strncpy(subcadena, texto + posicionFinal, longitud);
            subcadena[longitud] = '\0';
            return subcadena;
        }
        else
            return EMPTY;
    }
    else
        return EMPTY;
}

void send_response(int client_socket, const char *header, const char *content_type, const char *content, size_t content_length){
    char response[BUFFER_SIZE];
    int response_length = snprintf(response, sizeof(response),
                                   "%s\r\n"
                                   "Content-Type: %s\r\n"
                                   "Content-Length: %zu\r\n"
                                   "Connection: close\r\n"
                                   "\r\n",
                                   header, content_type, content_length);
    write(client_socket, response, response_length);
    write(client_socket, content, content_length);
}

void header (int client_socket, const char *header, const char *content_type, const char *content, size_t content_length) {
	char response[BUFFER_SIZE];
    int response_length = snprintf(response, sizeof(response),
                                   "%s\r\n"
                                   "Content-Type: %s\r\n"
                                   "Content-Length: %zu\r\n"
                                   "Connection: close\r\n"
                                   "\r\n",
                                   header, content_type, content_length);
    write(client_socket, response, response_length);
    write(client_socket, content, content_length);
}

void send_file_response(int client_socket, const char *header, const char *content_type, const char *file_path){
    FILE *file = fopen(file_path, "rb");
    if (file == EMPTY){
        perror("send_file_response()");
        return;
    }
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *file_content = malloc(file_size);
    if (file_content == EMPTY){
        perror("send_file_response()");
        fclose(file);
        return;
    }
    fread(file_content, 1, file_size, file);
    fclose(file);
    send_response(client_socket, header, content_type, file_content, file_size);
    free(file_content);
}

String getExtension(String nombreArchivo){
    String punto = strrchr(nombreArchivo, '.');
    if (!punto || punto == nombreArchivo)
        return "";
    return punto + 1;
}

int compareExtension(String archivo1, String archivo2){
    String extension1 = getExtension(archivo1);
    String extension2 = getExtension(archivo2);
    if (strcmp(extension1, extension2) == 0)
        return OK;
    return ERROR;
}

int handle_client(server * server){
    int bytes_read;
    char dataGet[MAX];
    char pathPage[MAX];
    string ofGet = get("GET /", buffer, ' ');
    if (server->simple_pages == true){
        snprintf(pathPage, MAX, "html/%s", ofGet);
        snprintf(dataGet, MAX, "GET /%s HTTP/1.1", ofGet);
        bytes_read = read(server->client_socket, buffer, sizeof(buffer) - 1);
        if (bytes_read < 0){
            perror("handle_client()");
            close(server->client_socket);
            return ERROR;
        }
        buffer[bytes_read] = '\0';
        for (int i = 0; i < server->pages_actives; i++){
            char tm[MAX];
            snprintf(tm, MAX, "GET /%s HTTP/1.1", server->pages[i]);
            if (strncmp(buffer, tm, strlen(tm)) == 0)
                send_response(server->client_socket, "HTTP/1.1 200 OK", HTML_MIME, server->code_pages[i], strlen(server->code_pages[i]));
        }
        return OK;
    }
    snprintf(pathPage, MAX, "html/%s", ofGet);
    snprintf(dataGet, MAX, "GET /%s HTTP/1.1", ofGet);
    bytes_read = read(server->client_socket, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0){
        perror("handle_client()");
        close(server->client_socket);
        return ERROR;
    }
    buffer[bytes_read] = '\0';
    if (strncmp(buffer, "GET / HTTP/1.1", 14) == 0)
        send_file_response(server->client_socket, "HTTP/1.1 200 OK", HTML_MIME, "pages/index.html");
    else if (strncmp(buffer, dataGet, strlen(dataGet)) == 0){
        if (compareExtension(ofGet, "file.c") == OK)
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", HTML_MIME, pathPage);
        else if (compareExtension(ofGet, "file.png") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "image/png", path1);
        }
        if (compareExtension(ofGet, "file.jpeg") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "image/jpeg", path1);
        }
        else if (compareExtension(ofGet, "file.gif") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "image/gif", path1);
        }
        if (compareExtension(ofGet, "file.bmp") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "image/bmp", path1);
        }
        else if (compareExtension(ofGet, "file.webp") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "image/webp", path1);
        }
        if (compareExtension(ofGet, "file.svg") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "image/svg+xml", path1);
        }
        else if (compareExtension(ofGet, "file.ico") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "image/x-icon", path1);
        }
        if (compareExtension(ofGet, "file.js") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "js/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "application/javascript", path1);
        }
        else if (compareExtension(ofGet, "file.xml") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "res/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "application/xml", path1);
        }
        if (compareExtension(ofGet, "file.json") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "res/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "application/json", path1);
        }
        else if (compareExtension(ofGet, "file.mp4") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "video/mp4", path1);
        }
        if (compareExtension(ofGet, "file.webm") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "video/webm", path1);
        }
        else if (compareExtension(ofGet, "file.ogg") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "video/ogg", path1);
        }
        if (compareExtension(ofGet, "file.avi") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "video/x-msvideo", path1);
        }
        if (compareExtension(ofGet, "file.mp3") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "res/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "audio/mp3", path1);
        }
        if (compareExtension(ofGet, "file.wav") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "res/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "audio/wav", path1);
        }
        if (compareExtension(ofGet, "file.pdf") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "res/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "application/pdf", path1);
        }
        if (compareExtension(ofGet, "file.zip") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "res/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "application/zip", path1);
        }
        if (compareExtension(ofGet, "file.ttf") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "fonts/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "font/ttf", path1);
        }
        if (compareExtension(ofGet, "file.avi") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "video/x-msvideo", path1);
        }
        else if (compareExtension(ofGet, "file.quicktime") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "video/quicktime", path1);
        }
        if (compareExtension(ofGet, "file.css") == OK){
            char path2[MAX];
            snprintf(path2, MAX, "css/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "text/css", path2);
        }
        else
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "text/html", "pages/index.html");
    }
    else
        send_response(server->client_socket, "HTTP/1.1 404 Not Found", "text/html", server->response_code_404, strlen(server->response_code_404));
    close(server->client_socket);
    return OK;
}
