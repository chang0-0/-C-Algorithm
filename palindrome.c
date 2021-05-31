#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100

//문자열 char
typedef char element;
typedef struct _stacktype{
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

typedef char string;

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

//알고리즘.
//1.입력받은 문자열을 스택에 먼저 집어넣을거임
//주의사항(구두점이나 스페이스, 대소문자 등은 무시해야됨.)

int check(const char *in) {
    StackType s;
    init_stack(&s);
    int i, result,j=0;
    char rech[50];
    char ch[50];
    char temp[50];
    int n = strlen(in);

    for(i = 0; i<n; i++) {
        ch[i] = tolower(in[i]); //무든문자 소문자로 전환.

        //아스키코드 숫자값으로 문자열의 소문자만 추출.(97~122 사이의 아스키값)
        if(ch[i] >= 97 && ch[i] <= 122){
            rech[j] = ch[i];
            j++; 
        }
    }
    n = strlen(rech); //rech의 문자열 길이로 초기화.
    
    for(i = 0; i<n; i++) {
        push(&s,rech[i]);
    }

    for(i = 0; i<n; i++) {
        temp[i] = pop(&s);
        if(rech[i] != temp[i]){
            return 1; //회문 아닐경우 1반환.
        }
    }

    return 0; //함수 정상종료(회문일 경우.)
}

int main(void){
    StackType s;

    char *str;
    str = (char *)malloc(sizeof(char) *50);

    printf("문자열을 입력하세요 : ");
    scanf("%[^\n]",str);//엔터를 칠때까지 모든 내용을 입력받음.

    if(check(str) == 0){
        printf("%s는 회문입니다.",str);
    }
    else {
        printf("%s는 회문이 아닙니다.",str);
    }

    free(str);
    return 0;
}

//Madam, I'm Adam.