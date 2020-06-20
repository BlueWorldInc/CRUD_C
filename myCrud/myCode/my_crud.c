#include "myLib\fnc.h"
#include "myLib\crd.h"

struct key_value_pair {
    char* key;
    char* value;
};

struct kvp_holder {
    char* a;
    struct key_value_pair* k;
};

struct linked_list {
    char* value;
    struct linked_list* next_link;
};

void print_linked_list(struct linked_list* linked_list_start);
// void add_linked_list(struct linked_list linked_list_start, char* val);
void add_linked_list(struct linked_list* linked_list_start, char* val);
// struct linked_list create_link(char* val);
// void create_link(struct linked_list* new_link_address, char* val);
void create_link(struct linked_list** new_link_address, char* val);
// struct linked_list* get_last_link(struct linked_list linked_list_start);
void get_last_link(struct linked_list* linked_list_start_address, struct linked_list** last_link_address);
char* my_substr(char* str, int startIndex, int endIndex);
char* getKey(char* line);
int my_strcmp(char* s0, char* s1);
char* getValue(char* line);



int main(int argc, char *argv[]) {
    
    struct linked_list linked_list_start;

    linked_list_start.value = "5";
    linked_list_start.next_link = NULL;

    // add_linked_list(linked_list_start, "7");
    add_linked_list(&linked_list_start, "7");
    add_linked_list(&linked_list_start, "95");
    add_linked_list(&linked_list_start, "34");
    // add_linked_list(linked_list_start, "68");
    // add_linked_list(linked_list_start, "25");
    // add_linked_list(linked_list_start, "37");
    print_linked_list(&linked_list_start);
    // printf("a%sa\n", linked_list_start.next_link);
    // printf("a%pa\n", &linked_list_start);
    // test sur les struct

    // struct key_value_pair kvp0;
    // struct key_value_pair kvp1;
    // struct key_value_pair kvp2;
    // struct kvp_holder kvph;
    // kvp0.key = "all";
    // kvp1.key = "alla";
    // kvp2.key = "allz";
    // kvp0.value = "vultura";
    // kvp1.value = "vulture";
    // kvp2.value = "vulturd";
    // struct key_value_pair* kvps;
    // kvps = malloc(sizeof(*kvps) * 3);
    // kvph.k = kvps;
    // kvph.a = "aaas";
    // kvph.k[0] = kvp0;
    // kvph.k[1] = kvp1;
    // kvph.k[2] = kvp2;
    // kvph.k[3] = kvp2;
    // kvph.k[4] = kvp2;
    // printf("%s\n", kvph.a);
    // printf("%s\n", kvph.k[0].key);
    // printf("%s\n", kvph.k[3].key);
    // printf("%s\n", kvph.k[4].key);
    // printf("%s\n", kvph.k[0].value);
    // printf("%s\n", kvph.k[3].value);
    // printf("%s\n", kvph.k[4].value);

    char* line;
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

// void add_linked_list(struct linked_list linked_list_start, char* val) {
//     struct linked_list new_link = create_link(val);
//     struct linked_list* last_link_address;
//     get_last_link(&linked_list_start, &last_link_address);
//     // struct linked_list last_link = *last_link_address;
//     // last_link.next_link = &new_link;
//     // struct linked_list tmp_link = *last_link.next_link;
//     printf("a%pa\n", &linked_list_start);
//     printf("a%pa\n", last_link_address);
//     printf("a%pa\n", &last_link_address);
//     // printf("a%pa\n", &last_link);
//     printf("a%pa\n", &new_link);
//     printf("////////////////////////////\n");
// }

void add_linked_list(struct linked_list* linked_list_start, char* val) {
    // struct linked_list new_link0 = create_link("7");
    // struct linked_list new_link1 = create_link("9");
    // struct linked_list new_link2 = create_link("34");


    struct linked_list* current_link = linked_list_start;

    // printf("a%pa\n", (*current_link).next_link);
    // (*current_link).next_link = &new_link0;
    // current_link = (*current_link).next_link;
    // (*current_link).next_link = &new_link1;
    // current_link = (*current_link).next_link;

    // current_link = linked_list_start;
    // printf("a%pa\n", (*current_link).next_link);

    // printf("start add link %s\n", val);

    while((*current_link).next_link != NULL) {
        // printf("c%pc\n", (*current_link).next_link);
        // printf("d%sd\n", (*current_link).value);
        current_link = (*current_link).next_link;
    }
    
    // struct linked_list new_link = create_link(val);
    struct linked_list* new_link_add = NULL;
    struct linked_list** new_link_address = &new_link_add;
    create_link(new_link_address, val);
    // printf("%p\n", *new_link_address);
    // printf("%p\n", new_link_add);
    // printf("mid add link %s\n", val);


    // printf("d%sd\n", (*current_link).value);

    (*current_link).next_link = new_link_add;
    // printf("e%se\n", (*current_link).value);
    // (*current_link).next_link = &new_link2;
    // current_link = (*current_link).next_link;


    // printf("q%sq\n", (*linked_list_start).value);
    // printf("q%sq\n", (*current_link).value);

    // printf("q%sq\n", (*(*(*linked_list_start).next_link).next_link).value);


    // struct linked_list new_link = create_link(val);
    // struct linked_list* last_link = linked_list_start;
    // while((*last_link).next_link != NULL) {
    //     printf("e%se\n", (*last_link).value);
    //     last_link = (*last_link).next_link;
    // }
    // struct linked_list tmp_link = *last_link;
    // struct linked_list* current_link = tmp_link.next_link;
    // while(current_link != NULL) {
    //     last_link = current_link;
    //     tmp_link = *current_link;
    //     current_link = tmp_link.next_link;
    // }

    // using tmp_link will create a copy instead
        // tmp_link = *last_link;
        // tmp_link.next_link = &new_link;

            // (*last_link).next_link = &new_link;
    
    // printf("a%sa\n", (*last_link).next_link);
    // printf("a%sa\n", linked_list_start.value);
    // printf("a%pa\n", linked_list_start);
    // printf("a%pa\n", last_link);
    // printf("a%pa\n", &tmp_link);
    // printf("a%sa\n", linked_list_start.next_link);
    // printf("////////////////////////////\n");
}


// struct linked_list create_link(char* val) {
//     struct linked_list new_link;
//     new_link.value = val;
//     new_link.next_link = NULL;
//     return new_link;
// }

// void create_link(struct linked_list* new_link_address, char* val) {
//     struct linked_list new_link;
//     new_link.value = val;
//     new_link.next_link = NULL;
//     new_link_address = &new_link;
//     // return new_link_address;
// }

// void create_link(struct linked_list** new_link_address, char* val) {
//     struct linked_list new_link;
//     new_link.value = val;
//     new_link.next_link = NULL;
//     printf("%p\n", &new_link);
//     *new_link_address = &new_link;
//     printf("creating new link\n");
//     // return new_link_address;
// }

void create_link(struct linked_list** new_link_address, char* val) {
    struct linked_list* new_link;
    new_link = malloc(sizeof(*new_link) * 1);
    new_link[0].value = val;
    new_link[0].next_link = NULL;
    *new_link_address = &new_link[0];

}

// struct linked_list* get_last_link(struct linked_list linked_list_start) {
//     struct linked_list* last_link;
//     struct linked_list* current_link;
//     struct linked_list tmp_link;
//     last_link = &linked_list_start;
//     current_link = linked_list_start.next_link;
//     while (current_link != NULL) {
//         printf("hey");
//         tmp_link = *current_link;
//         last_link = current_link;
//         current_link = tmp_link.next_link;
//     }
//     // printf("b%pb\n", last_link);
//     // printf("b%pb\n", &linked_list_start);
//     return last_link;
// }

void get_last_link(struct linked_list* linked_list_start_address, struct linked_list** last_link_addresss) {
    struct linked_list linked_list_start = *linked_list_start_address;
    struct linked_list* current_link;
    struct linked_list* last_link_address = *last_link_addresss;
    struct linked_list tmp_link;
    last_link_address = &linked_list_start;
    current_link = linked_list_start.next_link;
    while (current_link != NULL) {
        tmp_link = *current_link;
        last_link_address = current_link;
        current_link = tmp_link.next_link;
    }
    printf("b%pb\n", last_link_address);
    printf("b%pb\n", &linked_list_start);
}

// void print_linked_list(struct linked_list linked_list_start) {
//     struct linked_list* last_link;
//     struct linked_list* current_link;
//     struct linked_list tmp_link;
//     last_link = &linked_list_start;
//     current_link = linked_list_start.next_link;
//     while (current_link != NULL) {
//         tmp_link = *current_link;
//         last_link = current_link;
//         printf("%s\n", tmp_link.value);
//         current_link = tmp_link.next_link;
//     }
// }

// void print_linked_list(struct linked_list* linked_list_start) {
//     struct linked_list* current_link = linked_list_start;
//     printf("start\n");
//     while((*current_link).next_link != NULL) {
//         printf("%s", (*current_link).value);
//         printf("z%pz\n", (*current_link).next_link);
//         current_link = (*current_link).next_link;
//     }
//     printf("end\n");
// }

void print_linked_list(struct linked_list* linked_list_start) {
    struct linked_list* current_link = linked_list_start;
    while((*current_link).next_link != NULL) {
        printf("%s\n", (*current_link).value);
        current_link = (*current_link).next_link;
    }
    printf("%s\n", (*current_link).value);
}