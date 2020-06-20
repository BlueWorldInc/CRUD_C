#include <stdio.h>
#include <stdlib.h>

void multiplybytwo(int* number);
void changeAddress(int** alpha);

int main(int argc, char** argv) {

    // test 1
    // int number = 5;
    // printf("%d\n", number);
    // printf("%p\n", &number);
    // multiplybytwo(&number);
    // printf("%d\n", number);

    // test 2
    // comment on fait pour récupérer l'addresse d'une variable locale dans une fonction
    int number = 8;
    int number2 = 9;
    int* p_number2 = NULL;
    int** p_number = &p_number2;

    printf("%p\n", &p_number);
    printf("%p\n", p_number);
    printf("%p\n", &number);
    printf("%p\n", *p_number);

    printf("*******************\n");

    // p_number = &number2;

    // printf("%p\n", &p_number);
    // printf("%p\n", p_number);
    // printf("%p\n", &number);

    changeAddress(p_number);

    printf("*******************\n");

    printf("%p\n", &p_number);
    printf("%p\n", p_number);
    printf("%p\n", *p_number);

    return 0;
}

void multiplybytwo(int* number) {
    int r = *number * 2;
    printf("%p\n", number);
    *number = r;
}

void changeAddress(int** alpha) {
    int numba = 7;
    printf("%p\n", &numba);
    *alpha = &numba;
    printf("%p\n", alpha);
    
}