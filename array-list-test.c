#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100

typedef int element;

typedef struct _ArrayList {
    element array[MAX_LIST_SIZE];
    int size;
}ArrayList;

void error(char *message) {
    fprintf(stderr,"%s",message);
    exit(1);
}

//리스트 초기화 함수
void init(ArrayList *L) {
    L -> size = 0;
}
//리스트가 비어 있으면 1을 반환
//그렇지 않으면 0을 반환

int is_empty(ArrayList *L) {
    return L -> size == 0;  //배열 개념이기 때문에 size 값이 0임
}

int is_full(ArrayList *L) { 
    return L -> size == MAX_LIST_SIZE;
}

element get_entry(ArrayList *L, int pos) {
    if(pos < 0 || pos >= L -> size) {   
        error("위치 오류");  //pos는 포지션을 의미함
    }                       //pos가 0보다 작거나 L의 size보다 크면 오류가발생함
    return L -> array[pos]; //오류가 없을경우 원하는 position 값의 인덱스에 있는 배열의 값을 반환홤
}

//리스트 출력
void print_list(ArrayList *L) { 
    int i;
    for(i = 0; i< L -> size; i++) {
        printf("%d -> ",L -> array[i]);
    }
    printf("\n");
}

element delete(ArrayList *L, int pos) {
    element item;

    if(pos < 0 || pos >= L -> size){
        error("위치 오류");
    }
    item = L -> array[pos];
    int i;
    for(i = pos; i<(L->size -1); i++) {
        L -> array[i] = L -> array[i + 1];
        //여기서 핵심은 입력한 인덱스값부터 전제 사이즈의 한개를 빼고
    } //실제 데이터를 삭제한다는 개념보다는
    //데이터를 한칸씩 당겨서 원래 있던 배열의 인덱스 값들을 바꾼다는 개념.
    L -> size --;
    return item;
}

void insert(ArrayList *L, int pos, element item) {
    if(!is_full(L) && (pos >= 0) && (pos <= L -> size)) {
        int i;
        for(i = (L->size - 1); i >= pos; i--) { //첫번째 배열에 비어있을때를 방지하기 위해 -1을 해줌
            L -> array[i + 1] = L -> array[i];
            //가장뒤에 있는거부터 뒤로 밀어야 하기 때문에 반복문을 감소로 돌아가게함
        }
        //무조건 돌게 되는 공간
        L -> array[pos] = item;
        L -> size ++;
    }
}

void insert_start(ArrayList *L, element item) {
   if (!is_full(L)) {
      int i;
      for (i = (L->size-1); i >= 0; i--) {
         L->array[i + 1] = L->array[i];
      }
   }
   L->array[0] = item;
   L->size++;
}


void insert_last(ArrayList *L, element item) {
    if(L -> size >= MAX_LIST_SIZE){
        error("리스트 오버플로우");
    }
    L -> array[L -> size ++] = item;
}

//함수 추가
void clear(ArrayList *L) {
    init(L);
    printf("리스트 초기화됨 \n");
}

int replace(ArrayList *L,int pos, element item) { //배열 개념이기때문에 포지션값에 -1해줘야됨 0부터 시작.
    L -> array[pos] = item;
    return 0;
}

int get_length(ArrayList *L) {
    return L -> size;
}


int main(void) {
    //ArrayListType을 정적으로 생성하고 ArrayListType을 가리키는 포인터를
    //함수의 매개변수로 전달한다.
    ArrayList list;

    init(&list);
    insert(&list, 0, 10); print_list(&list); //0번째 위치에 10추가
    insert(&list, 0, 20); print_list(&list); //0번째 위치에 20추가
    insert(&list, 0, 30); print_list(&list); //0번째 위치에 30추가
    replace(&list,1,70);

    int a = list.size;
    printf("현재 사이즈 : %d \n",a);

    insert_start(&list, 50); print_list(&list);

    insert_last(&list, 40); print_list(&list); //맨끝에 40추가
    
    delete(&list, 0); print_list(&list);//0번째 항목 삭제

    //clear(&list); print_list(&list);

    return 0;
}
