// 特性：左子树 < 根 < 右子树
#include<stdio.h>
#include<stdlib.h>

//节点
typedef struct BSTNode{
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

//插入
BSTNode* insertBST(BSTNode** T,int data){
    if(*T==NULL){
        *T = (BSTNode*)malloc(sizeof(BSTNode));
        (*T)->data=data;
        (*T)->left = (*T)->right = NULL;
        return *T;
    }
    if(data<(*T)->data){
        return insertBST(&(*T)->left, data);
    } else if (data > (*T)->data) {
        return insertBST(&(*T)->right, data);
    } else {
        return *T; 
    }
}

//查找
BSTNode* searchBST(BSTNode* T, int data) {
    if (T == NULL || T->data == data) {
        return T;
    }
    if (data < T->data) {
        return searchBST(T->left, data);
    } else {
        return searchBST(T->right, data);
    }
}

//删除
BSTNode* deleteBST(BSTNode** T, int data) {
    if (*T == NULL) {
        return NULL;
    }
    if (data < (*T)->data) {
        (*T)->left = deleteBST(&(*T)->left, data);
    } else if (data > (*T)->data) {
        (*T)->right = deleteBST(&(*T)->right, data);
    } else {
        if ((*T)->left == NULL) {
            BSTNode* temp = (*T)->right;
            free(*T);
            return temp;
        }
        else if ((*T)->right == NULL) {
            BSTNode* temp = (*T)->left;
            free(*T);
            return temp;
        }
        else {
            BSTNode* temp = (*T)->right;
            while (temp->left != NULL) {
                temp = temp->left;
            };
            (*T)->data = temp->data;  
            (*T)->right = deleteBST(&(*T)->right, temp->data);
        }
    }
    return *T;
}

// 中序遍历
void inOrder(struct BSTNode* root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// 创建
BSTNode* createBST(int arr[], int n) {
    BSTNode* root = NULL;
    for (int i = 0; i < n; i++) {
        insertBST(&root, arr[i]);
    }
    return root;
}

int main() {
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 创建二叉排序树
    BSTNode* root = createBST(arr, n);

    // 中序遍历
    printf("中序遍历结果: ");
    inOrder(root);
    printf("\n");

    //查找
    if (searchBST(root,90)){
        printf("找到90\n");
    }else{
        printf("未找到90\n");
    }
    if (searchBST(root, 20)) {
        printf("找到20\n");
    } else {
        printf("未找到20\n");
    }

    //插入
    printf("插入90：");
    insertBST(&root, 90);
    inOrder(root);
    printf("\n");

    //删除
    printf("删除60：");
    deleteBST(&root, 60);
    inOrder(root);
    printf("\n");

    return 0;
}