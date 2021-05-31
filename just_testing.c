#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
    int data;
    char string [20];
} element;

int main(void) {
    element *p = NULL;
    p = (element *)malloc(sizeof(element));

    p -> data = 100;
    strcpy(p -> string,"just testing");

    printf("%d 과 %s 입니다.",p->data,p->string);

    free(p);

    return 0;
}
