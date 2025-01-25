#include <stdio.h>
#include "../include/cweb.h"

char buffer[BUFFER_SIZE] = {0};

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

string searchInResponse(String palabra, char caracterLimite, string response){
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

int getFileContent (string var, int size, string name){
	FILE * fp = fopen(name,"rb");
	if (fp == EMPTY){
		perror("getFileContent()");
		return ERROR;
	}
	fread(var,sizeof(char),size,fp);
	fclose(fp);
	return OK;
}

off_t fsize(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0)
        return st.st_size;
    fprintf(stderr, "fsize(): Cannot determine size of %s: %s\n",filename, strerror(errno));
    return ERROR;
}

void cat (char *result, const char *format, ...){
    va_list args;
    va_start(args, format);
    va_list args_copy;
    va_copy(args_copy, args);
    int length = vsnprintf(EMPTY, 0, format, args_copy);
    va_end(args_copy);
    vsnprintf(result, length + 1, format, args);
    va_end(args);
}
