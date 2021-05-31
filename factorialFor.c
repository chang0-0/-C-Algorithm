#include <stdio.h>

int factorial(int n){
    int i, fac = 1;

    for(int i=n; i>0; i--){
        printf("factorial (%d) \n", i);
        fac = fac * i;
    }
    return fac;
}

int main(void){
    int fac;
    int n = 0;
    printf("정수입력:");
    scanf("%d", &n);

    fac = factorial(n);

    printf("%d!은 %d 입니다.",n ,fac);
}