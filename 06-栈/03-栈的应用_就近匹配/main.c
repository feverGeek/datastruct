#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

typedef struct MYCHAR{
    LinkNode node;
    int index;
    char character;
}MyChar;

int IsLeft(char c)
{
    return c == '(';
}

int IsRight(char c)
{
    return c == ')';
}

void ShowError(char *str, int pos)
{
    printf("出现没有匹配的括号\n");
    printf("%s\n", str);
    for(int i=0; i < pos; i++)
    {
        printf(" ");
    }
    printf("|\n");
}

MyChar *CreateMyChar(char p, int index)
{
    MyChar *mychar = (MyChar *)malloc(sizeof(MyChar));
    mychar->character = p;
    mychar->index = index;
    return mychar;
}

int main()
{
    //char *str = "1+2+6((sdf)adf)sdd(sas(df"; 
    //char *str = "((())))ssdf(()))"; 
    char *str = "(((((";
    //char *str = ")))))";
    
    // 创建栈容器
    LinkStack *stack = Init_LinkStack();

    char *p = str;
    int index = 0;
    while(*p != '\0')
    {
        // 如果是左括号 入栈
        if(IsLeft(*p))
        {
            Push_LinkStack(stack, (LinkNode *)CreateMyChar(*p, index));
        }

        // 如果是右括号　出栈  判断是不是不是左括号
        if(IsRight(*p))
        {
            if(Size_LinkStack(stack) > 0)
            {
                MyChar *c = (MyChar *)Top_LinkStack(stack);
                Pop_LinkStack(stack);
                free(c);
            }
            else{
                // 没有匹配到
                ShowError(str, index);
                //break;
            }
        }
        p++;
        index++;
    }
    printf("\n");

    while(Size_LinkStack(stack) > 0)
    {
        MyChar *c = (MyChar *)Top_LinkStack(stack);
        ShowError(str, c->index);
        Pop_LinkStack(stack);
        free(c);
    }

    printf("\n");
    FreeSpace_LinkStack(stack);
    return 0;
}

