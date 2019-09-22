#include "LinkList.h"

LinkList * Init_LinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->size = 0;

	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;
	return list;
}

void Insert_LinkList(LinkList * list, int pos, void * data)
{
	if (list == NULL)
		return;

	if (data == NULL)
		return;

	// 友好处理pos越界
	if (pos < 0 || pos > list->size)
		pos = list->size;

	// 创建新节点
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	// 找节点
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	// 新节点入链表
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;
	list->size++;
}

void RemoveByPos_LinkList(LinkList * list, int pos)
{
	if (list == NULL)
		return;

	if (pos < 0 || pos > list->size)
		return;

	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	free(pDel);

	list->size--;
}

int GetSize_LinkList(LinkList * list)
{
	return list->size;
}

int GetPos_LinkList(LinkList * list, void * data)
{
	if (list == NULL)
		return -1;

	if (data == NULL)
		return -1;

	LinkNode* pCurrent = list->head->next;

	for (int i = 0; i < list->size; i++)
	{
		if (data == pCurrent->data)
		{
			return i;
		}
		pCurrent = pCurrent->next;
	}
	return -1;
}

void * GetData_LinkList(LinkList * list, int pos)
{
	if (list == NULL)
		return nullptr;

	if (pos < 0 || pos > list->size)
		return nullptr;
	
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++)
		pCurrent = pCurrent->next;

	return pCurrent->data;
}

void * GetFirstNode_LinkList(LinkList * list)
{
	return list->head->next->data;
}

void Print_LinkList(LinkList * list, PRINTLINKNODE print)
{
	if (list == NULL)
		return;
	LinkNode* pCurrent = list->head->next;
	
	while (pCurrent != NULL)
	{
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

void FreeSpace_LinkList(LinkList * list)
{
	if (list == NULL)
		return;
	LinkNode* pCurrent = list->head;
	while (pCurrent != NULL)
	{
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	// 释放链表内存
	free(list);
}
