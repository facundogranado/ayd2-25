#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "strfuncs.h"

size_t string_length(const char *str) {
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
char *string_filter(const char *str, char c) {
    size_t len = string_length(str);
    char *filtered = malloc(len + 1);
    if(filtered == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        filtered = NULL;
    }
    else
    {
        if (len == 0) {
            filtered[0] = '\0'; // Return an empty string if input is empty
            return filtered;
        }
        size_t j = 0;
        for (size_t i = 0; i < len; i++) {
            if (str[i] != c) {
                filtered[j++] = str[i];
            }
        }
        filtered[j] = '\0'; // Null-terminate the filtered string
    }
    
    return filtered;
}
bool string_is_symmetric(const char *str) {
    size_t len = string_length(str);
    bool result = true;
    size_t i = 0;
    while( i < len / 2 && result) {
        if (str[i] != str[len - 1 - i]) {
            result = false;
        }
        i++;
    }
    return result;
}