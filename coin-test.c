#include <stdio.h>

int main(void){
    int money,result;
    int c500,c100,c50,c10;

    printf("금액을 입력해주세요 : ");
    scanf("%d",&money);

    c500 = money / 500;
    result = money - (c500 * 500);

    printf("500원짜리 %d개 \n", c500);

    c100 = result / 100;
    result = result - (c100 * 100);

    printf("100원짜리 %d개 \n", c100);

    c50 = result / 50;
    result = result - (c50 * 50);

    printf("50원짜리 %d개 \n", c50);

    c10 = result / 10;
    result = result - (c10 * 10);
    
    printf("10원짜리 %d개 \n", c10);
    printf("나머지잔돈 %d원 \n",result);
}