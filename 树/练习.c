// 练习1：计算度为2的结点数
// 练习2：交换所有左右子树
// 练习3：求二叉树的宽度

#include<stdio.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

int countDegree2(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int count = 0;
    if(root->left!=NULL&&root->right!=NULL){
        return 1;
    }
    return count + countDegree2(root->left) + countDegree2(root->right);
}

void swapTree(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    swapTree(root->left);
    swapTree(root->right);
}

int getTreeWidth(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    struct TreeNode* queue[100]; 
    int front = 0, rear = 0;
    int max = 0;
    queue[rear++] = root;
    while (front < rear) {
        int size = rear - front;  
        if (size > max) {
            max = size;  
        }
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            if (node->left != NULL) {
                queue[rear++] = node->left;
            }
            if (node->right != NULL) {
                queue[rear++] = node->right;
            }
        }
    }
    return max;
}