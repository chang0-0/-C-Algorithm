#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 6

typedef int element;
typedef struct Stack {
    element data[MAX_STACK_SIZE];
    int top;
}stackType;

//스택 초기화 함수
void init_stack(stackType *s){
    s -> top = -1;
}

//공백 상태 검사 함수
int is_empty(stackType *s){
    return (s -> top == -1);
}

//포화 상태 검사함수
int is_full(stackType *s){
    return (s -> top == (MAX_STACK_SIZE -1));
}

//삽입 함수
void push(stackType *s, element item){
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else {
        s->data[++(s->top)] = item;
    }
}

//삭제 함수
element pop(stackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러 \n");
        exit(1);
    }
    else{
        return s->data[(s->top)--];
    }
}

//확인 함수
element peek(stackType *s){
    if(is_empty(s)) {
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else {
        return s->data[s->top];
    }
}

//스택 코드의 끝

void reverse(stackType *s) {
    int in = 0;

    printf("배열 6개입력 : ");
    for(int i = 0; i < MAX_STACK_SIZE; i++) {
        scanf("%d",&in);
        push(s, in);
    }

    printf("반전된 정수 배열 : ");
    for(int i = 0; i < MAX_STACK_SIZE; i++) {
        printf("%d ",pop(s));
    }
}

int main(void) {
    stackType s;
    init_stack(&s);

    printf("정수 배열의 크기 : 6 \n");
    reverse(&s);

    return 0;
}