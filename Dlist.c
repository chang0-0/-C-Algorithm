#include <stdio.h>
#include <stdlib.h>

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
     for(p = phead -> rlink; p != phead; p = p->rlink) {
         printf("<-| |%d| |-> ", p -> data);
     }
     printf("\n");
 }

 //새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(DLisNode *before, element data) {
    DLisNode *newnode = (DLisNode *)malloc(sizeof(DLisNode));
    newnode -> data = data;
    newnode -> llink = before;
    newnode -> rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

//노드 removed를 삭제한다.
void ddelete(DLisNode* head, DLisNode* removed){
    if(removed == head) {
        return ;
    }

    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

//이중 연결 리스트 테스트 프로그램
int main(void) {
    DLisNode* head = (DLisNode *)malloc(sizeof(DLisNode));
    init(head);

    printf("추가단계 \n");
    for (int i = 0; i < 5; i++){
        //헤드 노드의 오른쪽에 삽입
        dinsert(head, i);
        print_dlist(head);
    }   

    printf("삭제단계 \n");
    for (int i = 0; i < 5; i++){
        print_dlist(head);
        ddelete(head, head->rlink);
    }

    free(head);  
    return 0;
}