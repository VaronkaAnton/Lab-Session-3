#include <iostream>

using namespace std;

void bubble(int *array, int size);
void maximalProduct(int *array, int size);

int main()
{
	return(0);
}

void maximalProduct(int *array, int size)
{
	/*сортируем пузырьком и сравниваем произведение трёх наибольших с произведением
	двух наименьших на наибольшее (остальные заведомо меньше)*/
	bubble(array, size);
	if (*(array + size - 1) * *(array + size - 2) * *(array + size - 3) >= *array * *(array + 1) * *(array + size - 1))
		cout << *(array + size - 1) << " " << *(array + size - 2) << " " << *(array + size - 3) << endl;
	else
		cout << *array << " " << *(array + 1) << " " << *(array + size - 1) << endl;
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