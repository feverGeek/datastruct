#pragma once

#include <stdlib.h>
#include <stdio.h>

// œÚµã
typedef struct LINKNODE
{
	struct LINKNODE* next;
}LinkNode;

// ÁŽ±í
typedef struct LINKLIST
{
	LinkNode head;
	int size;
}LinkList;

// ±éÀúº¯ÊýÖžÕë
typedef void(*PRINTNODE)(LinkNode*);

// ±ÈœÏº¯ÊýÖžÕë
typedef int(*COMPARENODE)(LinkNode*, LinkNode*);

// ³õÊŒ»¯
LinkList* Init_LinkList();

// ²åÈë
void Insert_LinkList(LinkList* list, int pos, LinkNode* data);

// ÉŸ³ý
void Remove_LinkList(LinkList* list, int pos);

// ²éÕÒ
int Find_LinkList(LinkList* list, LinkNode* data, COMPARENODE compare);

// ·µ»ØÁŽ±íŽóÐ¡
int GetSize_LinkList(LinkList* list);

// ŽòÓ¡
void Print_LinkList(LinkList* list, PRINTNODE print);

// ÊÍ·ÅÄÚŽæ
void FreeSpace_LinkList(LinkList* list);
