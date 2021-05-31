#include <stdio.h>
#include <stdlib.h>

typedef struct _ListNode { //노드타입
    int coef; //coeficient : 계수
    int expon; //exponent : 지수
    struct ListNode *link;
}ListNode;

//연결 리스트 헤더
typedef struct _ListType { //리스트 헤더 타입
    int size;
    ListNode *head;
    ListNode *tail;
}ListType;

//오류함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//리스트 헤더 생성 함수
ListType* create() {
    ListType *plist = (ListType *)malloc(sizeof(ListType)); //크기가 변하는 리스트를 표현하기위해 동적메모리를 할당.
    plist -> size = 0; //초기 사이즈 0으로 초기화
    plist->head = plist->tail = NULL; //리스트와 헤드값 모두 NULL값으로 초기화.
    return plist;
}

//plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수,
//expon는 지수
void insert_last(ListType *plist, int coef, int expon) {
    ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
    if(temp == NULL) {
        error("메모리 할당 에러");
    }

    temp -> coef = coef;
    temp -> expon = expon;
    temp -> link = NULL;

    if(plist -> tail == NULL) {
        plist -> head = plist -> tail = temp;
    }
    else {
        plist -> tail -> link = temp;
        plist -> tail = temp;
    }
    plist -> size ++;
}

//list3 = list1 + list2
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) { //a의 차수 > b의 차수
    ListNode* a = plist1 -> head; 
    ListNode* b = plist2 -> head;
    int sum;

    while(a && b) { //AND 연산자.(a and b = a 와 b둘다 참일경우 반복.)
        if(a -> expon == b -> expon) { //조건문 a의 지수와 b의 지수가 같으면 sum의 변수에 a의 계수와 b의 계수를 더한값을 넣어라.
            sum = a->coef + b->coef; 
            if(sum != 0) { //만약 더한 sum의 값이 0이 아니면 plist3에 sum값은 계수자리에 넣어주고, 지수는 그대로 가져옴.
                insert_last(plist3, sum, a -> expon); 
            }
            a = a -> link; //링크가 NULL인지 왜 검사안함?
            b = b -> link;
        }
        else if(a -> expon > b -> expon) { //a의 차수 == b의 차수
            insert_last(plist3, a -> coef, a -> expon);
            a = a->link;
        }
        else {
            insert_last(plist3, b -> coef, b -> expon);
            b = b->link;
        }
    }
  
    //a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두 결과 다항식으로 복사
    for(; a!=NULL; a = a -> link) {
        insert_last(plist3, a->coef, a->expon);
    }
    for(; b != NULL; b = b -> link) {
        insert_last(plist3, b -> coef, b -> expon);
    }
}  

void poly_print(ListType* plist) {
    ListNode* p = plist -> head;

    printf("polynomial = ");
    for(; p; p = p -> link) {
        printf("%d^%d + ", p -> coef, p ->expon);
    }
    printf("\n");
}

int main(void) {
    ListType *list1, *list2, *list3;

    //연결 리스트 헤더 생성
    list1 = create();
    list2 = create();
    list3 = create();

    //다항식 1을 생성
    insert_last(list1, 3, 12);
    insert_last(list1, 2, 8);
    insert_last(list1, 1, 0);

    //다항식 2를 생성
    insert_last(list2, 8, 12);
    insert_last(list2, -3, 10);
    insert_last(list2, 10, 6);

    poly_print(list1);
    poly_print(list2);

    //다항식3 = 다항식1 + 다항식 2
    poly_add(list1, list2, list3);
    poly_print(list3);

    free(list1); 
    free(list2);
    free(list3);

    return 0;
}