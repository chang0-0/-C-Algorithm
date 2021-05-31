#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag {
    char name[10]; //문자배열로 된이름
    int age; //나이를 나타내는 정수값
} student;

int main(void){
    student *p;

    p = (student *)malloc(sizeof(student));
    if(p == NULL){
        fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다. \n");
        exit(1);
    }

    strcpy(p->name, "Park");
    p->age = 20;

    printf("name : %s\n",p->name);
    printf("age : %d",p->age);

    free(p);
    return 0;
}