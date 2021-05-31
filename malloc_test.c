#include <stdio.h>
#include <stdlib.h>
#define ADDRESS 1000

int main(void){
    int *p = (int *)ADDRESS;

    printf("before : %d \n", p);
    p = p + 4;
    printf("after : %d \n", p);

    return 0;
}
