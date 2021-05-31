#include <stdio.h>
#include <string.h>

typedef struct Person{
    char name[10];
    int age;
    float pay;

}person;


int main(void){
    person p1;
    
    strcpy(p1.name, "홍길동");
    p1.age = 30;
    p1.pay = 2500000.50;

    printf("-- Person 구조체 생성 -- %d \n");
    printf("이름 : %s \n", p1.name );
    printf("나이 : %d \n", p1.age );
    printf("월급 : %.1f", p1.pay);

    return 0;
}
