#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

typedef int element;
typedef struct StackType {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void error(char *message) {
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_stack(StackType *s) {
    s -> top = -1;
}

int is_empty(StackType *s) {
    return s -> top == -1;
}

int is_full(StackType *s) {
    return s -> top == (MAX_STACK_SIZE -1);
}

//삽입함수
void push(StackType *s, element item) {
    if(is_full(s)) {
        error(" 스택 포화 에러");
    }
    else {
        s -> data[++(s -> top)] = item;
    }
}

element pop(StackType *s) {
    if(is_empty(s)) {
        error("스택 공백 에러");
    }
    else {
        return s -> data[(s->top)--];
    }
}

//피크 함수
element peek(StackType *s) {
    if(is_empty(s)) {
        error("스택 공백 에러");
    }
    else {
        return s -> data[s->top];
    }
} 

int size(StackType *s) {
    return s -> top + 1;
}

int main(void) {
    StackType s;
    init_stack(&s);

    push(&s,1);
    push(&s,2);
    push(&s,3);

    printf("%d \n",pop(&s));

    int count = 0;
    count = size(&s);
    printf("사이즈는 %d",count);

    return 0;
}