#include <iostream>

using namespace std;

void bubble(int *array, int size);
int* maximalProduct(int *array, int size);
void assert(int A[], int size, int *result)
{

		if (*maximalProduct(A, size) == *result)
		{
			cout << "OK" << endl;
		}
		else
		{
			cout << "FAIL; " << endl;
		}

}

int main()
{
	int A[4] = { 1,2,3,4 };
	int A1[3] = { 2,3,4 };
	int B[4]={ 2, 4, 6, 5 };
	int B1[3] = {4, 6, 5 };
	int C[6]={ 1, 2, 3, -1, -2, -3 };
	int C1[3] = { -3, -2, 3 };
	int D[4] = { 5, 10, 15, 20 };
	int D1[3] = {10, 15, 20 };
	assert(A, 4, A1);
	assert(B, 4, B1);
	assert(C, 6, C1);
	assert(D, 4, D1);
	return 0;
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
