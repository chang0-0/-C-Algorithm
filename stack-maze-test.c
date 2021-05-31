#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
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

int prec(char op) {
    switch(op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1; //아무것도 해당되지 않을때
}

//중위 표기식 -> 후위 표기 수식
void infix_to_postfix(char exp[]) {
    int i = 0;
    char ch, top_op;
    int len = strlen(exp); //들어온 문자 배열길이 체크
    stackType s;

    init_stack(&s);
    for(i=0; i<len; i++) {
        ch =
        exp[i];
        switch(ch) {
            case '+' : case '-': case'*': case'/': //연산자
            //스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
            while(!is_empty(&s) && (prec(ch)) <= prec(peek(&s))) {
                
            }
        }
    }
}

int main(void) {

    return 0;
}