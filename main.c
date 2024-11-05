////////////////////////////////////////////////////////////////
//Este es un codigo de pruebas de la libreria cweb            //
//donde se estan probando todas la funcionalidades de la misma//
////////////////////////////////////////////////////////////////
#include "include/cweb.h"
#include <sqlite3.h>
#include <curl/curl.h>
/*Se crea una función para hacer una pagina de error 404 con la struct BuildHtml*/
void error_404_page (BuildHtml * page){
    page->html_o("lang=\"es\"");
    page->head_o(EMPTY);
    page->meta("charset=\"UTF-8\"");
    page->title("Error page 404");
    page->head_c();
    page->body_o(EMPTY);
    page->center_o();
    page->h1(EMPTY,"Esta es una pagina de error creada con la struct BuildHtml");
    page->p(EMPTY,"Este error surgio debido a que tu estabas solicitando un recurso a esta pagina que no se encuentra y/o no existe");
    page->center_c();
    page->body_c();
    page->html_c();
}
/*
* Function api()
* Esta función lo que realiza es una petición a una api
* con la struct Api_connect. Esta struct esta aun en un
* estado muy simple y de momento realiza cosas muy basicas
* como un get simple y un post simple
* existe tambien el valor headers que es para la cabecera de
* la petición.
*/
void api (){
    //Crear una variable de tipo Api_connect
    struct Api_connect api;
    //Esta función prepara la struct con las funciones indicadas recibe como parametro una variable de tipo
    api_connect(&api);
    //Esta propiedad es la url de la api a la que se va a realizar la petición.
    api.url = "https://api.thecatapi.com/v1/images/search";
    //Función para preparar la petición de a la api
    api.prepare(&api);
    //Función para realizar un una petición get sin más
    api.simple_get(&api);
    //Función para limpiar curl(llama a la función: curl_global_cleanup())
    api.clear(&api);
    //Función para guardar los datos devueltos de una petición y guardalo en la propiedad data de la struct
    //Nota: la respuesta de una petición a un api se guardab en un archivo.
    api.getData(&api);
    //Se muestra por consola la respuesta devuelta por la api
    printf("Datos api:\n%s\n",api.data);
}
/*
* Functión: server_web();
* Esta función lo que realiza es crear un servidor web sencillo para mostrar paginas web simple
* en el navegador. Para esto se usan la struct SERVER y la struct BuildHtml donde SERVER se
* se encarga de las cosas relaciondas con el servidor y buildHtml para el html, css y js de la pagina
* Nota: El usuaro de la struct SERVER y BuldHtml para ser usadas juntas no esta implementado de todo
* solo con las paginas de error 404 y 500(a medias)
*/
void server_web (){
    //Se define una variable de tipo SERVER
    struct SERVER server;
    //Se inician el puerto, url y el listen
    server.port = DEFAULT_PORT;//8000
    server.url = DEFAULT_URL;//127.0.0.1 o localhost
    server.listen = DEFAULT_LISTEN;//10
    //Se define una variable de tipo BuildHtml
    BuildHtml page_404, index_page;
    //Se inicializa la variable de tipo BuildHtml
    buildHtml(&page_404);
    buildHtml(&index_page);
    //Se usa la función anteriormente creada para crear la pagina de error 404
    //error_404_page(&page_404);
    index_page.html_o("lang=\"es\"");
    index_page.head_o(EMPTY);
    index_page.head_c();
    index_page.body_c(EMPTY);
    index_page.center_o();
    index_page.h1(EMPTY,"Ciao! questa é la mia pagina fabbricata con il lenguggio C!");
    index_page.center_c();
    index_page.body_c();
    index_page.html_c();
    //Se inicializa la propiedad .response_code_404 con la pagina creada en la función error_404
    server.response_code_404 = "<h1>Error 404</h1>"/*page_404.get_code_html()*/;
    //Se prepara el servidor o se pone en modo escucha de peticiones
    prepare_SERVER(&server);
    server.pages_actives = 1;
    server.simple_pages = true;
    server.pages[0] = "index";
    server.pages[1] = "login";
    server.pages[2] = "register.c";
    server.code_pages[0] = index_page.get_code_html();
    //Se crea un bucle infinito para peticiones
    while(true){
        //Función para aceptar las peticones entrantes. Recive como parametro una variable de tipo sturtc SERVER
        server.accept_conections(&server);
        server.handle_client(&server);
        //Función para mostrar en consola la respuesta o la petición en su defecto del navegador
        puts(GET_RESPONSE());
    }
}
/*
* Función: server_smtp ();
* Esta es una función simple muy simple para hacer puebas de correos
* en esta función se usa la struct smtp.
* Nota: la stuct smtp y sus funciones es solo para puebas en local no tiene
* ninguna implentación avanzada ni media ni de seguridad.
*/
void server_smtp () {
    //Se crear una variable de tipo struct smtp
    struct smtp mails;
    //se establece el puerto de escucha. La url por defecto es localhost
    mails.port = DEFAULT_PORT_SMTP;//1025
    //se inicializa la struct smtp
    Smtp(&mails);
    //se establece el archivo donde se va a guardar los 'correos' recividos. Sin extensión que por defecto y forzado es *.emails 
    mails.name_file = "correos";
    //se establece el servidor smtp en modo escucha de peticiones
    mails.read(&mails);
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
/*
* Función: base_data_sqlite();
* esta función prueba la struct CDO(copia muy pero muy barata de PDO de PHP) donde realiza un insert y muestra los datos
* con una encasulacion de la columna 'Nombre'
*/
void base_data_sqlite () {
    //Se define una variable de tipo CDO
    struct CDO cd;
    //se inicializa la struct CDO o la variable de tipo CDO
    cdo(&cd);
    //se estable si se quiere ver los errores en consola
    cd.errors = true;
    //nombre de la base de datos. Sin extensión que por defecto y de forma forzada es: *.db
    cd.name_s = "Pruebas2";
    //la query a ejecuta en este caso es para insertar valores. De momento la función para insertar valores por paramtros no funciona
    cd.query_s = "INSERT INTO users (Nombre, Edad) VALUES ('Nombre','1')";
    //se ejecuta la query
    cd.exec(&cd);
    //se realiza otra query pero esta vez es para mostrar valores
    cd.query_s = "SELECT * FROM users WHERE Nombre='Nombre'";
    //se ejecuta la query y adicional se le pasa una función callback para trabajar con los datos mostrados
    cd.select(&cd,callback);
    //Se muestra la si hubo errores: 200=OK y 500=ERROR
    printf("Errors = %i\n",cd.is_error);
}
/*
* Función: send_mail();
* esta función usa la strut mail que se encuentra en la struct smtp
* para enviar correos y la función `mail(struct smtp * email)`. A esta struct aun le faltan algunas funciones
* para que sea mas sencillo enviar correo.
* Nota: La función `mail()` y la mail dentro de struct smtp estan configuradas para el uso de proveedores de 
* servición smtp y todos las propiedades de mail son obligatorios para enviar los correos.
*/
void send_mail (){
    //Declaración de la variable tipo smtp
    struct smtp email;
    //Se establece la url del proveedor del servidor smtp
    strcpy(email.mail.smtp_url,"localhost:1025");
    //Se estable el usuario de la cuenta creada en el proveedor SMTP
    strcpy(email.mail.smtp_user,"localhost");
    //Se establece la contraceña de la cuenta creada en el proveedor SMTP
    strcpy(email.mail.smtp_password,"");
    //Se establece quien envia el correo
    strcpy(email.mail.mail_from,"example@example.com");
    //Se establece para quien es el correo
    strcpy(email.mail.recipient,"example@example.com");
    //Se establece el texto del correo
    strcpy(email.mail.payload_text,"Message example");
    //Se envia el correo
    mail(&email);
}
/*
* Función: create_html_page();
* Esta función crea una pagina html con la struct BuildHtml pero sin la necesidad de funciones
* Lo cual tiene la ventaja de poder crear paginas un poco más facil y sin problemas de confución
* de codigos html al usar las funciones de la struct BuildHtml ya que usan variables globales
* para crear las paginas html.
*/
void create_html_page (){
    BuildHtml html;
    html.HTML.h1.text = "etiqueta h1";
    html.HTML.h1.attributes = EMPTY;
    html.HTML.h1.add = true;
    html.HTML.h2.text = "etiqueta h2";
    html.HTML.h2.attributes = "class=\"color-azul\"";
    html.HTML.h2.add = true;
    html.HTML.b.text = "Texto";
    html.HTML.b.class = "a";
    html.HTML.b.id = "t";
    html.HTML.b.attributes = "referer";
    html.HTML.b.add = true;
    create_html(&html);
    html.HTML.h1.text = "otro h1";
    html.HTML.h1.attributes = EMPTY;
    html.HTML.h1.id = EMPTY;
    html.HTML.h1.class = EMPTY;
    html.HTML.h1.add = true;
    html.HTML.select.class = EMPTY;
    html.HTML.select.id = EMPTY;
    html.HTML.select.is_open = true;
    html.HTML.select.attributes = EMPTY;
    html.HTML.select.name = "paises";
    html.HTML.select.option.add = true;
    html.HTML.select.option.class = "";
    html.HTML.select.option.id = "";
    html.HTML.select.option.text = "Rusia";
    html.HTML.select.option.value = "ru";
    html.HTML.select.add = true;
    create_html(&html);
    printf("Codigo html:\n%s",html.HTML.code);
}

int main (){
    //server_web();
    //server_smtp();
    //base_data_sqlite();
    //api();
    //send_mail();
    create_html_page();
    return 0;
}
