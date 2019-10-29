#ifndef LINKSTACK_H
#define LINKSTACK_H

#define LINKSTACK_TRUE 1
#define LINKSTACK_FALSE 0

// 链式栈的结点
typedef struct LINKNODE{
    struct LINKNODE *next;
}LinkNode;

typedef struct LINKSTACK{
    LinkNode head;
    int size;
}LinkStack;

// 初始化栈
LinkStack *Init_LinkStack();

// 入栈
void Push_LinkStack(LinkStack *stack, LinkNode *data);

// 返回栈顶元素
void *Top_LinkStack(LinkStack *stack);

// 出栈
void Pop_LinkStack(LinkStack *stack);

// 判断是否为空
int IsEmpty(LinkStack *stack);

// 返回栈中元素个数
int Size_LinkStack(LinkStack *stack);

// 清空栈
void Clear_LinkStack(LinkStack *stack);

// 销毁
void FreeSpace_LinkStack(LinkStack *stack);

#endif

