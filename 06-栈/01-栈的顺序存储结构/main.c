#include "seqstack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct PERSON{
    char name[64];
    int age;
}Person;

int main()
{
    // 创建栈
    SeqStack *stack = Init_SeqStack();

    // 创建数据
    Person p1 = {"aaa", 10};
    Person p2 = {"bbb", 20};
    Person p3 = {"ccc", 30};
    Person p4 = {"ddd", 40};
    Person p5 = {"eee", 50};

    // 入栈
    Push_SeqStack(stack, &p1);
    Push_SeqStack(stack, &p2);
    Push_SeqStack(stack, &p3);
    Push_SeqStack(stack, &p4);
    Push_SeqStack(stack, &p5);

    // 出栈
    while(Size_SeqStack(stack) > 0)
    {
        Person *person = (Person *)Top_SeqStack(stack);
        printf("name:%s age:%d\n", person->name, person->age);
        Pop_SeqStack(stack);
    }

    FreeSpace_SeqStack(stack);
    return 0;
}

