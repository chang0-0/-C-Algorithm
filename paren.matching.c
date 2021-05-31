#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

//포화 상태 검사
int is_full(stackType *s){
    return (s -> top == (MAX_STACK_SIZE -1));
}

//삽입함수
void push(stackType *s, element item){
    if(is_full(s)){
        fprintf(stderr,"스택 포화 에러n");
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

//피크 함수
element peek(stackType *s){
    if(is_empty(s)) {
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else {
        return s->data[s->top];
    }
}

int check_matching(const char *in){  //const??
    stackType s; 
    char ch, open_ch; //ch는 *in에서 반복문으로 가져올 내용을 저장하는 변수, open_ch는 pop함수 실행후 스택에서 꺼내서 나오는 문자열을 가져오는 변수.
    int i; //for문에서 반복할 i 생성
    int n = strlen(in); //in의 문자열 길이 n변수에 대입
    init_stack(&s);

    for(i=0; i<n; i++){
        ch = in[i]; //ch는 다음문자.
        switch(ch) {
            case '(': case '[': case'{':
            push(&s,ch);
            break;
            case ')' : case ']': case'}':
                if(is_empty(&s)){
                    return 0;
                }
                else {
                    open_ch = pop(&s);
                    if((open_ch == '(' && ch != ')') ||
                        (open_ch == '[' && ch != ']') || 
                        (open_ch == '{' && ch != '}')) {
                            return  0;
                        }
                    }
                    break;
                }
    }//for문 종료

    if(!is_empty(&s)) { //스택에 남아있으면 오류
        return 0;
    }
   return 1; //matching 함수내에서 모든 문장이 성공적으로 다 완료되서 반환값이 0이없을때 1로 반환해서 main함수의 
   //if조건문을 완성 시켜줌.
    
}

int main(void){
    char *p = "{ A[(i+1)]=0; }";
    if (check_matching(p) == 1) {
        printf("%s 괄호검사성공 \n", p);
    }
    else {
        printf("%s 괄호검사실패 \n", p);
    }

    return 0; //오류 x
}