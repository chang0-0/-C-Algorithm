#include <stdio.h>

int main(void){
    int grade; 

    printf("점수를 입력하세요 : ");
    scanf("%d",&grade);

    if(grade >= 95){
        printf("A+입니다. ");
    }
    else if(grade >= 90){
        printf("A0입니다. ");
    }
    else if(grade >= 85){
        printf("B+입니다. ");
    }
    else if(grade >= 80){
        printf("B0입니다. ");
    }
    else if(grade >= 75){
        printf("C+입니다. ");
    }
    else if(grade >= 70){
        printf("C0입니다. ");
    }
    else if(grade >= 65){
        printf("D+입니다. ");
    }
    else if(grade >= 60){
        printf("D0입니다. ");
    }
    else if(grade < 60){
        printf("F입니다. ");
    }

    return 0;
}