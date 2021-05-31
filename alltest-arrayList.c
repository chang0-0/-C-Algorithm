#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { //노드타입
    element data;
    struct ListNode *link;
} ListNode;

//오류 처리 함수
void error(char *message) {
    fprintf(stderr, "%s \n",message);
    exit(1);
}

ListNode *insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p -> data = value;
    p -> link = head;
    head = p;
    return head;
}

ListNode *insert(ListNode *head, ListNode *pre, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
    p -> data = value;                                  //(2)
    p -> link = pre -> link;                            //(3)
    pre -> link = p;                                    //(4)
    return head;                                        //(5)
}

int main(void) {

    return 0;
}