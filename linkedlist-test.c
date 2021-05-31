#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct _ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void error(char *message) {
    fprintf(stderr,"%s\n",message);
    exit(1);
}

ListNode* insert_first(ListNode *head, int value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p -> data = value;
    p -> link = head;
    head = p;
    return head; //반환은 항상 삽입한 노드가 아니라 리스트전체의 시작점인
    //헤드포인터값을 반환하게된다. 삭제 삽입 모두 동일해당. 
}

ListNode* insert(ListNode* head, ListNode *pre, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p -> data = value;
    p -> link = pre -> link;
    pre -> link = p;
    return head;
}

ListNode *delete_first(ListNode *head) {
    ListNode *remove;
    if(head == NULL) {
        return NULL;
    }
    remove = head;
    head = remove -> link;

    free(remove);

    return head;
}

ListNode *delete(ListNode *head, ListNode *pre) {
    ListNode *remove;
    remove = pre -> link;
    pre -> link = remove -> link;

    free(remove);

    return head;
}

void print_list(ListNode *head) {
    ListNode *p;
    for(p = head; p!=NULL; p -> link) {
        printf("%d->", p -> data);
    } //반복해서 리스트의 끝가지 출력함.
    printf("NULL \n");
}

int main(void) {
    ListNode *head = NULL;
    int i;
    for(i=0; i<5; i++){
        head = insert_first(head,i);
        print_list(head);
    }

    for(i=0; i<5; i++) {
        head = delete_first(head);
        print_list(head);
    }

    return 0;
}