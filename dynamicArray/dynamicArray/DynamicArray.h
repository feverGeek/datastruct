#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H  

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct DYNAMICARRAY {
	int *pAddr;  // 指向地址
	int size;   // 元素个数
	int capacity; // 容量
}Dynamic_Array;

Dynamic_Array* Init_Array(); // 初始化
void PushBack_Array(Dynamic_Array* array, int value);// 插入
void RemoveByPos_Array(Dynamic_Array* array, int pos); // 删除
void RemoveByValue_Array(Dynamic_Array* array, int value);
void FreeSpace_Array(Dynamic_Array* array); // 释放
int  GetPos_Array(Dynamic_Array* array, int value); // 查找
void Print_Array(Dynamic_Array* array); // 打印
void Clear_Array(Dynamic_Array* array);
int Capacity_Array(Dynamic_Array* array);
int Size_Array(Dynamic_Array* array);
int GetValue_Array(Dynamic_Array* array, int pos);

#endif