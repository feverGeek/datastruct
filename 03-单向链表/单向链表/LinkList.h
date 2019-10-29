#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <stdlib.h>
#include <stdio.h>


// ����ڵ�
typedef struct LINKNODE
{
	void* data;  // ָ���κ���������
	struct LINKNODE* next;
}LinkNode;

// ����ṹ��
typedef struct LINKLIST {
	LinkNode* head;
	int size;
}LinkList;

// ��ӡ����ָ��
typedef void(*PRINTLINKNODE) (void*);

// ��ʼ������
LinkList* Init_LinkList();

// ָ��λ������
void Insert_LinkList(LinkList* list, int pos, void* data);

// ɾ��ָ��λ�õ�ֵ
void RemoveByPos_LinkList(LinkList* list, int pos);

// ��ȡ������
int GetSize_LinkList(LinkList* list);

// ��ȡ���ݵ�λ��
int GetPos_LinkList(LinkList* list, void* data);

// ��ȡָ��λ�õ�����
void* GetData_LinkList(LinkList* list, int pos);

// ���ص�һ���ڵ�
void* GetFirstNode_LinkList(LinkList* list);

// ��ӡ����ڵ�
void Print_LinkList(LinkList* list, PRINTLINKNODE print);

// �ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list);

#endif
