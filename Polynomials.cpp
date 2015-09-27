#include <iostream>

using namespace std;

int max(int a, int b);
int* sumOfPolynoms(int* Polynom1, int* Polynom2, int deg1, int deg2);
int* productOfPolynoms(int* Polynom1, int* Polynom2, int deg1, int deg2);


int main()
{
	return (0);
}

//функция, возвращающая массив коэффициентов произведения; аргументы: два массива, их степени
int* productOfPolynoms(int* Polynom1, int* Polynom2, int deg1, int deg2)
{//делаем нулями коэффициенты, соответствующие степеням, бОльшим степени многочлена 
	for (int i = deg2 + 1; i <= deg1 + deg2; i++)
		*(Polynom2 + i) = 0;
	for (int i = deg1 + 1; i <= deg1 + deg2; i++)
		*(Polynom1 + i) = 0;
	//инициализируем массив, соответствующий коэффициентам многочлена произведения
	int *productResult;
	productResult = new int[deg1 + deg2 + 1];//выделяем память под массив произведения
	for (int i = 0; i <= deg1 + deg2; i++)
		*(productResult + i) = 0; //все элементы приравняем к нулю

	for (int i = 0; i <= deg1 + deg2; i++)
		for (int j = 0; j <= i; j++)
			*(productResult + i) += *(Polynom1 + j) * *(Polynom2 + i - j); //увеличиваем значения элементов массива произведения
	return productResult; //функция возвращает массив произведения
	delete[]productResult; //освобождаем ненужную больше память
}

//функция, возвращающая массив коэффициентов суммы; аргументы: два массива, их степени
int* sumOfPolynoms(int* Polynom1, int* Polynom2, int deg1, int deg2)
{//приравняем к нулям элементы массива многочлена меньшей степени, соответствующие степеням, 
 //которые есть в многочлене большей степени, и которых нет в многочлене меньшей степени
	if (max(deg1, deg2) == deg1)
		for (int i = deg2 + 1; i <= deg1; i++)
			*(Polynom2 + i) = 0;
	else
		for (int i = deg1 + 1; i <= deg2; i++)
			*(Polynom1 + i) = 0;
	int *sumResult; //инициализация массива с коэффициентами суммы
	sumResult = new int[max(deg1, deg2) + 1]; //выделение памяти под него
	for (int i = 0; i <= max(deg1, deg2); i++)
		*(sumResult + i) = *(Polynom1 + i) + *(Polynom2 + i); //присваиваем каждому коэффициенту его значение
	return sumResult; //функция возвраает массив коэффициентов суммы
	delete[]sumResult; //освобождение памяти
}

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}
