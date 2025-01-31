/*
* Codigo para probar como funcionan las funciones
* para realizar peticiones a una API o servicio
* el siguiente codigo es para crear una pagina de galeria con imagenes de gatos
* con la API: thecatapi
*/
#include "../include/cweb.h"

int main(){
    //Declaración de una variable con la ruta de la pagina index.html con el codigo
    string index_page = "pages/index.html";
    //Obtención del tamaño del archivo index.html
    int page_html_size = fsize(index_page);
    //Se crea un arreglo de tipo char con el tamaño del archivo index.html
    char index_html[page_html_size];
    //Se guarda el contenido del archivo index.html en la variable anteriormente creada
    getFileContent(index_html, page_html_size, index_page);
    //Se crea un arreglo del tipo connect_api
    connect_api api[11];
    //Se crea un arreglo para guardar las urls de las imagenes
    string urls[11];
    int length = 0;
    for(int i = 0; i < 11; i++){
    	//Se preparan las api(No es necesario hasta cierto puento inutil solo se establece por defecto el header en "application/json" para recivir la respuesta en formato json)
    	prepare_connect_api(&api[i]);
    	//Se establece la url de la api
    	api[i].url = "https://api.thecatapi.com/v1/images/search";
    	//Se prepare para hacer la petición
    	connect_api_prepare(&api[i]);
    	//Se realiza una petición de tipo GET
    	connect_api_get(&api[i]);
    	//usleep(1000 * 1000);
    	//Se limpiar cURL y cierre
      connect_api_clear(&api[i]);
      //Se guarda el resultado obtenido
      connect_api_getData(&api[i]);
      char** datos;
      //Se convierte la respuesta de json a un arreglo de tipo char y se guarda en el arreglo urls
      datos = json_decode(api[i].data,&length);
      urls[i] = datos[4];
      free(datos);
    }
    puts("Listen server. . .");
    //Se agrega las urls a la pagina index.html
    char index_html_[page_html_size];
    cat(index_html_,index_html,urls[0],urls[1],urls[2],urls[3],urls[4],urls[5],urls[6],urls[7],urls[8],urls[9],urls[10]);
    //Se crea una variable del tipo server y se inicializan el puerto, url y el listen
    server server;
	  server.port = DEFAULT_PORT;//3000
	  server.url = DEFAULT_URL;//localhost/127.0.1
	  server.listen = DEFAULT_LISTEN;//10
	  //Se establece cuantas paginas se van a utilizar
	  server.pages_actives = 1;
	  //Se establece si se va usar paginas simples
	  server.simple_pages = true;
	  //Se inicialza el servidor y se pone en modo escucha
	  open_server(&server);
	  //Se establecen los nombres de las paginas para que pueda ser allada
	  server.pages[0] = "index";
	  //Se establece el codigo de la pagina 
	  server.code_pages[0] = index_html_;
	  //Se establece el codigo de la pagina error 404
	  server.response_code_404 = "<center><h1>Error 404</h1></center>";
	  while(true){
		    //Haceptar las conexiones
		    accept_conections(&server);
		    //Manejar las conexiones
        handle_client(&server);
        //Ver la petición del navegador
        printf("%s",GET_RESPONSE());
    }
    return 0;
}
