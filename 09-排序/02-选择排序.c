#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX 10000

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

// 选择排序
void SelectSort(int arr[], int length)
{
    for(int i = 0; i < length; i++)
    {
        int min = i;
        for(int j = i+1; j < length; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            swap(&arr[min], &arr[i]);
        }
    }

}

// 优化后的冒泡排序
void BubbbleSort(int arr[], int length)
{
    int flag = 0;
    for(int i = 0; i < length && flag == 0; i++)
    {
        flag = 1;
        for(int j = length - 1; j > i; j--)
        {
            if(arr[j-1] < arr[j])
            {
                flag = 0;
                swap(&arr[j-1], &arr[j]);
            }
        }
    }
}

int main()
{

    int arr[MAX];
    int arr2[MAX];
    srand((unsigned int)time(NULL));

    for(int i = 0; i < MAX; i++)
    {
        int temp = rand() % MAX;
        arr[i] = temp;
        arr2[i] = temp;
    }
    
    printf("%d个元素\n", MAX);

    long tbubble_start = getsystime();
    BubbbleSort(arr, MAX);
    long tbubble_end = getsystime();
    printf("冒泡需要时间:%ld\n", tbubble_end - tbubble_start);


    long tselect_start = getsystime();
    SelectSort(arr2, MAX);
    long tselect_end = getsystime();
    printf("选择需要时间:%ld\n", tselect_end - tselect_start);

    return 0;
}

