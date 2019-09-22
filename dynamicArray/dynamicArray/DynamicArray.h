#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H  

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct DYNAMICARRAY {
	int *pAddr;  // ָ���ַ
	int size;   // Ԫ�ظ���
	int capacity; // ����
}Dynamic_Array;

Dynamic_Array* Init_Array(); // ��ʼ��
void PushBack_Array(Dynamic_Array* array, int value);// ����
void RemoveByPos_Array(Dynamic_Array* array, int pos); // ɾ��
void RemoveByValue_Array(Dynamic_Array* array, int value);
void FreeSpace_Array(Dynamic_Array* array); // �ͷ�
int  GetPos_Array(Dynamic_Array* array, int value); // ����
void Print_Array(Dynamic_Array* array); // ��ӡ
void Clear_Array(Dynamic_Array* array);
int Capacity_Array(Dynamic_Array* array);
int Size_Array(Dynamic_Array* array);
int GetValue_Array(Dynamic_Array* array, int pos);

#endif