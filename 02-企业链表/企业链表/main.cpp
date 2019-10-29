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

int MyCompare(LinkNode* node1, LinkNode* node2)
{
    Person *p1 = (Person*)node1;
    Person *p2 = (Person*)node2;

    if(strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
    {
        return 0;
    }
    return -1;
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

	// œ«œÚµã²åÈëÁŽ±í
	Insert_LinkList(list, 0, (LinkNode*)&p1);
	Insert_LinkList(list, 0, (LinkNode*)&p2);
	Insert_LinkList(list, 0, (LinkNode*)&p3);
	Insert_LinkList(list, 0, (LinkNode*)&p4);
	Insert_LinkList(list, 0, (LinkNode*)&p5);

    // ŽòÓ¡ÁŽ±í
	Print_LinkList(list, MyPrint);
     
    // ÉŸ³ýœáµã
    Remove_LinkList(list, 3);

    // ŽòÓ¡ÁŽ±í
    printf("\n");
	Print_LinkList(list, MyPrint);

    // ²éÕÒ
    Person findP;
    strcpy(findP.name, "ccc");
    findP.age = 18;
    int pos = Find_LinkList(list, (LinkNode*)&findP, MyCompare);
    printf("position:%d", pos);

    // ÊÍ·ÅÁŽ±í
	FreeSpace_LinkList(list);

	return 0;
}

