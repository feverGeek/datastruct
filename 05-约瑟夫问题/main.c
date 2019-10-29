#include <stdio.h>
#include "CircleLinkList.h"

#define M 8
#define N 3

typedef struct MYNUM
{
    CircleLinkNode node;
    int val;
}MyNum;

void MyPrint(CircleLinkNode *data)
{
    MyNum *num = (MyNum *)data;
    printf("num:%d\n", num->val);
}

int MyCompare(CircleLinkNode *data1, CircleLinkNode *data2)
{
    MyNum *num1 = (MyNum *)data1;
    MyNum *num2 = (MyNum *)data2;
    if(num1->val == num2->val)
        return CIRCLELINKLIST_TRUE;

    return CIRCLELINKLIST_FALSE;
}

int main()
{
    // 创建循环链表
    CircleLinkList *clist = Init_CircleLinkList();
    MyNum num[M];
    for(int i = 0; i < M; i++)
    {
        num[i].val = i+1;
        Insert_CircleLinkList(clist, i, (CircleLinkNode *)&num[i]);

    }
    
    // 打印
    Print_CircleLinkList(clist, MyPrint);
    printf("\n");

    int index = 1;
    CircleLinkNode *pCurrent = clist->head.next;

    while(Size_CircleLinkList(clist) > 1)
    {
        if(index == N)
        {
            MyPrint(pCurrent);

            CircleLinkNode *pNext = pCurrent->next;
            RemoveByValue_CircleLinkList(clist, pCurrent, MyCompare);
            pCurrent = pNext;

            // 如果指向的是头结点　则指向下一个结点
            if(pCurrent == &(clist->head))
                pCurrent = pCurrent->next;

            index = 1;
        }

        pCurrent = pCurrent->next;
        // 如果指向的是头结点　则指向下一个结点
        if(pCurrent == &(clist->head))
            pCurrent = pCurrent->next;

        index++;
    }

    if(Size_CircleLinkList(clist) == 1)
    {
        // 打印最后一个结点
        MyNum *tempNum = (MyNum *)Front_CircleLinkList(clist);
        MyPrint((CircleLinkNode *)tempNum);
    }
    else
    {
        printf("error\n");
    }
    

    FreeSpace_CircleLinkList(clist);
    return 0;
}

