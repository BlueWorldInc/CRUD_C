#include <stddef.h>
#include "fnc.h"

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

char *my_readline(void)
{
    char* chaine = "samit";
    char *tmp;
    char *buff;
    ssize_t size;
    int i = 0;

    buff = malloc(sizeof(*buff) * (100 + 1));
    tmp = malloc(sizeof(*tmp) * (1));
    if (buff == NULL)
        return NULL;



    do {
        read(0, tmp, 1);
        // printf("%c", tmp[0]);
        buff[i] = tmp[0];
        i++;
    } while (tmp[0] != 10);
    
    // buff[i] = '\0';
    size = i;
    // for (int i = 0; i < 1; i++) {
        // read(0, tmp, 1);
    // }
    // int l = strlen(*buff);
    // printf("%s", buff);
    // if (tmp[0] == 57) {
        // printf("hey");
    // } else {
        // printf("no");
    // }
    if (size > 1)
    {
        
        buff[size - 1] = '\0';
        // printf("\n***%s***\n", buff);
        // printf("%d", strlen(buff));
        return buff;
    }
    free(buff);
    return NULL;
}