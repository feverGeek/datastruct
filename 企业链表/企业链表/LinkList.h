#pragma once

#include <stdlib.h>
#include <stdio.h>

// �ڵ�
typedef struct LINKNODE
{
	struct LINKNODE* next;
}LinkNode;

// ����
typedef struct LINKLIST
{
	LinkNode head;
	int size;
}LinkList;

typedef void(*PRINTNODE)(LinkNode*);


// ��ʼ��
LinkList* Init_LinkList();

// ����
void Insert_LinkList(LinkList* list, int pos, LinkNode* data);

// ɾ��
void Remove_LinkList(LinkList* list, int pos);

// ����
int Find_LinkList(LinkList* list, LinkNode* data);

// ���������С
int GetSize_LinkList(LinkList* list);

// ��ӡ
void Print_LinkList(LinkList* list, PRINTNODE print);

// �ͷ��ڴ�
void FreeSpace_LinkList(LinkList* list);
