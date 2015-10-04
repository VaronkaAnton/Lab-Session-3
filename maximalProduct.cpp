#include <iostream>

using namespace std;

void bubble(int *array, int size);
int* maximalProduct(int *array, int size);
void assert(int* a, int size, int* test)
{
	int* r;
	r = maximalProduct(a, size);
	for (int i = 0; i < 3; i++)
	{
		if (r[i] == test[i])
		{
			cout << "OK" << endl;
		}
		else 
		{ cout << "FAIL" << endl; }
	}
}
int main()
{
	int a[7] = { 1,2,3,4,5,6,7 };
	int test1[3] = { 5,6,7 };
	assert(a, 7, test1);
	int a1[7] = { 1,2,3,4,5,-6,-7 };
	int test2[3] = { -7,-6,5 };
	assert(a1, 7, test2);
	int a3[9] = { 1,2,3,2,3,2,4,2,1 };
	int test3[3] = { 3,3,4 };
	assert(a3, 9, test3);
}

int* maximalProduct(int *array, int size)
{
	int* result;
	result = new int;
	/*сортируем пузырьком и сравниваем произведение трёх наибольших с произведением
	двух наименьших на наибольшее (остальные заведомо меньше)*/
	bubble(array, size);
	if (*(array + size - 1) * *(array + size - 2) * *(array + size - 3) >= *array * *(array + 1) * *(array + size - 1))
		for (int i = 0; i < 3; i++)
			*(result + i) = *(array + size - 1 - i);
	else
	{
		for (int i = 0; i < 2; i++)
			*(result + i) = *(array + i);
		*(result + 2) = *(array + size - 1);
	}
	bubble(result, 3);
	return result;
	delete[]result;
}

//сортировка пузырьком
void bubble(int *array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (*(array + j) > *(array + j + 1))
			{
				int t = *(array + j);
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = t;
			}
		}
	}
}
