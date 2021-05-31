#include <stdio.h>
#include <stdlib.h>
//단순 연결리스트는 헤드 포인터만 있으면 된다.

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct ListNode { //노드 타입
    element data;
    struct ListNode *link;
} ListNode;

//오류 처리함수
void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode *head, int value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
    p -> data = value; //(2)
    p -> link = head; //헤드 포인터의 값을 복사 (3)
    head = p; //헤드 포인터 변경 (4)
    return head; //변경된 헤드 포인터 반환
}

//포인터의 개념잡는게 매우 중요 포인터변수는 변수의 주소를담는개념임
//★★★★★포인터 변수의 주소를 주는게 아님.(진짜 매우 중요)★★★★
//p -> link = head 는 head에 담긴 앞에 있는 노드의 주소를 넘겨줌
//p -> link는 전의 노드를 가리키게 되고 다음코드에서
//head = p가 되서 p의 주소를 다시 head에 담으므로
//리스트의 시작점이 p가 됨.

//노드 pre뒤에 새로운 노드 삽입
ListNode* insert(ListNode *head, ListNode *pre, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
    p -> data = value; //(2)
    p -> link = pre -> link; //(3)
    pre -> link = p; //(4)
    return head; //(5)
}

ListNode* delete_first(ListNode *head){
    ListNode *removed;
    if(head == NULL) {
        return NULL;
    }
    removed = head;
    head = removed -> link;

    free(removed);

    return head;
}

//pre가 가리키는 노드의 다음 노드를 삭제한다
ListNode *delete(ListNode *head, ListNode *pre){
    ListNode *removed;
    removed = pre -> link;
    pre -> link = removed -> link;

    free(removed);

    return head;
}

void print_list(ListNode *head) {
    ListNode *p;
    for(p = head; p!= NULL; p = p -> link) {
        printf("%d->", p->data);
    }
    printf("NULL \n");
}

//테스트 프로그램
int main(void){
    ListNode *head = NULL;
    int i;
    for(i = 0; i< 5; i++){
        head = insert_first(head, i);
        print_list(head);
    }

    for(i = 0; i< 5; i++){
        head = delete_first(head);
        print_list(head);
    }

    return 0;
}
