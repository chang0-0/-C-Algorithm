#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void init_list(ListNode *p) {

}

ListNode *insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));

    p -> data = value;
    p -> link = head;
    head = p;
    return head; //헤드 포인터를 반환 head 노드가 있는 주소값을 전달함.
} //리스트의 첫번째에 노드 삽입

void print_list(ListNode *p) {

    while(p != NULL) {
        printf("%d -> ",p -> data);
        p = p -> link;
    }
    printf("NULL \n");
}

//헤드 연결함수
ListNode *concate_List(ListNode *head1, ListNode *head2) {
    if(head1 == NULL) {
        return head2;
    }
    else if(head2 == NULL) {
        return head1;
    }
    else {
        ListNode *p;
        p = head1; //새로운 헤드포인터에 head1의 주소를 받음
        while(p -> link != NULL) {
            p = p -> link; //p의 노드가 마지막 노드가 될때까지 끝까지 반복함
        }
        p -> link = head2; //head1의 마지막 노드의 링크가 head2의 포인터를 향하게함'
        return head1;
    }
}

int main(void) {
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);    
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = insert_first(head2, 70);
    head2 = insert_first(head2, 80);
    print_list(head2);

    ListNode *total = NULL;
    total = concate_List(head1, head2);
    print_list(total);

    free(head2);
    free(head1);

    return 0;
}