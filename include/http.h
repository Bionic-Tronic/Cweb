#ifndef HTTP_H
#define HTTP_H

#include "cweb.h"
#include "server.h"

int isset (String word){
	String texto = GET_RESPONSE();
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

string search_response (string palabra, char caracterLimite){
	string texto = GET_RESPONSE();
	string encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const string limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			string subcadena = (string )malloc(longitud + 1);
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

int isset_get (String word){
	char true_word[1000];
	snprintf(true_word, 1000, "GET /%s",word);
	string texto = GET_RESPONSE();
	string text_copy = strdup(true_word);
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

int isset_post (String word){
	char true_word[1000];
	snprintf(true_word, 1000, "POST /%s",word);
	string texto = GET_RESPONSE();
	string text_copy = strdup(true_word);
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

string GET (String palabra, char caracterLimite){
	char true_palabra[1000];
	snprintf(true_palabra, 1000, "GET /%s", palabra);
	string texto = GET_RESPONSE();
	string encontrado = strstr(texto, true_palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(true_palabra);
		const string limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			string subcadena = (string )malloc(longitud + 1);
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

string POST (String palabra, char caracterLimite){
	char true_palabra[1000];
	snprintf(true_palabra, 1000, "POST /%s", palabra);
	string texto = GET_RESPONSE();
	string encontrado = strstr(texto, true_palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(true_palabra);
		const string limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			string subcadena = (string )malloc(longitud + 1);
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

String content_length (){
	String palabra = "content-length: ";
	char caracterLimite = '\0';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
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

String platform_user (){
	String palabra = "sec-ch-ua-platform: \"";
	char caracterLimite = '"';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
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

String referer (){
	String palabra = "Referer: ";
	char caracterLimite = '\n';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
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

String accept_language (){
	String palabra = "Accept-Language: ";
	char caracterLimite = '\n';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
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

String host (){
	String palabra = "Host: ";
	char caracterLimite = '\n';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
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

String connection (){
	String palabra = "Connection: ";
	char caracterLimite = '\n';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
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

String Accept (){
	String palabra = "Accept: ";
	char caracterLimite = '\n';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
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

String get_accept_encoding (){
	String palabra = "Accept-Encoding: ";
	char caracterLimite = '\n';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
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

String user_agent (){
	String palabra = "User-Agent: ";
	char caracterLimite = '\n';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
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

String UIR (){
	String palabra = "Upgrade-Insecure-Requests: ";
	char caracterLimite = '\n';
	char *texto = GET_RESPONSE();
	char *encontrado = strstr(texto, palabra);
	if (encontrado != EMPTY){
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != EMPTY){
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
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

#endif
