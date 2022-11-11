// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

void autoGeneration(TDynamicMatrix<int>& m)
{
	int LO = -5;
	int HI = 5;

	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m.size(); j++)
		{
			m[i][j] = LO + (rand() / (RAND_MAX / (HI - LO)));
		}
	}
}

void matAddMat(size_t genType)
{
	cout << "Введите размерность матрицы: ";
	size_t sz = 0;
	cin >> sz;
	TDynamicMatrix<int> a(sz), b(sz), c(sz);
	if (genType == 2) 
	{
		cout << "Введите первую матрицу: ";
		cin >> a;
		cout << "Введите вторую матрицу: ";
		cin >> b;
	}
	else
	{
		autoGeneration(a);
		autoGeneration(b);
	}
	cout << a << endl;
	cout << "\t + " << "\n\n";
	cout << b << endl;
	cout << "\t = " << "\n\n";
	c = a + b;
	cout << c << endl;
}
void matMulScal(size_t genType)
{
	cout << "Введите размерность матрицы: ";
	size_t sz = 0;
	cin >> sz;
	TDynamicMatrix<int> a(sz), c(sz);
	int num = 0;
	if (genType == 2)
	{
		cout << "Введите первую матрицу: ";
		cin >> a;
		cout << "Введите число: ";
		cin >> num;
	}
	else
	{
		autoGeneration(a);
		num = -5 + (rand() /(RAND_MAX / (10)));
	}
	cout << a << endl;
	cout << "\t * " << "\n\n";
	cout << "\t" << num << "\n\n";
	cout << "\t = " << "\n\n";
	c = a * num;
	cout << c << endl;
}
void matMul(size_t genType)
{
	cout << "Введите размерность матрицы: ";
	size_t sz = 0;
	cin >> sz;
	TDynamicMatrix<int> a(sz), b(sz), c(sz);
	if (genType == 2)
	{
		cout << "Введите первую матрицу: ";
		cin >> a;
		cout << "Введите вторую матрицу: ";
		cin >> b;
	}
	else
	{
		autoGeneration(a);
		autoGeneration(b);
	}
	cout << a << endl;
	cout << "\t * " << "\n\n";
	cout << b << endl;
	cout << "\t = " << "\n\n";
	c = a * b;
	cout << c << endl;
}
void main()
{
	srand(static_cast <unsigned> (time(0)));

	setlocale(LC_ALL, "Russian");
	cout << "Тестирование класс работы с матрицами"
		<< endl;
	cout << "Выберите операцию (введите номер): " << endl;
	cout << "1.Матрица * матрица" << endl;
	cout << "2.Матрица + матрица" << endl;
	cout << "3.Матрица * число" << endl;
	size_t choose = 0;
	cin >> choose;
	cout << "Нажмите 1 для автоматической генерации матриц." << endl;
	cout << "Нажмите 2 для заполнения матриц с клавиатуры." << endl;
	size_t genType = 0;
	cin >> genType;
	switch (choose)
	{
	case 1:
		matMul(genType);
		break;
	case 2:
		matAddMat(genType);
		break;
	case 3:
		matMulScal(genType);
		break;
	default:
		cout << "Неверный номер!";
		break;
	}
}
//---------------------------------------------------------------------------
