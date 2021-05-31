#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct _stacktype{
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

//스택 초기화 함수
void init_stack(StackType *s){
    s -> top = -1;
}

//공백 상태 검사 함수
int is_empty(StackType *s){
    return (s -> top == -1);
}

//포화 상태 검사
int is_full(StackType *s){
    return (s -> top == (MAX_STACK_SIZE -1));
}

//삽입함수
void push(StackType *s, element item){
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러n");
        return;
    }
    else {
        s->data[++(s->top)] = item;
    }
}

//삭제 함수
element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러 \n");
        exit(1);
    }
    else{
        return s->data[(s->top)--];
    }
}

//피크 함수
element peek(StackType *s){
    if(is_empty(s)) {
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else {
        return s->data[s->top];
    }
}

int prec(char op){
    switch(op){
        case '(': case ')' : return 0;
        case '+': case '-' : return 1;
        case '*': case '/' : return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[]){
    char ch, top_op;
    int len = strlen(exp);
    StackType s;

    init_stack(&s);
    for(int i=0; i<len; i++) {
        ch = exp[i];
        switch(ch){
            case '+' : case '-' : case '*' : case '/' : //연산자
                //스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
                while (!is_empty(&s) && (prec( ch) <= prec(peek(&s)))) {
                    printf("%c", pop(&s));
                }
                push(&s, ch);
                break;
            case '(' : //왼쪽 괄호
                push(&s, ch);
                break;
            case ')' : //오른쪽 괄호
                top_op = pop(&s);
                //왼쪽 괄호를 만날때까지 출력
                while (top_op != '('){
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                break;
            default : //정수일때.
                printf("%c", ch);
                break;
        }
    }
    while (!is_empty(&s)){
        printf("%c", pop(&s));
    } 
}

int main(void){

    char *s = "(2+3)*4+9";
    printf("중위표시수식 %s \n", s);
    printf("후위표시수식 ");
    infix_to_postfix(s);
    printf("\n");

    return 0;
}