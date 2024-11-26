#ifndef CWEB_H
#define CWEB_H

typedef char * string;
typedef const char * String;
typedef char page [10000];

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <netdb.h>
#include <sys/stat.h>
#include <sys/socket.h> 
#include <sys/types.h> 
#include <arpa/inet.h>
#include <sqlite3.h>
#include <curl/curl.h>
#include <stdbool.h>

#define EMPTY ((void*)0)
#define ERROR 500
#define OK    200

#ifdef _INCLUDE_ALL_

#include "server.h"
#include "html.h"
#include "archives.h"
#include "smtp.h"
#include "base_data.h"
#include "api_connect.h"
#include "http.h"
#include "json.h"
#endif

typedef struct{
    char dat[2024];
    String nameData;
} properties;

typedef struct{
    char current_date[20];
    char hour[9];
} date;

string intToString (int entero){
    int len = snprintf(EMPTY, 0, "%d", entero);
    string str = malloc(len + 1);
    snprintf(str, len + 1, "%d", entero);
    return str;
}

string floatToString (double flotante){
    int len = snprintf(EMPTY, 0, "%.2f", flotante);
    string str = malloc(len + 1);
    snprintf(str, len + 1, "%.2f", flotante);
    return str;
}

int stringToInt (string str){
    return atoi(str);
}

string stringsearchInResponse(String palabra, char caracterLimite, string response){
    string texto = response;
    string encontrado = strstr(texto, palabra);
    if (encontrado != EMPTY){
        size_t posicionFinal = encontrado - texto + strlen(palabra);
        String limite = strchr(texto + posicionFinal, caracterLimite);
        if (limite != EMPTY){
            size_t longitud = limite - (texto + posicionFinal);
            string subcadena = (string)malloc(longitud + 1);
            strncpy(subcadena, texto + posicionFinal, longitud);
            subcadena[longitud] = '\0';
            return subcadena;
        }
        else
            return EMPTY;
    }
    else
        return EMPTY;
}

string searchWord(String texto, String palabra, char caracterLimite){
    string encontrado = strstr(texto, palabra);
    if (encontrado != EMPTY){
        size_t posicionFinal = encontrado - texto + strlen(palabra);
        String limite = strchr(texto + posicionFinal, caracterLimite);
        if (limite != EMPTY){
            size_t longitud = limite - (texto + posicionFinal);
            string subcadena = (char *)malloc(longitud + 1);
            strncpy(subcadena, texto + posicionFinal, longitud);
            subcadena[longitud] = '\0';
            return subcadena;
        }
        else
            return EMPTY;
    }
    else
        return EMPTY;
}

int search_w(String word, String texto){
    string text_copy = strdup(word);
    if (text_copy == EMPTY)
        return ERROR;
    string line = strtok(text_copy, "\n");
    while (line != EMPTY){
        if (strstr(line, texto) != EMPTY){
            free(text_copy);
            return OK;
        }
        line = strtok(EMPTY, "\n");
    }
    free(text_copy);
    return ERROR;
}

#endif
