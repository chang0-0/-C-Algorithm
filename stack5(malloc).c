#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct _stacktype{
    element *data; //스택안의 value
    int capacity; //스택의 크기변수
    int top; //스택의 가장위를 알려주는 변수
}StackType;

//스택 생성 함수
void init_stack(StackType *s){
    s -> top = -1;
    s -> capacity = 1;
    s -> data = (element *)malloc(s->capacity * sizeof(element));//스택의 크기를 element형의 크기만큼 곱한값으로 동적메모리 할당.
}

//공백 상태 검출 함수
int is_empty(StackType *s){
    return(s -> top == -1);
}

//포화 상태 검출 함수
int is_full(StackType *s){
    return (s->top == (s->capacity -1));
}

void push(StackType *s, element item){
    if(is_full(s)){
        s->capacity *= 2;
        s -> data = (element *)realloc(s->data, s->capacity * sizeof(element)); //push함수가 발생될떄 data의 값에 따라 변화가 일어남.
    }
    s -> data[++(s->top)] = item;
}

//삭제함수 (공백 에러는 있지만 포화에러는 없다.)
element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else {
        return s->data[(s->top)--];
    }
}

int main(void){
    StackType s;
    init_stack(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);

    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

    free(s.data);
    return 0;
}
