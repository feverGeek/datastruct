#include "linkstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PERSON{
    LinkNode node;
    char name[64];
}Person;

int main()
{
    // 创建栈
    LinkStack *stack = Init_LinkStack();

    // 创建数据
    Person p1 , p2, p3, p4, p5;
    strcpy(p1.name, "aaa");
    strcpy(p2.name, "bbb");
    strcpy(p3.name, "ccc");
    strcpy(p4.name, "ddd");
    strcpy(p5.name, "eee");

    // 入栈
    Push_LinkStack(stack, (LinkNode *)&p1);
    Push_LinkStack(stack, (LinkNode *)&p2);
    Push_LinkStack(stack, (LinkNode *)&p3);
    Push_LinkStack(stack, (LinkNode *)&p4);
    Push_LinkStack(stack, (LinkNode *)&p5);

    // 出栈
    while(Size_LinkStack(stack) > 0)
    {
        Person *person = (Person *)Top_LinkStack(stack);
        printf("name:%s \n", person->name);
        Pop_LinkStack(stack);
    }

    FreeSpace_LinkStack(stack);
    return 0;
}

