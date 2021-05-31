#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct _ListNode { //노드 타입
    element data;
    struct ListNode *link;
} ListNode;

ListNode* insert_first(ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    strcpy(node -> data, data);
    if(head == NULL) {
        head = node;
        node -> link = head;
    }
    else {
        node -> link = head -> link;
        head -> link = node;
    }
    return head; //변경된 헤드 포인터를 반환한다.
}

//원형 연결 리스트 테스트 프로그램
int main(void) {
    ListNode *head = NULL;

    head = insert_first(head, "KIM");
    head = insert_first(head, "PARK");
    head = insert_first(head, "CHOI");

    ListNode *p = head;
    for(int i=0; i < 10; i++) {
        printf("현재 차례=%s \n", p -> data);
        p = p -> link;
    }

    //KIM을 한번만 넣었을 경우 반복해서 10번동안 KIM이 나오게됨.
    //node -> link 는 head를 가르키면서 계속해서 자기자신을 가르킴
    return 0;
}