#ifndef SMTP_H
#define SMTP_H

#define MAX_MAILS 1024
#define SMTP_TEXT 500
#define BUFFER_SIZE_SMTP 1000

#include <curl/curl.h>

typedef struct {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    String name_file;
    int port;
    int is_error;
    int show_errors;
    struct{
        char smtp_url[MAX_MAILS];
        char smtp_user[MAX_MAILS];
        char smtp_password[MAX_MAILS];
        char mail_from[MAX_MAILS];
        char recipient[MAX_MAILS];
        char payload_text[SMTP_TEXT];
    } mail;
    string nameFileEmail;
    bool isContinue;
}SMTP;

void handle_client_smtp (SMTP * s) {
    char buffer[BUFFER_SIZE_SMTP];
    char rute_file[1024];
    int bytes_read;
    FILE *file;
    snprintf(rute_file,1024,"./emails/%s.emails",s->nameFileEmail);
    String welcome_message = "220 Testing server SMTP cweb\r\n";
    send(s->client_socket, welcome_message, strlen(welcome_message), 0);
    file = fopen(rute_file, "a");
    if (file == NULL) {
        perror("cweb ");
        close(s->client_socket);
        return;
    }
    while ((bytes_read = recv(s->client_socket, buffer, BUFFER_SIZE_SMTP - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Content: %s\n", buffer);
        fprintf(file, "%s", buffer);
        if (strncmp(buffer, "HELO", 4) == 0) {
            String response = "250 Hello\r\n";
            send(s->client_socket, response, strlen(response), 0);
        } else if (strncmp(buffer, "MAIL FROM:", 10) == 0) {
            String response = "250 OK\r\n";
            send(s->client_socket, response, strlen(response), 0);
        } else if (strncmp(buffer, "RCPT TO:", 8) == 0) {
            String response = "250 OK\r\n";
            send(s->client_socket, response, strlen(response), 0);
        } else if (strncmp(buffer, "DATA", 4) == 0) {
            String response = "354 End data with <CR><LF>.<CR><LF>\r\n";
            send(s->client_socket, response, strlen(response), 0);
            while ((bytes_read = recv(s->client_socket, buffer, BUFFER_SIZE_SMTP - 1, 0)) > 0) {
                buffer[bytes_read] = '\0';
                if (strcmp(buffer, ".\r\n") == 0) {
                    break;
                }
                fprintf(file, "\n\nDATA EMAIL = {\n%s\n}\n", buffer);
            }
            String end_response = "250 OK: Message received\r\n";
            send(s->client_socket, end_response, strlen(end_response), 0);
        } else {
            String error_response = "500 Command unrecognized\r\n";
            send(s->client_socket, error_response, strlen(error_response), 0);
        }
    }
    fclose(file);
    close(s->client_socket);
}

void listen_emails (SMTP * s){
    while(s->isContinue){
        s->client_socket = accept(s->server_socket, (struct sockaddr *)&s->client_addr, &s->client_addr_len);
        if (s->client_socket == -1) {
            perror("cweb ");
            continue;
        }
        handle_client_smtp(s);
    }
}

void end_smtp (SMTP * s){
    close(s->server_socket);
}

int prepare_smtp (SMTP * s){
    s->client_addr_len = sizeof(s->client_addr);
    s->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (s->server_socket == -1) {
        perror("cweb ");
        return ERROR;
    }
    s->server_addr.sin_family = AF_INET;
    s->server_addr.sin_port = htons(s->port);
    s->server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(s->server_socket, (struct sockaddr *)&s->server_addr, sizeof(s->server_addr)) == -1) {
        perror("cweb ");
        close(s->server_socket);
        return ERROR;
    }
    if (listen(s->server_socket, 5) == -1) {
        perror("cweb ");
        close(s->server_socket);
        return ERROR;
    }
    return OK;
}

int mail(SMTP * email){
    CURL *curl;
    CURLcode res = CURLE_OK;
    curl = curl_easy_init();
    if (curl){
        curl_easy_setopt(curl, CURLOPT_URL, email->mail.smtp_url);
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, email->mail.mail_from);
        struct curl_slist *recipients = EMPTY;
        recipients = curl_slist_append(recipients, email->mail.recipient);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        curl_easy_setopt(curl, CURLOPT_USERNAME, email->mail.smtp_user);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, email->mail.smtp_password);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, EMPTY);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_READDATA, email->mail.payload_text);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "%s\n", curl_easy_strerror(res));

        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
    return (int)res;
}

#endif
