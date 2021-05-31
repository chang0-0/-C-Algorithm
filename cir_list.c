#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

//리스트의 항목 출력
void print_list(ListNode* head) {
    ListNode* p;

    if(head == NULL) {
        return ;
    }
    p = head->link;
    do{
        printf("%d->", p->data);
        p = p -> link;
    } while (p != head);
    printf("%d->", p -> data); //마지막 노드 출력
}

ListNode* insert_first(ListNode* head, element data) {//리스트의 가장 앞에 데이터를 삽입.
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node -> data = data;
    if(head == NULL) {
        head = node;
        node -> link = head;
    }
    else {
        node -> link = head -> link;
        head -> link = node;
    }
    return head;
}

ListNode* insert_last(ListNode* head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node -> data = data;
    if(head == NULL) { // 처음 노드가 생성됬을때 head는 포인터주소를 넣는 공간
        head = node; // 배열처럼 노드가 할당된 시작 주소를 head에 넣음
        node -> link = head; // 생성된 노드의 링크(포인터일듯?)에 생성된 위에꺼 시작주소를 저장
    }
    else { // head가 NULL이 아닐때 즉 노드생성이 두번째부터일때
        node -> link = head -> link; //(1) //새로운 노드의 링크에 그전의 노드의 주소를 담음
        head -> link = node; //(2) // 그전에 생성된 노드의 링크를 현재 생성된 노드의 주소를 담음 이로써 원형연결리스트가 됨
        head = node; //(3)  //헤드는 새로 생성된 노드를 가르킴
    }
    return head; //변경된 헤드 포인터를 반환한다.
}

//원형 연결 리스트 테스트 프로그램
int main(void) {
    ListNode *head = NULL;

    //list = 10 -> 20 -> 30 -> 40
    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    head = insert_first(head, 10);
    print_list(head);
    return 0;
}