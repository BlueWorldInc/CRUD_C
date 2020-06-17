#include <stddef.h>

int my_strlen(char* s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

char* my_strchr(char* string_to_search, int char_to_search) {
    for (int i = 0; i < my_strlen(string_to_search); i++) {
        if (string_to_search[i] == char_to_search) {
            char* first_occurence = &string_to_search[i];
            return first_occurence;
        }
    }
    return NULL;
}