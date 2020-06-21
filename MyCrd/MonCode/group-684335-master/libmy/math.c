#include "fnc.h"
    
int my_strcmp(char *s1, char *s2)
{
    if ((s1 == NULL) | (s2 == NULL)) {
        return (-1);
    }
    int longeur=0;
    int longeurs1 = my_strlen(s1);
    int longeurs2 = my_strlen(s2);
    if (longeurs1>longeurs2){
        longeur=longeurs1;}
    else{
        longeur=longeurs2;
    }
    int i=0;
    while(i<longeur){
        if(s1[i]==s2[i]){
            i++;
        }
        else {
            return (s1[i]-s2[i]);}
    }
    return (0);
}

int my_strncmp(char *s1, char *s2,int n){
    int longeur=0;
    int longeurs1 = my_strlen(s1);
    int longeurs2 = my_strlen(s2);
    if (longeurs1>longeurs2){
        longeur=longeurs1;}
    else{
        longeur=longeurs2;
    }
    if (longeur>n){
        longeur=n;}
    int i=0;
    while(i<longeur){
        if(s1[i]==s2[i]){
            i++;
        }
        else {
            return (s1[i]-s2[i]);}
    }
    return (0);
}

char *my_strdup(char *str)
{
    int stringlenght = my_strlen(str);
    char *stringcopy = NULL;
    int i;
    if (stringlenght >= 0) {
        stringcopy = malloc(sizeof(char) * (stringlenght + 1));
        if (stringcopy == NULL) {
            exit(0);
        }
        for (i = 0; i < (stringlenght + 1); i++) {
            stringcopy[i] = str[i];
        }
        return (stringcopy);
    }
    return (0);
}

int my_nbrlen(int n) {
    int i = 0;
    if (n == 0){
        return 1;
    }
    if (n < 0) {
        i = 1;
        n = - n;
    }
    while (n != 0) {
        n = n / 10;
        i++;
    }
    return i;
}
