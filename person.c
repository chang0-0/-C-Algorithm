#include <stdio.h>
#include <string.h>

typedef struct Person{
    char name[10];
    int age;
    float pay;

}person;


int main(void){
    person p1;
    
    strcpy(p1.name, "ȫ�浿");
    p1.age = 30;
    p1.pay = 2500000.50;

    printf("-- Person ����ü ���� -- %d \n");
    printf("�̸� : %s \n", p1.name );
    printf("���� : %d \n", p1.age );
    printf("���� : %.1f", p1.pay);

    return 0;
}
