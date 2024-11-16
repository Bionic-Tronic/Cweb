#define _INCLUDE_ALL_
#include "include/cweb.h"
#include <sqlite3.h>
#include <curl/curl.h>

void server_web (){
   show_errors = true;
   html html;
   html.code_html = 
   "<!DOCTYPE >"
   "<html lang=\"es\">"
   "<head>"
   "<title>cweb - login</title>"
   "</head>"
   "<body>"
   "<center>"
   "<form action=\"#\" method=\"POST\" ><br>"
   "<input type=\"email\" name=\"email\" placeholder=\"Ingrese su correo. . .\" required>"
   "<input type=\"password\" name=\"password\" placeholder=\"Ingrese su contraceña. . .\" required>"
   "</form>"
   "</center>"
   "</body>"
   "</html>";
   server server;
   server.port = DEFAULT_PORT;
   server.url = DEFAULT_URL;
   server.listen = DEFAULT_LISTEN;
   server.pages_actives = 3;
   server.simple_pages = true;
   open_server(&server);
   server.pages[0] = "index";
   server.pages[1] = "login";
   server.pages[2] = "registro";
   server.code_pages[0] = "index";
   server.code_pages[1] = html.code_html;
   server.code_pages[2] = "<h1>Pagina del registro</h1>";
   server.response_code_404 = server.code_pages[0] = "<h1>Error 404 - Recurso no encontrado</h1>";
   while(true){
       accept_conections(&server);
       handle_client(&server);
       printf("%s",GET_RESPONSE());
   }
}

void server_smtp (){
    SMTP smtp;
    smtp.port = 1025;
    smtp.isContinue = true;
    smtp.nameFileEmail = "pruebas";
    prepare_smtp(&smtp);
    listen_emails(&smtp);
    end_smtp(&smtp);
}

void send_simple_mail (){
    
}

void connect_api_ (){
    connect_api api;
    connect_api_construct(&api);
    api.url = "https://api.thecatapi.com/v1/images/search";
    connect_api_prepare(&api);
    connect_api_get(&api);
    connect_api_clear();
    connect_api_getData(&api);
    printf("Datos api: %s\n",api.data);
}

int main (){
   //server_web();
   //server_smtp();
   //send_simple_mail();
   //connect_api_();
   return 0;
}
