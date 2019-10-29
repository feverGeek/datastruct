#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

typedef struct MYCHAR{
    LinkNode node;
    char *character;
}MyChar;


// 判断是否是数字
int IsNumber(char *c)
{
    return *c >= '0' && *c <= '9';
}

// 输出数字运算符 
void NumberOperate(char *c)
{
    printf("%c", *c);
}

// 判读是不是左括号
int IsLeft(char *c)
{
    return *c == '(';
}

// 判读是不是右括号
int IsRight(char *c)
{
    return *c == ')';
}

// 判断是不是运算符
int IsOperator(char *c)
{
    return *c == '+' || *c == '-' || *c == '*' || *c == '/';
}

// 返回操作符号的优先级
int GetPriority(char *c)
{
    if(*c == '*' || *c == '/')
        return 2;

    if(*c == '+' || *c == '-')
        return 1;

    return 0;
}


// 创建节点
MyChar *CreateMyChar(char *p)
{
    MyChar *c = (MyChar *)malloc(sizeof(MyChar));
    c->character = p;
    return c;
}

// 左括号操作
void LeftOperate(LinkStack *stack, char *p)
{
    MyChar *c = CreateMyChar(p);
    Push_LinkStack(stack, (LinkNode *)c);
}

// 右括号操作
void RightOperate(LinkStack *stack)
{
    while(Size_LinkStack(stack) > 0)
    {

        MyChar *c = (MyChar *)Top_LinkStack(stack);
        // 左括号弹出
        if(IsLeft(c->character))
        {
            Pop_LinkStack(stack);
            break;
        }

        printf("%c", *(c->character));
        Pop_LinkStack(stack);
        // 释放内存
        free(c);
    }
}

// 运算符操作
void OperatorOperate(LinkStack *stack, char *p)
{
    // 取出栈顶符号
    MyChar *c = (MyChar *)Top_LinkStack(stack);

    if(c == NULL)
    {
        Push_LinkStack(stack, (LinkNode *)CreateMyChar(p));
        return;
    }

    // 如果栈顶符号优先级低于当前符号的优先级　直接入栈
    if(GetPriority(p) > GetPriority(c->character))
    {
        Push_LinkStack(stack, (LinkNode *)CreateMyChar(p));
        return;
    }
    // 栈顶符号优先级不低于当前符号的优先级 出栈
    else
    {
        while(Size_LinkStack(stack) > 0)
        {
            MyChar *c2 = (MyChar *)Top_LinkStack(stack);
            // 如果栈顶符号优先级低于当前符号的优先级　直接入栈
            if(GetPriority(p) > GetPriority(c2->character))
            {
                Push_LinkStack(stack, (LinkNode *)CreateMyChar(p));
                break;
            }

            printf("%c", *(c2->character));
            Pop_LinkStack(stack);
            free(c2);
        }
    }
}

int main()
{
    char *str = "8+(3-1)*5";
    char *p = str;

    // 创建栈容器
    LinkStack *stack = Init_LinkStack();

    while(*p != '\0')
    {
        // 如果是数字
        if(IsNumber(p))
            NumberOperate(p);

        // 如果是左括号　进栈
        if(IsLeft(p))
            LeftOperate(stack, p);

        // 如果是右括号　出栈直到左括号弹出
        if(IsRight(p))
            RightOperate(stack);

        // 如果是运算符号
        if(IsOperator(p))
            OperatorOperate(stack, p);        

        p++;
    }

    // 把栈中剩余的符号弹出
    while(Size_LinkStack(stack) > 0)
    {
        MyChar *c = (MyChar *)Top_LinkStack(stack);
        printf("%c", *(c->character));
        Pop_LinkStack(stack);
        free(c);
    }

    FreeSpace_LinkStack(stack);
    printf("\n");
    return 0;
}

