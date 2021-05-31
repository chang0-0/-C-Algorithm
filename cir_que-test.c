#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5 //큐 사이즈.

typedef int element;
typedef struct _QUEUE {
    element data[MAX_QUEUE_SIZE];
    int rear;
    int front;
}Queue;

void error(char *message) {
    fprintf(stderr,"%s\n", message);
    exit(1);
}

void init_queue(Queue *q) {
    //원형 큐는 초기값이 0
    q -> front = 0;
    q -> rear = 0;
}

//공백 상태 검출함수.
int is_empty(Queue *q) {
    return (q -> front == q -> rear);
}

//포화상태 검출 함수.
int is_full(Queue *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q -> front);
}

void queue_print(Queue *q){
    printf("QUEQUE(front=%d rear=%d) = ", q -> front, q->rear);
    if(!is_empty(q)){ //큐가 비어있지 않으면.
        //i는 큐의 front 값으로 초기화.
        //기존 원형큐의 do-while문을 일반 while문으로 고침.
        int i = (q -> front + 1) % MAX_QUEUE_SIZE;
        while(i != q -> front){
            printf("%d  | ", q -> data[i]); //2번째 큐출력 안되고 1번째 데이터 무한반복 출력 오류 발생.
            if(i == q -> rear){
                break;            
            }
        }
    }
    printf("\n");
}

//큐 삽입함수
void enqueue(Queue *q, element item) {
    if(is_full(q)) {
        error("큐가 포화상태 입니다.");
    }
    q -> rear = (q -> rear + 1) % MAX_QUEUE_SIZE; //MAX 상수의 나머지값이 rear가 되서 4이상으로 넘어가지않고 계속 증가만함.
    q -> data[q->rear] = item;
}

//큐 삭제함수
element dequeue(Queue *q){
    if(is_empty(q)){
        error("큐가 공백상태 입니다.");
    }
    return q -> data[(q -> front +1) % MAX_QUEUE_SIZE]; //front도 증가하되 5를 넘지않도록 5와 나눈 나머지값으로 수정.
}

int main(void) {
    Queue q;
    int element;

    init_queue(&q);
    printf("--데이터 추가 단계 --\n");
    while(!is_full(&q)) {
        printf("정수를 입력하시오: ");
        scanf("%d", &element);
        enqueue(&q, element);
        queue_print(&q);
    }
    printf("큐는 포화상태 입니다. \n\n"); //무한루프

    printf("--데이터 삭제 단계 --\n");
    while(!is_empty(&q)){
        element = dequeue(&q);
        printf("꺼내진 정수 : %d \n", element);
        queue_print(&q);
    }
    printf("큐는 공백상태입니다.");
    
    return 0;
}


