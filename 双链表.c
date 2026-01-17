#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{
    int data;
    struct DNode *prior, *next;
} DNode;

//初始化
void initDLinkList(DNode** l){
    *l = (DNode*)malloc(sizeof(DNode));
    if(*l==NULL){
        return;
    }
    (*l)->prior = NULL;
    (*l)->next = NULL;
}

//判空
int Empty(DNode* l){
    if(l->next==NULL){
        return 1;
    }
    return 0;
}

//插入,在p节点后插入s节点（后插）
void insertNextDNode(DNode* p,DNode* s){
    if(p==NULL||s==NULL){
        return;
    }
    s->next = p->next;
    if(p->next!=NULL){
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
}

//前插
void insertPriorDNode(DNode* p, DNode* s) {
    if (p == NULL || s == NULL) {
        return;
    }
    insertNextDNode(p->prior, s);
}

// 按位插入，在第i个位置插
void insertAtPosition(DNode* l, int i, DNode* s) {
    if (i < 1 || l == NULL) {
        return;
    }
    DNode* p = l;  
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {  
        return;
    }
    insertNextDNode(p, s);
}

// 删除p节点的后继节点
void deleteNextDNode(DNode* p) {
    if(p==NULL||p->next==NULL){
        return;
    }
    DNode* q = p->next;
    p->next = q->next;
    if(q->next!=NULL){
        q->next->prior = p;
    }
    free(q);
}

//销毁
void destroyList(DNode** l){
    while((*l)->next!=NULL){
        deleteNextDNode(*l);
    }
    free(*l);
    *l = NULL;
}

//打印
void printList(DNode* l) {
    DNode* p = l->next;
    printf("双链表: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    DNode* L = NULL;

    // 初始化
    initDLinkList(&L);

    if(Empty(L)){
        printf("链表为空\n");
    }

    // 创建一些测试节点
    DNode* node1 = (DNode*)malloc(sizeof(DNode));
    node1->data = 10;
    DNode* node2 = (DNode*)malloc(sizeof(DNode));
    node2->data = 20;
    DNode* node3 = (DNode*)malloc(sizeof(DNode));
    node3->data = 30;
    DNode* node4 = (DNode*)malloc(sizeof(DNode));
    node4->data = 40;
    DNode* node5 = (DNode*)malloc(sizeof(DNode));
    node5->data = 50;

    // 插入（后插）
    insertNextDNode(L, node1);
    insertNextDNode(node1, node2);
    insertNextDNode(node2, node3);
    printf("插入后：\n");
    printList(L);

    //前插
    insertPriorDNode(node3, node4);
    printf("3节点前插入4节点后：\n");
    printList(L);

    //按位插
    insertAtPosition(L, 3, node5);
    printf("在第三个节点插入5节点后：\n");
    printList(L);

    // 删除
    deleteNextDNode(node1);
    printf("删除节点2后：\n");
    printList(L);

    // 销毁
    destroyList(&L);

    return 0;
}