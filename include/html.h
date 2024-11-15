#ifndef HTML_H
#define HTML_H

#define HTML_LONG 3000

typedef struct {
    string code_html;
    string code_js;
    string code_css;
    struct{
        char code[HTML_LONG];
    struct{
        string text;
        string attributes;
        string class;
        string id;
        bool add;
    } h1;
    struct{
        string text;
        string attributes;
        string class;
        string id;
        bool add;
    } h2;
    struct{
        string text;
        string attributes;
        string class;
        string id;
        bool add;
    } h3;
    struct{
        string text;
        string attributes;
        string class;
        string id;
        bool add;
    } h4;
    struct{
        string text;
        string attributes;
        string class;
        string id;
        bool add;
    } h5;
    struct{
        string text;
        string attributes;
        bool add;
        string class;
        string id;
    } h6;
    struct{
        string text;
        string attributes;
        bool add;
        string class;
        string id;
    } p;
    struct{
        bool add;
    } br;
    struct{
        string code;
        string attributes;
        string src;
        bool add;
        string class;
        string id;
    } script;
    struct{
        string code;
        string attributes;
        string src;
        string class;
        string id;
        bool add;
    }style;
    struct{
        string attributes;
        string class;
        string id;
        string src;
        bool add;
    } img;
    struct{
        string href;
        string text;
        string attributes;
        string class;
        string id;
        bool add;
    }a;
    struct{
        string text;
        string attributes;
        string class;
        string id;
        bool add;
    }i;
    struct{
        string text;
        string attributes;
        string class;
        string id;
        bool add;
    }e;
    struct{
        string attributes;
        string class;
        string id;
        bool add;
        bool is_open;
    }span;
    struct{
        string src;
        string attributes;
        string class;
        string id;
        bool add;
    }video;
    struct{
        string src;
        string attributes;
        string class;
        string id;
        bool add;
    }audio;
    struct{
        bool is_open;
        bool add;
        string lang;
        string attributes;
    }html;
    struct{
        bool is_open;
        bool add;
    }center;
    struct{
        bool add;
        string rel;
        string href;
        string attributes;
    }link;
    struct{
        string type;
        string name;
        string value;
        string placeholder;
        string class;
        string id;
        bool add;
        bool required;
        string attributes;
    }input;
    struct{
        string class;
        string id;
        string attributes;
        string text;
        bool add;
    }b;
    struct{
        string class;
        string id;
        string attributes;
        string text;
        bool add;
    }em;
    struct{
        bool add;
        string attributes;
    }meta;
    struct{
        string text;
        string attributes;
        bool add;
        string class;
        string id;
    }button;
    struct{
        string text;
        string class;
        string id;
        string attributes;
        bool add;
    }label;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }div;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }body;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }head;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }header;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }main;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }section;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }article;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
        string name;
        struct{
            bool add;
            string text;
            string class;
            string id;
            string value;
        }option;
    }select;
    struct{
        bool add;
        string attributes;
        string class;
        string id;
        string value;
        string text;
    }option;
    struct{
        bool add;
        string attributes;
        string class;
        string id;
        string text;
        bool is_open;
    }footer;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
        string action;
        string method;
        string encrypt;
    }form;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }aside;
    struct{
        bool add;
    }hr;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }pre;
    struct{
        bool add;
        string attributes;
        string class;
        string id;
        string name;
        string cols;
        string rows;
    }textarea;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }blockquote;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }ol;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }ul;
    struct{
        bool add;
        string attributes;
        string class;
        string id;
        string text;
    }li;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }dl;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }dt;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }dd;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }figure;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }small;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }cite;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }sub;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }sup;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }mark;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }iframe;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }embed;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }table;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }tbody;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }thead;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }tfoot;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
        string text_td;
        string text;
        struct{
            bool add;
            string attributes;
            bool is_open;
            string class;
            string id;
        }td;
    }tr;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }td;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }th;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }dialog;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }caption;
    struct{
        bool add;
        string attributes;
        bool is_open;
        string class;
        string id;
    }nav;
    struct{
        bool add;
        string text;
    }text;
    struct{
        bool add;
        string text;
    }title;
    }HTML;
}html;

void cat(const char *texto1, const char *texto2, char *resultado){
    strcpy(resultado, texto1);
    strcat(resultado, texto2);
}

void create_html (html * html){
    char tm_code[HTML_LONG];
    if(html->HTML.h1.add == true){
        char tm[HTML_LONG];
        if(html->HTML.h1.attributes == EMPTY || strcmp(html->HTML.h1.attributes,"null") == 0 || strcmp(html->HTML.h1.attributes,"") == 0){
            snprintf(tm_code, HTML_LONG, "<h1>%s</h1>\n", html->HTML.h1.text);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<h1 %s >%s</h1>\n", html->HTML.h1.attributes, html->HTML.h1.text);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.h1.add = false;
    }
    if(html->HTML.h2.add == true){
        char tm[HTML_LONG];
        if(html->HTML.h2.attributes == EMPTY || strcmp(html->HTML.h2.attributes,"null") == 0 || strcmp(html->HTML.h2.attributes,"") == 0){
            snprintf(tm_code, HTML_LONG, "<h2>%s</h2>\n", html->HTML.h2.text);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<h2 %s >%s</h2>\n", html->HTML.h2.attributes, html->HTML.h2.text);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.h2.add = false;
    }
    if(html->HTML.h3.add == true){
        char tm[HTML_LONG];
        if(html->HTML.h3.attributes == EMPTY || strcmp(html->HTML.h3.attributes,"null") == 0 || strcmp(html->HTML.h3.attributes,"") == 0){
            snprintf(tm_code, HTML_LONG, "<h3>%s</h3>\n", html->HTML.h3.text);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<h3 %s >%s</h3>\n", html->HTML.h3.attributes, html->HTML.h3.text);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.h3.add = false;
    }
    if(html->HTML.h4.add == true){
        char tm[HTML_LONG];
        if(html->HTML.h4.attributes == EMPTY || strcmp(html->HTML.h4.attributes,"null") == 0 || strcmp(html->HTML.h4.attributes,"") == 0){
            snprintf(tm_code, HTML_LONG, "<h4>%s</h4>\n", html->HTML.h4.text);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<h4 %s >%s</h4>\n", html->HTML.h4.attributes, html->HTML.h4.text);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.h4.add = false;
    }
    if(html->HTML.h5.add == true){
        char tm[HTML_LONG];
        if(html->HTML.h5.attributes == EMPTY || strcmp(html->HTML.h5.attributes,"null") == 0 || strcmp(html->HTML.h5.attributes,"") == 0){
            snprintf(tm_code, HTML_LONG, "<h5>%s</h5>\n", html->HTML.h5.text);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<h5 %s >%s</h5>\n", html->HTML.h5.attributes, html->HTML.h5.text);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.h5.add = false;
    }
    if(html->HTML.h6.add == true){
        char tm[HTML_LONG];
        if(html->HTML.h6.attributes == EMPTY || strcmp(html->HTML.h6.attributes,"null") == 0 || strcmp(html->HTML.h6.attributes,"") == 0){
            snprintf(tm_code, HTML_LONG, "<h6>%s</h6>\n", html->HTML.h6.text);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<h6 %s >%s</h6>\n", html->HTML.h6.attributes, html->HTML.h6.text);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.h6.add = false;
    }
    if(html->HTML.br.add == true){
        char tm[10];
        snprintf(tm_code, HTML_LONG, "<br>");
        cat(html->HTML.code, "", tm);
        cat(tm, tm_code, html->HTML.code);
        html->HTML.br.add = false;
    }
    
    if(html->HTML.p.add == true){
        char tm[HTML_LONG];
        if(html->HTML.p.attributes == EMPTY || strcmp(html->HTML.p.attributes,"null") == 0 || strcmp(html->HTML.p.attributes,"") == 0){
            snprintf(tm_code, HTML_LONG, "<p>%s</p>\n", html->HTML.p.text);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<p %s >%s</p>\n", html->HTML.p.attributes, html->HTML.p.text);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.p.add = false;
    }
    if(html->HTML.a.add == true){
        char tm[HTML_LONG];
        snprintf(tm_code, HTML_LONG, "<a href=\"%s\" class=\"%s\" id=\"%s\" %s >%s</a>\n", html->HTML.a.href, html->HTML.a.class, html->HTML.a.id, html->HTML.a.attributes, html->HTML.a.text);
        cat(html->HTML.code, "", tm);
        cat(tm, tm_code, html->HTML.code);
        html->HTML.a.add = false;
    }
    if(html->HTML.i.add == true){
        char tm[HTML_LONG];
        snprintf(tm_code, HTML_LONG, "<i class=\"%s\" id=\"%s\" %s >%s</i>\n",html->HTML.i.class, html->HTML.i.id, html->HTML.i.attributes, html->HTML.i.text);
        cat(html->HTML.code, "", tm);
        cat(tm, tm_code, html->HTML.code);
        html->HTML.i.add = false;
    }
    if(html->HTML.e.add == true){
        char tm[HTML_LONG];
        snprintf(tm_code, HTML_LONG, "<e class=\"%s\" id=\"%s\" %s >%s</e>\n",html->HTML.e.class, html->HTML.e.id, html->HTML.e.attributes, html->HTML.e.text);
        cat(html->HTML.code, "", tm);
        cat(tm, tm_code, html->HTML.code);
        html->HTML.e.add = false;
    }
    if(html->HTML.span.add == true){
        if(html->HTML.span.is_open == true){
            char tm[HTML_LONG];
            snprintf(tm_code, HTML_LONG, "<span class=\"%s\" id=\"%s\" %s >\n",html->HTML.span.class, html->HTML.span.id, html->HTML.span.attributes);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
            html->HTML.span.add = false;
        } else {
            char tm[HTML_LONG];
            snprintf(tm_code, HTML_LONG, "</span>\n");
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
            html->HTML.span.add = false;
        }
    }
    
    if(html->HTML.html.add == true){
        if(html->HTML.html.is_open == true){
            char tm[HTML_LONG];
            snprintf(tm_code, HTML_LONG, "<html lang=\"%s\" %s>\n",html->HTML.html.lang, html->HTML.html.attributes);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
            html->HTML.html.add = false;
        } else {
            char tm[HTML_LONG];
            snprintf(tm_code, HTML_LONG, "</html>\n");
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
            html->HTML.html.add = false;
        }
    }
    
    if(html->HTML.center.add == true){
        if(html->HTML.center.is_open == true){
            char tm[HTML_LONG];
            snprintf(tm_code, HTML_LONG, "<center>\n");
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
            html->HTML.center.add = false;
        } else {
            char tm[HTML_LONG];
            snprintf(tm_code, HTML_LONG, "</center>\n");
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
            html->HTML.center.add = false;
        }
    }
    if(html->HTML.link.add == true){
        char tm[HTML_LONG];
        snprintf(tm_code, HTML_LONG, "<link rel=\"%s\" href=\"%s\" %s >\n",html->HTML.link.rel, html->HTML.link.href, html->HTML.link.attributes);
        cat(html->HTML.code, "", tm);
        cat(tm, tm_code, html->HTML.code);
        html->HTML.link.add = false;
    }
    if(html->HTML.input.add == true){
        char tm[HTML_LONG];
        if(html->HTML.input.required == true){
            snprintf(tm_code, HTML_LONG, "<input type=\"%s\" name=\"%s\" id=\"%s\" value=\"%s\" placeholder=\"%s\" class=\"%s\" %s required>\n",html->HTML.input.type, html->HTML.input.name, html->HTML.input.id, html->HTML.input.value, html->HTML.input.placeholder, html->HTML.input.class, html->HTML.input.attributes);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<input type=\"%s\" name=\"%s\" id=\"%s\" value=\"%s\" placeholder=\"%s\" class=\"%s\" %s >\n",html->HTML.input.type, html->HTML.input.name, html->HTML.input.id, html->HTML.input.value, html->HTML.input.placeholder, html->HTML.input.class, html->HTML.input.attributes);
            cat(html->HTML.code, "", tm);
            cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.input.add = false;
    }
    if(html->HTML.b.add == true){
        char tm[HTML_LONG];
        snprintf(tm_code, HTML_LONG, "<b class=\"%s\" id=\"%s\" %s >%s</b>\n",html->HTML.b.class, html->HTML.b.id,html->HTML.b.attributes ,html->HTML.b.text);
        cat(html->HTML.code, "", tm);
        cat(tm, tm_code, html->HTML.code);
        html->HTML.b.add = false;
    }
    if(html->HTML.em.add == true){
        char tm[HTML_LONG];
        snprintf(tm_code, HTML_LONG, "<em class=\"%s\" id=\"%s\" %s >%s</em>\n",html->HTML.em.class, html->HTML.em.id,html->HTML.em.attributes ,html->HTML.em.text);
        cat(html->HTML.code, "", tm);
        cat(tm, tm_code, html->HTML.code);
        html->HTML.em.add = false;
    }
    if(html->HTML.meta.add == true){
	    char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<meta %s >", html->HTML.meta.attributes);
	    cat(html->HTML.code,"",tm);
	    cat(tm, tm_code, html->HTML.code);
	    html->HTML.meta.add = false;
    }
    if(html->HTML.button.add == true){
	    char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<button class=\"%s\" id=\"%s\" %s >%s</button>", html->HTML.button.class, html->HTML.button.id, html->HTML.button.attributes, html->HTML.button.text);
	    cat(html->HTML.code,"",tm);
	    cat(tm, tm_code, html->HTML.code);
	    html->HTML.button.add = false;
    }
    if(html->HTML.label.add == true){
	    char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<label class=\"%s\" id=\"%s\" %s >%s</label>", html->HTML.label.class, html->HTML.label.id, html->HTML.label.attributes, html->HTML.label.text);
	    cat(html->HTML.code,"",tm);
	    cat(tm, tm_code, html->HTML.code);
	    html->HTML.label.add = false;
    }
    if(html->HTML.div.add == true){
        if(html->HTML.div.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<div class=\"%s\" id=\"%s\" %s >", html->HTML.div.class, html->HTML.div.id, html->HTML.div.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</div>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.div.add = false;
    }
    if(html->HTML.body.add == true){
        if(html->HTML.body.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<body class=\"%s\" id=\"%s\" %s >", html->HTML.body.class, html->HTML.body.id, html->HTML.body.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</body>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.body.add = false;
    }
    if(html->HTML.head.add == true){
        if(html->HTML.head.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<head class=\"%s\" id=\"%s\" %s >", html->HTML.head.class, html->HTML.head.id, html->HTML.head.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</head>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.head.add = false;
    }
    if(html->HTML.header.add == true){
        if(html->HTML.header.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<header class=\"%s\" id=\"%s\" %s >", html->HTML.header.class, html->HTML.header.id, html->HTML.header.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</header>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.header.add = false;
    }
    if(html->HTML.main.add == true){
        if(html->HTML.main.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<main class=\"%s\" id=\"%s\" %s >", html->HTML.main.class, html->HTML.main.id, html->HTML.main.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</main>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.main.add = false;
    }
    if(html->HTML.section.add == true){
        if(html->HTML.section.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<section class=\"%s\" id=\"%s\" %s >", html->HTML.section.class, html->HTML.section.id, html->HTML.section.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</section>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.section.add = false;
    }
    if(html->HTML.article.add == true){
        if(html->HTML.article.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<article class=\"%s\" id=\"%s\" %s >", html->HTML.article.class, html->HTML.article.id, html->HTML.article.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</article>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.article.add = false;
    }
    if(html->HTML.select.add == true){
        if(html->HTML.select.is_open == true){
            if(html->HTML.select.option.add == true){
                char tm[HTML_LONG];
	            snprintf(tm_code, HTML_LONG, "<select class=\"%s\" id=\"%s\" %s ><option class=\"%s\" id=\"%s\" value=\"%s\" >%s</option>", html->HTML.select.class, html->HTML.select.id, html->HTML.select.attributes, html->HTML.select.option.class, html->HTML.select.option.id, html->HTML.select.option.value, html->HTML.select.option.text);
	            cat(html->HTML.code,"",tm);
	            cat(tm, tm_code, html->HTML.code);
            } else {
                char tm[HTML_LONG];
	            snprintf(tm_code, HTML_LONG, "<select class=\"%s\" id=\"%s\" %s >", html->HTML.select.class, html->HTML.select.id, html->HTML.select.attributes);
	            cat(html->HTML.code,"",tm);
	            cat(tm, tm_code, html->HTML.code);
            }
            
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</select>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.select.add = false;
    }
    if(html->HTML.option.add == true){
        char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<option class=\"%s\" id=\"%s\" value=\"%s\" %s >%s</option>", html->HTML.option.class, html->HTML.option.id, html->HTML.option.value, html->HTML.option.attributes, html->HTML.option.text);
	    cat(html->HTML.code,"",tm);
	    cat(tm, tm_code, html->HTML.code);
        html->HTML.option.add = false;
    }
    if(html->HTML.footer.add == true){
        if(html->HTML.footer.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<footer class=\"%s\" id=\"%s\" %s >%s", html->HTML.footer.class, html->HTML.footer.id, html->HTML.footer.attributes, html->HTML.footer.text);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</footer>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.footer.add = false;
    }
    if(html->HTML.form.add == true){
        if(html->HTML.form.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<form action=\"%s\" method=\"%s\" encrypt=\"%s\" class=\"%s\" id=\"%s\" %s >",html->HTML.form.action, html->HTML.form.method, html->HTML.form.encrypt, html->HTML.form.class, html->HTML.form.id, html->HTML.form.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</form>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.article.add = false;
    }
    if(html->HTML.aside.add == true){
        if(html->HTML.aside.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<aside class=\"%s\" id=\"%s\" %s >", html->HTML.aside.class, html->HTML.aside.id, html->HTML.aside.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</aside>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.aside.add = false;
    }
    if(html->HTML.hr.add == true){
        char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<hr/>");
	    cat(html->HTML.code,"",tm);
	    cat(tm, tm_code, html->HTML.code);
    }
    if(html->HTML.pre.add == true){
        if(html->HTML.pre.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<pre class=\"%s\" id=\"%s\" %s >", html->HTML.pre.class, html->HTML.pre.id, html->HTML.pre.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</pre>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.pre.add = false;
    }
    if(html->HTML.textarea.add == true){
        char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<textarea class=\"%s\" id=\"%s\" name=\"%s\" cols=\"%s\" rows=\"%s\" %s ></textarea>", html->HTML.textarea.class, html->HTML.textarea.id,html->HTML.textarea.name, html->HTML.textarea.cols, html->HTML.textarea.rows, html->HTML.textarea.attributes);
	    cat(html->HTML.code,"",tm);
	    cat(tm, tm_code, html->HTML.code);
        html->HTML.textarea.add = false;
    }
    if(html->HTML.blockquote.add == true){
        if(html->HTML.blockquote.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<blockquote class=\"%s\" id=\"%s\" %s >", html->HTML.blockquote.class, html->HTML.blockquote.id, html->HTML.blockquote.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</blockquote>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.blockquote.add = false;
    }
    if(html->HTML.ol.add == true){
        if(html->HTML.ol.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<ol class=\"%s\" id=\"%s\" %s >", html->HTML.ol.class, html->HTML.ol.id, html->HTML.ol.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</ol>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.ol.add = false;
    }
    if(html->HTML.ul.add == true){
        if(html->HTML.ul.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<ul class=\"%s\" id=\"%s\" %s >", html->HTML.ul.class, html->HTML.ul.id, html->HTML.ul.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</ul>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.ul.add = false;
    }
    if(html->HTML.li.add == true){
        char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<li class=\"%s\" id=\"%s\" %s>%s</li>",html->HTML.li.class, html->HTML.li.id, html->HTML.li.attributes, html->HTML.li.text);
	    cat(html->HTML.code,"",tm);
	    cat(tm, tm_code, html->HTML.code);
    }
    if(html->HTML.dl.add == true){
        if(html->HTML.dl.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<dl class=\"%s\" id=\"%s\" %s >", html->HTML.dl.class, html->HTML.dl.id, html->HTML.dl.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</dl>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.dl.add = false;
    }
    if(html->HTML.dt.add == true){
        if(html->HTML.dt.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<dt class=\"%s\" id=\"%s\" %s >", html->HTML.dt.class, html->HTML.dt.id, html->HTML.dt.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</dt>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.dt.add = false;
    }
    if(html->HTML.dd.add == true){
        if(html->HTML.dd.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<dd class=\"%s\" id=\"%s\" %s >", html->HTML.dd.class, html->HTML.dd.id, html->HTML.dd.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</dd>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.dd.add = false;
    }
    if(html->HTML.figure.add == true){
        if(html->HTML.figure.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<figure class=\"%s\" id=\"%s\" %s >", html->HTML.figure.class, html->HTML.figure.id, html->HTML.figure.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</figure>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.figure.add = false;
    }
    if(html->HTML.small.add == true){
        if(html->HTML.small.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<small class=\"%s\" id=\"%s\" %s >", html->HTML.small.class, html->HTML.small.id, html->HTML.small.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</small>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.small.add = false;
    }
    if(html->HTML.cite.add == true){
        if(html->HTML.cite.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<cite class=\"%s\" id=\"%s\" %s >", html->HTML.cite.class, html->HTML.cite.id, html->HTML.cite.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</cite>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.cite.add = false;
    }
    if(html->HTML.sub.add == true){
        if(html->HTML.sub.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<sub class=\"%s\" id=\"%s\" %s >", html->HTML.sub.class, html->HTML.sub.id, html->HTML.sub.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</sub>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.sub.add = false;
    }
    if(html->HTML.mark.add == true){
        if(html->HTML.mark.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<mark class=\"%s\" id=\"%s\" %s >", html->HTML.mark.class, html->HTML.mark.id, html->HTML.mark.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</mark>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.mark.add = false;
    }
    if(html->HTML.iframe.add == true){
        char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<iframe class=\"%s\" id=\"%s\" %s ></iframe>", html->HTML.iframe.class, html->HTML.iframe.id, html->HTML.iframe.attributes);
	    cat(html->HTML.code,"",tm);
	    cat(tm, tm_code, html->HTML.code);
        html->HTML.iframe.add = false;
    }
    if(html->HTML.embed.add == true){
        if(html->HTML.embed.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<embed class=\"%s\" id=\"%s\" %s >", html->HTML.embed.class, html->HTML.embed.id, html->HTML.embed.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</embed>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.embed.add = false;
    }
    if(html->HTML.table.add == true){
        if(html->HTML.table.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<table class=\"%s\" id=\"%s\" %s >", html->HTML.table.class, html->HTML.table.id, html->HTML.table.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</table>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.table.add = false;
    }
    if(html->HTML.tbody.add == true){
        if(html->HTML.tbody.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<tbody class=\"%s\" id=\"%s\" %s >", html->HTML.tbody.class, html->HTML.tbody.id, html->HTML.tbody.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</tbody>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.tbody.add = false;
    }
    if(html->HTML.thead.add == true){
        if(html->HTML.thead.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<thead class=\"%s\" id=\"%s\" %s >", html->HTML.thead.class, html->HTML.thead.id, html->HTML.thead.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</thead>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.thead.add = false;
    }
    if(html->HTML.tfoot.add == true){
        if(html->HTML.tfoot.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<tfoot class=\"%s\" id=\"%s\" %s >", html->HTML.tfoot.class, html->HTML.tfoot.id, html->HTML.tfoot.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</tfoot>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.tfoot.add = false;
    }
    if(html->HTML.tr.add == true){
        if(html->HTML.tr.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<tr class=\"%s\" id=\"%s\" %s >", html->HTML.tr.class, html->HTML.tr.id, html->HTML.tr.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</tr>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.tr.add = false;
    }
    if(html->HTML.td.add == true){
        if(html->HTML.td.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<td class=\"%s\" id=\"%s\" %s >", html->HTML.td.class, html->HTML.td.id, html->HTML.td.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</td>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.td.add = false;
    }
    if(html->HTML.th.add == true){
        if(html->HTML.th.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<th class=\"%s\" id=\"%s\" %s >", html->HTML.th.class, html->HTML.th.id, html->HTML.th.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</th>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.th.add = false;
    }
    if(html->HTML.dialog.add == true){
        if(html->HTML.dialog.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<dialog class=\"%s\" id=\"%s\" %s >", html->HTML.dialog.class, html->HTML.dialog.id, html->HTML.dialog.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</dialog>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.dialog.add = false;
    }
    if(html->HTML.caption.add == true){
        if(html->HTML.caption.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<caption class=\"%s\" id=\"%s\" %s >", html->HTML.caption.class, html->HTML.caption.id, html->HTML.caption.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</caption>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.caption.add = false;
    }
    if(html->HTML.nav.add == true){
        if(html->HTML.nav.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<nav class=\"%s\" id=\"%s\" %s >", html->HTML.nav.class, html->HTML.nav.id, html->HTML.nav.attributes);
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</nav>");
	        cat(html->HTML.code,"",tm);
	        cat(tm, tm_code, html->HTML.code);
        }
        html->HTML.nav.add = false;
    }
    if(html->HTML.text.add == true){
        char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "%s",html->HTML.text.text);
	    cat(html->HTML.code,"",tm);
	    cat(tm, tm_code, html->HTML.code);
	    html->HTML.text.add = false;
    }
    if(html->HTML.title.add == true){
        char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<title>%s</title>",html->HTML.title.text);
	    cat(html->HTML.code,"",tm);
	    cat(tm, tm_code, html->HTML.code);
	    html->HTML.title.add = false;
    }
}

#endif
