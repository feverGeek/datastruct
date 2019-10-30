#include "linkstack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 初始化栈
LinkStack *Init_LinkStack()
{
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
    stack->head.next = NULL;
    stack->size = 0;
    return stack;
}

// 入栈
void Push_LinkStack(LinkStack *stack, LinkNode *data)
{
    if(stack == NULL || data == NULL)
        return ;

    data->next = stack->head.next;
    stack->head.next = data;
    stack->size++;
}

// 返回栈顶元素
void *Top_LinkStack(LinkStack *stack)
{
    if(stack == NULL || stack->size == 0)
        return NULL;

    return stack->head.next;
}

// 出栈
void Pop_LinkStack(LinkStack *stack)
{
    if(stack == NULL || stack->size == 0)
        return;

    stack->head.next = stack->head.next->next;
    stack->size--;
}

// 判断是否为空
int IsEmpty(LinkStack *stack)
{
    if(stack == NULL)
        return -1;

    if(stack->size == 0)
        return LINKSTACK_TRUE;
    return LINKSTACK_FALSE;
}

// 返回栈中元素个数
int Size_LinkStack(LinkStack *stack)
{
    if(stack == NULL)
        return -1;

    return stack->size;
}

// 清空栈
void Clear_LinkStack(LinkStack *stack)
{
    if(stack == NULL)
        return;

    stack->head.next = NULL;
    stack->size = 0;
}

// 销毁
void FreeSpace_LinkStack(LinkStack *stack)
{
    if(stack == NULL)
        return ;

    free(stack);
}


