#include<stdio.h>

//int coffee_machine(int button); 함수선언
void coffee_machine(int button) {
	printf("\n1. (자동으로) 뜨거운 물을 준비한다. \n");
	printf("2. (자동으로) 종이컵을 준비한다. \n");
	
	switch(button) {
		case 1 : printf("3. (자동으로) 보통커피를 탄다 \n"); break;
		case 2 : printf("3. (자동으로) 설탕커피를 탄다 \n"); break;
		case 3 : printf("3. (자동으로) 블랙커피를 탄다 \n"); break;
		default : printf("3. (자동으로) 아무커피를 탄다 \n"); break;
	}
	
	printf("4. (자동으로) 물을 붓는다 \n");
	printf("5. (자동으로) 스푼으로 저어서 녹인다 \n");
	
	//return 0;
} 
 
int main(void) {
	int coffee, i;
	
	i=1;
	while(1) {
		printf("[%d] 번 손님 어떤 커피를 드릴까요? (1:보통 2:설탕 3:블랙) = ",i);
		scanf(" %d",&coffee);
		
		if(coffee==1000) {
			break;
		}
		
		coffee_machine(coffee); 
		printf("[%d] 번 손님 커피 여기 있습니다.\n",i);	
		i=i+1;
	}
	
	return 0;
}