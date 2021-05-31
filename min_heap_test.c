#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct _element{
    int key;
} element;

typedef struct HeapType {
    element heap[MAX];
    int heap_size;
} HeapType;

//생성함수
HeapType *create() {
    return (HeapType *)malloc(sizeof(HeapType));
}

//초기화 함수
void init(HeapType *h) {
    h -> heap_size = 0;
}

//현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
//삽입함수
void insert_min_heap(HeapType *h, element item) {
    int i;
    i = ++(h -> heap_size);

    //트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while((i != 1) && (item.key < h -> heap[i/2].key)) {
        h -> heap[i] = h->heap[i/2];
        i /= 2;
    }
    h -> heap[i] = item; //새로운 노드를 삽입
}

//삭제 함수
element delete_min_heap(HeapType *h) {
    int parent, child;
    element item, temp;

    item = h -> heap[1];
    temp = h -> heap[(h -> heap_size)--];
    parent = 1;
    child = 2;

    while(child <= h -> heap_size) {
        //현재 노드의 자식노드 중 더큰 자식노드를 찾는다.
        if((child < h -> heap_size) && (h -> heap[child].key > h -> heap[child + 1].key)) {
            child ++;
        }

        if(temp.key <= h -> heap[child].key) {
            break;
        }

        h -> heap[parent] = h -> heap[child];
        parent = child;
        child *= 2;
    }
    h -> heap[parent] = temp;
    return item;
}

//특정 숫자를 삭제함.
element delete_some_heap(HeapType *h, element el) {
	int p, c;
    element item;
	for(int i = 1; i <= h->heap_size; i++)
		if (h -> heap[i].key == el.key) {
			p = i;
			c = 2 * i;
			break;
		}

	item.key = h -> heap[p].key;
    int temp = h->heap[(h->heap_size)--].key;
	while (c <= h->heap_size) {
		if ((c < h->heap_size) && (h->heap[c].key < h->heap[c + 1].key))
			c++;
		if (temp >= h->heap[c].key)
			break;
		h->heap[p] = h->heap[c];
		p = c;
		c *= 2;
	}
	h->heap[p].key = temp;
	return item;
}

int main(void) {
    element e1 = {10} , e2 = {5}, e3 = {30};

    element e4, e5, e6;
    HeapType *heap;

    heap = create(); //히프 생성
    init(heap);      //히프 초기화

    //삽입
    insert_min_heap(heap, e1);
    insert_min_heap(heap, e2);
    insert_min_heap(heap, e3);

    // element e9 = {56};
    // delete_some_heap(heap,e9);

    //삭제
    e4 = delete_min_heap(heap);
    printf("< %d > ", e4.key);
    e5 = delete_min_heap(heap);
    printf("< %d > ", e5.key);
    e6 = delete_min_heap(heap);
    printf("< %d > ", e6.key);

    free(heap);
    return 0;
}