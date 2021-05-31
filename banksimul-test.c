#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int arrival_time;
    int service_time;
} element;

#define MAX_QUEUE_SIZE 5
typedef struct _QueueType {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} _QueueType;

void error(char *message) {
    fprintf(stderr,"%s \n",message);
    exit(1);
}

//오류함수
void init_queue(_QueueType *q) {
    q -> front = q -> rear = 0;
}

//공백 상태 검출 함수
int is_empty(_QueueType *q) {
    return (q->front == q -> rear);
}

int is_full(_QueueType *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q -> front);
}

//원형큐 출력 함수
void queue_print(_QueueType *q) {
    printf("QUEUE(fornt=%d rear=%d) = ", q -> front, q -> rear);
    if(!is_empty(q)) {
        int i = q -> front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q -> data[i]);
            if() {
                
            }
        }
    }
}

//포화 상태 검출 함수


int main(void) {

    return 0;
}