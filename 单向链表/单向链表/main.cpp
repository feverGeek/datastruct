#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

typedef struct PERSON
{
	char name[64];
	int age;
	int score;
}Person;

void MyPrint(void *data)
{
	Person* p = (Person*)data;
	printf("Name:%s,Age:%d,Score:%d\n", p->name, p->age, p->age);
}

int main()
{
	LinkList* list = Init_LinkList();
	
	Person p1 = { "aa", 19, 90 };
	Person p2 = { "bb", 18, 78 };
	Person p3 = { "cc", 17, 81 };
	Person p4 = { "dd", 20, 70 };
	Person p5 = { "ee", 19, 100 };
	Person p6 = { "ff", 19, 59 };
	Person p7 = { "gg", 19, 97 };

	// 数据插入链表
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	Insert_LinkList(list, 0, &p6);
	Insert_LinkList(list, 0, &p7);

	// 遍历
	Print_LinkList(list, MyPrint);

	printf("-------------------\n");
	// 删除3
	RemoveByPos_LinkList(list, 3);
	Print_LinkList(list, MyPrint);

	printf("--------------------\n");
	Person* per = (Person*)GetFirstNode_LinkList(list);
	MyPrint(per);

	// 销毁
	FreeSpace_LinkList(list);
	system("pause");
	return 0;
}


