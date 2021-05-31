#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct _QueueType{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

//오류함수
void error(char *message) {
    fprintf(stderr,"%s\n", message);
    exit(1);
}

//공백 상태 검출 함수
void init_queue(QueueType *q){
    q -> front = q -> rear = 0;
}

//공백 상태 검출 함수
int is_empty(QueueType *q){
    return (q->front == q->rear);
}

//포화 상태 검출 함수
int is_full(QueueType *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q -> front);
}

//원형큐 출력 함수.
void queue_print(QueueType *q) {
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!is_empty(q)){
        int i = q -> front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if(i == q -> rear) {
                break;
            }
        } while (i != q -> front);
    }
    printf("\n");
}

//삽입 함수
void enqueue(QueueType *q, element item) {
    if(is_full(q)) {
        error("큐가 포화상태 입니다.");
    }
    q -> rear = (q -> rear +1) % MAX_QUEUE_SIZE;
    q -> data[q->rear] = item;
}

//삭제 함수
element dequeue(QueueType *q) {
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

//무삭제 추출함수
element peek(QueueType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    }
    return q -> data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void) {
    QueueType queue;
    int element;

    init_queue(&queue); 
    srand(time(NULL));

    int i;
    for(i=0;i<100;i++) { 
        int a = rand();
        int b=0;
        if(a % 5 == 0) { //5로 나누어 떨어지면
            printf("enque if 조건 충족한수 : %d\n",a);
            b = rand() % 100;
            printf("큐에 들어간수 : %1d\n",b);
            enqueue(&queue, b);
        }
        else {
            printf("enque if 조건 충족하지못한수 : %d\n",a);
            queue_print(&queue);
        }
        int r = rand();
        if(r % 10 == 0) { //10으로 나누어 떨어지면
            printf("deque if조건 충족한수 : %d\n",r);
            int data = dequeue(&queue);
        }
        else {
            printf("deque if조건 불충족한수 : %d\n",r);
            queue_print(&queue);
        }
    }
    return 0;
}