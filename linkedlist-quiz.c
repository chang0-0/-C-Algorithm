#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct Node *link;
} ListNode;  

ListNode *insertfirst(ListNode *head, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));

    p -> data = value;
    p -> link = head;
    head = p;

    return head;
}

ListNode *insertAfter(ListNode *head, ListNode *pre, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));

    p -> data = value;
    p -> link = pre -> link;
    pre -> link = p;

}

void print_list(ListNode *p) {

}

int main(void) {

    return 0;
}