#include <stdio.h>

typedef int element;
typedef struct DLisNode { //이중연결 노드 타입
    element data;
    struct DLisNode* llink;
    struct DLisNode* rlink;
} DLisNode;

void init(DLisNode* phead) {
    phead -> llink = phead;
    phead -> rlink = phead;
}

//이중 연결 리스트의 노드를 출력
void print_dlist(DLisNode* phead) {
    DLisNode* p;
    for(p = phead -> rlink; p!= phead; p = p -> rlink){
        printf("<-| |%d| |-> ",p -> data);
    }
    printf("\n");
}

//새로운 데이터를 노드 before의 오른쪽에 삽입한다.
int main(void) {
    DLisNode* head = (DLisNode *)malloc(sizeof(DLisNode));
    init(head);

    printf("추가단계 \n");
    for(int i=0; i<5; i++) {
        //헤드 노드의 오른쪽에 삽입
        dinsert(head, i);
        print_dlist(head);
    }

    printf("삭제단계 \n");
    for(int i=0; i<5; i++){
        printf_dlist(head);
    }

    return 0;
}