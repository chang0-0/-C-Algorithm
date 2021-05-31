#include <stdio.h>
#include <stdlib.h>

int factorial(int n); //함수 선언(function prototype) 형태만선언 함수 원형이라고 부릅니다.

int main(void){

    int fac, n;
    
    printf("팩토리얼 숫자입력 : ");
    scanf("%d",&n);

    fac = factorial(n);
    printf("%d!은 %d 입니다.",n, fac);

    return 0;
}

int factorial(int n){
    int result;

    printf("factorial(%d) \n", n);
    if(n <= 1){
        return 1;
    }
    else {
        return result = n * factorial(n - 1);
    }

}