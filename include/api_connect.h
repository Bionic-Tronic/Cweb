#ifndef API_CONNECT_H
#define API_CONNECT_H

#define DATA_API 2024

#include "../include/cweb.h"
#include <curl/curl.h>

typedef struct {
    CURL *curl;
    CURLcode res;
    String url;
    String post;
    String headers;
    String type_data;
    char data[DATA_API];
}connect_api;

int connect_api_callback (void *data, size_t size, size_t nmemb, void *userp){
    FILE *fp = fopen("./logs/server.api", "w");
    if (fp == EMPTY){
        perror("cweb");
        return ERROR;
    }
    size_t realsize = size * nmemb;
    fprintf(fp, "%.*s\n\n", (int)realsize, (char *)data);
    fclose(fp);
    return realsize;
}

int connect_api_get (connect_api * api){
        int res = 0;
        curl_easy_setopt(api->curl, CURLOPT_URL, api->url);
        curl_easy_setopt(api->curl, CURLOPT_WRITEFUNCTION, connect_api_callback);
        res = curl_easy_perform(api->curl);
        if (res != CURLE_OK){
            fprintf(stderr, "cweb: %s\n", curl_easy_strerror(res));
            return ERROR;
        }
        curl_easy_cleanup(api->curl);
        return OK;
}

int connect_api_prepare(connect_api * api){
    curl_global_init(CURL_GLOBAL_DEFAULT);
    api->curl = curl_easy_init();
    if (api->curl)
        return OK;
    else
        return ERROR;
}

int connect_api_post (connect_api * api){
    int res = 0;
        curl_easy_setopt(api->curl, CURLOPT_URL, api->url);
        curl_easy_setopt(api->curl, CURLOPT_POST, 1L);
        curl_easy_setopt(api->curl, CURLOPT_POSTFIELDS, api->post);
        curl_easy_setopt(api->curl, CURLOPT_WRITEFUNCTION, connect_api_callback);
        struct curl_slist *headers = EMPTY;
        headers = curl_slist_append(headers, api->headers);
        curl_easy_setopt(api->curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(api->curl);
        if (res != CURLE_OK){
            fprintf(stderr, "cweb: %s\n", curl_easy_strerror(res));
            return ERROR;
        }
        curl_slist_free_all(headers);
        curl_easy_cleanup(api->curl);
        return OK;
}

int connect_api_getData (connect_api * api){
    FILE *fp = fopen("./logs/server.api", "r");
    if (fp == EMPTY){
        perror("cweb");
        return ERROR;
    }
    fread(api->data, sizeof(char), 3024, fp);
    fclose(fp);
    return OK;
}

void connect_api_clear (){
    curl_global_cleanup();
}

void connect_api_construct (connect_api * api){
    api->url = "http://example.com";
    api->headers = "Content-Type: application/json";
    api->post = "{\"example1\":\"example1\",\"example2\":\"example2\"}";
}

#endif
