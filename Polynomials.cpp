#include <iostream>

using namespace std;

int max(int a, int b);
int* sumOfPolynoms(int* Polynom1, int* Polynom2, int deg1, int deg2);
int* productOfPolynoms(int* Polynom1, int* Polynom2, int deg1, int deg2);


int main()
{
	return (0);
}

//�������, ������������ ������ ������������� ������������; ���������: ��� �������, �� �������
int* productOfPolynoms(int* Polynom1, int* Polynom2, int deg1, int deg2)
{//������ ������ ������������, ��������������� ��������, ������� ������� ���������� 
	for (int i = deg2 + 1; i <= deg1 + deg2; i++)
		*(Polynom2 + i) = 0;
	for (int i = deg1 + 1; i <= deg1 + deg2; i++)
		*(Polynom1 + i) = 0;
	//�������������� ������, ��������������� ������������� ���������� ������������
	int *productResult;
	productResult = new int[deg1 + deg2 + 1];//�������� ������ ��� ������ ������������
	for (int i = 0; i <= deg1 + deg2; i++)
		*(productResult + i) = 0; //��� �������� ���������� � ����

	for (int i = 0; i <= deg1 + deg2; i++)
		for (int j = 0; j <= i; j++)
			*(productResult + i) += *(Polynom1 + j) * *(Polynom2 + i - j); //����������� �������� ��������� ������� ������������
	return productResult; //������� ���������� ������ ������������
	delete[]productResult; //����������� �������� ������ ������
}

//�������, ������������ ������ ������������� �����; ���������: ��� �������, �� �������
int* sumOfPolynoms(int* Polynom1, int* Polynom2, int deg1, int deg2)
{//���������� � ����� �������� ������� ���������� ������� �������, ��������������� ��������, 
 //������� ���� � ���������� ������� �������, � ������� ��� � ���������� ������� �������
	if (max(deg1, deg2) == deg1)
		for (int i = deg2 + 1; i <= deg1; i++)
			*(Polynom2 + i) = 0;
	else
		for (int i = deg1 + 1; i <= deg2; i++)
			*(Polynom1 + i) = 0;
	int *sumResult; //������������� ������� � �������������� �����
	sumResult = new int[max(deg1, deg2) + 1]; //��������� ������ ��� ����
	for (int i = 0; i <= max(deg1, deg2); i++)
		*(sumResult + i) = *(Polynom1 + i) + *(Polynom2 + i); //����������� ������� ������������ ��� ��������
	return sumResult; //������� ��������� ������ ������������� �����
	delete[]sumResult; //������������ ������
}

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}
