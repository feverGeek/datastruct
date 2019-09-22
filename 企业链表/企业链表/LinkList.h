#pragma once

#include <stdlib.h>
#include <stdio.h>

// 节点
typedef struct LINKNODE
{
	struct LINKNODE* next;
}LinkNode;

// 链表
typedef struct LINKLIST
{
	LinkNode head;
	int size;
}LinkList;

typedef void(*PRINTNODE)(LinkNode*);


// 初始化
LinkList* Init_LinkList();

// 插入
void Insert_LinkList(LinkList* list, int pos, LinkNode* data);

// 删除
void Remove_LinkList(LinkList* list, int pos);

// 查找
int Find_LinkList(LinkList* list, LinkNode* data);

// 返回链表大小
int GetSize_LinkList(LinkList* list);

// 打印
void Print_LinkList(LinkList* list, PRINTNODE print);

// 释放内存
void FreeSpace_LinkList(LinkList* list);
