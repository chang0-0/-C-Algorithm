#include <stdio.h>
#include <stdlib.h>

//차후에 스택이 필요하면 여기만 복사하여 붙인다.
// ======= 스택 코드의 시작 ======

#define MAX_STACK_SIZE 100

typedef char element;
typedef struct _stacktype{
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

//삽입 함수zx
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

// ========== 스택 코드의 끝 ==============

int main(void) {    
    stackType s;

    init_stack(&s);

    push(&s,'a');
    push(&s,'b');
    printf("%c ", pop(&s));
    push(&s,'c');
    printf("%c ", pop(&s));
    push(&s,'d');
    push(&s,'e');
    printf("%c ", pop(&s));
    printf("%c ", pop(&s));
    printf("%c ", pop(&s));

    return 0;
}