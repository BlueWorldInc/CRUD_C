#include "fnc.h"

void addfirsttokeyvaluepair (struct keyvaluepairlist *list,
                             char *inputkey, char *inputvalue)
{
    struct keyvaluepair *nvx = malloc(sizeof(struct keyvaluepair));
    (*nvx).key = my_strdup(inputkey);
    (*nvx).value = my_strdup(inputvalue);
    (*nvx).next = (*list).first;
    (*list).first = nvx;
}

struct keyvaluepairlist *initialisation()
{
    struct keyvaluepairlist *list = malloc(sizeof(struct keyvaluepairlist));
    struct keyvaluepair *initialkeyvalue = malloc(sizeof(struct keyvaluepair));
    (*initialkeyvalue).key = NULL;
    (*initialkeyvalue).value = NULL;
    (*initialkeyvalue).next = NULL;
    (*list).first = initialkeyvalue;
    return list;
}

void delkeyvaluepair (struct keyvaluepairlist *list, struct keyvaluepair *strcttodel)
{
    if (strcttodel != 0) {
        struct keyvaluepair *actuel = (*list).first;
        while (actuel != 0) {
            if ((*actuel).next == strcttodel) {
                (*actuel).next = (*strcttodel).next;
                free((*strcttodel).key);
                free((*strcttodel).value);
                (*strcttodel).next = NULL;
                (*strcttodel).key = NULL;
                (*strcttodel).value = NULL;
                free(strcttodel);
            } else {
                actuel = (*actuel).next;
            }
        }
    }
}

void freelist(struct keyvaluepairlist *listtofree)
{
    struct keyvaluepair *actuel = (*listtofree).first;
    struct keyvaluepair *actueltmp = NULL;
    while (actuel != 0) {
        actueltmp = actuel;
        actuel = (*actuel).next;
        free((*actueltmp).key);
        free((*actueltmp).value);
        free(actueltmp);
    }
    free(actuel);
}

void printkeyvaluelist (struct keyvaluepairlist *listtoprint)
{
    struct keyvaluepair *actuel = (*listtoprint).first;

    while (actuel != 0) {
        my_putstr((*actuel).key);
        my_putstr((*actuel).value);
        actuel = (*actuel).next;
    }
}

struct keyvaluepair *foundkey (struct keyvaluepairlist *listtosearch, char *keytofound)
{
    if (listtosearch != 0) {
        struct keyvaluepair *actuel = (*listtosearch).first;
        while (actuel != NULL) {
            if (my_strcmp((*actuel).key, (keytofound)) == 0) {
                return actuel;
            }
            actuel = (*actuel).next;
        }
        return NULL;
    }
    return NULL;
}
