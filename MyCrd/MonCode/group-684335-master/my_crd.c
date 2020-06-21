/*
** ETNA PROJECT, 01/04/2019 by ocal_n
** my_crd.c
** File description:
**      fichier crd
*/

#include "fnc.h"

int main()
{
    char *strptr = NULL;
    size_t n = 0;
    ssize_t nread = 0;
    int i = 0;
    struct keyvaluepair *foundit = NULL;
    struct keyvaluepairlist *listtotry = initialisation();
    char *actualstr;
    char *actualkey;
    char *actualvalue;
    while (nread != -1) {
        nread = getline(&strptr, &n, stdin);
        if (nread != -1) {
            actualstr = my_strdup(strptr);
            actualkey = getkey(actualstr);
            actualvalue = getvalue(actualstr);
            foundit = foundkey(listtotry,actualkey);
            int type = detline(actualstr);
            if (type == 1) {
                if (foundit != NULL) {
                    free((*foundit).value);
                    (*foundit).value = my_strdup(actualvalue);
                    my_putstr((*foundit).key);
                    my_putchar('\n');
                } else {
                    addfirsttokeyvaluepair (listtotry, actualkey, actualvalue);
                    my_putstr(actualkey);
                    my_putchar('\n');
                }
            }
            if (type == 2) {
                if (foundit != NULL) {
                    my_putstr((*foundit).value);
                    delkeyvaluepair(listtotry,foundit);
                    my_putstr("\n");
                } else {
                    my_putstr("-1\n");
                }
            }
            if (type == 3) {
                if (foundit != NULL) {
                    my_putstr((*foundit).value);
                    my_putstr("\n");
                } else {
                    my_putstr("-1\n");
                }
            }
            free(actualkey);
            actualkey = NULL;
            free(actualvalue);
            actualvalue = NULL;
            free(actualstr);
            actualstr = NULL;
        }
        free(strptr);
        strptr = NULL;
        i++;
    }
    freelist (listtotry);
    free (listtotry);
}
