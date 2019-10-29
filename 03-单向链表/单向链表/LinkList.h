#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <stdlib.h>
#include <stdio.h>


// 链表节点
typedef struct LINKNODE
{
	void* data;  // 指向任何类型数据
	struct LINKNODE* next;
}LinkNode;

// 链表结构体
typedef struct LINKLIST {
	LinkNode* head;
	int size;
}LinkList;

// 打印函数指针
typedef void(*PRINTLINKNODE) (void*);

// 初始化链表
LinkList* Init_LinkList();

// 指定位置输入
void Insert_LinkList(LinkList* list, int pos, void* data);

// 删除指定位置的值
void RemoveByPos_LinkList(LinkList* list, int pos);

// 获取链表长度
int GetSize_LinkList(LinkList* list);

// 获取数据的位置
int GetPos_LinkList(LinkList* list, void* data);

// 获取指定位置的数据
void* GetData_LinkList(LinkList* list, int pos);

// 返回第一个节点
void* GetFirstNode_LinkList(LinkList* list);

// 打印链表节点
void Print_LinkList(LinkList* list, PRINTLINKNODE print);

// 释放链表内存
void FreeSpace_LinkList(LinkList* list);

#endif
