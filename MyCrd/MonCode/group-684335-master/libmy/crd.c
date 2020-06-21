#include "fnc.h"

char *getkey(char *inputstr)
{
    int index = 0;
    for (int i = 0; i < my_strlen(inputstr); i++) {
        if (inputstr[i] == ' ') {
            index = i;
            break;
        } else if (inputstr[i] == '\n') {
            index = i;
        }
    }

    char *keyoutput = malloc(sizeof(char) * (index + 1));

    for (int i = 0; i < index; i++) {
        keyoutput[i] = inputstr[i];
    }
    keyoutput[index] = '\0';
    return keyoutput;
}

char *getvalue(char *inputstr)
{
    int index = 0;
    int len = my_strlen(inputstr);
    for (int i = 0; i < len; i++) {
        if (inputstr[i] == ' ') {
            index = i;
            break;
        }
    }
    if (index == 0) {
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        if (inputstr[i] == 'D') {
            return NULL;
        }
    }
    char *value = malloc(sizeof(char) * (len - index + 1));

    for (int i = 0; i < (len - index - 2); i++) {
        value[i] = inputstr[i+index+1];
    }
    value[(len - index - 2)] = '\0';
    return value;
}

int detline(char *inputstr)
{
    int index = 0;
    int len = my_strlen(inputstr);
    for (int i = 0; i < len; i++) {
        if (inputstr[i] == ' ') {
            index = i;
            break;
        }
    }
    if (index == 0) {
        return (3);
    }
    index = 0;
    for (int i = 0; i < len; i++) {
        if (inputstr[i] == 'D') {
            index = i;
            break;
        }
    }
    if (index == 0) {
        return (1);
    } else {
        return (2);
    }
}

int checkkey(char *keytofind, char **keylist, int i)
{
    for (int j = 0; j < i; j++) {
        if (my_strcmp(keytofind,keylist[j]) == 0) {
            return (j);
        }
    }
    return (-1);
}
