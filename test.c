#include <stdio.h>
#include <stdlib.h>
 
typedef int element;
 
typedef struct Node {
  element data;
  struct Node *link;
} Node;
 
// Node* createNode(element data);
// void appendNode(Node **head, Node *newNode); 
// Node* getNodeAt(Node *head, int location); 
// int getNodeCount(Node *head); 
 
// void insertBefore(Node **head, Node *current, Node *newHead);
// void deleteAllNodes(Node **list);
 
//노드 자체를 새로 만들어 내는 함수.
Node* createNode(element data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) 
  {
    fprintf(stderr, "동적할당 실패\n");
    exit(EXIT_FAILURE); 
  }

  newNode->data = data;
  newNode->link = NULL;
  return newNode;
}
 
//노드를 삽입할때 헤드부터 꼬리를 찾아서 뒤에다가 노드를 삽입함.
void appendNode(Node **head, Node *newNode) {
  if ((*head) == NULL) 
    *head = newNode;
  else
  { 
    Node *tail = (*head);
    while (tail->link != NULL)
    {
      tail = tail->link;
    }
    tail->link = newNode;
  }
}
 
Node* getNodeAt(Node *head, int location)
{
  Node *current = head;
  while (current != NULL && (--location) >= 0)
  {
    current = current->link;
  }
  return current;
}
 
int getNodeCount(Node *head)
{
  int count = 0;
  Node *current = head;
 
  while (current != NULL)
  {
    count++;
    current = current->link;
  }
 
  return count;
}

//특정 노드사이에 노드를 삽입하는 함수.
void insertBefore(Node **head, Node *current, Node *newHead)
{
  Node *prev = NULL;
 
  Node *now = *head;
 
  if (now == NULL) {
    fprintf(stderr, "잘못 사용하셨습니다. 비어있는 리스트입니다.\n");
    return;
  }
 
 
  else if (now->link == NULL) {
    if (now == current) { 
      newHead->link = *head; 
      *head = newHead;
      return; 
    }
  }
 
  while (now->link != NULL)
  {
    prev = now; 
    now = now->link; 
     
    // 만약 내가 찾던 노드가 now가 맞다면 while문 탈출
    if (now == current)
      break;
  }

  newHead->link = now;
  prev->link = newHead;
}
 
void deleteAllNodes(Node **list)
{

  Node *current = *list;
 
  Node *next = current->link;
  if (next == NULL)
  {

    free(current);
    return;
  }
 
  while (next != NULL) 
  {
    free(current); 
    current = next; 
    next = next->link;
  }
 
  free(current);
} 

//메인 함수.
void main(){
  int i = 0;
  int count = 0; 
  Node *list, *current, *newNode;
  //*list는 곧 head임

  //초기는 모두 NULL로 설정.
  list = current = newNode = NULL; 
  
  //반복문을 통해서 새로운 노드를 5개만들어냄.
  //노드1개를 만들고 appendNode함수 실행
  for (i = 0; i < 5; i++) {
    newNode = createNode(i); 
    appendNode(&list, newNode);
  }
 
  count = getNodeCount(list);
  for (i = 0; i < count; i++) {
    current = getNodeAt(list, i);
    printf("list[%d]: %d\n", i, current->data);
  }
 
  printf("\nTest inputBefore()...\n");
 
 //원하는 위치에 노드 삽입
  while (1) { 
    printf("\nInput node index what you want to find\n");
    printf("\n입력한 위치 바로 전에 새로운 노드가 삽입됩니다.\n");
 
    scanf("%d", &i);
    current = getNodeAt(list, i);
 
    if (current != NULL)
      break;
  }
 
  newNode = createNode(2500);
 
  insertBefore(&list, current, newNode);
 
  count = getNodeCount(list);
  for (i = 0; i < count; i++)
  {
    current = getNodeAt(list, i);
    printf("list[%d]: %d\n", i, current->data);
  }
 
  printf("\nTest deleteAllNodes()...\n");
  deleteAllNodes(&list);
}