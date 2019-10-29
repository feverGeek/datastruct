#include "DynamicArray.h"

Dynamic_Array * Init_Array()
{
	Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));

	myArray->size = 0;
	myArray->capacity = 20;
	myArray->pAddr = (int*)malloc(sizeof(int) * 20);

	return myArray;
}

void PushBack_Array(Dynamic_Array * array, int value)
{
	if (array->pAddr == nullptr)
		return;

	if (array->size == array->capacity)
	{
		int* newSpace = (int*)malloc(sizeof(int)*array->capacity * 2);
		memcpy(newSpace, array->pAddr, array->capacity * sizeof(int));
		free(array->pAddr);

		array->capacity = array->capacity * 2;
		array->pAddr = newSpace;
	}

	array->pAddr[array->size] = value;
	array->size++;
}

void RemoveByPos_Array(Dynamic_Array * array, int pos)
{
	if (array->pAddr == nullptr)
		return;

	if (pos < 0 || pos >= array->size)
		return;

	for (int i = pos; i < array->size; i++)
	{
		array->pAddr[i] = array->pAddr[i + 1];
	}
	array->size--;
}

// 删除value第一次出现的位置
void RemoveByValue_Array(Dynamic_Array * array, int value)
{
	if (array == nullptr)
		return;

	int pos = GetPos_Array(array, value);
	RemoveByPos_Array(array, pos);
}

void FreeSpace_Array(Dynamic_Array * array)
{
	if (array->pAddr == nullptr)
		return;

	free(array->pAddr);
	free(array);
}

int GetPos_Array(Dynamic_Array * array, int value)
{
	if (array->pAddr == nullptr)
		return -1;

	int pos = -1;
	for (int i = 0; i < array->size; i++)
	{
		if (array->pAddr[i] == value)
		{
			pos = i;
			break;
		}
	}
	return pos;  // 如果返回-1, 则为没找到
}

void Print_Array(Dynamic_Array * array)
{	
	if (array->pAddr == nullptr)
		return;

	for (int  i = 0; i < array->size; i++)
	{
		printf("%d", array->pAddr[i]);
	}
	printf("\n");
}


void Clear_Array(Dynamic_Array * array)
{
	if (array->pAddr == nullptr)
		return;

	array->size = 0;
}

int Capacity_Array(Dynamic_Array * array)
{
	if (array->pAddr == nullptr)
		return -1;

	return array->capacity;
}

int Size_Array(Dynamic_Array * array)
{
	if (array->pAddr == nullptr)
		return -1;

	return array->size;
}

int GetValue_Array(Dynamic_Array * array, int pos)
{
	return array->pAddr[pos];
}


