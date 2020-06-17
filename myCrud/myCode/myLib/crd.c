#include "crd.h"

char* assertOperation(char* operation) {
    if(operation[my_strlen(operation) - 1] == 'D') {
        return "delete";
    } else if (my_strchr(operation, ' ') != NULL) {
        return "add";
    } else {
        return "search";
    }
}


