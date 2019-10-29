#include "CircleLinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PERSON{
    CircleLinkNode node;
    char name[64];
    int age;
}Person;

void MyPrint(CircleLinkNode* data)
{
    Person *p = (Person *)data;
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

int MyCompare(CircleLinkNode *data1 , CircleLinkNode *data2)
{
    Person *p1 = (Person *)data1;
    Person *p2 = (Person *)data2;

    if(strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
    {
        return CIRCLELINKLIST_TRUE;
    }

    return CIRCLELINKLIST_FALSE;
}

int main()
{

    // 创建循环链表
    CircleLinkList *clist = Init_CircleLinkList();

    // 创建数据
    Person p1, p2, p3, p4, p5;
    strcpy(p1.name, "aaa");
    strcpy(p2.name, "bbb");
    strcpy(p3.name, "ccc");
    strcpy(p4.name, "ddd");
    strcpy(p5.name, "eee");
    p1.age = 10;
    p2.age = 20;
    p3.age = 30;
    p4.age = 40;
    p5.age = 50;

    // 判断是否为空
    if(IsEmpty_CircleLinkList(clist) == CIRCLELINKLIST_TRUE)
    {
        printf("circle link list is empty\n");
    }


    // 插入数据 
    Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p1);
    Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p2);
    Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p3);
    Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p4);
    Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p5);
    
    // 判断是否为空
    if(IsEmpty_CircleLinkList(clist) == CIRCLELINKLIST_TRUE)
    {
        printf("circle link list is empty\n");
    }
    else if(IsEmpty_CircleLinkList(clist) == CIRCLELINKLIST_FALSE)
    {
        printf("circle link list is not empty\n");
    }
    printf("clist size : %d\n", clist->size);

    // 打印
    Print_CircleLinkList(clist, MyPrint);

    // 删除
    Person pDel;
    strcpy(pDel.name, "ddd");
    pDel.age = 40;
    RemoveByValue_CircleLinkList(clist, (CircleLinkNode *)&pDel, MyCompare);
    
    printf("---------\n");
    // 打印
    Print_CircleLinkList(clist, MyPrint);

    // 释放内存
    FreeSpace_CircleLinkList(clist);
    return 0;

}

