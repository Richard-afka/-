#include <stdio.h>
#include <stdlib.h>

#define InitSize 10

typedef struct sqlist {
    int* data;
    int length;
    int MaxSize;
} Sqlist;

// 初始化顺序表
void Initlist(Sqlist* l) {
    l->data = (int*)malloc(InitSize * sizeof(int));
    l->length = 0;
    l->MaxSize = InitSize;
}

// 扩容
void increasesize(Sqlist* l, int len) {
    int* p = l->data;
    l->data = (int*)malloc((l->MaxSize + len) * sizeof(int));
    for (int i = 0; i < l->length; i++) {
        l->data[i] = p[i];
    }
    l->MaxSize += len;
    free(p);
}

// 在第i位插入元素num
void listinsert(Sqlist* l, int i, int num) {
    if (l->length == l->MaxSize) {
        increasesize(l, 1);
    }
    for (int j = l->length; j >= i; j--) {
        l->data[j] = l->data[j - 1];  
    }
    l->data[i - 1] = num;
    l->length++;
}

//删除第i位的元素
int listdelete(Sqlist* l, int i) {
    if (i < 1 || i > l->length) {
        printf("删除位置i无效\n");
        return 0;
    }
    for (int j = i; j < l->length; j++) {
        l->data[j - 1] = l->data[j];
    }
    l->length--;  
    return 1;
}

// 按位查找
int getelem(Sqlist* l, int i) {
    if (i < 1 || i > l->length) {
        printf("i无效\n");
        return -1;
    }
    return l->data[i - 1];
}

// 按值查找
int locateelem(Sqlist* l, int num) {
    for (int i = 0; i < l->length; i++) {
        if (l->data[i] == num) {
            return i + 1;
        }
    }
    return 0;
}

//打印
void printlist(Sqlist* l) {
    printf("顺序表内容：");
    for (int i = 0; i < l->length; i++) {
        printf("%d ", l->data[i]);
    }
    printf("\n");
}

int main() {
    Sqlist L;
    // 初始化顺序表
    Initlist(&L);
    printf("初始容量：%d\n", L.MaxSize);
    printf("当前长度：%d\n", L.length);
    printf("\n");

    int n;
    printf("请输入要输入的元素个数: ");
    scanf("%d", &n);
    L.length = n;
    for (int i = 0; i < L.length; i++) {
        scanf("%d", &L.data[i]);
    }

    // 插入元素
    listinsert(&L, 4, 88);
    printf("插入88元素后：\n");
    printlist(&L);
    printf("\n");

    // 扩容
    increasesize(&L, 5);
    printf("增加5个空间后容量为：%d\n", L.MaxSize);
    printlist(&L);
    printf("\n");

    // 按位查找
    int i = 5;
    int m = getelem(&L, i);
    if (m != -1) {
        printf("第%d个元素是：%d\n", i, m);
    }
    printf("\n");

    // 按值查找
    int num = 99;
    int loc = locateelem(&L, num);
    if (loc > 0) {
        printf("元素%d在第%d个位置\n", num, loc);
    } else {
        printf("未找到元素%d\n", num);
    }
    printf("\n");

    // 删除元素
    int del_num = 4;
    if (listdelete(&L, del_num)) {
        printf("删除第%d个元素后：\n", del_num);
        printlist(&L);
        printf("当前长度：%d\n", L.length);
    }
    printf("\n");
    return 0;
}