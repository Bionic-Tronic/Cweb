////////////////////////////////////////////////////////////////
//Archivo: var.h                                              //
//Este header contiene los tipo de datos, structs, macros y   //
// enums necesarios para el funcionamiento                    //
//de la libreria cweb.                                        //
////////////////////////////////////////////////////////////////
#ifndef VAR_H
#define VAR_H

typedef const char *String;
typedef void (*func)();
typedef void function;

#define ERROR 500
#define OK 200
#define EMPTY ((void *)0)
#define PAGE String
#define BUFFER_SIZE 1096
#define HTML_LONG 10096
#define GET_RESPONSE() buffer
#define DEFAULT_PORT 8000
#define DEFAULT_LISTEN 10
#define DEFAULT_BUFFER_FILE 6046
#define DEFAULT_URL "127.0.0.1"
#define MAX 100
#define SMTP_TEXT 500
#define DEFAULT_PORT_SMTP 1025
#define MAX_VARS 1024
#define MAX_LENGTH_JSON_TEXT 1000
#define MAX_ARRAY_JSON 100
#define MAX_QUERY 500
#define MAX_MAILS 200

char buffer[BUFFER_SIZE] = {0};
char code_html[HTML_LONG] = " ";
char tmp_code_html[HTML_LONG] = "<html>";
int pre = 0;
String content_file;
size_t length;
size_t body_offset;
String end_of_header;
String _rute;
String _query_std;
String _query;
int isAtError = 0;
String strError = "";
int peticiones = 0;

typedef enum{
    false,
    true
} boolean;

struct SERVER{
    int addrlen;
    int server_fd, new_socket, valread;
    int server_socket, client_socket, errors, is_error, port, listen, buffer_file;
    String url, response_code_html, response_code_404;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    int (*handle_client)(struct SERVER *);
    int (*accept_conections)(struct SERVER *);
    String (*load_response)();
    int (*save_response_server)(const String);
};

struct smtp{
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    String name_file;
    int port;
    int is_error;
    int show_errors;
    int (*read)(struct smtp *);
    void (*close)(struct smtp *);
    struct{
        char smtp_url[MAX_MAILS];
        char smtp_user[MAX_MAILS];
        char smtp_password[MAX_MAILS];
        char mail_from[MAX_MAILS];
        char recipient[MAX_MAILS];
        char payload_text[SMTP_TEXT];
    } mail;
};

typedef struct{
    int (*save)(const String, const String, const String, const String);
    int (*delete)(const String);
    char dat[2024];
    String nameData;
    String (*getValue)(const String, const String, const String);
    void (*resetData)(const String);
    String (*getDat)(const String);
} Properties;

typedef struct{
    char current_date[20];
    char hour[9];
} date;

typedef struct{
    int long_html;
    void (*show_html_console)();
    void (*resetAllHTML)();
    void (*view_html)();
    void (*title)(const String);
    void (*html_o)(const String);
    void (*html_c)();
    void (*canvas_o)(const String);
    void (*canvas_c)();
    void (*center_o)();
    void (*center_c)();
    void (*h1)(const String, const String);
    void (*h2)(const String, const String);
    void (*h3)(const String, const String);
    void (*h4)(const String, const String);
    void (*h5)(const String, const String);
    void (*h6)(const String, const String);
    void (*i)(const String, const String);
    void (*b)(const String, const String);
    void (*e)(const String, const String);
    void (*em)(const String, const String);
    void (*button)(const String, const String);
    void (*script)(const String, const String);
    void (*script_src)(const String, struct SERVER *, int);
    void (*div)(const String);
    void (*div_o)(const String);
    void (*div_c)();
    void (*body_o)(const String);
    void (*body_c)();
    void (*body)();
    void (*head_o)(const String);
    void (*head_c)();
    void (*head)(const String);
    int (*img)(const String);
    int (*a)(const String, const String);
    void (*main_o)(const String);
    void (*main_c)();
    void (*section_o)(const String);
    void (*section_c)();
    void (*section)(const String);
    void (*article_o)(const String);
    void (*article_c)();
    void (*article)(const String);
    void (*header_o)(const String);
    void (*header_c)();
    void (*header)(const String);
    void (*style)(const String);
    void (*footer)(const String);
    void (*footer_o)(const String);
    void (*footer_c)();
    void (*video)(const String);
    void (*source)(const String);
    void (*form)(const String);
    void (*form_o)(const String);
    void (*form_c)();
    int (*input)(const String);
    int (*meta)(const String);
    int (*link)(const String);
    void (*aside)(const String);
    void (*hr)();
    void (*br)();
    void (*pre)();
    void (*center)();
    void (*textarea)(const String);
    void (*blockquote)(const String);
    void (*ol)(const String);
    void (*ol_o)(const String);
    void (*ol_c)();
    void (*ul)(const String);
    void (*ul_o)(const String);
    void (*ul_c)();
    void (*li)(const String, const String);
    void (*dl)();
    void (*dl_o)(const String);
    void (*dl_c)();
    void (*dt)();
    void (*dt_o)(const String);
    void (*dt_c)();
    void (*dd)();
    void (*dd_o)(const String);
    void (*dd_c)();
    void (*figure)();
    void (*figure_o)(const String);
    void (*figure_c)();
    void (*small)();
    void (*cite)();
    void (*sub)();
    void (*sup)();
    void (*mark)();
    int (*iframe)(const String);
    void (*embed)();
    void (*audio)(const String);
    void (*table)();
    void (*table_o)(const String);
    void (*table_c)();
    void (*tbody)(const String);
    void (*tbody_o)(const String);
    void (*tbody_c)();
    void (*thead)(const String);
    void (*thead_o)(const String);
    void (*thead_c)();
    void (*tfoot)(const String);
    void (*tfoot_o)(const String);
    void (*tfoot_c)();
    int (*tr)(const String, const String);
    int (*td)(const String, const String);
    int (*th)(const String, const String);
    void (*label)(const String, const String);
    void (*select)(const String);
    void (*select_o)(const String);
    void (*select_c)();
    void (*option)(const String);
    void (*option_o)(const String);
    void (*option_c)();
    void (*caption)();
    void (*p)(const String, const String);
    void (*coment_o)();
    void (*coment_c)();
    void (*php_o)();
    void (*php_c)();
    void (*nav_o)(const String);
    void (*nav_c)();
    void (*nav)();
    void (*script_o)();
    void (*script_c)();
    void (*style_o)();
    void (*style_c)();
    void (*style_src)(const String, struct SERVER *, int);
    void (*php)(const String);
    void (*text)(const String);
    int (*send)(struct SERVER *);
    int (*send_)(struct SERVER *);
    void (*tr_o)(const String);
    void (*tr_c)();
    void (*load_extern_html)(const String);
    String (*get_code_html)();
    struct{
    size_t length;
    char code[HTML_LONG];
    struct{
        String text;
        String attributes;
        String class;
        String id;
        boolean add;
    } h1;
    struct{
        String text;
        String attributes;
        String class;
        String id;
        boolean add;
    } h2;
    struct{
        String text;
        String attributes;
        String class;
        String id;
        boolean add;
    } h3;
    struct{
        String text;
        String attributes;
        String class;
        String id;
        boolean add;
    } h4;
    struct{
        String text;
        String attributes;
        String class;
        String id;
        boolean add;
    } h5;
    struct{
        String text;
        String attributes;
        boolean add;
        String class;
        String id;
    } h6;
    struct{
        String text;
        String attributes;
        boolean add;
        String class;
        String id;
    } p;
    struct{
        boolean add;
    } br;
    struct{
        String code;
        String attributes;
        String src;
        boolean add;
        String class;
        String id;
    } script;
    struct{
        String code;
        String attributes;
        String src;
        String class;
        String id;
        boolean add;
    }style;
    struct{
        String attributes;
        String class;
        String id;
        String src;
        boolean add;
    } img;
    struct{
        String href;
        String text;
        String attributes;
        String class;
        String id;
        boolean add;
    }a;
    struct{
        String text;
        String attributes;
        String class;
        String id;
        boolean add;
    }i;
    struct{
        String text;
        String attributes;
        String class;
        String id;
        boolean add;
    }e;
    struct{
        String text;
        String attributes;
        String class;
        String id;
        boolean add;
    }span;
    struct{
        String src;
        String attributes;
        String class;
        String id;
        boolean add;
    }video;
    struct{
        String src;
        String attributes;
        String class;
        String id;
        boolean add;
    }audio;
    struct{
        boolean is_open;
        boolean add;
    }html;
    struct{
        boolean is_open;
        boolean add;
    }center;
    struct{
        boolean add;
        String rel;
        String href;
        String hreflang;
        String class;
        String id;
        String attributes;
    }link;
    struct{
        String type;
        String name;
        String value;
        String placeholder;
        String class;
        String id;
        boolean add;
    }input;
    struct{
        String class;
        String id;
        String attributes;
        String text;
        boolean add;
    }b;
    struct{
        String class;
        String id;
        String attributes;
        String text;
        boolean add;
    }em;
    struct{
        boolean add;
        String attributes;
    }meta;
    struct{
        String text;
        String attributes;
        boolean add;
    }button;
    struct{
        String text;
        String class;
        String id;
        String attributes;
        boolean add;
    }label;
    struct{
        boolean add;
        String atributes;
        boolean is_open;
        String class;
        String id;
    }div;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }body;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }head;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }header;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }main;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }section;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }article;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
        String name;
    }select;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
        String value;
    }option;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
        String text;
    }footer;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
        String action;
        String method;
        String encrypt;
    }form;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }aside;
    struct{
        boolean add;
    }hr;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }pre;
    struct{
        boolean add;
        String attributes;
        String class;
        String id;
        String name;
        String cols;
        String rows;
    }textarea;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }blockquote;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }ol;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }ul;
    struct{
        boolean add;
        String attributes;
        String class;
        String id;
        String text;
    }li;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }dl;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }dt;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }dd;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }figure;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }small;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }cite;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }sub;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }sup;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }mark;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }iframe;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }embed;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }table;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }tbody;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }thead;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }tfoot;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
        String text_td;
        String text;
        struct{
            boolean add;
            String attributes;
            boolean is_open;
            String class;
            String id;
        }td;
    }tr;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }td;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }th;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }dialog;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }caption;
    struct{
        boolean add;
        String attributes;
        boolean is_open;
        String class;
        String id;
    }nav;
    struct{
        boolean add;
        String text;
    }text;
}HTML;
} BuildHtml;

typedef struct{
    String (*name_archive)();
    String (*size_archive)();
    String (*type_archive)();
    int (*prepare_save)(struct SERVER *);
    int (*save)(const String);
    int (*isset_archive)();
    int (*upload)(struct SERVER *, const char *);
    void (*create_archive)(const String, const String, const String);
    String (*get_content_file)(String, int);
    String name;
    String type;
    String length;
} Archives;

typedef struct{
    struct{
        char *(*get)();
        int (*isset)(const String);
        char *(*get_name)(const char *, char);
        int (*read_img)();
        int (*read_video)();
    } Get;
    struct{
        char *(*post)();
        int (*isset)(const String);
        char *(*post_name)(const char *, char);
    } Post;
    struct{
        const int code;
        const String msg;
    } request_responses;
    int (*isset)(const String);
    char *(*get_isset)(const char *, char);
} Http;

typedef struct{
    String (*contentLength)();
    String (*platform_user)();
    String (*referer)();
    String (*accept_language)();
    String (*host)();
    String (*connection)();
    String (*accept)();
    String (*accept_encoding)();
    String (*user_agent)();
    String (*upgrade_insecure_requests)();
} Response;

struct Api_connect{
    CURL *curl;
    CURLcode res;
    String url;
    String post;
    String headers;
    String type_data;
    char data[MAX_VARS];
    int errors, is_error;
    int (*prepare)(struct Api_connect *);
    int (*simple_get)(struct Api_connect *);
    int (*simple_post)(struct Api_connect *);
    void (*clear)(struct Api_connect *);
    void (*getData)(struct Api_connect *);
};

typedef struct{
    String rute;
    String query_std;
    char query[MAX_QUERY];
    int (*execute_std)(struct SERVER *);
    int (*execute)(struct SERVER *);
} Sqlite;

struct CDO{
    String name_s;
    String query_s;
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int errors;
    int is_error;
    size_t length_arr;
    int (*exec)(struct CDO *);
    int (*insert_update)(struct CDO *, const String[]);
    int (*select)(struct CDO *, int (*)());
};

typedef enum{
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_BOOLEAN,
    JSON_NULL
} JsonValueType;

typedef struct{
    JsonValueType type;
    union {
        char string_value[MAX_LENGTH_JSON_TEXT];
        double number_value;
        int boolean_value;
    } value;
} JsonValue;

typedef struct{
    JsonValue values[MAX_ARRAY_JSON];
    int size;
} JsonArray;

static const char *IMGS_MIMES[] = {
    "image/jpeg",
    "image/png",
    "image/gif",
    "image/bmp",
    "image/webp",
    "image/svg+xml",
    "image/x-icon",
};

static const char *TEXT_DOCUMENTS_MIMES[] = {
    "text/html",
    "text/plain",
    "text/css",
    "application/javascript",
    "application/xml",
    "application/json",
    "application/chtml"};

static const char *VIDEOS_MIMES[] = {
    "video/mp4",
    "video/webm",
    "video/ogg",
    "video/x-msvideo",
    "video/quicktime",
};

static const char *AUDIO_MIMES[] = {
    "audio/mpeg",
    "audio/ogg",
    "audio/wav",
    "audio/webm",
    "audio/midi",
};

static const char *APPLICATIONS_MIMES[] = {
    "application/pdf",
    "application/gzip",
    "application/zip",
    "application/octet-stream",
};

static const char *OTHERS_MIMES[] = {
    "font/ttf",
    "font/otf",
    "font/woff",
    "font/woff2",
};

#endif
