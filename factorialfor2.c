#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main(void){
    int fac, n;

    printf("숫자를 입력하세요 : ");
    scanf("%d", &n);

    fac = factorial(n);
    printf("%d!은 %d 입니다.",n, fac);

    return 0;
}

int factorial(int n){
    int result = 1;

    for(int i = n; i > 0; i--){
        result =  result * i;
    }
    //순환(재귀) 반복의 차이 이해 매우중요
    return result;
}
