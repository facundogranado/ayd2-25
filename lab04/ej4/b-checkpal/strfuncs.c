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
    size_t filtered_len = 0;
        for (size_t i = 0; i < len; i++) {
            if (str[i] != c) {
                filtered_len++;
            }
        }
    char *filtered = malloc((filtered_len + 1) * sizeof(char));
    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (str[i] != c) {
            filtered[j] = str[i];
            j++;
        }
    }
    filtered[filtered_len] = '\0'; // Null-terminate the filtered string
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