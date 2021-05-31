#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode n11 = {11, NULL, NULL}; 
TreeNode n10 = {9, NULL, NULL};
TreeNode n9 = {3, NULL, NULL};
TreeNode n8 = {1, NULL, NULL};
TreeNode n7 = {10, &n10, &n11};
TreeNode n6 = {7, NULL, NULL};
TreeNode n5 = {5, NULL, NULL};
TreeNode n4 = {2, &n8, &n9 };
TreeNode n3 = {8, &n6, &n7 };
TreeNode n2 = {4, &n4, &n5 };
TreeNode n1 = {6, &n2, &n3 };

TreeNode *root = &n1;

int sum = 0;
int count = 0;

//중위 순회
int inorder(TreeNode *root) {
    if(root != NULL) {
        sum += root -> data;
        inorder(root -> left);  //왼쪽 서브트리 순회
        printf("[%d] ", root -> data); //노드 방문
        inorder(root -> right); //오른쪽 서브트리 순회

        if(root -> left == NULL) {
            count ++;
        }
        else if(root -> right == NULL) {
            count ++;
        }
    }

    return sum;
}

//전위 순회
void preorder(TreeNode *root) {
    if(root != NULL) {
        printf("[%d] ", root -> data); //노드 방문
        preorder(root -> left);         //왼쪽 서브트리 순회
        preorder(root -> right);        //오른쪽 서브트리 순회


        
    }
}

//후위 순회
void postorder(TreeNode *root) {
    if(root != NULL) {
       postorder(root -> left);       // 왼쪽 서브트리 순회
       postorder(root -> right);      // 오른쪽 서브트리 순회
       printf("[%d] ", root -> data); //노드 방문

    }
}

int max(int a, int b) {
    if(a == b) {
        return a;
    }
    else if(a > b) {
        return a;
    }
    else {
        return b;
    }
}

int min(int a, int b) {
    if(a == b) {
        return a;
    }
    else if(a > b) {
        return b;
    }
    else if(a < b){
        return a;
    }
}

int max_mystery(TreeNode *p) {
    if(p == NULL) {
        return 0;
    }
    else if(p -> left == NULL && p->right == NULL) {
        return p -> data;
    }
    else {
        return max(max_mystery(p->left), max_mystery(p->right));
    }
}

int min_mystery(TreeNode *p) {
    if(p == NULL) {
        return 0;
    }
    else if(p -> left == NULL && p->right == NULL) {
        return p -> data;
    }
    else {
        return min(min_mystery(p->left), min_mystery(p->right));
    }
}

int main(void) {
    printf("중위 순회=");
    int sum = inorder(root);
    printf("\n");

    printf("전위 순회=");
    preorder(root);
    printf("\n");

    printf("후위 순회=");
    postorder(root);
    printf("\n트리전체 합 = %d", sum);
    printf("\n");

    int max = max_mystery(root);
    printf("트리의 최대값 = %d",max);

    int min = min_mystery(root);
    printf("\n트리의 최솟값 = %d",min);

    printf("단말 노드의 갯수 = %d ", count);
    return 0;
}
