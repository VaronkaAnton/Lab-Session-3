#include <iostream>

using namespace std;

int max(int a, int b);
int* sumOfPolynoms(int* Polynom1, int* Polynom2, int deg1, int deg2);
int* productOfPolynoms(int* Polynom1, int* Polynom2, int deg1, int deg2);
void assertpro(int* a, int* b, int n, int m, int* test);
void assertsum(int* a, int* b, int n, int m, int* test);



int main()
{
	int a[3] = { 1,2,6 };
	int b[2] = { 2,3 };
	int test[4] = { 2,7,18,18 };
	int test1[3] = { 3,5,6 };
	assertpro(a, b, 2, 1, test);
	assertsum(a, b, 2, 1, test1);
	int f[3] = { 3,5,4 };
	int g[2] = { 3,10 };
	int test5[4] = { 9,45,62,40 };
	int test6[3] = { 6,15,4 };
	assertpro(f, g, 2, 1, test5);
	assertsum(f, g, 2, 1, test6);
	return 0;
}

//функция, возвращающая массив коэффициентов произведения; аргументы: два массива, их степени
int* productOfPolynoms(int* Polynom1, int* Polynom2, int deg1, int deg2)
{//делаем нулями коэффициенты, соответствующие степеням, бОльшим степени многочлена 
	for (int i = deg2 + 1; i <= deg1 + deg2; i++)
		Polynom2 [i] = 0;
	for (int i = deg1 + 1; i <= deg1 + deg2; i++)
		Polynom1 [i] = 0;
	//инициализируем массив, соответствующий коэффициентам многочлена произведения
	int productResult [100];
	for (int i = 0; i <= deg1 + deg2; i++)
		productResult [i] = 0; //все элементы приравняем к нулю

	for (int i = 0; i <= deg1 + deg2; i++)
		for (int j = 0; j <= i; j++)
			productResult [i] += Polynom1 [j] * Polynom2 [i - j]; //увеличиваем значения элементов массива произведения
	return productResult; //функция возвращает массив произведения
}

//функция, возвращающая массив коэффициентов суммы; аргументы: два массива, их степени
int* sumOfPolynoms(int* Polynom1, int* Polynom2, int deg1, int deg2)
{//приравняем к нулям элементы массива многочлена меньшей степени, соответствующие степеням, 
 //которые есть в многочлене большей степени, и которых нет в многочлене меньшей степени
	if (max(deg1, deg2) == deg1)
		for (int i = deg2 + 1; i <= deg1; i++)
			Polynom2 [i] = 0;
	else
		for (int i = deg1 + 1; i <= deg2; i++)
			Polynom1 [i] = 0;
	int sumResult [100]; //инициализация массива с коэффициентами суммы
	for (int i = 0; i <= max(deg1, deg2); i++)
		sumResult [i] = Polynom1 [i] + Polynom2 [i]; //присваиваем каждому коэффициенту его значение
	return sumResult; //функция возвраает массив коэффициентов суммы
}

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

void assertpro(int* a, int* b, int n, int m, int* test)
{
	int sch = 0;
	int* r = productOfPolynoms(a, b, n, m);
	for (int i = 0; i <= (m + n); i++)
	{
		if (test[i] == r[i])
		{
			sch++;
		}
	}
	if (sch == (n + m + 1))
	{
		cout << "pro ok" << endl;
	}
	else
	{
		cout << "pro false " << endl;
	}
}
void assertsum(int* a, int* b, int n, int m, int* test)
{
	int sch = 0;
	int g = 0;
	int* r = sumOfPolynoms(a, b, n, m);
	if (n > m)
	{
		g = n;
	}
	else
	{
		g = m;
	}
	for (int i = 0; i < (g + 1); i++)
	{
		if (test[i] == r[i])
		{
			sch++;
		}
	}
	if (sch == (g + 1))
	{
		cout << "sum ok" << endl;
	}
	else
	{
		cout << "sum false " << endl;
	}
}