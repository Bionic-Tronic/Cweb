#define _INCLUDE_ALL_
#include "include/cweb.h"
#include <sqlite3.h>
#include <curl/curl.h>

#define MAX_PAGE 6839

int main(){
    show_errors = true;
   char page_index[MAX_PAGE];
   read_file("index.html", MAX_PAGE, page_index);
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
   server.code_pages[0] = page_index;
   server.code_pages[1] = "<h1>Pagina de login</h1>";
   server.code_pages[2] = "<h1>Pagina de registro</h1>";
   server.response_code_404 = "<h1>Error 404 - Recurso no encontrado</h1>";
   while(true){
       read_file("index.html", MAX_PAGE, page_index);
       server.code_pages[0] = page_index;
       accept_conections(&server);
       handle_client(&server);
       printf("%s",GET_RESPONSE());
   }
    return 0;
}