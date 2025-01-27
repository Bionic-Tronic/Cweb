/*
* Codigo de pruebas y ejemplos de como usar y crear servidores con cweb.h
* Este es un codigo de ejemplo y pruebas de enviar paginas html sin la necesidad
* de llamanar a los archivos *.html directamente tipo enrutadores
* Los cambios de la struct CDO aun no estan implementados. Se agregaran pronto
*/
#include "../include/cweb.h"

int main(){
    string pages_html[] = {"pages/index.html","pages/registro.html","pages/dashboard.html","pages/error404.html"};
	int pages_html_size[] = {fsize(pages_html[0]),fsize(pages_html[1]),fsize(pages_html[2]),fsize(pages_html[3])};
	char index_html[pages_html_size[0]];
	char registro_html[pages_html_size[1]];
	char dashboard_html[pages_html_size[2]];
	char error404_html[pages_html_size[3]];
	bool es_login = false;
	server server;
	server.port = DEFAULT_PORT;
	server.url = DEFAULT_URL;
	server.listen = DEFAULT_LISTEN;
	server.pages_actives = 3;
	server.simple_pages = true;
	open_server(&server);
	server.pages[0] = "login";
	server.pages[1] = "registro";
	server.pages[2] = "dashboard";
	getFileContent(index_html, pages_html_size[0], pages_html[0]);
	getFileContent(registro_html, pages_html_size[1], pages_html[1]);
	getFileContent(dashboard_html, pages_html_size[2], pages_html[2]);
	getFileContent(error404_html, pages_html_size[3], pages_html[3]);
	server.code_pages[0] = index_html;
	server.code_pages[1] = registro_html;
	server.code_pages[2] = dashboard_html;
	server.response_code_404 = error404_html;
	while(true){
		accept_conections(&server);
        handle_client(&server);
        printf("%s",GET_RESPONSE());
        if(isset_post("username"))
       	es_login = true;
        if(es_login == true){
       	char dashboad[pages_html_size[2]];
       	PDO cdo;
	       cdo.get_data.db_name = "config/ventas_ejemplo.db";
	       cdo.get_data.sql = "SELECT * FROM ventas;";
	       cdo.get_data.capacity = 10;
	       cdo.get_data.max_length = 50;
	       Result * data = get_sqlite_data(&cdo);
       	cat(dashboad, dashboard_html, "Miguel",
       	data->rows[0].columns[1],
       	data->rows[0].columns[2],
       	data->rows[0].columns[3],
       	data->rows[0].columns[4],
       	data->rows[0].columns[5],
       	data->rows[0].columns[6],
       	data->rows[0].columns[7],
       	data->rows[0].columns[8],
       	data->rows[0].columns[9],
       	data->rows[0].columns[10]);
       	header(server.client_socket,HEADER_200,HTML_MIME,dashboad,strlen(dashboad));
        }
	}
    return 0;
}
