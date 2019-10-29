#ifndef CIRCLELINKLIST_H
#define CIRCLELINKLIST_H

// 链表的结点
typedef struct CIRCLELINKLISTNODE{
    struct CIRCLELINKLISTNODE *next;
}CircleLinkNode;

// 链表结构体
typedef struct CIRCLELINKLIST{
    CircleLinkNode head;
    int size;
}CircleLinkList;

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

// 比较回调
typedef int(*COMPARENODE)(CircleLinkNode *, CircleLinkNode *);

// 打印回调
typedef void(*PRINTNODE)(CircleLinkNode *);

// 初始化
CircleLinkList *Init_CircleLinkList();

// 插入结点
void Insert_CircleLinkList(CircleLinkList *clist, int pos, CircleLinkNode *data);

// 获得第一个元素
CircleLinkNode *Front_CircleLinkList(CircleLinkList *clist);

// 根据位置删除
void RemoveByPos_CircleLinkList(CircleLinkList *clist, int pos);

// 根据值删除
void RemoveByValue_CircleLinkList(CircleLinkList *clist, CircleLinkNode *data, COMPARENODE compare);

// 获取链表的长度
int Size_CircleLinkList(CircleLinkList *clist);

// 判读是否为空
int IsEmpty_CircleLinkList(CircleLinkList *clist);

// 根据值查找
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode *data, COMPARENODE compare);

// 打印结点
void Print_CircleLinkList(CircleLinkList *clist, PRINTNODE print);

// 释放内存
void FreeSpace_CircleLinkList(CircleLinkList *clist);

#endif

