////////////////////////////////////////////////////////////////
//Archivo: server.h                                           //
//Este header contiene todas las funciones necesarias o que   //
//son del servidor.                                           //
////////////////////////////////////////////////////////////////

#ifndef SERVER_H
#define SERVER_H

static void _decrypt(char *message, int shift)
{
    char *ptr = message;
    while (*ptr != '\0')
    {
        if (*ptr >= 'a' && *ptr <= 'z')
        {
            *ptr = (*ptr - 'a' - shift + 26) % 26 + 'a';
        }
        else if (*ptr >= 'A' && *ptr <= 'Z')
        {
            *ptr = (*ptr - 'A' - shift + 26) % 26 + 'A';
        }
        ptr++;
    }
}

static void _encrypt(char *message, int shift)
{
    char *ptr = message;
    while (*ptr != '\0')
    {
        if (*ptr >= 'a' && *ptr <= 'z')
        {
            *ptr = (*ptr - 'a' + shift) % 26 + 'a';
        }
        else if (*ptr >= 'A' && *ptr <= 'Z')
        {
            *ptr = (*ptr - 'A' + shift) % 26 + 'A';
        }
        ptr++;
    }
}

static char * load_buffer()
{
    return buffer;
}

static char *descryptChar(char *txt)
{
    char * today[42] = {
        "%25",       // %
        "%5C",       //espace
        "+",         // espacio
        "%7C",       // |
        "%3D",       // =
        "%5B",       // [
        "%5D",       // ]
        "%3C",       // <
        "%3E",       // >
        "%7B",       // {
        "%7D",       // }
        "%23",       // #
        "%E2%82%AC", // €
        "%26",       // &
        "%28",       // (
        "%29",       // )
        "%22",       // "
        "%27",       // '
        "%3A",       // :
        "%3B",       // ;
        "%21",       // !
        "%3F",       // ?
        "%C2%A9",    // ©
        "%24",       // $
        "%CF%80",    // π
        "%40",       //@
        "%7E",       //~
        "%60",       //`
        "%E2%80%A2", //•
        "%E2%88%9A", //√
        "%C3%B7",    //÷
        "%C3%97",    //×
        "%C2%A7",    //§
        "%E2%88%86", //∆
        "%C2%A3",    //£
        "%C2%A5",    //¢
        "%C2%A2",    //^
        "%C2%B0",    //°
        "%C2%AE",    //®
        "%E2%84%A2", //™
        "%E2%9C%93", //✓
    };
    if (strcmp(txt, today[0]) == 0)
    {
        return "%";
    }
    if (strcmp(txt, today[1]) == 0)
    {
        return "\\";
    }
    if (strcmp(txt, today[2]) == 0)
    {
        return " ";
    }
    if (strcmp(txt, today[3]) == 0)
    {
        return "|";
    }
    if (strcmp(txt, today[4]) == 0)
    {
        return "=";
    }
    if (strcmp(txt, today[5]) == 0)
    {
        return "[";
    }
    if (strcmp(txt, today[6]) == 0)
    {
        return "]";
    }
    if (strcmp(txt, today[7]) == 0)
    {
        return "<";
    }
    if (strcmp(txt, today[8]) == 0)
    {
        return ">";
    }
    if (strcmp(txt, today[9]) == 0)
    {
        return "{";
    }
    if (strcmp(txt, today[10]) == 0)
    {
        return "}";
    }
    if (strcmp(txt, today[11]) == 0)
    {
        return "#";
    }
    if (strcmp(txt, today[12]) == 0)
    {
        return "€";
    }
    if (strcmp(txt, today[13]) == 0)
    {
        return "&";
    }
    if (strcmp(txt, today[14]) == 0)
    {
        return "(";
    }
    if (strcmp(txt, today[15]) == 0)
    {
        return ")";
    }
    if (strcmp(txt, today[16]) == 0)
    {
        return "\"";
    }
    if (strcmp(txt, today[17]) == 0)
    {
        return "'";
    }
    if (strcmp(txt, today[18]) == 0)
    {
        return ":";
    }
    if (strcmp(txt, today[19]) == 0)
    {
        return ";";
    }
    if (strcmp(txt, today[20]) == 0)
    {
        return "!";
    }
    if (strcmp(txt, today[21]) == 0)
    {
        return "?";
    }
    if (strcmp(txt, today[22]) == 0)
    {
        return "©";
    }
    if (strcmp(txt, today[23]) == 0)
    {
        return "$";
    }
    if (strcmp(txt, today[24]) == 0)
    {
        return "π";
    }
    if (strcmp(txt, today[25]) == 0)
    {
        return "@";
    }
    if (strcmp(txt, today[26]) == 0)
    {
        return "~";
    }
    if (strcmp(txt, today[27]) == 0)
    {
        return "`";
    }
    if (strcmp(txt, today[28]) == 0)
    {
        return "•";
    }
    if (strcmp(txt, today[29]) == 0)
    {
        return "√";
    }
    if (strcmp(txt, today[30]) == 0)
    {
        return "÷";
    }
    if (strcmp(txt, today[31]) == 0)
    {
        return "×";
    }
    if (strcmp(txt, today[32]) == 0)
    {
        return "§";
    }
    if (strcmp(txt, today[33]) == 0)
    {
        return "∆";
    }
    if (strcmp(txt, today[34]) == 0)
    {
        return "£";
    }
    if (strcmp(txt, today[35]) == 0)
    {
        return "¥";
    }
    if (strcmp(txt, today[36]) == 0)
    {
        return "¢";
    }
    if (strcmp(txt, today[37]) == 0)
    {
        return "^";
    }
    if (strcmp(txt, today[38]) == 0)
    {
        return "°";
    }
    if (strcmp(txt, today[39]) == 0)
    {
        return "®";
    }
    if (strcmp(txt, today[40]) == 0)
    {
        return "™";
    }
    if (strcmp(txt, today[41]) == 0)
    {
        return "✓";
    }
    return EMPTY;
}

void concatplus(char *result, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    va_list args_copy;
    va_copy(args_copy, args);
    int length = vsnprintf(EMPTY, 0, format, args_copy);
    va_end(args_copy);
    vsnprintf(result, length + 1, format, args);
    va_end(args);
}

static int _save_response(const char *namefile)
{
    char finalFile[100];
    concatplus(finalFile, "res/%s.log", namefile);
    FILE *fp = fopen(finalFile, "a");
    if (fp == EMPTY)
    {
        return ERROR;
    }
    fprintf(fp, "%s", GET_RESPONSE());
    fclose(fp);
    return OK;
}

char * parseInt(int entero)
{
    int len = snprintf(EMPTY, 0, "%d", entero);
    char * str = malloc(len + 1);
    snprintf(str, len + 1, "%d", entero);
    return str;
}

char * parseFloat(double flotante)
{
    int len = snprintf(EMPTY, 0, "%.2f", flotante);
    char * str = malloc(len + 1);
    snprintf(str, len + 1, "%.2f", flotante);
    return str;
}

int parseStr(char * str)
{
    return atoi(str);
}

char *searchInResponse(const char *palabra, char caracterLimite)
{
    char *texto = GET_RESPONSE();
    char *encontrado = strstr(texto, palabra);
    if (encontrado != EMPTY)
    {
        size_t posicionFinal = encontrado - texto + strlen(palabra);
        const char *limite = strchr(texto + posicionFinal, caracterLimite);
        if (limite != EMPTY)
        {
            size_t longitud = limite - (texto + posicionFinal);
            char *subcadena = (char *)malloc(longitud + 1);
            strncpy(subcadena, texto + posicionFinal, longitud);
            subcadena[longitud] = '\0';
            return subcadena;
        }
        else
        {
            return EMPTY;
        }
    }
    else
    {
        return EMPTY;
    }
}

char *searchWord(const char *texto, const char *palabra, char caracterLimite)
{
    char *encontrado = strstr(texto, palabra);
    if (encontrado != EMPTY)
    {
        size_t posicionFinal = encontrado - texto + strlen(palabra);
        const char *limite = strchr(texto + posicionFinal, caracterLimite);
        if (limite != EMPTY)
        {
            size_t longitud = limite - (texto + posicionFinal);
            char *subcadena = (char *)malloc(longitud + 1);
            strncpy(subcadena, texto + posicionFinal, longitud);
            subcadena[longitud] = '\0';
            return subcadena;
        }
        else
        {
            return EMPTY;
        }
    }
    else
    {
        return EMPTY;
    }
}

int search_w(const char *word, const char *texto)
{
    char *text_copy = strdup(word);
    if (text_copy == EMPTY)
    {
        return ERROR;
    }
    char *line = strtok(text_copy, "\n");
    while (line != EMPTY)
    {
        if (strstr(line, texto) != EMPTY)
        {
            free(text_copy);
            return OK;
        }
        line = strtok(EMPTY, "\n");
    }
    free(text_copy);
    return ERROR;
}

int _save(const char * fp, const char * key, const char * value, const char * comentarios)
{
    if (fp == EMPTY)
    {
        fprintf(stderr, "Name file is EMPTY\n");
        return ERROR;
    }
    char tmp[100];
    char data[2024];
    concatplus(tmp, "res/%s.dat", fp);
    FILE *f = fopen(tmp, "a"), *f2 = fopen(tmp, "r");
    if (f == EMPTY || f2 == EMPTY)
    {
        perror("cwebError ");
        fclose(f2);
        fclose(f);
        return ERROR;
    }
    if (key == EMPTY || value == EMPTY)
    {
        fprintf(stderr, "Key or Value is EMPTY\n");
        fclose(f2);
        fclose(f);
        return ERROR;
    }
    fread(data, sizeof(char), 2024, f2);
    int res = search_w(data, key);
    if (res == OK)
    {
        fprintf(stderr, "Key not exists\n");
        fclose(f2);
        fclose(f);
        return ERROR;
    }
    if (comentarios == EMPTY)
    {
        fprintf(f, "%s=%s\n", key, value);
    }
    else
    {
        fprintf(f, "/*%s*/\n%s=%s\n", comentarios, key, value);
    }
    fclose(f2);
    fclose(f);
    return OK;
}

char * _getValue(const char * name, const char * key, const char * value)
{
    if (name == EMPTY)
    {
        fprintf(stderr, "Name file is EMPTY\n");
        return EMPTY;
    }
    if (key == EMPTY)
    {
        fprintf(stderr, "Key is EMPTY\n");
        return EMPTY;
    }
    char tmp[100];
    char data[2024];
    char tmp2[100];
    char * result;
    concatplus(tmp2, "%s=", key);
    concatplus(tmp, "res/%s.dat", name);
    FILE *fp = fopen(tmp, "r");
    if (fp == EMPTY)
    {
        perror("cwebError ");
        return EMPTY;
    }
    fread(data, sizeof(char), 2024, fp);
    result = searchWord(data, tmp2, '\n');
    if (strcmp(result, "") == 0)
    {
        result = value;
    }
    if (strcmp(result, " ") == 0)
    {
        result = value;
    }
    fclose(fp);
    return result;
}

char * _getDat(const char * d)
{
    if (d == EMPTY)
    {
        fprintf(stderr, "Name file is EMPTY\n");
        return EMPTY;
    }
    char tmp[100];
    char data[2024];
    char * result;
    concatplus(tmp, "res/%s.dat", d);
    FILE *fp = fopen(tmp, "r");
    if (fp == EMPTY)
    {
        perror("cweb ");
        return EMPTY;
    }
    fread(data, sizeof(char), 2024, fp);
    result = data;
    return result;
}

int _quit(const char * fp)
{
    if (fp == EMPTY)
    {
        fprintf(stderr, "Name file is EMPTY\n");
        return ERROR;
    }
    char tmp[100];
    concatplus(tmp, "res/%s.dat", fp);
    if (remove(tmp) == -1)
    {
        perror("cweb ");
        return ERROR;
    }
    else
    {
        return OK;
    }
}

static const char *getExtension(const char *nombreArchivo)
{
    const char *punto = strrchr(nombreArchivo, '.');
    if (!punto || punto == nombreArchivo)
        return "";
    return punto + 1;
}

int compareExtension(const char *archivo1, const char *archivo2)
{
    const char *extension1 = getExtension(archivo1);
    const char *extension2 = getExtension(archivo2);

    if (strcmp(extension1, extension2) == 0)
    {
        return OK;
    }
    else
    {
        return ERROR;
    }
}

void properties(Properties *p)
{
    p->save = _save;
    p->delete = _quit;
    p->getValue = _getValue;
    p->getDat = _getDat;
}

int send_email(email *email)
{
    CURL *curl;
    CURLcode res = CURLE_OK;
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, email->smtp_url);
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, email->mail_from);
        struct curl_slist *recipients = EMPTY;
        recipients = curl_slist_append(recipients, email->recipient);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        curl_easy_setopt(curl, CURLOPT_USERNAME, email->smtp_user);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, email->smtp_password);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, EMPTY);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_READDATA, email->payload_text);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "%s\n", curl_easy_strerror(res));

        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
    return (int)res;
}

static void _clear_(struct Api_connect *api)
{
    curl_global_cleanup();
}

static int api_connect_callback(void *data, size_t size, size_t nmemb, void *userp)
{
    FILE *fp = fopen("./res/dataApi.api", "a");
    if (fp == EMPTY)
    {
        perror("cweb");
        return -1;
    }
    size_t realsize = size * nmemb;
    fprintf(fp, "%.*s\n\n", (int)realsize, (char *)data);
    fclose(fp);
    return realsize;
}

static int _simple_get(struct Api_connect *api)
{
    if (api->is_error == OK)
    {
        int res = 0;
        curl_easy_setopt(api->curl, CURLOPT_URL, api->url);
        curl_easy_setopt(api->curl, CURLOPT_WRITEFUNCTION, api_connect_callback);
        res = curl_easy_perform(api->curl);
        if (res != CURLE_OK)
        {
            if (api->errors == true)
            {
                fprintf(stderr, "cweb: %s\n", curl_easy_strerror(res));
                api->is_error = ERROR;
                return ERROR;
            }
            else
            {
                api->is_error = ERROR;
                return ERROR;
            }
        }
        curl_easy_cleanup(api->curl);
        api->is_error = OK;
        return OK;
    }
    else
    {
        api->is_error = ERROR;
        return ERROR;
    }
}

static int _prepare(struct Api_connect *api)
{
    curl_global_init(CURL_GLOBAL_DEFAULT);
    api->curl = curl_easy_init();
    if (api->curl)
    {
        api->is_error = OK;
        return OK;
    }
    else
    {
        api->is_error = ERROR;
        return ERROR;
    }
}

int _simple_post(struct Api_connect *api)
{
    int res = 0;
    if (api->is_error == OK)
    {
        curl_easy_setopt(api->curl, CURLOPT_URL, api->url);
        curl_easy_setopt(api->curl, CURLOPT_POST, 1L);
        curl_easy_setopt(api->curl, CURLOPT_POSTFIELDS, api->post);
        curl_easy_setopt(api->curl, CURLOPT_WRITEFUNCTION, api_connect_callback);
        struct curl_slist *headers = EMPTY;
        headers = curl_slist_append(headers, api->headers);
        curl_easy_setopt(api->curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(api->curl);
        if (res != CURLE_OK)
        {
            if (api->errors == true)
            {
                fprintf(stderr, "cweb: %s\n", curl_easy_strerror(res));
                api->is_error = ERROR;
                return ERROR;
            }
            else
            {
                api->is_error = ERROR;
                return ERROR;
            }
        }
        curl_slist_free_all(headers);
        curl_easy_cleanup(api->curl);
        api->is_error = OK;
        return OK;
    }
    else
    {
        api->is_error = ERROR;
        return ERROR;
    }
}

static void getData_ (struct Api_connect * api){
    FILE * fp = fopen("./res/dataApi.api","r");
    if(fp == EMPTY){
        perror("cweb");
        return;
    }
    fread(api->data,sizeof(char), 1024, fp);
    fclose(fp);
}

void api_connect(struct Api_connect *api)
{
    api->url = "http://example.com";
    api->headers = "Content-Type: application/json";
    api->post = "{\"example1\":\"example1\",\"example2\":\"example2\"}";
    api->errors = true;
    api->is_error = OK;
    api->prepare = _prepare;
    api->simple_get = _simple_get;
    api->clear = _clear_;
    api->simple_post = _simple_post;
}

static char *get_name_get_(const char *palabra, char *texto, char caracterLimite)
{
    char true_palabra[1000];
    concatplus(true_palabra, "%s", palabra);
    char *encontrado = strstr(texto, true_palabra);
    if (encontrado != EMPTY)
    {
        size_t posicionFinal = encontrado - texto + strlen(true_palabra);
        const char *limite = strchr(texto + posicionFinal, caracterLimite);
        if (limite != EMPTY)
        {
            size_t longitud = limite - (texto + posicionFinal);
            char *subcadena = (char *)malloc(longitud + 1);
            strncpy(subcadena, texto + posicionFinal, longitud);
            subcadena[longitud] = '\0';
            return subcadena;
        }
        else
        {
            return EMPTY;
        }
    }
    else
    {
        return EMPTY;
    }
}

void send_response(int client_socket, const char *header, const char *content_type, const char *content, size_t content_length)
{
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

void send_file_response(int client_socket, const char *header, const char *content_type, const char *file_path)
{
    FILE *file = fopen(file_path, "rb");
    if (file == EMPTY)
    {
        perror("Error al abrir el archivo ");
        return;
    }
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *file_content = malloc(file_size);
    if (file_content == EMPTY)
    {
        perror("Error al asignar memoria");
        fclose(file);
        return;
    }
    fread(file_content, 1, file_size, file);
    fclose(file);
    send_response(client_socket, header, content_type, file_content, file_size);
    free(file_content);
}

static int _handle_client(struct SERVER *server)
{
    char buffer[BUFFER_SIZE];
    int bytes_read;
    char dataGet[BUFFER_SIZE];
    char pathPage[BUFFER_SIZE];
    char *ofGet = get_name_get_("GET /", buffer, ' ');
    if (ofGet == EMPTY)
    {
        goto hereIfError;
    }
    concatplus(pathPage, "html/%s", ofGet);
    concatplus(dataGet, "GET /%s HTTP/1.1", ofGet);
hereIfError:
    bytes_read = read(server->client_socket, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0)
    {
        if (server->errors == true)
        {
            perror("cweb");
            server->is_error = ERROR;
            close(server->client_socket);
            return ERROR;
        }
        else
        {
            server->is_error = ERROR;
            close(server->client_socket);
            return ERROR;
        }
    }
    buffer[bytes_read] = '\0';
    if (strncmp(buffer, "GET / HTTP/1.1", 14) == 0)
    {
    defaultPage:
        send_file_response(server->client_socket, "HTTP/1.1 200 OK", "text/html", "html/index.c");
    }
    else if (strncmp(buffer, dataGet, strlen(dataGet)) == 0)
    {
        if (compareExtension(ofGet, "example.c") == OK)
        {
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "text/html", pathPage);
        }
        //Mimes de imagenes
        else if (compareExtension(ofGet, "example.png") == OK)
        {
            char path1[BUFFER_SIZE];
            concatplus(path1, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", IMGS_MIMES[1], path1);
        }
        if (compareExtension(ofGet, "example.jpeg") == OK)
        {
            char path1[BUFFER_SIZE];
            concatplus(path1, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", IMGS_MIMES[0], path1);
        }
        else if (compareExtension(ofGet, "example.gif") == OK)
        {
            char path1[BUFFER_SIZE];
            concatplus(path1, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", IMGS_MIMES[2], path1);
        }
        if (compareExtension(ofGet, "example.bmp") == OK)
        {
            char path1[BUFFER_SIZE];
            concatplus(path1, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", IMGS_MIMES[3], path1);
        }
        else if (compareExtension(ofGet, "example.webp") == OK)
        {
            char path1[BUFFER_SIZE];
            concatplus(path1, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", IMGS_MIMES[4], path1);
        }
        if (compareExtension(ofGet, "example.svg") == OK)
        {
            char path1[BUFFER_SIZE];
            concatplus(path1, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", IMGS_MIMES[5], path1);
        }
        else if (compareExtension(ofGet, "example.ico") == OK)
        {
            char path1[BUFFER_SIZE];
            concatplus(path1, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", IMGS_MIMES[6], path1);
        }
        //Mimes text documents
        if (compareExtension(ofGet, "example.js") == OK)
        {
            char path1[BUFFER_SIZE];
            concatplus(path1, "js/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", TEXT_DOCUMENTS_MIMES[3], path1);
        }
        else if (compareExtension(ofGet, "example.xml") == OK)
        {
            char path1[BUFFER_SIZE];
            concatplus(path1, "res/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", TEXT_DOCUMENTS_MIMES[4], path1);
        }
        if (compareExtension(ofGet, "example.json") == OK)
        {
            char path1[BUFFER_SIZE];
            concatplus(path1, "res/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", TEXT_DOCUMENTS_MIMES[5], path1);
        }
        //Mimes videos
        else if (compareExtension(ofGet, "example.mp4") == OK)
        {
            char path1[BUFFER_SIZE];
            concatplus(path1, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", VIDEOS_MIMES[0], path1);
        }
        if (compareExtension(ofGet, "example.webm") == OK)
        {
            char path1[BUFFER_SIZE];
            concatplus(path1, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", VIDEOS_MIMES[1], path1);
        }
        else if (compareExtension(ofGet, "example.ogg") == OK)
        {
            char path1[BUFFER_SIZE];
            concatplus(path1, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", VIDEOS_MIMES[2], path1);
        }
        if (compareExtension(ofGet, "example.avi") == OK)
        {
            char path1[BUFFER_SIZE];
            concatplus(path1, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", VIDEOS_MIMES[3], path1);
        }
        else if (compareExtension(ofGet, "example.quicktime") == OK)
        {
            char path1[BUFFER_SIZE];
            concatplus(path1, "img/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", VIDEOS_MIMES[4], path1);
        }
        if (compareExtension(ofGet, "example.css") == OK)
        {
            char path2[BUFFER_SIZE];
            concatplus(path2, "css/%s", ofGet);
            send_file_response(server->client_socket, "HTTP/1.1 200 OK", "text/css", path2);
        }
        else
        {
            goto defaultPage;
        }
    }
    else
    {
        send_response(server->client_socket, "HTTP/1.1 404 Not Found", "text/html", server->response_code_404, strlen(server->response_code_404));
    }
    close(server->client_socket);

    server->is_error = OK;
    return OK;
}

static int _accept_conections(struct SERVER *server)
{
    server->client_addr_len = sizeof(server->client_addr);
    server->client_socket = accept(server->server_socket, (struct sockaddr *)&server->client_addr, &server->client_addr_len);
    if (server->client_socket < 0)
    {
        if (server->errors == true)
        {
            perror("cweb");
            server->is_error = ERROR;
            close(server->server_socket);
            return ERROR;
        }
        else
        {
            server->is_error = ERROR;
            close(server->server_socket);
            return ERROR;
        }
    }
    server->is_error = OK;
    return OK;
}

char * _load_response()
{
    return buffer;
}

int _save_response_server(const char * file)
{
    char res[MAX_VARS];
    concatplus(res, "logs/%s.server", file);
    FILE *fp = fopen(res, "a");
    if (fp != EMPTY)
    {
        fprintf(fp, "\n[%s]\n", buffer);
        fclose(fp);
        return OK;
    }
    else
    {
        perror("cweb");
        return ERROR;
    }
}

int prepare_SERVER(struct SERVER *server)
{
    server->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->server_socket < 0)
    {
        if (server->errors == true)
        {
            perror("cweb");
            server->is_error = ERROR;
            return ERROR;
        }
        else
        {
            server->is_error = ERROR;
            return ERROR;
        }
    }
    server->server_addr.sin_family = AF_INET;
    server->server_addr.sin_addr.s_addr = INADDR_ANY;
    server->server_addr.sin_port = htons(server->port);
    if (bind(server->server_socket, (struct sockaddr *)&server->server_addr, sizeof(server->server_addr)) < 0)
    {
        if (server->errors == true)
        {
            perror("cweb");
            server->is_error = ERROR;
            close(server->server_socket);
            return ERROR;
        }
        else
        {
            server->is_error = ERROR;
            close(server->server_socket);
            return ERROR;
        }
    }
    if (listen(server->server_socket, server->listen) < 0)
    {
        if (server->errors == true)
        {
            perror("cweb");
            server->is_error = ERROR;
            close(server->server_socket);
            return ERROR;
        }
        else
        {
            server->is_error = ERROR;
            close(server->server_socket);
            return ERROR;
        }
    }
    server->is_error = OK;
    server->handle_client = _handle_client;
    server->accept_conections = _accept_conections;
    server->load_response = _load_response;
    server->save_response_server = _save_response_server;
    return OK;
}

#endif
