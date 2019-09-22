#include "LinkList.h"

LinkList * Init_LinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	return list;
}

void Insert_LinkList(LinkList * list, int pos, LinkNode * data)
{
	if (list == NULL)
		return;
	if (data == NULL)
		return; 

	if (pos < 0 || pos > list->size)
		pos = list->size;

	// 查找插入位置
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
		pCurrent = pCurrent->next;

	// 插入新节点
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->size++;
}

void Remove_LinkList(LinkList * list, int pos)
{
	
}

int Find_LinkList(LinkList * list, LinkNode * data)
{

	return 0;
}

int GetSize_LinkList(LinkList * list)
{
	return 0;
}

void Print_LinkList(LinkList * list, PRINTNODE print)
{
	if (list == NULL)
		return;

	LinkNode* pCurrent = list->head.next;
	for (int i = 0; i < list->size; i++)
	{
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
}

void FreeSpace_LinkList(LinkList * list)
{
	if (list == NULL)
		return;

	free(list);
}
