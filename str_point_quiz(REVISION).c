#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct pointTag{ 
    int x;
    int y;
}point;

double get_distance(point p1, point p2){
//구조체를 매개변수로 사용가능함 받아올때는 메인함수에서 함수호출에서 매개변수로 받아옴.

    int xdiff, ydiff;
    double dist;

    xdiff = p1.x - p2.x;
    ydiff = p1.y - p2.y;

    dist = sqrt((double)(xdiff*xdiff+ydiff*ydiff));

    return dist;
}

int main(){
    //struct pointTag p1, p2; 구조체 변수생성
    //실제로 실행되는 함수(구조체 및 함수 호출.)
    point p1, p2;
    double distance;

    printf("첫번째 점의 좌표 입력(x,y) : ");
    scanf("%d%d", &p1.x, &p1.y);

    printf("두번째 점의 좌표 입력(x,y) : ");
    scanf("%d%d", &p2.x, &p2.y);

    distance = get_distance(p1, p2);
    /*함수에서 호출 자체를 구조체의 멤버들로 구성할수있음
    (함수를 호출할 때 구조체 변수 전달, 멤버가 복사됨)*/

    printf(" 거리는 %.1f 입니다.",distance);

    return 0;
}
