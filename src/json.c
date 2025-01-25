#include "../include/cweb.h"

char **json_to_array(const char *json_string, int *size){
	char **result = NULL;
	int count = 0;
	const char *p = json_string;
	while (isspace(*p))
		p++;
	if (*p != '{'){
		fprintf(stderr, "Error: JSON inválido, debe comenzar con '{'\n");
		return NULL;
	}
	p++;
	result = (char **)malloc(MAX_PAIRS * 2 * sizeof(char *));
	if (!result){
		fprintf(stderr, "Error: No se pudo asignar memoria\n");
		return NULL;
	}
	while (*p){
		if (*p == '}')
			break;
		if (*p == '"'){
			p++;
			const char *start = p;
			while (*p && *p != '"'){
				if (*p == '\\' && *(p + 1))
					p++;
				p++;
			}
			if (*p != '"'){
				fprintf(stderr, "Error: Clave no cerrada\n");
				for (int i = 0; i < count; i++)
					free(result[i]);
				free(result);
				return NULL;
			}
			int length = p - start;
			result[count] = (char *)malloc((length + 1) * sizeof(char));
			if (!result[count]){
				fprintf(stderr, "Error: No se pudo asignar memoria para la clave %d\n", count / 2);
				for (int i = 0; i < count; i++)
					free(result[i]);
				free(result);
				return NULL;
			}
			strncpy(result[count], start, length);
			result[count][length] = '\0';
			count++;
			p++;
		}
		while (*p && *p != ':')
			p++;
		if (*p != ':'){
			fprintf(stderr, "Error: Se esperaba ':' después de la clave\n");
			for (int i = 0; i < count; i++)
				free(result[i]);
			free(result);
			return NULL;
		}
		p++;
		while (isspace(*p))
			p++;
		if (*p == '"'){
			p++;
			const char *start = p;
			while (*p && *p != '"'){
				if (*p == '\\' && *(p + 1))
					p++;
				p++;
			}
			if (*p != '"'){
				fprintf(stderr, "Error: Valor no cerrado\n");
				for (int i = 0; i < count; i++)
					free(result[i]);
				free(result);
				return NULL;
			}
			int length = p - start;
			result[count] = (char *)malloc((length + 1) * sizeof(char));
			if (!result[count]) {
				fprintf(stderr, "Error: No se pudo asignar memoria para el valor %d\n", count / 2);
				for (int i = 0; i < count; i++)
					free(result[i]);
				free(result);
				return NULL;
			}
			strncpy(result[count], start, length);
			result[count][length] = '\0';
			count++;
			p++;
		}
		else{
			fprintf(stderr, "Error: Se esperaba un valor entre comillas\n");
			for (int i = 0; i < count; i++)
				free(result[i]);
			
			free(result);
			return NULL;
		}
		while (*p && (isspace(*p) || *p == ','))
			p++;
	}
	if (*p != '}') {
		fprintf(stderr, "Error: JSON inválido, debe terminar con '}'\n");
		for (int i = 0; i < count; i++)
			free(result[i]);
		free(result);
		return NULL;
	}
	*size = count;
	return result;
}