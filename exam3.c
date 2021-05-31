#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct stack{
	int data[MAX_STACK_SIZE];
	int top;
}stack;

void init(stack *s) {
	s -> top = -1;
}

int is_empty(stack *s){
	return (s -> top == -1);
}

int is_full(stack *s) {
	return (s -> top == (MAX_STACK_SIZE -1));
}

void push(stack *s, element item) {
	if(is_full(s)) {
		fprintf(stderr,"스택포화에러");
		return ;
	}
	else {
		s -> data[++(s -> top)] = item;
	}
} 

element pop(stack *s) {
	if(is_empty(s)) {
		fprintf(stderr,"스택 공백 에러");
		exit(1); 
	}
	else {
		return s -> data[(s->top)--];	
	}
}

void reverse(stack *s) {
	int len;
	printf("정수 배열의 크기 : ");
	scanf("%d",&len);
	
	int a[MAX_STACK_SIZE];
	int temp = 0;
	printf("정수를 입력하시오:");
	for(int i=0;i<len; i++){
		scanf(" %d",&a[i]);
	}
	
	for(int i=0; i<len; i++) {
		push(s,a[i]);
	}
	
	for(int i = 0; i<len; i++) {
		printf(" %d ",pop(s));
	}
}

int main(void) {
	stack *s;
	init(&s);
		
	reverse(&s);
	
	return 0;
}