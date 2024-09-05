#ifndef SMTP_H
#define SMTP_H

//#include "cweb.h"

void handle_client(int client_socket, String name) {
    char buffer[BUFFER_SIZE];
    char rute_file[1024];
    int bytes_read;
    FILE *file;
    snprintf(rute_file,1024,"./emails/%s.emails",name);
    const char *welcome_message = "220 Simple SMTP Server\r\n";
    send(client_socket, welcome_message, strlen(welcome_message), 0);
    file = fopen(rute_file, "a");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        close(client_socket);
        return;
    }
    while ((bytes_read = recv(client_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Recibido: %s\n", buffer);
        fprintf(file, "%s", buffer);
        if (strncmp(buffer, "HELO", 4) == 0) {
            const char *response = "250 Hello\r\n";
            send(client_socket, response, strlen(response), 0);
        } else if (strncmp(buffer, "MAIL FROM:", 10) == 0) {
            const char *response = "250 OK\r\n";
            send(client_socket, response, strlen(response), 0);
        } else if (strncmp(buffer, "RCPT TO:", 8) == 0) {
            const char *response = "250 OK\r\n";
            send(client_socket, response, strlen(response), 0);
        } else if (strncmp(buffer, "DATA", 4) == 0) {
            const char *response = "354 End data with <CR><LF>.<CR><LF>\r\n";
            send(client_socket, response, strlen(response), 0);
            while ((bytes_read = recv(client_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
                buffer[bytes_read] = '\0';
                if (strcmp(buffer, ".\r\n") == 0) {
                    break;
                }
                fprintf(file, "\n\nREAL DATA CORREO = {\n%s\n}\n", buffer);
            }
            const char *end_response = "250 OK: Message received\r\n";
            send(client_socket, end_response, strlen(end_response), 0);
        } else {
            const char *error_response = "500 Command unrecognized\r\n";
            send(client_socket, error_response, strlen(error_response), 0);
        }
    }
    fclose(file);
    close(client_socket);
}

int _listen_ (struct smtp * s){
    while(true){
        s->client_socket = accept(s->server_socket, (struct sockaddr *)&s->client_addr, &s->client_addr_len);
        if (s->client_socket == -1) {
            perror("Error al aceptar la conexión");
            continue;
        }
        handle_client(s->client_socket, s->name_file);
    }
}

void _close_smtp (struct smtp * s){
    close(s->server_socket);
}

void Smtp (struct smtp * s){
    s->client_addr_len = sizeof(s->client_addr);
    s->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (s->server_socket == -1) {
        perror("Error al crear el socket");
        exit(EXIT_FAILURE);
    }
    s->server_addr.sin_family = AF_INET;
    s->server_addr.sin_port = htons(s->port);
    s->server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(s->server_socket, (struct sockaddr *)&s->server_addr, sizeof(s->server_addr)) == -1) {
        perror("Error al enlazar el socket");
        close(s->server_socket);
        exit(EXIT_FAILURE);
    }
    if (listen(s->server_socket, 5) == -1) {
        perror("Error al poner el socket en modo de escucha");
        close(s->server_socket);
        exit(EXIT_FAILURE);
    }
    s->read = _listen_;
    s->close = _close_smtp;
}

#endif
