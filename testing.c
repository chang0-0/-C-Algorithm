#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dyna{
    int num;
    char str[20]
}dyna;

int main(){
    dyna *dy;

    dy = (dyna *)malloc(sizeof(dyna));
    if(dy == NULL){
        fprintf(stderr, "메모리가 부족합니다 \n");
        exit(1);
    }

    dy->num = 100;
    strcpy(dy->str,"just testing");

    printf("num = %d \n", dy->num);
    printf("str = %s", dy->str);


    free(dy);
    return 0;
}