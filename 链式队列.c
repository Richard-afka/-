#include <stdio.h>
#include <stdlib.h>

// 链队列结点
typedef struct QNode {
    int data;
    struct QNode* next;
} QNode;

// 链队列
typedef struct {
    QNode* front;  
    QNode* rear;   
} LinkQueue;

// 初始化
void InitLinkQueue(LinkQueue* Q) {
    QNode* head = (QNode*)malloc(sizeof(QNode));
    if (head == NULL) {
        return;
    }
    head->next = NULL;
    Q->front = Q->rear = head; 
}

// 判空
int LinkQueueEmpty(LinkQueue* Q) {
    if (Q->front == Q->rear){
        return 1;
    }
    return 0;
}

// 入队
void EnLinkQueue(LinkQueue* Q, int num) {
    QNode* new = (QNode*)malloc(sizeof(QNode));
    if (new == NULL) {
        return;
    }
    new->data = num;
    new->next = NULL;
    Q->rear->next = new;  
    Q->rear = new;       
}

// 出队
void DeLinkQueue(LinkQueue* Q) {
    if (LinkQueueEmpty(Q)) {
        printf("队列为空，无法出队！\n");
        return;
    }
    QNode* temp = Q->front->next;  
    Q->front->next = temp->next;  
    if (Q->rear == temp) {
        Q->rear = Q->front;  
    }
    free(temp);
}

// 获取队头元素
int GetLinkQueueHead(LinkQueue* Q) {
    if (LinkQueueEmpty(Q)) {
        printf("队列为空！\n");
        return -1;
    }
    return Q->front->next->data;
}

// 遍历,打印链队列
void TraverseLinkQueue(LinkQueue* Q) {
    if (LinkQueueEmpty(Q)) {
        printf("队列为空！\n");
        return;
    }
    printf("链队列元素: ");
    QNode* p = Q->front->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 销毁
void DestroyLinkQueue(LinkQueue* Q) {
    while (Q->front != NULL) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}

int main() {
    LinkQueue Q;
    int num;

    //初始化
    InitLinkQueue(&Q);

    // 入队
    for (int i = 1; i <= 5; i++) {
        EnLinkQueue(&Q, i * 10);
        printf("入队: %d\n", i * 10);
        TraverseLinkQueue(&Q);
    }

    // 获取队头
    num = GetLinkQueueHead(&Q);
    printf("队头元素: %d\n", num);

    // 出队
    for (int i = 1; i <= 5; i++) {
        DeLinkQueue(&Q);
        TraverseLinkQueue(&Q);
    }

    //销毁
    DestroyLinkQueue(&Q);

    return 0;
}