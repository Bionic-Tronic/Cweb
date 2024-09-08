#ifndef HTML_H
#define HTML_H

void cat_str(const String texto1, const String texto2, String resultado)
{
    strcpy(resultado, texto1);
    strcat(resultado, texto2);
}

String catStr(const String texto1, const String texto2)
{
    String resultado;
    strcpy(resultado, texto1);
    strcat(resultado, texto2);
    return resultado;
}

static void _title(const String title)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<title>%s</title>\n", title);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _canvas_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _html_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _h1(const String attributes, const String h1)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _h2(const String attributes, const String h2)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _h3(const String attributes, const String h3)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _h4(const String attributes, const String h4)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _h5(const String attributes, const String h5)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _h6(const String attributes, const String h6)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _i(const String attributes, const String i)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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
static void _b(const String attributes, const String b)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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
static void _e(const String attributes, const String e)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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
static void _em(const String attributes, const String em)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _p(const String attributes, const String p)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _pInt(const String attributes, const String p)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _button(const String attributes, const String button)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _script(const String attributes, const String script)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _style(const String style)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<style>%s</style>\n", style);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _div(const String div)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<div %s ></div>\n", div);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _div_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _body_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _body(const String body)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<body>%s</body>\n", body);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _head_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _head(const String head)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<head>%s</head>\n", head);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static int _img(const String attributes)
{
    if (attributes == NULL)
    {
        return ERROR;
    }
    else
    {
        char tmp1[HTML_LONG];
        concatplus(tmp_code_html, "<img %s />\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static int _a(const String attributes, const String a)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
    {
        concatplus(tmp_code_html, "<a>%s</a>\n", a);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<a %s >%s</a>\n", attributes, a);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _main_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _section_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _section(const String section)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<section>%s</section>\n", section);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _article_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _article(const String article)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<article>%s</article>\n", article);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _header_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _header(const String header)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<header>%s</header>\n", header);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _footer(const String footer)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<footer %s >%s</footer>\n", footer);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _footer_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _video(const String attributes, const String video)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _form(const String from)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<form>%s</form>\n");
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _form_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static int _input(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
    {
        concatplus(tmp_code_html, "<input />\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<input %s >\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static int _meta(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static int _link(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _aside(const String attributes, const String aside)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _textarea(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _blockquote(const String block)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<blockquote>%s</blockquote>\n", block);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _ol(const String ol)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<ol>%s</ol>\n", ol);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _ol_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _ul(const String ul)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<ul>%s</ul>\n", ul);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _ul_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _li(const String attributes, const String li)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _dl(const String _ddl)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<dl>%s</dl>\n", _ddl);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _dl_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _dt(const String _ddt)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<dt>%s</dt>\n", _ddt);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _dt_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _dd_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _figure(const String fig)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<figure>%s</figure>\n", fig);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _figure_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _small(const String sm)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<small>%s</small>\n", sm);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _cite(const String ci)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<cite>%s</cite>\n", ci);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _sub(const String su)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<sub>%s</sub>\n", su);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _sup(const String sup)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<sup>%s</sup>\n", sup);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _mark(const String mar)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<mark>%s</mark>\n", mar);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static int _iframe(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
    {
        concatplus(tmp_code_html, "<iframe />\n");
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
    else
    {
        concatplus(tmp_code_html, "<iframe %s />\n", attributes);
        cat_str(code_html, "", tmp1);
        cat_str(tmp1, tmp_code_html, code_html);
    }
}

static void _embed(const String attributes, const String em)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _audio(const String attributes, const String source)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _table(const String t)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<table >%s</table>\n", t);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _table_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _tbody(const String tb)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<tbody>%s</tbody>\n", tb);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _tbody_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _thead(const String th)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<thead>%s</thead>\n", th);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _thead_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _tfoot(const String tf)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<tfoot>%s</tfoot>\n", tf);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _tfoot_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _tr(const String attributes, const String tr)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<tr %s >%s</tr>\n", attributes, tr);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _td(const String attributes, const String td)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<td %s >%s</td>\n", attributes, td);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _th(const String attributes, const String th)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _label(const String attributes, const String label)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _select(const String sec)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<select>%s</select>\n", sec);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _select_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _option(const String ops)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<option>%s</option>\n", ops);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _php(const String ops)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "<?php %s ?>\n", ops);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _option_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _caption(const String cap)
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

static void _nav_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _tr_o(const String attributes)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _nav(const String attributes, const String nav)
{
    char tmp1[HTML_LONG];
    if (attributes == NULL)
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

static void _text(const String cap)
{
    char tmp1[HTML_LONG];
    snprintf(tmp_code_html, HTML_LONG, "%s\n", cap);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static int _send_html(Server *Server)
{
        if (listen(Server->server_fd, 3) < 0)
        {
            return ERROR;
        }
        if ((Server->new_socket = accept(Server->server_fd, (struct sockaddr *)&Server->address, (socklen_t *)&Server->addrlen)) < 0)
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

static int _send_html_(struct SERVER * Server){
        if (listen(Server->server_fd, 3) < 0){
            if(Server->errors == true){
                perror("cweb");
                Server->is_error = ERROR;
                return ERROR;
            } else {
                Server->is_error = ERROR;
                return ERROR;
            }
        }
        if ((Server->new_socket = accept(Server->server_fd, (struct sockaddr *)&Server->server_addr, (socklen_t *)&Server->addrlen)) < 0){
            if(Server->errors == true){
                perror("cweb");
                Server->is_error = ERROR;
                return ERROR;
            } else {
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

String get_code_html_ () {
    return code_html;
}

void _delete(){
    memset(code_html, 0, sizeof(code_html));
}

void viewHtml(){
    printf("%s\n", code_html);
}

void _show_html_console(){
    printf("HTML send(length: %ld):\n%s\n", strlen(code_html), code_html);
}

static void _script_src(const String archivo, Server *s, int op)
{
    char archivo1[HTML_LONG];
    char contentJs[s->buffer_file];
    char tmp1[HTML_LONG];
    concatplus(archivo1, "js/%s.js", archivo);
    FILE *fp = fopen(archivo1, "r");
    if (fp == NULL)
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

String getStringHtml(const String archivo)
{
    char archivo_total[HTML_LONG];
    char content_html[HTML_LONG];
    concatplus(archivo_total, "html/%s.html", archivo);
    FILE *fp = fopen(archivo_total, "r");
    if (fp == NULL)
    {
        perror("cweb ");
    }
    size_t html_size = fread(content_html, sizeof(char), HTML_LONG, fp);
    fclose(fp);
    return content_html;
}

static void _load_extern_html(const String code)
{
    char tmp1[HTML_LONG];
    concatplus(tmp_code_html, "%s\n", code);
    cat_str(code_html, "", tmp1);
    cat_str(tmp1, tmp_code_html, code_html);
}

static void _style_src(const String archivo, Server *s, int op)
{
    char archivo1[HTML_LONG];
    char contentJs[s->buffer_file];
    char tmp1[HTML_LONG];
    concatplus(archivo1, "css/%s.css", archivo);
    FILE *fp = fopen(archivo1, "r");
    if (fp == NULL)
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
#endif
