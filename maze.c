#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {
    short r;
    short c;
} element;

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

element here = {1,0}, entry = {1,0};

//2차원 배열
char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'},
};

//위치를 스택에 삽입
void push_loc(StackType *s, int r, int c) {
    if(r < 0 || c < 0 ) {
        return ;
    }
    if(maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

//미로를 화면에 출력한다.
void maze_printf(char maze[MAZE_SIZE][MAZE_SIZE]) {
    printf("\n");
    for(int r = 0; r < MAZE_SIZE; r++){
       for(int c = 0; c < MAZE_SIZE; c++){
           printf("%c", maze[r][c]);
       }
       printf("\n");
    }
}

int main(void){
    int r,c;
    StackType s;

    init_stack(&s);
    here = entry;
    while (maze[here.r][here.c] != 'x') { //현재위치가 출구가 아니면 계속해서 반복함.
        r = here.r;
        c = here.c;
        maze[r][c] = '.'; //방문했던곳은 .을 찍어서 표시를 함.
        maze_printf(maze);
        push_loc(&s, r - 1, c); //위
        push_loc(&s, r + 1, c); //아래
        push_loc(&s, r, c - 1); //왼쪽
        push_loc(&s, r, c + 1); //오른쪽
        if (is_empty(&s)){
            printf("실패\n");
            return;
        }
        else 
            here = pop(&s);
        
    }
    printf("성공\n");
    return 0;
}


