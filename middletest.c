#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //문제2번 while문을 사용해서 구구단을 작성하라.
    int i,j;

    i = 2;
    
    while(i<=9) {
        printf("  == %d단 ==  ",i);
        i++;
    }

    printf("\n");
    printf("\n");

    j = 1;

    while(j<=9) {

        i = 2;
        while(i<=9){
            printf("%2d x %2d = %2d ",i,j,i*j);
            i++;
        }

    j++;
    
    printf("\n"); 
    } 

    return 0;
}