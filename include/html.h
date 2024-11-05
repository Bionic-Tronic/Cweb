////////////////////////////////////////////////////////////////
//Archivo: html.h                                             //
//Este header contiene las funciones nesarias para trabajar   //
//con la creación de paginas webs con html, css y js.         //
////////////////////////////////////////////////////////////////
#ifndef HTML_H
#define HTML_H

//#include "cweb.hh"
//#include "cweb.h"

void cat_str(const char *texto1, const char *texto2, char *resultado){
    strcpy(resultado, texto1);
    strcat(resultado, texto2);
}

static void _title(const char *title)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<title>%s</title>\n", title);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _canvas_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<canvas>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<canvas %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _canvas_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</canvas>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _html_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<!DOCTYPE html>\n<html>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<!DOCTYPE html>\n<html %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _html_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</html>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _center_open()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<center>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _center_close()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</center>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _h1(const char *attributes, const char *h1)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<h1>%s</h1>\n", h1);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<h1 %s >%s</h1>\n", attributes, h1);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _h2(const char *attributes, const char *h2)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<h2>%s</h2>\n", h2);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<h2 %s >%s</h2>\n", attributes, h2);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _h3(const char *attributes, const char *h3)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<h3>%s</h3>\n", h3);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<h3 %s >%s</h3>\n", attributes, h3);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _h4(const char *attributes, const char *h4)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<h4>%s</h4>\n", h4);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<h4 %s >%s</h4>\n", attributes, h4);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _h5(const char *attributes, const char *h5)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<h5>%s</h5>\n", h5);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<h5 %s >%s</h5>\n", attributes, h5);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _h6(const char *attributes, const char *h6)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<h6>%s</h6>\n", h6);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<h6 %s >%s</h6>\n", attributes, h6);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _i(const char *attributes, const char *i)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<i>%s</i>\n", i);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<i %s >%s</i>\n", attributes, i);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}
static void _b(const char *attributes, const char *b)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<b>%s</b>\n", b);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<b %s >%s</b>\n", attributes, b);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}
static void _e(const char *attributes, const char *e)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<e>%s</e>\n", e);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<e %s >%s</e>\n", attributes, e);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}
static void _em(const char *attributes, const char *em)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<em>%s</em>\n", em);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<em %s >%s</em>\n", attributes, em);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _p(const char *attributes, const char *p)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<p>%s</p>\n", p);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<p %s >%s</p>\n", attributes, p);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _pInt(const char *attributes, const char *p)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<p>%s</p>\n", p);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<p %s >%s</p>\n", attributes, p);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _button(const char *attributes, const char *button)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<button>%s</button>\n", button);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<button %s >%s</button>\n", attributes, button);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _script(const char *attributes, const char *script)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<script>%s</script>\n", script);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<script %s >%s</script>\n", attributes, script);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _style(const char *style)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<style>%s</style>\n", style);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _div(const char *div)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<div %s ></div>\n", div);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _div_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<div>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<div %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _div_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</div>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _body_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<body>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<body %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}
static void _body_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</body>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _body(const char *body)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<body>%s</body>\n", body);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _head_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<head>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<head %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _head_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</head>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _head(const char *head)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<head>%s</head>\n", head);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static int _img(const char *attributes)
{
    if (attributes == EMPTY)
    {
        return ERROR;
    }
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<img %s />\n", attributes);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
    return OK;
}

static int _a(const char *attributes, const char *a)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<a>%s</a>\n", a);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
        return OK;
    }
    concatplus(tmp_code_html, "<a %s >%s</a>\n", attributes, a);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
    return OK;
}

static void _main_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<main>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<main %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _main_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</main>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _section_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<section>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<section %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _section_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</section>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _section(const char *section)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<section>%s</section>\n", section);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _article_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<article>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<article %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _article_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</article>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _article(const char *article)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<article>%s</article>\n", article);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _header_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<header>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<header %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _header_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</header>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _header(const char *header)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<header>%s</header>\n", header);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _footer(const char *footer)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<footer %s >%s</footer>\n", footer);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _footer_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<footer>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<footer %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _footer_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</footer>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _video(const char *attributes, const char *video)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<video>%s</video>\n", video);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<video %s >%s</video>\n", attributes, video);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _form(const char *from)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<form>%s</form>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _form_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<form>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<form %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _form_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</form>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static int _input(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<input />\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
        return OK;
    }
    else
    {
        concatplus(tmp_code_html, "<input %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
        return OK;
    }
}

static int _meta(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<meta />\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<meta %s />\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static int _link(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<link />\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<link %s />\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _aside(const char *attributes, const char *aside)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<aside> %s </aside>\n", aside);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<aside %s >%s</aside>\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _hr()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<hr>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _br()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<br>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _pre()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<pre>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _center()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<center></center>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _textarea(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<textarea></textarea>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<textarea %s ></textarea>\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _blockquote(const char *block)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<blockquote>%s</blockquote>\n", block);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _ol(const char *ol)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<ol>%s</ol>\n", ol);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _ol_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<ol>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<ol %s>\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _ol_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</ol>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _ul(const char *ul)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<ul>%s</ul>\n", ul);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _ul_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<ul>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<ul %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _ul_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</ul>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _li(const char *attributes, const char *li)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<li>%s</li>\n", li);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<li %s >%s</li>\n", attributes, li);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _dl(const char *_ddl)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<dl>%s</dl>\n", _ddl);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _dl_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<dl>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<dl %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _dl_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</dl>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _dt(const char *_ddt)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<dt>%s</dt>\n", _ddt);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _dt_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<dt>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<dt %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _dt_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</dt>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _dd_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<dd>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<dd %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _dd_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</dd>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _figure(const char *fig)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<figure>%s</figure>\n", fig);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _figure_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<figure>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<figure %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _figure_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</figure>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _small(const char *sm)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<small>%s</small>\n", sm);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _cite(const char *ci)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<cite>%s</cite>\n", ci);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _sub(const char *su)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<sub>%s</sub>\n", su);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _sup(const char *sup)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<sup>%s</sup>\n", sup);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _mark(const char *mar)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<mark>%s</mark>\n", mar);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static int _iframe(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<iframe />\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
        return OK;
    }
    else
    {
        concatplus(tmp_code_html, "<iframe %s />\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
        return OK;
    }
}

static void _embed(const char *attributes, const char *em)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<embed>%s</embed>\n", em);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<embed %s >%s</embed>\n", attributes, em);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _audio(const char *attributes, const char *source)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<audio><source %s ></source></audio>\n", source);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<audio %s ><source %s ></source></audio>\n", attributes, source);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _table(const char *t)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<table >%s</table>\n", t);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _table_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<table>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<table %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _table_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</table>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _tbody(const char *tb)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<tbody>%s</tbody>\n", tb);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _tbody_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<tbody>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<tbody %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _tbody_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</tbody>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _thead(const char *th)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<thead>%s</thead>\n", th);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _thead_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<thead>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<thead %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _thead_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</thead>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _tfoot(const char *tf)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<tfoot>%s</tfoot>\n", tf);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _tfoot_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<tfoot>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<tfoot %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _tfoot_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</tfoot>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _tr(const char *attributes, const char *tr)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<tr %s >%s</tr>\n", attributes, tr);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _td(const char *attributes, const char *td)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<td %s >%s</td>\n", attributes, td);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _th(const char *attributes, const char *th)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<th>%s</th>\n", th);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<th %s >%s</th>\n", attributes, th);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _label(const char *attributes, const char *label)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<label>%s</label>\n", label);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<label %s >%s</label>\n", attributes, label);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _select(const char *sec)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<select>%s</select>\n", sec);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _select_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<select>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<select %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _select_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</select>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _option(const char *ops)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<option>%s</option>\n", ops);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _php(const char *ops)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<?php %s ?>\n", ops);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _option_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<option>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<option %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _option_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</option>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void coment_1()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<!--\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void coment_2()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "-->\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _caption(const char *cap)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<caption >%s</caption>\n", cap);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _php_o()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<php \n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _php_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "?>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _script_o()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<script>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _script_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</script>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _style_o()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<style>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _style_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</style>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _nav_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<nav>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<nav %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _nav_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</nav>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _tr_o(const char *attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<tr>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<tr %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _tr_c()
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "</tr>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _nav(const char *attributes, const char *nav)
{
    char tmp1[HTML_LONG];
    if (attributes == EMPTY)
    {
        concatplus(tmp_code_html, "<nav>%s</nav>\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<nav %s >%s</nav>\n", attributes, nav);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _text(const char *cap)
{
    char tmp1[HTML_LONG];
    snprintf(tmp_code_html, HTML_LONG, "%s\n", cap);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static int _send_html(struct SERVER *Server)
{
    if (listen(Server->server_fd, 3) < 0)
    {
        return ERROR;
    }
    if ((Server->new_socket = accept(Server->server_fd, (struct sockaddr *)&Server->addrlen, (socklen_t *)&Server->addrlen)) < 0)
    {
        return ERROR;
    }
    char *response_2[BUFFER_SIZE];
    Server->valread = read(Server->new_socket, buffer, BUFFER_SIZE);
    cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", code_html, response_2);
    write(Server->new_socket, response_2, strlen(response_2));
    close(Server->new_socket);
    return OK;
}

static int _send_html_(struct SERVER *Server)
{
    if (listen(Server->server_fd, 3) < 0)
    {
        if (Server->errors == true)
        {
            perror("cweb");
            Server->is_error = ERROR;
            return ERROR;
        }
        else
        {
            Server->is_error = ERROR;
            return ERROR;
        }
    }
    if ((Server->new_socket = accept(Server->server_fd, (struct sockaddr *)&Server->server_addr, (socklen_t *)&Server->addrlen)) < 0)
    {
        if (Server->errors == true)
        {
            perror("cweb");
            Server->is_error = ERROR;
            return ERROR;
        }
        else
        {
            Server->is_error = ERROR;
            return ERROR;
        }
    }
    char *response_2[BUFFER_SIZE];
    Server->valread = read(Server->new_socket, buffer, BUFFER_SIZE);
    cat_str("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", code_html, response_2);
    write(Server->new_socket, response_2, strlen(response_2));
    close(Server->new_socket);
    Server->is_error = OK;
    return OK;
}

char *get_code_html_()
{
    return code_html;
}

void _delete()
{
    memset(code_html, 0, sizeof(code_html));
}

void viewHtml()
{
    printf("%s\n", code_html);
}

void _show_html_console()
{
    printf("HTML send(length: %ld):\n%s\n", strlen(code_html), code_html);
}

static void _script_src(const char *archivo, struct SERVER *s, int op)
{
    char archivo1[HTML_LONG];
    char contentJs[s->buffer_file];
    char tmp1[HTML_LONG];
    concatplus(archivo1, "js/%s.js", archivo);
    FILE *fp = fopen(archivo1, "r");
    if (fp == EMPTY)
    {
        perror("cweb ");
        return;
    }
    else
    {
        size_t html_size = fread(contentJs, sizeof(char), s->buffer_file, fp);
        if (op == 0)
        {
            concatplus(tmp_code_html, "<script>\n%s\n</script>\n", contentJs);
            cat_str(code_html, "", tmp1);
            cat_str(tmp1, tmp_code_html, code_html);
        }
        else if (op == 1)
        {
            concatplus(tmp_code_html, "%s\n", contentJs);
            cat_str(code_html, "", tmp1);
            cat_str(tmp1, tmp_code_html, code_html);
        }
    }
    fclose(fp);
}

char *getStringHtml(const char *archivo)
{
    char archivo_total[HTML_LONG];
    char content_html[HTML_LONG];
    concatplus(archivo_total, "html/%s.html", archivo);
    FILE *fp = fopen(archivo_total, "r");
    if (fp == EMPTY)
    {
        perror("cweb ");
    }
    size_t html_size = fread(content_html, sizeof(char), HTML_LONG, fp);
    fclose(fp);
    return content_html;
}

static void _load_extern_html(const char *code)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "%s\n", code);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _style_src(const char *archivo, struct SERVER *s, int op)
{
    char archivo1[HTML_LONG];
    char contentJs[DEFAULT_BUFFER_FILE];
    char tmp1[HTML_LONG];
    concatplus(archivo1, "css/%s.css", archivo);
    FILE *fp = fopen(archivo1, "r");
    if (fp == EMPTY)
    {
        perror("cweb ");
        return;
    }
    else
    {
        size_t html_size = fread(contentJs, sizeof(char), s->buffer_file, fp);
        if (op == 0)
        {
            concatplus(tmp_code_html, "<style>\n%s\n</style>\n", contentJs);
            cat_str(code_html, "", tmp1);
            cat_str(tmp1, tmp_code_html, code_html);
        }
        else if (op == 1)
        {
            concatplus(tmp_code_html, "%s\n", contentJs);
            cat_str(code_html, "", tmp1);
            cat_str(tmp1, tmp_code_html, code_html);
        }
    }
    fclose(fp);
}

void buildHtml(BuildHtml *html)
{
    html->tr_o = _tr_o;
    html->tr_c = _tr_c;
    html->script_src = _script_src;
    html->style_src = _style_src;
    html->php_o = _php_o;
    html->php_c = _php_c;
    html->load_extern_html = _load_extern_html;
    html->script_o = _script_o;
    html->script_c = _script_c;
    html->style_o = _style_o;
    html->style_c = _style_c;
    html->php = _php;
    html->text = _text;
    html->show_html_console = _show_html_console;
    html->view_html = viewHtml;
    html->title = _title;
    html->html_o = _html_o;
    html->html_c = _html_c;
    html->canvas_o = _canvas_o;
    html->canvas_c = _canvas_c;
    html->h1 = _h1;
    html->h2 = _h2;
    html->h3 = _h3;
    html->h4 = _h4;
    html->h5 = _h5;
    html->h6 = _h6;
    html->p = _p;
    html->button = _button;
    html->script = _script;
    html->center_o = _center_open;
    html->center_c = _center_close;
    html->send = _send_html;
    html->div = _div;
    html->div_o = _div_o;
    html->div_c = _div_c;
    html->style = _style;
    html->body_o = _body_o;
    html->body_c = _body_c;
    html->body = _body;
    html->head_o = _head_o;
    html->head_c = _head_c;
    html->head = _head;
    html->img = _img;
    html->a = _a;
    html->section_o = _section_o;
    html->section_c = _section_c;
    html->main_o = _main_o;
    html->main_c = _main_c;
    html->section = _section;
    html->article_o = _article_o;
    html->article_c = _article_c;
    html->article = _article;
    html->header_o = _header_o;
    html->header_c = _header_o;
    html->header = _header;
    html->footer = _footer;
    html->footer_o = _footer_o;
    html->footer_c = _footer_c;
    html->video = _video;
    html->form = _form;
    html->form_o = _form_o;
    html->form_c = _form_c;
    html->input = _input;
    html->meta = _meta;
    html->link = _link;
    html->aside = _aside;
    html->hr = _hr;
    html->br = _br;
    html->pre = _pre;
    html->center = _center;
    html->textarea = _textarea;
    html->blockquote = _blockquote;
    html->ol = _ol;
    html->ol_o = _ol_o;
    html->ol_c = _ol_c;
    html->ul = _ul;
    html->ul_o = _ul_o;
    html->ul_c = _ul_c;
    html->li = _li;
    html->dl = _dl;
    html->dl_o = _dl_o;
    html->dl_c = _dl_c;
    html->dt = _dt;
    html->dt_o = _dt_o;
    html->dt_c = _dt_c;
    html->dd_o = _dd_o;
    html->dd_c = _dd_c;
    html->figure = _figure;
    html->figure_o = _figure_o;
    html->figure_c = _figure_c;
    html->small = _small;
    html->cite = _cite;
    html->sub = _sub;
    html->sup = _sup;
    html->mark = _mark;
    html->iframe = _iframe;
    html->embed = _embed;
    html->audio = _audio;
    html->table = _table;
    html->table_o = _table_o;
    html->table_c = _table_c;
    html->tbody = _tbody;
    html->tbody_o = _tbody_o;
    html->tbody_c = _tbody_c;
    html->nav_o = _nav_o;
    html->nav_c = _nav_c;
    html->nav = _nav;
    html->thead = _thead;
    html->thead_o = _thead_o;
    html->thead_c = _thead_c;
    html->tfoot = _tfoot;
    html->tfoot_o = _tfoot_o;
    html->tfoot_c = _tfoot_c;
    html->tr = _tr;
    html->td = _td;
    html->th = _th;
    html->label = _label;
    html->select = _select;
    html->select_o = _select_o;
    html->select_c = _select_c;
    html->option = _option;
    html->option_o = _option_o;
    html->option_c = _option_c;
    html->caption = _caption;
    html->i = _i;
    html->b = _b;
    html->e = _e;
    html->em = _em;
    html->coment_o = coment_1;
    html->coment_c = coment_2;
    html->send_ = _send_html_;
    html->resetAllHTML = _delete;
    html->get_code_html = get_code_html_;
}

void create_html (BuildHtml *html){
    char tm_code[HTML_LONG];
    if(html->HTML.h1.add == true){
        char tm[HTML_LONG];
        if(html->HTML.h1.attributes == EMPTY || strcmp(html->HTML.h1.attributes,"null") == 0 || strcmp(html->HTML.h1.attributes,"") == 0){
            snprintf(tm_code, HTML_LONG, "<h1>%s</h1>\n", html->HTML.h1.text);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<h1 %s >%s</h1>\n", html->HTML.h1.attributes, html->HTML.h1.text);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.h1.add = false;
    }
    
    if(html->HTML.h2.add == true){
        char tm[HTML_LONG];
        if(html->HTML.h2.attributes == EMPTY || strcmp(html->HTML.h2.attributes,"null") == 0 || strcmp(html->HTML.h2.attributes,"") == 0){
            snprintf(tm_code, HTML_LONG, "<h2>%s</h2>\n", html->HTML.h2.text);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<h2 %s >%s</h2>\n", html->HTML.h2.attributes, html->HTML.h2.text);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.h2.add = false;
    }
    
    if(html->HTML.h3.add == true){
        char tm[HTML_LONG];
        if(html->HTML.h3.attributes == EMPTY || strcmp(html->HTML.h3.attributes,"null") == 0 || strcmp(html->HTML.h3.attributes,"") == 0){
            snprintf(tm_code, HTML_LONG, "<h3>%s</h3>\n", html->HTML.h3.text);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<h3 %s >%s</h3>\n", html->HTML.h3.attributes, html->HTML.h3.text);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.h3.add = false;
    }
    
    if(html->HTML.h4.add == true){
        char tm[HTML_LONG];
        if(html->HTML.h4.attributes == EMPTY || strcmp(html->HTML.h4.attributes,"null") == 0 || strcmp(html->HTML.h4.attributes,"") == 0){
            snprintf(tm_code, HTML_LONG, "<h4>%s</h4>\n", html->HTML.h4.text);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<h4 %s >%s</h4>\n", html->HTML.h4.attributes, html->HTML.h4.text);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.h4.add = false;
    }
    
    if(html->HTML.h5.add == true){
        char tm[HTML_LONG];
        if(html->HTML.h5.attributes == EMPTY || strcmp(html->HTML.h5.attributes,"null") == 0 || strcmp(html->HTML.h5.attributes,"") == 0){
            snprintf(tm_code, HTML_LONG, "<h5>%s</h5>\n", html->HTML.h5.text);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<h5 %s >%s</h5>\n", html->HTML.h5.attributes, html->HTML.h5.text);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.h5.add = false;
    }
    
    if(html->HTML.h6.add == true){
        char tm[HTML_LONG];
        if(html->HTML.h6.attributes == EMPTY || strcmp(html->HTML.h6.attributes,"null") == 0 || strcmp(html->HTML.h6.attributes,"") == 0){
            snprintf(tm_code, HTML_LONG, "<h6>%s</h6>\n", html->HTML.h6.text);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<h6 %s >%s</h6>\n", html->HTML.h6.attributes, html->HTML.h6.text);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.h6.add = false;
    }
    
    if(html->HTML.br.add == true){
        char tm[10];
        snprintf(tm_code, HTML_LONG, "<br>");
        cat_str(html->HTML.code, "", tm);
        cat_str(tm, tm_code, html->HTML.code);
        html->HTML.br.add = false;
    }
    
    if(html->HTML.p.add == true){
        char tm[HTML_LONG];
        if(html->HTML.p.attributes == EMPTY || strcmp(html->HTML.p.attributes,"null") == 0 || strcmp(html->HTML.p.attributes,"") == 0){
            snprintf(tm_code, HTML_LONG, "<p>%s</p>\n", html->HTML.p.text);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<p %s >%s</p>\n", html->HTML.p.attributes, html->HTML.p.text);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.p.add = false;
    }
    if(html->HTML.a.add == true){
        char tm[HTML_LONG];
        snprintf(tm_code, HTML_LONG, "<a href=\"%s\" class=\"%s\" id=\"%s\" %s >%s</a>\n", html->HTML.a.href, html->HTML.a.class, html->HTML.a.id, html->HTML.a.attributes, html->HTML.a.text);
        cat_str(html->HTML.code, "", tm);
        cat_str(tm, tm_code, html->HTML.code);
        html->HTML.a.add = false;
    }
    if(html->HTML.i.add == true){
        char tm[HTML_LONG];
        snprintf(tm_code, HTML_LONG, "<i class=\"%s\" id=\"%s\" %s >%s</i>\n",html->HTML.i.class, html->HTML.i.id, html->HTML.i.attributes, html->HTML.i.text);
        cat_str(html->HTML.code, "", tm);
        cat_str(tm, tm_code, html->HTML.code);
        html->HTML.i.add = false;
    }
    if(html->HTML.e.add == true){
        char tm[HTML_LONG];
        snprintf(tm_code, HTML_LONG, "<e class=\"%s\" id=\"%s\" %s >%s</e>\n",html->HTML.e.class, html->HTML.e.id, html->HTML.e.attributes, html->HTML.e.text);
        cat_str(html->HTML.code, "", tm);
        cat_str(tm, tm_code, html->HTML.code);
        html->HTML.e.add = false;
    }
    if(html->HTML.span.add == true){
        if(html->HTML.span.is_open == true){
            char tm[HTML_LONG];
            snprintf(tm_code, HTML_LONG, "<span class=\"%s\" id=\"%s\" %s >\n",html->HTML.span.class, html->HTML.span.id, html->HTML.span.attributes);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
            html->HTML.span.add = false;
        } else {
            char tm[HTML_LONG];
            snprintf(tm_code, HTML_LONG, "</span>\n");
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
            html->HTML.span.add = false;
        }
    }
    
    if(html->HTML.html.add == true){
        if(html->HTML.html.is_open == true){
            char tm[HTML_LONG];
            snprintf(tm_code, HTML_LONG, "<html lang=\"%s\" %s>\n",html->HTML.html.lang, html->HTML.html.attributes);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
            html->HTML.html.add = false;
        } else {
            char tm[HTML_LONG];
            snprintf(tm_code, HTML_LONG, "</html>\n");
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
            html->HTML.html.add = false;
        }
    }
    
    if(html->HTML.center.add == true){
        if(html->HTML.center.is_open == true){
            char tm[HTML_LONG];
            snprintf(tm_code, HTML_LONG, "<center>\n");
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
            html->HTML.center.add = false;
        } else {
            char tm[HTML_LONG];
            snprintf(tm_code, HTML_LONG, "</center>\n");
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
            html->HTML.center.add = false;
        }
    }
    if(html->HTML.link.add == true){
        char tm[HTML_LONG];
        snprintf(tm_code, HTML_LONG, "<link rel=\"%s\" href=\"%s\" %s >\n",html->HTML.link.rel, html->HTML.link.href, html->HTML.link.attributes);
        cat_str(html->HTML.code, "", tm);
        cat_str(tm, tm_code, html->HTML.code);
        html->HTML.link.add = false;
    }
    if(html->HTML.input.add == true){
        char tm[HTML_LONG];
        if(html->HTML.input.required == true){
            snprintf(tm_code, HTML_LONG, "<input type=\"%s\" name=\"%s\" id=\"%s\" value=\"%s\" placeholder=\"%s\" class=\"%s\" %s required>\n",html->HTML.input.type, html->HTML.input.name, html->HTML.input.id, html->HTML.input.value, html->HTML.input.placeholder, html->HTML.input.class, html->HTML.input.attributes);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        } else {
            snprintf(tm_code, HTML_LONG, "<input type=\"%s\" name=\"%s\" id=\"%s\" value=\"%s\" placeholder=\"%s\" class=\"%s\" %s >\n",html->HTML.input.type, html->HTML.input.name, html->HTML.input.id, html->HTML.input.value, html->HTML.input.placeholder, html->HTML.input.class, html->HTML.input.attributes);
            cat_str(html->HTML.code, "", tm);
            cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.input.add = false;
    }
    if(html->HTML.b.add == true){
        char tm[HTML_LONG];
        snprintf(tm_code, HTML_LONG, "<b class=\"%s\" id=\"%s\" %s >%s</b>\n",html->HTML.b.class, html->HTML.b.id,html->HTML.b.attributes ,html->HTML.b.text);
        cat_str(html->HTML.code, "", tm);
        cat_str(tm, tm_code, html->HTML.code);
        html->HTML.b.add = false;
    }
    if(html->HTML.em.add == true){
        char tm[HTML_LONG];
        snprintf(tm_code, HTML_LONG, "<em class=\"%s\" id=\"%s\" %s >%s</em>\n",html->HTML.em.class, html->HTML.em.id,html->HTML.em.attributes ,html->HTML.em.text);
        cat_str(html->HTML.code, "", tm);
        cat_str(tm, tm_code, html->HTML.code);
        html->HTML.em.add = false;
    }
    if(html->HTML.meta.add == true){
	    char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<meta %s >", html->HTML.meta.attributes);
	    cat_str(html->HTML.code,"",tm);
	    cat_str(tm, tm_code, html->HTML.code);
	    html->HTML.meta.add = false;
    }
    if(html->HTML.button.add == true){
	    char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<button class=\"%s\" id=\"%s\" %s >%s</button>", html->HTML.button.class, html->HTML.button.id, html->HTML.button.attributes, html->HTML.button.text);
	    cat_str(html->HTML.code,"",tm);
	    cat_str(tm, tm_code, html->HTML.code);
	    html->HTML.button.add = false;
    }
    if(html->HTML.label.add == true){
	    char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<label class=\"%s\" id=\"%s\" %s >%s</label>", html->HTML.label.class, html->HTML.label.id, html->HTML.label.attributes, html->HTML.label.text);
	    cat_str(html->HTML.code,"",tm);
	    cat_str(tm, tm_code, html->HTML.code);
	    html->HTML.label.add = false;
    }
    if(html->HTML.div.add == true){
        if(html->HTML.div.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<div class=\"%s\" id=\"%s\" %s >", html->HTML.div.class, html->HTML.div.id, html->HTML.div.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</div>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.div.add = false;
    }
    if(html->HTML.body.add == true){
        if(html->HTML.body.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<body class=\"%s\" id=\"%s\" %s >", html->HTML.body.class, html->HTML.body.id, html->HTML.body.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</body>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.body.add = false;
    }
    if(html->HTML.head.add == true){
        if(html->HTML.head.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<head class=\"%s\" id=\"%s\" %s >", html->HTML.head.class, html->HTML.head.id, html->HTML.head.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</head>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.head.add = false;
    }
    if(html->HTML.header.add == true){
        if(html->HTML.header.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<header class=\"%s\" id=\"%s\" %s >", html->HTML.header.class, html->HTML.header.id, html->HTML.header.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</header>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.header.add = false;
    }
    if(html->HTML.main.add == true){
        if(html->HTML.main.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<main class=\"%s\" id=\"%s\" %s >", html->HTML.main.class, html->HTML.main.id, html->HTML.main.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</main>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.main.add = false;
    }
    if(html->HTML.section.add == true){
        if(html->HTML.section.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<section class=\"%s\" id=\"%s\" %s >", html->HTML.section.class, html->HTML.section.id, html->HTML.section.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</section>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.section.add = false;
    }
    if(html->HTML.article.add == true){
        if(html->HTML.article.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<article class=\"%s\" id=\"%s\" %s >", html->HTML.article.class, html->HTML.article.id, html->HTML.article.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</article>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.article.add = false;
    }
    if(html->HTML.select.add == true){
        if(html->HTML.select.is_open == true){
            if(html->HTML.select.option.add == true){
                char tm[HTML_LONG];
	            snprintf(tm_code, HTML_LONG, "<select class=\"%s\" id=\"%s\" %s ><option class=\"%s\" id=\"%s\" value=\"%s\" >%s</option>", html->HTML.select.class, html->HTML.select.id, html->HTML.select.attributes, html->HTML.select.option.class, html->HTML.select.option.id, html->HTML.select.option.value, html->HTML.select.option.text);
	            cat_str(html->HTML.code,"",tm);
	            cat_str(tm, tm_code, html->HTML.code);
            } else {
                char tm[HTML_LONG];
	            snprintf(tm_code, HTML_LONG, "<select class=\"%s\" id=\"%s\" %s >", html->HTML.select.class, html->HTML.select.id, html->HTML.select.attributes);
	            cat_str(html->HTML.code,"",tm);
	            cat_str(tm, tm_code, html->HTML.code);
            }
            
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</select>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.select.add = false;
    }
    if(html->HTML.option.add == true){
        char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<option class=\"%s\" id=\"%s\" value=\"%s\" %s >%s</option>", html->HTML.option.class, html->HTML.option.id, html->HTML.option.value, html->HTML.option.attributes, html->HTML.option.text);
	    cat_str(html->HTML.code,"",tm);
	    cat_str(tm, tm_code, html->HTML.code);
        html->HTML.option.add = false;
    }
    if(html->HTML.footer.add == true){
        if(html->HTML.footer.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<footer class=\"%s\" id=\"%s\" %s >%s", html->HTML.footer.class, html->HTML.footer.id, html->HTML.footer.attributes, html->HTML.footer.text);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</footer>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.footer.add = false;
    }
    if(html->HTML.form.add == true){
        if(html->HTML.form.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<form action=\"%s\" method=\"%s\" encrypt=\"%s\" class=\"%s\" id=\"%s\" %s >",html->HTML.form.action, html->HTML.form.method, html->HTML.form.encrypt, html->HTML.form.class, html->HTML.form.id, html->HTML.form.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</form>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.article.add = false;
    }
    if(html->HTML.aside.add == true){
        if(html->HTML.aside.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<aside class=\"%s\" id=\"%s\" %s >", html->HTML.aside.class, html->HTML.aside.id, html->HTML.aside.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</aside>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.aside.add = false;
    }
    if(html->HTML.hr.add == true){
        char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<hr/>");
	    cat_str(html->HTML.code,"",tm);
	    cat_str(tm, tm_code, html->HTML.code);
    }
    if(html->HTML.pre.add == true){
        if(html->HTML.pre.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<pre class=\"%s\" id=\"%s\" %s >", html->HTML.pre.class, html->HTML.pre.id, html->HTML.pre.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</pre>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.pre.add = false;
    }
    if(html->HTML.textarea.add == true){
        char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<textarea class=\"%s\" id=\"%s\" name=\"%s\" cols=\"%s\" rows %s ></textarea>", html->HTML.textarea.class, html->HTML.textarea.id,html->HTML.textarea.name, html->HTML.textarea.cols, html->HTML.textarea.rows, html->HTML.textarea.attributes);
	    cat_str(html->HTML.code,"",tm);
	    cat_str(tm, tm_code, html->HTML.code);
        html->HTML.textarea.add = false;
    }
    if(html->HTML.blockquote.add == true){
        if(html->HTML.blockquote.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<blockquote class=\"%s\" id=\"%s\" %s >", html->HTML.blockquote.class, html->HTML.blockquote.id, html->HTML.blockquote.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</blockquote>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.blockquote.add = false;
    }
    if(html->HTML.ol.add == true){
        if(html->HTML.ol.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<ol class=\"%s\" id=\"%s\" %s >", html->HTML.ol.class, html->HTML.ol.id, html->HTML.ol.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</ol>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.ol.add = false;
    }
    if(html->HTML.ul.add == true){
        if(html->HTML.ul.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<ul class=\"%s\" id=\"%s\" %s >", html->HTML.ul.class, html->HTML.ul.id, html->HTML.ul.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</ul>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.ul.add = false;
    }
    if(html->HTML.li.add == true){
        char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<li class=\"%s\" id=\"%s\" %s>%s</li>",html->HTML.li.class, html->HTML.li.id, html->HTML.li.attributes, html->HTML.li.text);
	    cat_str(html->HTML.code,"",tm);
	    cat_str(tm, tm_code, html->HTML.code);
    }
    if(html->HTML.dl.add == true){
        if(html->HTML.dl.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<dl class=\"%s\" id=\"%s\" %s >", html->HTML.dl.class, html->HTML.dl.id, html->HTML.dl.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</dl>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.dl.add = false;
    }
    if(html->HTML.dt.add == true){
        if(html->HTML.dt.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<dt class=\"%s\" id=\"%s\" %s >", html->HTML.dt.class, html->HTML.dt.id, html->HTML.dt.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</dt>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.dt.add = false;
    }
    if(html->HTML.dd.add == true){
        if(html->HTML.dd.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<dd class=\"%s\" id=\"%s\" %s >", html->HTML.dd.class, html->HTML.dd.id, html->HTML.dd.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</dd>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.dd.add = false;
    }
    if(html->HTML.figure.add == true){
        if(html->HTML.figure.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<figure class=\"%s\" id=\"%s\" %s >", html->HTML.figure.class, html->HTML.figure.id, html->HTML.figure.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</figure>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.figure.add = false;
    }
    if(html->HTML.small.add == true){
        if(html->HTML.small.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<small class=\"%s\" id=\"%s\" %s >", html->HTML.small.class, html->HTML.small.id, html->HTML.small.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</small>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.small.add = false;
    }
    if(html->HTML.cite.add == true){
        if(html->HTML.cite.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<cite class=\"%s\" id=\"%s\" %s >", html->HTML.cite.class, html->HTML.cite.id, html->HTML.cite.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</cite>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.cite.add = false;
    }
    if(html->HTML.sub.add == true){
        if(html->HTML.sub.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<sub class=\"%s\" id=\"%s\" %s >", html->HTML.sub.class, html->HTML.sub.id, html->HTML.sub.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</sub>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.sub.add = false;
    }
    if(html->HTML.mark.add == true){
        if(html->HTML.mark.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<mark class=\"%s\" id=\"%s\" %s >", html->HTML.mark.class, html->HTML.mark.id, html->HTML.mark.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</mark>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.mark.add = false;
    }
    if(html->HTML.iframe.add == true){
        char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "<iframe class=\"%s\" id=\"%s\" %s ></iframe>", html->HTML.iframe.class, html->HTML.iframe.id, html->HTML.iframe.attributes);
	    cat_str(html->HTML.code,"",tm);
	    cat_str(tm, tm_code, html->HTML.code);
        html->HTML.iframe.add = false;
    }
    if(html->HTML.embed.add == true){
        if(html->HTML.embed.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<embed class=\"%s\" id=\"%s\" %s >", html->HTML.embed.class, html->HTML.embed.id, html->HTML.embed.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</embed>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.embed.add = false;
    }
    if(html->HTML.table.add == true){
        if(html->HTML.table.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<table class=\"%s\" id=\"%s\" %s >", html->HTML.table.class, html->HTML.table.id, html->HTML.table.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</table>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.table.add = false;
    }
    if(html->HTML.tbody.add == true){
        if(html->HTML.tbody.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<tbody class=\"%s\" id=\"%s\" %s >", html->HTML.tbody.class, html->HTML.tbody.id, html->HTML.tbody.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</tbody>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.tbody.add = false;
    }
    if(html->HTML.thead.add == true){
        if(html->HTML.thead.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<thead class=\"%s\" id=\"%s\" %s >", html->HTML.thead.class, html->HTML.thead.id, html->HTML.thead.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</thead>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.thead.add = false;
    }
    if(html->HTML.tfoot.add == true){
        if(html->HTML.tfoot.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<tfoot class=\"%s\" id=\"%s\" %s >", html->HTML.tfoot.class, html->HTML.tfoot.id, html->HTML.tfoot.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</tfoot>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.tfoot.add = false;
    }
    if(html->HTML.tr.add == true){
        if(html->HTML.tr.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<tr class=\"%s\" id=\"%s\" %s >", html->HTML.tr.class, html->HTML.tr.id, html->HTML.tr.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</tr>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.tr.add = false;
    }
    if(html->HTML.td.add == true){
        if(html->HTML.td.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<td class=\"%s\" id=\"%s\" %s >", html->HTML.td.class, html->HTML.td.id, html->HTML.td.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</td>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.td.add = false;
    }
    if(html->HTML.th.add == true){
        if(html->HTML.th.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<th class=\"%s\" id=\"%s\" %s >", html->HTML.th.class, html->HTML.th.id, html->HTML.th.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</th>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.th.add = false;
    }
    if(html->HTML.dialog.add == true){
        if(html->HTML.dialog.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<dialog class=\"%s\" id=\"%s\" %s >", html->HTML.dialog.class, html->HTML.dialog.id, html->HTML.dialog.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</dialog>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.dialog.add = false;
    }
    if(html->HTML.caption.add == true){
        if(html->HTML.caption.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<caption class=\"%s\" id=\"%s\" %s >", html->HTML.caption.class, html->HTML.caption.id, html->HTML.caption.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</caption>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.caption.add = false;
    }
    if(html->HTML.nav.add == true){
        if(html->HTML.nav.is_open == true){
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "<nav class=\"%s\" id=\"%s\" %s >", html->HTML.nav.class, html->HTML.nav.id, html->HTML.nav.attributes);
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        } else {
            char tm[HTML_LONG];
	        snprintf(tm_code, HTML_LONG, "</nav>");
	        cat_str(html->HTML.code,"",tm);
	        cat_str(tm, tm_code, html->HTML.code);
        }
        html->HTML.nav.add = false;
    }
    if(html->HTML.text.add == true){
        char tm[HTML_LONG];
	    snprintf(tm_code, HTML_LONG, "%s",html->HTML.text.text);
	    cat_str(html->HTML.code,"",tm);
	    cat_str(tm, tm_code, html->HTML.code);
    }
}

#endif
