#include <stdio.h>
#include <stdlib.h>

//스택 코드 시작

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct _StackType {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType *s) {
    s -> top = -1;
}

int is_empty(StackType *s) {
    return s -> top == -1;
}

int is_full(StackType *s) {
    return (s -> top == (MAX_STACK_SIZE -1));
}

void push(StackType *s, element item){
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러");
        return;
    }
    else {
        s -> data[++(s->top)] = item;
    }
}

int pop(StackType *s){
    if(is_empty){
        fprintf(stderr,"공백 상태 입니다.");
        exit(1);
    }
    else {
        return s -> data[(s->top)--];
    }
}

int peek(StackType *s){
    if(is_empty(s)){
        fprintf(stderr,"공백 상태 입니다.");
        exit(1);
    }
    else {
        return s -> data[(s->top)];
    }
}


int main(void) {
    StackType *s;

    init_stack(&s);
    push(&s, 1);
    push(&s, 1);
    push(&s, 1);

    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    
    return 0;
}
