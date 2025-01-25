#ifndef CWEB_H
#define CWEB_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <netdb.h>
#include <sys/stat.h>
#include <sys/socket.h> 
#include <sys/types.h> 
#include <arpa/inet.h>
#include <sqlite3.h>
#include <curl/curl.h>
#include <stdbool.h>

#define MAX_PAGES 10000
#define EMPTY ((void*)0)
#define ERROR 500
#define OK    200
#define MAX_URLS 1000
#define DEFAULT_PORT 3000
#define DEFAULT_LISTEN 10
#define DEFAULT_BUFFER_FILE 6046
#define DEFAULT_URL "127.0.0.1"
#define BUFFER_SIZE 1096
#define MAX 1024
#define MAX_QUERY 2024
#define DB_ERROR  -1
#define DB_OK     1
#define FILE_ERROR 404
#define FILE_OK    201
#define MAX_MAILS 1024
#define SMTP_TEXT 500
#define BUFFER_SIZE_SMTP 1000
#define DATA_API 5024
#define MAX_PAIRS 100
#define MAX_STRING_LENGTH 1024
//Headers
#define HEADER_100 "HTTP/1.1 100 Continue"
#define HEADER_101 "HTTP/1.1 101 Switching Protocol"
#define HEADER_102 "HTTP/1.1 102 Processing"
#define HEADER_103 "HTTP/1.1 103 Early Hints"
#define HEADER_200 "HTTP/1.1 200 OK"
#define HEADER_201 "HTTP/1.1 201 Created"
#define HEADER_202 "HTTP/1.1 202 Accepted"
#define HEADER_203 "HTTP/1.1 203 Non-Authoritative Information"
#define HEADER_204 "HTTP/1.1 204 No Content"
#define HEADER_205 "HTTP/1.1 205 Reset Content"
#define HEADER_206 "HTTP/1.1 206 Partial Content"
#define HEADER_207 "HTTP/1.1 207 Multi-Status"
#define HEADER_208 "HTTP/1.1 208 Multi-Status"
#define HEADER_226 "HTTP/1.1 226 IM Used"
#define HEADER_300 "HTTP/1.1 300 Multiple Choice"
#define HEADER_301 "HTTP/1.1 301 Moved Permanently"
#define HEADER_302 "HTTP/1.1 302 Found"
#define HEADER_303 "HTTP/1.1 303 See Other"
#define HEADER_304 "HTTP/1.1 304 Not Modified"
#define HEADER_307 "HTTP/1.1 307 Temporaly Redirect"
#define HEADER_308 "HTTP/1.1 308 Permanent Redirect"
#define HEADER_400 "HTTP/1.1 400 Bad Request"
#define HEADER_401 "HTTP/1.1 401 Unauthorized"
#define HEADER_403 "HTTP/1.1 403 Forbidden"
#define HEADER_404 "HTTP/1.1 404 Not Found"
#define HEADER_405 "HTTP/1.1 405 Method Not Allowed"
#define HEADER_406 "HTTP/1.1 406 Not Acceptable"
#define HEADER_407 "HTTP/1.1 407 Proxy Authentication Required"
#define HEADER_408 "HTTP/1.1 408 Request Timeout"
#define HEADER_409 "HTTP/1.1 409 Conflict"
#define HEADER_410 "HTTP/1.1 410 Gone"
#define HEADER_411 "HTTP/1.1 411 Length Required"
#define HEADER_412 "HTTP/1.1 412 Precondition Failed"
#define HEADER_413 "HTTP/1.1 413 Payload Too Large"
#define HEADER_414 "HTTP/1.1 414 URI Too Long"
#define HEADER_415 "HTTP/1.1 415 Unsupported Media Type"
#define HEADER_416 "HTTP/1.1 416 Requested Range Not Satisfiable"
#define HEADER_417 "HTTP/1.1 417 Expectation Failed"
#define HEADER_418 "HTTP/1.1 418 I'm a teapot"
#define HEADER_421 "HTTP/1.1 421 Misdirected Request"
#define HEADER_422 "HTTP/1.1 422 Unprocessable Entity"
#define HEADER_423 "HTTP/1.1 423 Locked"
#define HEADER_424 "HTTP/1.1 424 Failed Dependency"
#define HEADER_426 "HTTP/1.1 426 Upgrade Required"
#define HEADER_428 "HTTP/1.1 428 Precondition Required"
#define HEADER_429 "HTTP/1.1 429 Too Many Requests"
#define HEADER_431 "HTTP/1.1 431 Request Header Fields Too Large"
#define HEADER_451 "HTTP/1.1 451 Unavailable For Legal Reasons"
#define HEADER_500 "HTTP/1.1 500 Internal Server Error"
#define HEADER_501 "HTTP/1.1 501 Not Implemented"
#define HEADER_502 "HTTP/1.1 502 Bad Gateway"
#define HEADER_503 "HTTP/1.1 503 Service Unavailable"
#define HEADER_504 "HTTP/1.1 504 Gateway Timeout"
#define HEADER_505 "HTTP/1.1 505 HTTP Version Not Supported"
#define HEADER_506 "HTTP/1.1 506 Variant Also Negotiates"
#define HEADER_507 "HTTP/1.1 507 Insufficient Storage"
#define HEADER_508 "HTTP/1.1 508 Loop Detected"
#define HEADER_509 "HTTP/1.1 510 Not Extended"
#define HEADER_510 "HTTP/1.1 511 Network Authentication Required"
//Mimes of most used files
#define HTML_MIME "text/html"
#define PNG_MIME "image/png"
#define JPG_MIME "image/jpeg"
#define GIF_MIME "image/gif"
#define BMP_MIME "image/bmp"
#define WEBP_MIME "image/webp"
#define SVG_MIME "image/svg+xml"
#define ICON_MIME "image/x-icon"
#define JS_MIME "application/javascript"
#define XML_MIME "application/xml"
#define JSON_MIME "application/json"
#define MP4_MIME "video/mp4"
#define WEBM_MIME "video/webm"
#define OGG_MIME "video/ogg"
#define AVI_MIME "video/x-msvideo"
#define MP3_MIME "audio/mp3"
#define WAV_MIME "audio/wav"
#define PDF_MIME "application/pdf"
#define ZIP_MIME "application/zip"
#define TTF_MIME "font/ttf"
#define QUICKTIME_MIME "video/quicktime"
#define CSS_MIME "text/css"

typedef char * string;
typedef const char * String;
typedef char page [MAX_PAGES];

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

typedef struct{
    string name_s;
    string query_s;
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int errors;
    int is_error;
    size_t length_arr;
}CDO;

typedef struct{
    string filename;
    string typefile;
    string sizefile;
    string end_of_header;
    size_t body_offset;
    size_t length;
    string content_file;
    int pre;
} files;

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

typedef struct {
    CURL *curl;
    CURLcode res;
    String url;
    String post;
    String headers;
    String type_data;
    char data[DATA_API];
}connect_api;
//Declarations of server.c
extern char buffer[BUFFER_SIZE];
#define GET_RESPONSE() buffer
int open_server (server * server);
int accept_conections (server * server);
string get (String palabra, string texto, char caracterLimite);
void send_response(int client_socket, const char *header, const char *content_type, const char *content, size_t content_length);
void send_file_response(int client_socket, const char *header, const char *content_type, const char *file_path);
String getExtension(String nombreArchivo);
int compareExtension(String archivo1, String archivo2);
int handle_client(server * server);
void header (int client_socket, const char *header, const char *content_type, const char *content, size_t content_length);
//Functions of cweb.c
string intToString (int entero);
string floatToString (double flotante);
int search_w(String word, String texto);
string searchWord(String texto, String palabra, char caracterLimite);
string searchInResponse(String palabra, char caracterLimite, string response);
//Declarations of http.c
int isset (String word);
string search_response (string palabra, char caracterLimite);
int isset_get (String word);
int isset_post (String word);
string GET (String palabra, char caracterLimite);
string POST (String palabra, char caracterLimite);
String content_length ();
String platform_user ();
String referer ();
String accept_language ();
String host ();
String connection ();
String Accept ();
String get_accept_encoding ();
String user_agent ();
String UIR ();
void send_http_code (int client_socket, string code, string res);
void cat (char *result, const char *format, ...);
//Functions of files.c
int getFileContent (string ptr, int size, string name);
off_t fsize(const char *filename);
//Functions of cdo.c
int exec (CDO * cdo);
int exec_insert (CDO * cdo, const String datos[]);
int exec_select(CDO * cdo, int (*callback)());
//Functions of smtp.c
void handle_client_smtp (SMTP * s);
void listen_emails (SMTP * s);
void end_smtp (SMTP * s);
int prepare_smtp (SMTP * s);
int mail(SMTP * email);
//Functions of api.c
int connect_api_callback (void *data, size_t size, size_t nmemb, void *userp);
int connect_api_get (connect_api * api);
int connect_api_prepare(connect_api * api);
int connect_api_post (connect_api * api);
int connect_api_getData (connect_api * api);
void connect_api_clear ();
void prepare_connect_api (connect_api * api);
//Functions of json.c
char** json_to_array(const char* json_string, int* size);
#endif
