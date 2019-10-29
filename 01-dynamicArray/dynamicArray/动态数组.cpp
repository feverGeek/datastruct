#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "DynamicArray.h"

void test01()
{
	Dynamic_Array* myArray = Init_Array();
	printf("array capacity: %d\n", Capacity_Array(myArray));
	printf("array size : %d\n", Size_Array(myArray));
	for (int i = 0; i < 30; i++)
	{
		PushBack_Array(myArray, i);
	}
	printf("array capacity: %d\n", Capacity_Array(myArray));
	printf("array size : %d\n", Size_Array(myArray));
	Print_Array(myArray);

	RemoveByPos_Array(myArray, 0);
	Print_Array(myArray);

	RemoveByValue_Array(myArray, 27);
	Print_Array(myArray);

	int pos = GetPos_Array(myArray, 5);
	printf("value 5, pos: %d, value: %d", pos, GetValue_Array(myArray, pos));

	FreeSpace_Array(myArray);
}


int main()
{
	test01();
	system("pause");
	return 0;
}
