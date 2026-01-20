#include <stdio.h>
#include <stdlib.h>

// 节点
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

#define MAXSIZE 100
typedef struct {
    struct TreeNode* data[MAXSIZE];
    int front;
    int rear;
} CircularQueue;
// 初始化
void InitQueue(CircularQueue* Q) {
    Q->front = 0;
    Q->rear = 0;
}
// 判空
int QueueEmpty(CircularQueue* Q) {
    if (Q->front == Q->rear) {
        return 1;
    }
    return 0;
}
// 判满
int QueueFull(CircularQueue* Q) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        return 1;
    }
    return 0;
}
// 入队
void EnQueue(CircularQueue* Q, struct TreeNode* num) {
    if (QueueFull(Q)) {
        printf("队列已满，无法入队！\n");
        return;
    }
    Q->data[Q->rear] = num;
    Q->rear = (Q->rear + 1) % MAXSIZE;
}
// 出队
struct TreeNode* DeQueue(CircularQueue* Q) {
    if (QueueEmpty(Q)) {
        printf("队列为空，无法出队！\n");
        return NULL;
    }

    struct TreeNode* num = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return num;
}

// //节点
// struct TreeNode{
//     int data;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };

// 创建新节点
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 先序遍历
void preOrder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// 中序遍历
void inOrder(struct TreeNode* root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// 后序遍历
void postOrder(struct TreeNode* root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    inOrder(root->right);
    printf("%d ", root->data);
}

// 层次遍历（队列实现）
void levelOrder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    CircularQueue* new = (CircularQueue*)malloc(sizeof(CircularQueue));
    InitQueue(new);
    EnQueue(new, root);
    while (!QueueEmpty(new)) {
        struct TreeNode* node;
        node = DeQueue(new);
        printf("%d ", node->data);
        if (node->left != NULL)
            EnQueue(new, node->left);
        if (node->right != NULL)
            EnQueue(new, node->right);
    }
    free(new);
}

// 计算结点数
int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 1;
    }
    return countNodes(root->left) + countNodes(root->right);
}

// 计算叶子结点数
int countLeaves(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

// 计算树高
int getHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftheight = getHeight(root->left);
    int rightheight = getHeight(root->right);
    if (leftheight > rightheight) {
        return leftheight + 1;
    } else {
        return rightheight + 1;
    }
}

// 在树中查找一个值
int search(struct TreeNode* root, int target) {
    if (root == NULL)
        return 0;
    if (root->data == target)
        return 1;
    if (search(root->left, target))
        return 1;
    if (search(root->right, target))
        return 1;
    return 0;
}

// 先序创建二叉树(用'#'表示空结点)
struct TreeNode* createTree() {
    char c;
    scanf("%c", &c);
    if (c == '#' || c == '\n')
        return NULL;
    struct TreeNode* newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    int num = c - 'A' + 1;
    newNode->data = num;
    // printf("输入%d的左孩子(#表示空): \n", num);
    newNode->left = createTree();
    // printf("输%d的右孩子(#表示空): \n", num);
    newNode->right = createTree();
    return newNode;
}

int main() {
    struct TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->right = createNode(20);
    root->left->left->left = createNode(1);

    printf("树的形状：\n");
    printf("        10\n");
    printf("       /  \\\n");
    printf("      5    15\n");
    printf("     / \\    \\\n");
    printf("    3   7     20\n");
    printf("   /\n");
    printf("  1\n\n");

    // 遍历
    printf("先序遍历: ");
    preOrder(root);
    printf("\n");
    printf("中序遍历: ");
    inOrder(root);
    printf("\n");
    printf("后序遍历: ");
    postOrder(root);
    printf("\n");
    printf("层次遍历: ");
    levelOrder(root);
    printf("\n\n");

    printf("树高: %d\n", getHeight(root));
    printf("结点总数: %d\n", countNodes(root));
    printf("叶子结点数: %d\n", countLeaves(root));

    // 查找
    int num = 3;
    if (search(root, num)) {
        printf("找到了数字 %d\n", num);
    } else {
        printf("没找到数字 %d\n", num);
    }
    num = 100;
    if (search(root, num)) {
        printf("找到了数字 %d\n", num);
    } else {
        printf("没找到数字 %d\n", num);
    }

    printf("\n");
    // 创建
    printf("请输入二叉树的先序序列（用#表示空节点）：\n");
    printf("例如：ABD##E##C#F##\n");
    printf("输入：");
    root = createTree();
    printf("先序遍历: ");
    preOrder(root);
    printf("\n");
    return 0;
}
