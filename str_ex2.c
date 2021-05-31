#include <stdio.h>
#include <string.h>//strcpy() 헤더파일

typedef struct studentTag{ //stdudnetTag 구조체 선언
    int number; //학번
    char name[10]; //이름
    double grade; //학점
}student; //구조체 변수이름을 지정.

int main(void){//구조체변수 s생성
    //struct studentTag s;
    student s = {2020001,"홍길동",4.3}; //구조체 변수에서 main함수에서 사용할 변수를 재추가.
    //이름 하나로 여러개의 함수를 여러번 다른매개변수로 호출가능

    s.number = 20200001;
    strcpy(s.name,"김길동"); //홍길동을 s.name에
    s.grade = 4.3;

    student s1 = {2020002,"",0.1}; //s1.grade = 0.0으로 나오게됨.

    printf("** 결과출력 **\n\n");
	printf("학번:%d \n", s.number);
	printf("이름:%s \n",s.name);
	printf("학점:%.2f \n",s.grade);

    printf("학번:%d \n", s1.number);
	printf("이름:%s \n",s1.name);
	printf("학점:%.2f \n",s1.grade);

}