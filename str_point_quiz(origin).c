#include<stdio.h>//표준 입출력헤더
#include<math.h>//수학함수 헤더 

typedef struct pointTag{ //구조체선언 
	int x;
	int y;
}point; 

double get_distance(p1_x,  p1_y,  p2_x,  p2_y){
	printf("첫번째 점의 좌표 입력(x,y) : ");
	scanf("%d%d", &p1_x, &p1_y);
	
	printf("두번째 점의 좌표 입력(x,y) : ");
	scanf("%d%d", &p2_x, &p2_y);
	
	int xdiff, ydiff;
	double dist;
	
	xdiff=p1_x-p2_x;
	ydiff=p1_y-p2_y;
	
	dist=sqrt((double)(xdiff*xdiff+ydiff*ydiff));
	
	return dist;
}

int main(void){
	//struct pointTag p1, p2;//구조체변수생성 
	
	point p1, p2;
	double distance;
	
	distance = get_distance(p1.x,p1.y,p2.x,p2.y);

	printf("거리는 %.1f입니다.",distance);
	
	return 0; 
}