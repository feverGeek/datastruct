#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct PERSON {
	LinkNode node;
	char name[64];
	int age;
}Person;

void MyPrint(LinkNode* data)
{
	Person* p = (Person*)data;
	printf("Name:%s, Age:%d \n", p->name, p->age);
}

int main()
{
	LinkList* list = Init_LinkList();

	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");
	p1.age = 19;
	p2.age = 21;
	p3.age = 18;
	p4.age = 20;
	p5.age = 22;

	// 将节点插入链表
	Insert_LinkList(list, 0, (LinkNode*)&p1);
	Insert_LinkList(list, 0, (LinkNode*)&p2);
	Insert_LinkList(list, 0, (LinkNode*)&p3);
	Insert_LinkList(list, 0, (LinkNode*)&p4);
	Insert_LinkList(list, 0, (LinkNode*)&p5);

	Print_LinkList(list, MyPrint);
	FreeSpace_LinkList(list);

	system("pause");
	return 0;
}

