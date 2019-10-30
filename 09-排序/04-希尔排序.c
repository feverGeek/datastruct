/******************************
 *
 * 希尔排序
 *
 *      1. 插入排序在什么情况下最高?
 *       (1)在序列基本有序情况下
 *       (2)插入排序时,数据比较少
 *     
 *      2. 由于插入排序的要求比较严苛，出现了分组插入排序
 *         先分组　然后对每一组分别插入排序
 *
 *
 * 从小到大排序
 *      4  2  8  0  5  7  1  3  9
 *      
 *  (1)分组
 *      4     8     5     1     9
 *         2     0     7     3
 *
 *  (2)分别插入排序
 *      (A)    4  8  5  1  9
 *             4  8 (5) 1  9
 *             4  5  8  1  9
 *             4  5  8 (1) 9
 *             4  5  1  8  9
 *             4  1  5  8  9
 *      (A)    1  4  5  8  9
 *
 *      (B)    2  0  7  3
 *             2 (0) 7  3
 *             0  2  7  3
 *             0  2  7 (3)
 *      (B)    0  2  3  7 
 *
 *  (3) 把 (A) (B) 合并
 *      1 0 4 2 5 3 8 7 9
 *
 *  (4) 插入排序
 *      1  0  4  2  5  3  8  7  9
 *      1 (0) 4  2  5  3  8  7  9
 *      0  1  4  2  5  3  8  7  9
 *      0  1  4 (2) 5  3  8  7  9
 *      0  1  2  4  5  3  8  7  9
 *      0  1  2  4  5 (3) 8  7  9
 *      0  1  2  4  3  5  8  7  9
 *      0  1  2  3  4  5  8  7  9
 *      0  1  2  3  4  5  8 (7) 9
 *      0  1  2  3  4  5  7  8  9
 *
 *   3. 新的问题　就是分组怎么确定
 *      经过大量的观察　分组的经验式为 increasement / 3 + 1
 * *********************************/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX 20000

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

// 希尔排序 从小到大
void ShellSort(int arr[], int length)
{
    int increasement = length;
    int i, j, k;

    do
    {
        // 确定分组增量
        increasement = increasement / 3 + 1;
        for(i = 0; i < increasement; i++)
        {
            for(j=i+increasement; j < length; j+=increasement)
            {
                if(arr[j] < arr[j-increasement])
                {
                    int temp = arr[j];
                    for(k=j-increasement; k >= 0 && temp < arr[k]; k-=increasement)
                    {
                        arr[k+increasement] = arr[k];
                    }
                    arr[k+increasement] = temp;
                }
            }

        }

    }while(increasement > 1);

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

    long tshell_start = getsystime();
    ShellSort(arr, MAX);
    long tshell_end = getsystime();


    printf("time is %ld\n", tshell_end-tshell_start);


    return 0;
}

