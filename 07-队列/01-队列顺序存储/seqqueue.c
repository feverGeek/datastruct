#include "seqqueue.h"
#include <stdlib.h>
#include <stdio.h>

// 初始化
SeqQueue* Init_SeqQueue()
{
    SeqQueue *queue = (SeqQueue *)malloc(sizeof(SeqQueue));
    for(int i = 0; i < MAX_SIZE; i++)
    {
        queue->data[i] = NULL;
    }
    queue->size = 0;
    return queue;
}

// 入队
void Push_SeqQueue(SeqQueue *queue, void *data)
{
    if(queue == NULL || data == NULL || queue->size == MAX_SIZE)
        return ;
    queue->data[queue->size] = data;
    queue->size++;
}

// 返回队头元素
void *Front_SeqQueue(SeqQueue *queue)
{
    if(queue == NULL || queue->size == 0)
        return NULL;
    return queue->data[0];
}

// 出队
void Pop_SeqQueue(SeqQueue *queue)
{
    if(queue == NULL || queue->size == 0)
        return ;

    for(int i=0; i < queue->size; i++)
        queue->data[i] = queue->data[i+1];
    queue->size--;
}

// 返回队尾元素
void *Back_SeqQueue(SeqQueue *queue)
{
    if(queue == NULL || queue->size == 0)
        return NULL;

    return queue->data[queue->size-1];
}

// 返回大小
int Size_SeqQueue(SeqQueue *queue)
{
    if(queue == NULL)
        return -1;
    return queue->size;
}

// 清空队列
void Clear_SeqQueue(SeqQueue *queue)
{
    if(queue == NULL)
        return;
    queue->size = 0;
}

// 销毁
void FreeSpace_SeqQueue(SeqQueue *queue)
{
    if(queue == NULL)
        return;
    free(queue);
}


