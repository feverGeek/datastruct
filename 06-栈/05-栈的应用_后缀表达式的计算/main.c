#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

typedef struct MYNUM{
    LinkNode node;
    int val;
}MyNum;


// 判断是否是数字
int IsNumber(char *c)
{
    return *c >= '0' && *c <= '9';
}

int Calc(int left, int right, char c)
{
    int ret = 0;
    switch(c)
    {
    case '+': ret = left+right; break;
    case '-': ret = left-right; break;
    case '*': ret = left*right; break;
    case '/': ret = left/right; break;
    }
    return ret;
}

int main()
{
    // 中缀表达式
    //char *str = "8+(3-1)*5";
    // 后缀表达式
    char *str = "831-5*+";
    char *p = str;

    // 创建栈容器
    LinkStack *stack = Init_LinkStack();

    while(*p != '\0')
    {
        // 如果是数字
        if(IsNumber(p))
        {
            MyNum *num = (MyNum *)malloc(sizeof(MyNum));
            num->val = *p - '0';
            Push_LinkStack(stack, (LinkNode *)num);
        }
        // 如果是运算符
        else
        {
            // 先从栈中弹出右操作数
            MyNum *right = (MyNum *)Top_LinkStack(stack);
            int rightNum = right->val;
            Pop_LinkStack(stack);
            free(right);

            // 取出左操作数
            MyNum *left = (MyNum *)Top_LinkStack(stack);
            int leftNum = left->val;
            Pop_LinkStack(stack);
            free(left);

            int ret = Calc(leftNum, rightNum, *p);
            // 把结果入栈
            MyNum *num = (MyNum *)malloc(sizeof(MyNum));
            num->val = ret;
            Push_LinkStack(stack, (LinkNode *)num);
        }
        p++;
    }
    
    // 如果结果正确　栈中只剩下结果
    if(Size_LinkStack(stack) == 1)
    {
        MyNum *num = (MyNum *)Top_LinkStack(stack);
        printf("运算结果:%d", num->val);
        Pop_LinkStack(stack);
        free(num);
    }

    FreeSpace_LinkStack(stack);
    printf("\n");
    return 0;
}

