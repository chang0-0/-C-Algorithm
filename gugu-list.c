#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i = 0, num;
    int multiply[9]; //구구단의 결과를 배열에 저장

    printf("\n 1~9의 정수 입력 : ");

    while(1) {
        scanf(" %d", &num);
        if(num<0 || num>9) {
            printf("\n 1~9의 정수 입력 : ");
        }
        else {
            break; //반복문 종료
        }
    }

    printf("\n");

    for(i=0; i<9; i++) {
        multiply[i] = num * (i + 1);
        printf(" %d * %d = %d \n",num,i + 1,multiply[i]);
    }

    return 0;
}