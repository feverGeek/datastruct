// 分治法+挖坑填数
// 分治法：大问题分解成小问题，对小问题求解，使得大问题得到解决
// // 4  2  8  0  5  7  1  3  9// // 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX 1000000


long getsystime()
{
    struct timeb tb;
    ftime(&tb);
    return tb.time*1000+tb.millitm;
}

void PrintArray(int arr[], int length)
{	
    for (int i = 0; i < length; ++i)	
    {		
        printf("%d", arr[i]);	
    }	
    printf("\n");}
    
// 从小到大
void QuickSort(int arr[], int start, int end)
{	
    int i = start;	
    int j = end;	
    int temp = arr[start];	
    if (i < j)	
    {		
        while (i < j)		
        {			
            // 从右向左找比基准数小的数			
            while(i < j && arr[j] >= temp)				
                j--;			
            // 填坑			
            if (i < j)			
            {				
                arr[i] = arr[j];				
                i++;			
            }			
            // 从左向右找比基准大的数			
            while(i < j && arr[i] < temp)				
                i++;			
            // 填坑			
            if (i < j)			
            {				
                arr[j] = arr[i];				
                j--;			
            }		
        }		
        // 把基准数放到i位置		
        arr[i] = temp;		
        // 对左半部分排序		
        QuickSort(arr, start, i-1);		
        // 对右半部分排序		
        QuickSort(arr, i+1, end);	
    }
}

int main(int argc, char const *argv[])
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

    //PrintArray(arr, MAX);	
    long tquick_start = getsystime();
    QuickSort(arr, 0, MAX-1);
    long tquick_end = getsystime();
    //PrintArray(arr, MAX);	

    printf("time: %ld\n", tquick_end - tquick_start);


    return 0;
}
