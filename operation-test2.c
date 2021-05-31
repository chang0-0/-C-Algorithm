#include <stdio.h>

void opera(int a, int b, char op){
    int result;

    if(op == '+'){
        result = a + b;
        printf("%d + %d = %d \n",a,b,result);
    }
    else if(op == '-'){
        result = a - b;
        printf("%d - %d = %d \n",a,b,result);
    }
    else if(op == '*'){
        result = a * b;
        printf("%d x %d = %d \n",a,b,result);
    }
    else if(op == '/'){
        if(b!=0){
            result = a / b;
            printf("%d / %d = %d \n",a,b,result);
        }
        else {
            printf("0으로는 나눌수 없습니다.");
        }
    }
    else if(op == '%'){
        if(b!=0){
            result = a % b;
            printf("%d %% %d = %d \n",a,b,result);
        }
        else {
            printf("0으로는 나머지를 구할수없습니다.");
        }
    }
}

int main(void) {
    int a,b,result = 0;
    char op;

    printf("첫번째 숫자를 입력해주세요 : ");
    scanf("%d \n",&a);

    printf("연산자를 입력해주세요 : ");
    scanf(" %c \n",&op);

    printf("두번째 숫자를 입력해주세요 : ");
    scanf("%d\n",&b);

    opera(a,b,op);

    return 0;
}
