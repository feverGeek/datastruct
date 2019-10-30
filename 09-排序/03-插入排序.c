/******************************************
 * 插入排序
 *  从小到大排序
 *  4 2 8 0 5 7 1 3 9 
 *
 * 1. 将无序序列插入到有序序列中
 *     4 (2) 8  0  5  7  1  3  9 
 *     2  4  8  0  5  7  1  3  9
 *     2  4  8 (0) 5  7  1  3  9
 *     2  4  0  8  5  7  1  3  9
 *     2  0  4  8  5  7  1  3  9
 *     0  2  4  8  5  7  1  3  9
 *     0  2  4  8 (5) 7  1  3  9
 *     0  2  4  5  8  7  1  3  9
 *     0  2  4  5  8 (7) 1  3  9
 *     0  2  4  5  7  8  1  3  9
 *     0  2  4  5  7  8 (1) 3  9
 *     0  2  4  5  7  1  8  3  9
 *     0  2  4  5  1  7  8  3  9
 *     0  2  4  1  5  7  8  3  9
 *     0  2  1  4  5  7  8  3  9
 *     0  1  2  4  5  7  8  3  9
 *     0  1  2  4  5  7  8 (3) 9
 *     0  1  2  4  5  7  3  8  9
 *     0  1  2  4  5  3  7  8  9
 *     0  1  2  4  3  5  7  8  9
 *     0  1  2  3  4  5  7  8  9
 *
 * 2. 插入排序在什么情况下最高?
 *       (1)在序列基本有序情况下
 *       (2)插入排序时,数据比较少
 * *******************************************/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX 10

long getsystime()
{
    struct timeb tb;
    ftime(&tb);
    return tb.time*1000+tb.millitm;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 插入排序
void InsertSort(int arr[], int length)
{   
    int j;
    //  因为将第一个元素看成是有序序列,
    //  所以插入排序是从第二个元素开始的
    for(int i = 1; i < length; i++)
    {
        if(arr[i] < arr[i-1])
        {
            int temp = arr[i];
            for(j = i - 1; j >= 0 && temp < arr[j]; j--)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = temp;
        }
    }
}


// 打印函数
void PrintArry(int arr[], int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\n");
}

int main()
{
    int arr[MAX];
    srand((unsigned int)time(NULL));

    for(int i = 0; i < MAX; i++)
    {
        int temp = rand() % MAX;
        arr[i] = temp;
    }


    printf("插入排序前:\n");
    PrintArry(arr, MAX);
    
    printf("插入排序后:\n");
    InsertSort(arr, MAX);
    PrintArry(arr, MAX);


    return 0;
}

