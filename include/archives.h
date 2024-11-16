#ifndef ARCHIVES_H
#define ARCHIVES_H

#define FILE_ERROR 404
#define FILE_OK    201

#include "../include/cweb.h"
#include "server.h"

typedef struct{
    string filename;
    string typefile;
    string sizefile;
    string end_of_header;
    size_t body_offset;
    size_t length;
    string content_file;
    int pre;
} archives;

int create_file (String fileName, String contentFile, String writeFile){
    if(strcmp(writeFile,"r") == 0 || strcmp(writeFile,"rb") == 0)
        return FILE_ERROR;
    FILE * fp = fopen(fileName, writeFile);
    if(fp == EMPTY)
        return FILE_ERROR;
    fprintf(fp, "%s", contentFile);
    fclose(fp);
    return FILE_OK;
}

string getof (String palabra, char caracterLimite){
    String texto = GET_RESPONSE();
    String encontrado = strstr(texto, palabra);
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

void getNameFile (archives * archives){
    archives->filename = getof("filename=\"",'"');
    if(archives->filename == EMPTY)
        archives->filename = "";
}

void getSizeFile (archives * archives){
    archives->sizefile = getof("Content-Length: ",'\0');
    if(archives->sizefile == EMPTY)
        archives->sizefile = "";
}

int isset_file (){
    String text = GET_RESPONSE();
	string word = "Content-Length";
	string text_copy = strdup(text);
	string line = strtok(text_copy, "\n");
	while (line != EMPTY){
		if (strstr(line, word) != EMPTY){
			return FILE_OK;
		}
		line = strtok(EMPTY, "\n");
	}
	free(text_copy);
	return FILE_ERROR;
}

void getTypeFile (archives * archives){
    archives->typefile = getof("Content-Type:",'\0');
    if(archives->typefile == EMPTY)
        archives->typefile = "";
}

int prepare_save_file (server * s, archives * archive){
    archive->end_of_header = strstr(buffer, "\r\n\r\n");
	if (archive->end_of_header != EMPTY){
		archive->body_offset = archive->end_of_header + 4 - buffer;
		archive->pre = 1;
		archive->content_file = buffer + archive->body_offset;
		archive->length = s->valread - archive->body_offset;
		return FILE_OK;
	}
	puts("cweb: not have content file");
	archive->pre = 0;
	return FILE_ERROR;
}

int move_uploaded_file(archives * archive){
	FILE * fp;
	if(archive->pre != 1){
	    puts("cweb: file is not prepared");
	    return FILE_ERROR;
	}
	fp = fopen(archive->filename,"wb");
	if(fp == EMPTY){
	    perror("cweb ");
	    return FILE_ERROR;
	}
	fwrite(archive->content_file, sizeof(char), archive->length, fp);
	fclose(fp);
	archive->pre = 0;
	return FILE_OK;
}

int download_file(server * Server){
	string fileName = getof("GET /", ' ');
	FILE *fp = fopen(fileName, "rb");
	size_t bytes_read;
	char r_headers_1[1024];
	snprintf(r_headers_1, 1024, "HTTP/1.1 200 OK\r\nContent-Disposition: attachment; filename=\"%s\" \r\nContent-Type: text/plain\r\n\r\n", fileName);
	if (fp == EMPTY){
		perror("cweb ");
		return FILE_ERROR;
	}
	send(Server->client_socket, r_headers_1, strlen(r_headers_1), 0);
	while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0){
			send(Server->client_socket, buffer, bytes_read, 0);
	}
	fclose(fp);
	return FILE_OK;
}

#endif
