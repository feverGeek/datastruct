#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX 20000

long getSystemTime()
{
    struct timeb tb;
    ftime(&tb);
    return tb.time*1000 + tb.millitm;
}


// 交换
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


// 冒泡排序
void BubbleSort(int arr[], int length)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = length - 1; j > i; j--)
        {
            if(arr[j-1] < arr[j])
            {
                swap(&arr[j-1], &arr[j]);
            }
        }
    }
}

// 打印函数
void PrintArry(int arr[], int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[MAX];

    srand((unsigned int) time(NULL));
    for(int i = 0; i < MAX; i++)
    {
        arr[i] = rand() % MAX;
    }

    // 排序前
    //printf("排序前:\n");
    //PrintArry(arr, MAX);

    long t_start = getSystemTime();
    // 冒泡
    BubbleSort(arr, MAX);

    long t_end = getSystemTime();
    // 排序后
    printf("排序后:\n");
    //PrintArry(arr, MAX);
    printf("%d个元素,所用时间:%ld", MAX, t_end-t_start);
    return 0;
}

