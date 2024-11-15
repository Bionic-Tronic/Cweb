#ifndef SERVER_H
#define SERVER_H

#define MAX_URLS 1000
#define DEFAULT_PORT 8080
#define DEFAULT_LISTEN 10
#define DEFAULT_BUFFER_FILE 6046
#define DEFAULT_URL "127.0.0.1"
#define BUFFER_SIZE 1096
#define MAX 1024

bool show_errors = false;

char buffer[BUFFER_SIZE] = {0};

#define GET_RESPONSE() buffer

typedef struct {
    int addrlen;
    int server_fd, new_socket, valread;
    int server_socket, client_socket, errors, is_error, port, listen, buffer_file;
    string url, response_code_html, response_code_404;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    string pages[MAX_URLS];
    string code_pages[MAX_URLS];
    bool simple_pages;
    int pages_actives;
} server;

String IMGS_MIMES[] = {
    "image/jpeg",
    "image/png",
    "image/gif",
    "image/bmp",
    "image/webp",
    "image/svg+xml",
    "image/x-icon",
};

String TEXT_DOCUMENTS_MIMES[] = {
    "text/html",
    "text/plain",
    "text/css",
    "application/javascript",
    "application/xml",
    "application/json",
    "application/chtml"};

String VIDEOS_MIMES[] = {
    "video/mp4",
    "video/webm",
    "video/ogg",
    "video/x-msvideo",
    "video/quicktime",
};

String AUDIO_MIMES[] = {
    "audio/mpeg",
    "audio/ogg",
    "audio/wav",
    "audio/webm",
    "audio/midi",
};

String APPLICATIONS_MIMES[] = {
    "application/pdf",
    "application/gzip",
    "application/zip",
    "application/octet-stream",
};

String OTHERS_MIMES[] = {
    "font/ttf",
    "font/otf",
    "font/woff",
    "font/woff2",
};

int open_server (server * server){
    server->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->server_socket < 0){
        if(show_errors == true)
           perror("cweb");
        return ERROR;
    }
    server->server_addr.sin_family = AF_INET;
    server->server_addr.sin_addr.s_addr = INADDR_ANY;
    server->server_addr.sin_port = htons(server->port);
    if (bind(server->server_socket, (struct sockaddr *)&server->server_addr, sizeof(server->server_addr)) < 0){
        if(show_errors == true)
           perror("cweb");
        close(server->client_socket);
        return ERROR;
    }
    if (listen(server->server_socket, server->listen) < 0){
        if(show_errors == true)
           perror("cweb");
        close(server->client_socket);
        return ERROR;
    }
    server->is_error = OK;
    return OK;
}

int save_log (){
    FILE *fp = fopen("logs/server.log", "a");
    if (fp == EMPTY){
        if(show_errors == true)
           perror("cweb ");
        return ERROR;
    }
    fprintf(fp, "\n%s\n", buffer);
    fclose(fp);
    return OK;
}

int accept_conections (server * server){
    server->client_addr_len = sizeof(server->client_addr);
    server->client_socket = accept(server->server_socket, (struct sockaddr *)&server->client_addr, &server->client_addr_len);
    if (server->client_socket < 0){
        if(show_errors == true)
           perror("cweb");
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

void send_file_response(int client_socket, const char *header, const char *content_type, const char *file_path){
    FILE *file = fopen(file_path, "rb");
    if (file == EMPTY){
        if(show_errors == true)
            perror("cweb");
        return;
    }
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *file_content = malloc(file_size);
    if (file_content == EMPTY){
        if(show_errors == true)
            perror("cweb");
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
            if(show_errors == true)
                perror("cweb");
            close(server->client_socket);
            return ERROR;
        }
        buffer[bytes_read] = '\0';
        for (int i = 0; i < server->pages_actives; i++){
            char tm[MAX];
            snprintf(tm, MAX, "GET /%s HTTP/1.1", server->pages[i]);
            if (strncmp(buffer, tm, strlen(tm)) == 0)
                send_response(server->client_socket, "HTTP/1.1 200 OK", "text/html", server->code_pages[i], strlen(server->code_pages[i]));
        }
        return OK;
    }
    snprintf(pathPage, MAX, "html/%s", ofGet);
    snprintf(dataGet, MAX, "GET /%s HTTP/1.1", ofGet);
    bytes_read = read(server->client_socket, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0){
        if(show_errors == true)
           perror("cweb");
        close(server->client_socket);
        return ERROR;
    }
    buffer[bytes_read] = '\0';
    if (strncmp(buffer, "GET / HTTP/1.1", 14) == 0)
        send_file_response(server->client_socket, "HTTP/1.1 200 OK", "text/html", "html/index.html");
    else if (strncmp(buffer, dataGet, strlen(dataGet)) == 0){
        if (compareExtension(ofGet, "example.c") == OK)
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "text/html", pathPage);
        else if (compareExtension(ofGet, "example.png") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", IMGS_MIMES[1], path1);
        }
        if (compareExtension(ofGet, "example.jpeg") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", IMGS_MIMES[0], path1);
        }
        else if (compareExtension(ofGet, "example.gif") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", IMGS_MIMES[2], path1);
        }
        if (compareExtension(ofGet, "example.bmp") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", IMGS_MIMES[3], path1);
        }
        else if (compareExtension(ofGet, "example.webp") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", IMGS_MIMES[4], path1);
        }
        if (compareExtension(ofGet, "example.svg") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", IMGS_MIMES[5], path1);
        }
        else if (compareExtension(ofGet, "example.ico") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", IMGS_MIMES[6], path1);
        }
        if (compareExtension(ofGet, "example.js") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "js/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", TEXT_DOCUMENTS_MIMES[3], path1);
        }
        else if (compareExtension(ofGet, "example.xml") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "res/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", TEXT_DOCUMENTS_MIMES[4], path1);
        }
        if (compareExtension(ofGet, "example.json") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "res/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", TEXT_DOCUMENTS_MIMES[5], path1);
        }
        else if (compareExtension(ofGet, "example.mp4") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", VIDEOS_MIMES[0], path1);
        }
        if (compareExtension(ofGet, "example.webm") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", VIDEOS_MIMES[1], path1);
        }
        else if (compareExtension(ofGet, "example.ogg") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", VIDEOS_MIMES[2], path1);
        }
        if (compareExtension(ofGet, "example.avi") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", VIDEOS_MIMES[3], path1);
        }
        else if (compareExtension(ofGet, "example.quicktime") == OK){
            char path1[MAX];
            snprintf(path1, MAX, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", VIDEOS_MIMES[4], path1);
        }
        if (compareExtension(ofGet, "example.css") == OK){
            char path2[MAX];
            snprintf(path2, MAX, "css/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "text/css", path2);
        }
        else
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "text/html", "html/index.html");
    }
    else
        send_response(server->client_socket, "HTTP/1.1 404 Not Found", "text/html", server->response_code_404, strlen(server->response_code_404));
    close(server->client_socket);
    return OK;
}

#endif
