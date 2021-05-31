#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _PointTag{
    int x;
    int y;
}point;

double get_distance(point *p1, point *p2){
    double distance;
    int a,b,c,d;

    int xdiff = (p1 -> x) - (p2 -> x);
    int ydiff = (p1 -> y) - (p2 -> y);

    distance = sqrt((double)(xdiff*xdiff+ydiff*ydiff));

    return distance;
}

int main(void){
    int result = 0; 

    point p1;
    point p2;

    printf("첫번째 점의 좌표 입력(x,y) : ");
    scanf("%d%d", &p1.x, &p1.y);

    printf("두번째 점의 좌표 입력(x,y) : ");
    scanf("%d%d", &p2.x, &p2.y);

    result = get_distance(&p1, &p2);

    printf("거리는 %.1f 입니다.", result);

    return 0;
}