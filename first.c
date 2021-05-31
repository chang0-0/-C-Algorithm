#include<stdio.h>

int factorial (int n){
    printf("factorial (%d) \n",n);

    if(n <= 1){
        return 1;
    }
    else {
        return (n * factorial (n-1));
    }
}

int main(void) { 
    int fac;
    int n=0; 
    printf("정수입력:");
    scanf("%d", &n);

    fac = factorial(n);

    printf("%d!은 %d 입니다 ",n ,fac);
}