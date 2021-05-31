#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a, b, result;
    char c;

    printf("첫번째 숫자를 입력하세요 : ");
    scanf("%d",&a);

    printf("연산자를 입력하세요<+,-,*,/,%> : ");
    scanf(" %c",&c);

    printf("두번째 숫자를 입력하세요 : ");
    scanf("%d",&b);

    if(c == '+') {
        result = a + b;
        printf("%d + %d = %d", a, b, result);
    }
    else if(c == '-'){
        result = a - b;
        printf("%d - %d = %d", a, b, result);
    }
    else if(c == '*'){
        result = a * b;
        printf("%d X %d = %d", a, b, result);
    }
    else if(c == '/'){
        if(b!=0){
            result = a / b;
            printf("%d / %d = %d", a, b, result);
        }
        else {
            printf("0으로는 나눌수 없습니다.");
        }        
    }
    else if(c == '%'){
        if(b!=0){
            result = a % b;
            printf("%d %% %d = %d", a, b, result);
        }
        else {
            printf("0으로는 나머지 연산을 할수 없습니다.");
        }
    }

    return 0;
}