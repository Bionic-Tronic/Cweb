////////////////////////////////////////////////////////////////
//Archivo: json.h                                             //
//Este header contiene todas las funciónes necesarias para    //
//convertir un string json a un arreglo                       //
////////////////////////////////////////////////////////////////
#ifndef JSON_H
#define JSON_H

void trim(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;

    while (isspace(*start)) start++;
    while (end > start && isspace(*end)) end--;

    *(end + 1) = '\0';
    memmove(str, start, end - start + 2);
}

void parse_string(const char *json, int *index, char *result) {
    int start = *index + 1;
    int end = start;
    while (json[end] != '"' || json[end-1] == '\\') {
        end++;
    }
    strncpy(result, json + start, end - start);
    result[end - start] = '\0';
    *index = end + 1;
}

double parse_number(const char *json, int *index) {
    char number_str[MAX_LENGTH_JSON_TEXT];
    int i = 0;
    while (isdigit(json[*index]) || json[*index] == '.' || json[*index] == '-' || json[*index] == 'e' || json[*index] == 'E') {
        number_str[i++] = json[(*index)++];
    }
    number_str[i] = '\0';
    return atof(number_str);
}

JsonValue parse_json_value(const char *json, int *index) {
    JsonValue value;
    while (isspace(json[*index])) (*index)++;

    switch (json[*index]) {
        case '"':
            value.type = JSON_STRING;
            parse_string(json, index, value.value.string_value);
            break;
        case '{':
            value.type = JSON_OBJECT;
            strcpy(value.value.string_value, "{}");
            (*index)++;
            while (json[*index] != '}') (*index)++;
            (*index)++;
            break;
        case '[':
            value.type = JSON_ARRAY;
            strcpy(value.value.string_value, "[]");
            (*index)++;
            while (json[*index] != ']') (*index)++;
            (*index)++;
            break;
        case 't':
            value.type = JSON_BOOLEAN;
            value.value.boolean_value = 1;
            *index += 4;
            break;
        case 'f':
            value.type = JSON_BOOLEAN;
            value.value.boolean_value = 0;
            *index += 5;
            break;
        case 'n':
            value.type = JSON_NULL;
            *index += 4;
            break;
        default:
            if (isdigit(json[*index]) || json[*index] == '-') {
                value.type = JSON_NUMBER;
                value.value.number_value = parse_number(json, index);
            }
    }
    return value;
}

JsonArray parse_json_array(const char *json) {
    JsonArray array;
    array.size = 0;
    int index = 0;
    
    while (isspace(json[index])) index++;

    if (json[index] != '[') {
        printf("cweb: Invalid JSON array\n");
        return array;
    }

    index++;

    while (json[index] != ']' && array.size < MAX_ARRAY_JSON) {
        JsonValue value = parse_json_value(json, &index);
        array.values[array.size++] = value;

        while (isspace(json[index]) || json[index] == ',') index++;
    }

    if (json[index] != ']') {
        printf("cweb: Invalid JSON array or array too large\n");
        array.size = 0;
    }

    return array;
}

void print_json_value(JsonValue value) {
    switch (value.type) {
        case JSON_STRING:
            printf("\"%s\"", value.value.string_value);
            break;
        case JSON_NUMBER:
            printf("%f", value.value.number_value);
            break;
        case JSON_OBJECT:
            printf("%s", value.value.string_value);
            break;
        case JSON_ARRAY:
            printf("%s", value.value.string_value);
            break;
        case JSON_BOOLEAN:
            printf("%s", value.value.boolean_value ? "true" : "false");
            break;
        case JSON_NULL:
            printf("null");
            break;
    }
}

#endif
