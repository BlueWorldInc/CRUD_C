#include "myLib\fnc.h"
#include "myLib\crd.h"

struct key_value_pair {
    char* key;
    char* value;
};

struct kvp_holder {
    char* a;
    struct key_value_pair k;
};

char* my_substr(char* str, int startIndex, int endIndex);
char* getKey(char* line);
int my_strcmp(char* s0, char* s1);
char* getValue(char* line);



int main(int argc, char *argv[]) {
    

    struct key_value_pair kvp0;
    struct key_value_pair kvp1;
    struct key_value_pair kvp2;
    struct kvp_holder kvph;
    kvp0.key = "all";
    kvp1.key = "alla";
    kvp2.key = "allz";
    kvp0.value = "vultura";
    kvp1.value = "vulture";
    kvp2.value = "vulturd";
    kvph.k = kvp1;
    kvph.a = "aaas";
    // kvph.k[1] = kvp1;
    // kvph.k[2] = kvp2;
    char* line;
    printf("%s\n", kvph.a);
    printf("%s\n", kvph.k.key);
    // printf("%s\n", kvph.k[2].key);
    // printf("%s\n", kvph.k[0].value);
    // printf("%s\n", kvph.k[1].value);
    // printf("%s\n", kvph.k[2].value);
    line = malloc(sizeof(*line) * 100);
    int line_number = 0;
    // while (line = my_readline()) {
    //     // printf("%d %s\n", line_number++, getKey(line));
    //     // printf("%s\n", assertOperation(line));
    //     char* current_operation = assertOperation(line);
    //     if (my_strcmp(current_operation, "add")) {
    //         printf("%d %s\n", line_number, getValue(line));
    //     }
    //     line_number++;
    // }
    return 0;
}

// void create(char* value)

int my_strcmp(char* s0, char* s1) {
    int len = my_strlen(s0);
    if (len != my_strlen(s1)) {
        return 0;
    }
    for (int i = 0; i < my_strlen(s0); i++) {
        if (s0[i] != s1[i]) {
            return 0;
        }
    }
    return 1;
}

char* getKey(char* line) {
    char* key;
    for (int i = 0; i < my_strlen(line) + 1; i++) {
        if (line[i] == ' ' || line[i] == '\0') {
            key = malloc(sizeof(key) * i + 1);
            key = my_substr(line, 0, i);
            return key;
        }
    }
    return NULL;
}

char* getValue(char* line) {
    char* value;
    int len = 0;
    for (int i = 0; i < my_strlen(line) + 1; i++) {
        if (line[i] == ' ') {
            len = my_strlen(line) + 2 - i;
            value = malloc(sizeof(value) * len + 1);
            value = my_substr(line, i + 1, len);
            return value;
        }
    }
    return NULL;
}

char* my_substr(char* str, int startIndex, int endIndex) {
    if (endIndex <= startIndex || startIndex < 0 || endIndex < 0) {
        return "";
    }
    int len = endIndex - startIndex;
    char* substr;
    substr = malloc(sizeof(*substr) * (len + 1));
    for (int i = 0; i < len; i++) {
        substr[i] = str[startIndex + i];
    }
    substr[len] = '\0';
    return substr;
}



