#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode;

// 初始化
int initlist(LNode** l) {
    *l = (LNode*)malloc(sizeof(LNode));
    if (*l == NULL)
        return 0;
    (*l)->next = NULL;
    return 1;
}

// 按位查找
LNode* getElem(LNode* l, int i) {
    if (i < 0)
        return NULL;
    LNode* p = l;
    int j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

// 按位序插入，在第i个位置插入元素num
void listinsert(LNode* l, int i, int num) {
    if (i < 1) {
        return;
    }
    // LNode* p;
    // int j = 0;
    // p = l;
    // while(p!=NULL&&j<i-1){
    //     p = p->next;
    //     j++;
    // }
    LNode* p = getElem(l, i - 1);
    if (p == NULL) {
        return;
    }
    LNode* q = (LNode*)malloc(sizeof(LNode));
    q->data = num;
    q->next = p->next;
    p->next = q;
}

// 指定节点的后插，在p节点后插入元素num
void insertNextNode(LNode* p, int num) {
    if (p == NULL) {
        return;
    }
    LNode* q = (LNode*)malloc(sizeof(LNode));
    if (q == NULL)
        return;
    q->data = num;
    q->next = p->next;
    p->next = q;
}

// 在p节点前插入num
void insertPtiorNode(LNode* p, int num) {
    if (p == NULL) {
        return;
    }
    LNode* q = (LNode*)malloc(sizeof(LNode));
    if (q == NULL)
        return;
    q->next = p->next;
    p->next = q;
    q->data = p->data;
    p->data = num;
}

// 按位序删除
void listdelete(LNode* l, int i) {
    if (i < 1) {
        return;
    }
    // LNode* p;
    // int j = 0;
    // p = l;
    // while(p!=NULL&&j<i-1){
    //     p = p->next;
    //     j++;
    // }
    LNode* p = getElem(l, i - 1);
    if (p == NULL || p->next == NULL) {
        return;
    }
    LNode* q = p->next;
    p->next = q->next;
    free(q);
}

// 删除指定节点
void deleteNode(LNode* p) {
    if (p == NULL || p->next == NULL)
        return;
    LNode* q = p->next;
    p->data = q->data;
    p->next = q->next;
}

// //按位查找
// LNode* getElem(LNode* l,int i){
//     if(i<0)
//         return;
//     LNode* p=l;
//     int j = 0;
//     while(p!=NULL&&j<i){
//         p = p->next;
//         j++;
//     }
//     return p;
// }

// 求表长
int length(LNode* l) {
    int len = 0;
    LNode* p = l->next;
    while (p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

// 尾插法建立
LNode* list_tailInsert(LNode* l) {
    int n;
    LNode* q = l;
    scanf("%d", &n);
    while (n != -1) {
        LNode* p = (LNode*)malloc(sizeof(LNode));
        p->data = n;
        p->next = NULL;
        q->next = p;
        q = p;
        scanf("%d", &n);
    }
    q->next = NULL;
    return l;
}

// 头插法建立
LNode* list_headInsert(LNode* l) {
    int n;
    scanf("%d", &n);
    while (n != -1) {
        LNode* p = (LNode*)malloc(sizeof(LNode));
        p->data = n;
        p->next = l->next;
        l->next = p;
        scanf("%d", &n);
    }
    return l;
}

// 打印链表
void printlist(LNode* l) {
    LNode* p = l->next;
    printf("链表内容：");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 销毁链表
void destroyList(LNode* l) {
    LNode* p = l;
    while (p != NULL) {
        LNode* temp = p;
        p = p->next;
        free(temp);
    }
}

int main() {
    LNode* L = NULL;
    LNode* L1 = NULL;
    LNode* L2 = NULL;

    // 初始化链表
    initlist(&L);
    initlist(&L1);
    initlist(&L2);

    // 先创建一个链表
    listinsert(L, 1, 10);
    listinsert(L, 2, 20);
    listinsert(L, 3, 30);
    listinsert(L, 4, 40);
    printf("插入10,20,30,40: \n");
    printlist(L);

    // 后插
    insertNextNode(getElem(L, 1), 15);
    printf("在第1个节点后插入15: \n");
    printlist(L);

    // 前插
    insertPtiorNode(getElem(L, 3), 25);
    printf("在第3个节点前插入25: \n");
    printlist(L);

    // 删除指定节点
    deleteNode(getElem(L, 2));
    printf("删除第2个节点: \n");
    printlist(L);

    // 按位删除
    listdelete(L, 3);
    printf("删除第3个节点: \n");
    printlist(L);

    // 表长
    printf("当前链表长度: %d\n\n", length(L));

    // 测试尾插法
    printf("=== 测试尾插法 ===\n");
    printf("请输入数字创建链表L1（以-1结束）: ");
    list_tailInsert(L1);
    printlist(L1);

    // 测试头插法
    printf("=== 测试头插法 ===\n");
    printf("请输入数字创建链表L2（以-1结束）: ");
    list_headInsert(L2);
    printlist(L2);

    // 销毁链表
    destroyList(L);
    destroyList(L1);
    destroyList(L2);

    return 0;
}
