#include "myLib\fnc.h"
#include "myLib\crd.h"
#include <time.h>

struct key_value_pair {
    char* key;
    char* value;
};

struct kvp_holder {
    char* a;
    struct key_value_pair* k;
};

// to be refactored to link and linked_list respectively instead of linked_list and linked_list_container
struct linked_list {
    char* value;
    char* key;
    struct linked_list* next_link;
};

struct linked_list_container {
    struct linked_list* first_link;
};

void print_linked_list(struct linked_list* linked_list_start);
// void add_linked_list(struct linked_list linked_list_start, char* val);
void add_linked_list(struct linked_list* linked_list_start, char* key, char* value);
struct linked_list* found_link(struct linked_list* linked_list_start, char* link_key);
struct linked_list* shift_linked_list(struct linked_list* linked_list_start, char* key, char* value);
void add_update_linked_list(struct linked_list* linked_list_start, char* key, char* value);
void delete_link(struct linked_list* linked_list_start, char* link_key);
// struct linked_list create_link(char* val);
// void create_link(struct linked_list* new_link_address, char* val);
// void create_link(struct linked_list** new_link_address, char* val);
void create_link(struct linked_list** new_link_address, char* key, char* value);
// struct linked_list* get_last_link(struct linked_list linked_list_start);
void get_last_link(struct linked_list* linked_list_start_address, struct linked_list** last_link_address);
char* delete_link_return(struct linked_list* linked_list_start, char* link_key);
char* my_substr(char* str, int startIndex, int endIndex);
char* getKey(char* line);
int my_strcmp(char* s0, char* s1);
char* getValue(char* line);



int main(int argc, char *argv[]) {
    // printf("start\n");
    clock_t begin = clock();
    struct linked_list linked_list_start;
    linked_list_start.key = "-1";
    struct linked_list* linked_list_first = &linked_list_start;

    // struct linked_list_container linked_list_container;
    // linked_list_container.first_link =  &linked_list_start;

    // linked_list_start.key = "5";
    // linked_list_start.value = "84235";
    // linked_list_start.next_link = NULL;
    // printf("%p\n", linked_list_first);

    // add_linked_list(linked_list_start, "7");
        // add_linked_list(linked_list_first, "7", "97845");
        // add_linked_list(linked_list_first, "95", "484512");
        // add_linked_list(linked_list_first, "34", "478419");
        // add_linked_list(linked_list_first, "33", "477619");
        // add_linked_list(linked_list_first, "91", "66548");

    
    // linked_list_first = shift_linked_list(linked_list_first, "7", "97845");
    // linked_list_first = shift_linked_list(linked_list_first, "95", "484512");
    // linked_list_first = shift_linked_list(linked_list_first, "34", "478419");
    // linked_list_first = shift_linked_list(linked_list_first, "33", "477619");
    // linked_list_first = shift_linked_list(linked_list_first, "91", "66548");

        // add_update_linked_list(linked_list_first, "7", "97845");
        // add_update_linked_list(linked_list_first, "95", "484512");
        // add_update_linked_list(linked_list_first, "34", "478419");
        // add_update_linked_list(linked_list_first, "33", "477619");
        // add_update_linked_list(linked_list_first, "91", "66548");

    // add_linked_list(linked_list_start, "25");
    // add_linked_list(linked_list_start, "37");
    // printf("printing list...\n");
    // print_linked_list(linked_list_first);
    // add_update_linked_list(linked_list_first, "33", "477119");
    // delete_link(linked_list_first, "95");
    // printf("printing list...\n");
    // print_linked_list(linked_list_first);
    // struct linked_list* search_result = found_link(linked_list_first, "95");
    // if (search_result != NULL) {
    //     printf("%s", (*search_result).key);
    // }
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
    while (line = my_readline()) {
        // printf("%d\n", my_strlen(line));

        // printf("%d %s\n", line_number++, getKey(line));
        // printf("%s\n", assertOperation(line));
        char* current_operation = assertOperation(line);
        if (my_strcmp(current_operation, "add")) {
            // printf("add\n");
            add_update_linked_list(linked_list_first, getKey(line), getValue(line));
            struct linked_list* search_result = found_link(linked_list_first, getKey(line));
            // printf("%p\n", linked_list_first);
            // printf("%d %s\n", line_number, getValue(line));
            printf("%s\n", (*search_result).key);
        } else if (my_strcmp(current_operation, "delete")) {
            // printf("delete\n");
            char* delete_result = delete_link_return(linked_list_first, getKey(line));
            if (delete_result == NULL) {
                printf("-1\n");
            } else {
                printf("%s", delete_result);
            }
        } else if (my_strcmp(current_operation, "search")) {
            // printf("search\n");
            struct linked_list* search_result = found_link(linked_list_first, getKey(line));
            if (search_result == NULL) {
                printf("-1\n");
            } else {
                printf("%s\n", (*search_result).value);
            }
        }
        // line_number++;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("end\n");
    printf("Time taken: %lf seconds", time_spent);
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

// void add_linked_list(struct linked_list* linked_list_start, char* key, char* value) {
    // struct linked_list new_link0 = create_link("7");
    // struct linked_list new_link1 = create_link("9");
    // struct linked_list new_link2 = create_link("34");


    // struct linked_list* current_link = linked_list_start;

    // printf("a%pa\n", (*current_link).next_link);
    // (*current_link).next_link = &new_link0;
    // current_link = (*current_link).next_link;
    // (*current_link).next_link = &new_link1;
    // current_link = (*current_link).next_link;

    // current_link = linked_list_start;
    // printf("a%pa\n", (*current_link).next_link);

    // printf("start add link %s\n", val);

    // while((*current_link).next_link != NULL) {
        // printf("c%pc\n", (*current_link).next_link);
        // printf("d%sd\n", (*current_link).value);
        // current_link = (*current_link).next_link;
    // }
    
    // struct linked_list new_link = create_link(val);
    // struct linked_list* new_link_add = NULL;
    // struct linked_list** new_link_address = &new_link_add;
    // create_link(new_link_address, key, value);
    // printf("%p\n", *new_link_address);
    // printf("%p\n", new_link_add);
    // printf("mid add link %s\n", val);


    // printf("d%sd\n", (*current_link).value);

    // (*current_link).next_link = new_link_add;
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
// }

void add_linked_list(struct linked_list* linked_list_start, char* key, char* value) {
    struct linked_list* current_link = linked_list_start;

    if (my_strcmp((*linked_list_start).key, "-1")) {
        (*current_link).key = key;
        (*current_link).value = value;
        (*current_link).next_link = NULL;
        return;
    }

    while ((*current_link).next_link != NULL) {
        current_link = (*current_link).next_link;
    }

    struct linked_list* new_link;
    new_link = malloc(sizeof(*new_link));
    (*new_link).key = key;
    (*new_link).value = value;
    (*new_link).next_link = NULL;


    (*current_link).next_link = new_link;
}

void add_update_linked_list(struct linked_list* linked_list_start, char* key, char* value) {
    struct linked_list* current_link = linked_list_start;
    int found = 0;

    if (my_strcmp((*linked_list_start).key, "-1")) {
        (*current_link).key = key;
        (*current_link).value = value;
        (*current_link).next_link = NULL;
        return;
    }

    while ((*current_link).next_link != NULL) {
        if (my_strcmp((*current_link).key, key)) {
            found = 1;
            break;
        }
        current_link = (*current_link).next_link;
    }

    if (found) {
        // printf("0: %s\n", (*current_link).value);
        (*current_link).value = value;
        // printf("1: %s\n", (*current_link).value);
    } else {
        struct linked_list* new_link;
        new_link = malloc(sizeof(*new_link));
        (*new_link).key = key;
        (*new_link).value = value;
        (*new_link).next_link = NULL;
        (*current_link).next_link = new_link;
        // printf("key: %s\n", key);
    }
}

struct linked_list* shift_linked_list(struct linked_list* linked_list_start, char* key, char* value) {
    struct linked_list* current_link = linked_list_start;

    struct linked_list* new_link;
    new_link = malloc(sizeof(*new_link));
    (*new_link).key = key;
    (*new_link).value = value;
    (*new_link).next_link = linked_list_start;
    return new_link;
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

void create_link(struct linked_list** new_link_address, char* key, char* value) {
    struct linked_list* new_link;
    new_link = malloc(sizeof(*new_link) * 1);
    new_link[0].key = key;
    new_link[0].value = value;
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
    
    while(current_link != NULL) {
        printf("key: %s, value: %s\n", (*current_link).key, (*current_link).value);
        current_link = (*current_link).next_link;
    }

}

void delete_link(struct linked_list* linked_list_start, char* link_key) {
    struct linked_list* current_link = linked_list_start;
    struct linked_list* last_link = current_link;
    int found = 0;

    while(current_link != NULL) {
        if ((*current_link).key == link_key) {
            found = 1;
            break;
        }
        last_link = current_link;
        current_link = (*current_link).next_link;
    }

    if (found) {
        (*last_link).next_link = (*current_link).next_link;
        free(current_link);
    }

}

char* delete_link_return(struct linked_list* linked_list_start, char* link_key) {
    struct linked_list* current_link = linked_list_start;
    struct linked_list* last_link = current_link;
    int found = 0;

    if (my_strcmp((*linked_list_start).key, "-1")) {
        return NULL;
    }

    while(current_link != NULL) {
        if ((*current_link).key == link_key) {
            found = 1;
            break;
        }
        last_link = current_link;
        current_link = (*current_link).next_link;
    }

    if (found) {
        (*last_link).next_link = (*current_link).next_link;
        char* deleted_value = (*current_link).value;
        free(current_link);
        return deleted_value;
    } else {
        return NULL;
    }

}

struct linked_list* found_link(struct linked_list* linked_list_start, char* link_key) {
    struct linked_list* current_link = linked_list_start;

    if (my_strcmp((*linked_list_start).key, "-1")) {
        return NULL;
    }

    if (my_strcmp((*current_link).key, link_key)) {
        return current_link;
    }

    while (current_link!= NULL) {
        if (my_strcmp((*current_link).key, link_key)) {
            return current_link;
        }
        current_link = (*current_link).next_link;
    }
    return NULL;
}
