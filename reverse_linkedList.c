#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { //노드 타입
    element data;
    struct ListNode *link;
} ListNode;

ListNode *insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p -> data = value;
    p -> link = head;
    head = p;
    return head;
}

void print_list(ListNode *head) {
    ListNode *p;
    for(p = head; p != NULL; p = p -> link) {
        printf("%d->", p -> data);
    }
    printf("NULL \n");
}

ListNode* reverse(ListNode *head) {
    //순회 포인터로 p,q,r을 사용
    ListNode *p, *q, *r;

    p = head; //p는 역순으로 만들 리스트
    q = NULL; //q는 역순으로 만들 노드
    while(p != NULL) {
        r = q; //r은 역순으로 된 리스트.
               //r은 q, q는 p를 차례로 따라간다.
        q = p;

        p = p -> link;
        q -> link = r; 
    }
    return q;
}

/*p를 한번식 head내용 그대로 없애면서 반복함.
p = 10 -> 20 -> 30 이므로 총 3번 반복 하게된다.
    r은 p의 리스트내용을 q에 거꾸로 넘겨주기 위해 r은 다리역할 및 저장소 역할을 하게됨.
    q => r => p => r => q
    p는 줄어들지만 r은 늘어나게 된다

    알고리즘 돌아가는 순서.
    1. p가 만들어진 List의 head 포인터 값을 가지게 되면서
    q는 p의 값으로 q = (10|link) 이 된다. 이제 p->link는 20|link이므로 p = p -> link 코드로 p는 10의 값이
    자동으로 없어지고 p는   (20|link -> 30|link -> null)     이돤다.
    결과 : q = [10|link -> 20|link -> 30|link -> null] 이 됨.

    2.
    다음 r = q 코드에서 q = 10|link이므로 r = 10|link 가 된다.
    q = p 코드에서 p는 전에 20|link 로 됬으므로,
    q  = 20 | link 가 됨 다음코드 p = p -> link 에서 p가 20|link이므로 p -> link는 30이 된다.
    그래서 p = 30|link -> null 이됨.
    q -> link = r에서 r은 10|link였으므로 q -> link = 10이 돤다.
    q의 값은 [20|link -> 10|link -> null] 이 된다.

    3.
    다음 순서대로 계속 반복해서
    q의 값은 30|link -> 20|link -> 10|link -> null 이 된다.

*/
int main(void) {
    ListNode* head1 = NULL;
    ListNode *head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = reverse(head1);
    print_list(head2);

    return 0;
}