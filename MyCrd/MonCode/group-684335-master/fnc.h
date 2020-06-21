#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct keyvaluepair {
    char *key;
    char *value;
    struct keyvaluepair *next;
};

struct keyvaluepairlist {
    struct keyvaluepair *first;
};

void my_putstr(char *str);
int my_strlen(char *str);
void my_putchar(char c);
char *my_strdup(char *str);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2,int n);
void my_putstr(char *str);
void addfirsttokeyvaluepair (struct keyvaluepairlist *list,
                             char *inputkey, char *inputvalue);
struct keyvaluepairlist *initialisation();
void delkeyvaluepair (struct keyvaluepairlist *list,
                      struct keyvaluepair *strcttodel);
void freelist(struct keyvaluepairlist *listtofree);
void printkeyvaluelist (struct keyvaluepairlist *listtoprint);
struct keyvaluepair *foundkey
(struct keyvaluepairlist *listtosearch, char *keytofound);
char *getkey(char *inputstr);
char *getvalue(char *inputstr);
int detline(char *inputstr);
int checkkey(char *keytofind, char **keylist, int i);
