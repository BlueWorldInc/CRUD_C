#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int two(int n);
char *my_readline(void);
char* assertOperation(char* operation);

int main(int argc, char *argv[]) {
    
    // test sur pointeur

    // int taille = 198;
    // printf("%d", &taille);
    // printf("\n");
    // int* voilure = &taille; // je veut un pointeur, donc l'adresse, d'un int
    // void* voilur = &taille; // je veut un pointeur, donc l'adresse, d'un type quelquonque // probablement aussi efficace car la taille d'une adresse ne varie pas en fonction du type referencer (sous jacent), enfin je croit.
    // int* ferari = (int*) 6422012;
    // printf("a%da", *ferari);
    // printf("%d", *voilure);
    // char *prenom = "Albert";
    // printf("\n%s", prenom);


    // int t = two(6);
    // char *a = my_readline();
    // char *b = my_readline();
    // my_readline();
    // while (my_readline()) {
        
    // }
    // printf("%s", assertOperation("a"));
    // printf("%s\n", assertOperation(my_readline()));
    // printf("%s\n", assertOperation(my_readline()));
    // printf("%s\n", assertOperation(my_readline()));
    char* line;
    line = malloc(sizeof(*line) * 100);
    while (line = my_readline()) {
        // printf("%s\n", assertOperation(line));
        assertOperation(line);
    }
    // char *b;
    // char* z = "hey";
    // printf("hello world \n%s", a);
    // printf("char : %d octets\n", sizeof(*b));
    // printf("int : %d octets\n", sizeof(int));
    // printf("long : %d octets\n", sizeof(long));
    // printf("double : %d octets\n", sizeof(double));
    return 0;
}

int two(int n)
{
    return (n * 2);
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

char* assertOperation(char* operation) {
    if(operation[strlen(operation) - 1] == 'D') {
        return "delete";
    } else if (strchr(operation, ' ') != NULL) {
        return "add";
    } else {
        return "search";
    }
}