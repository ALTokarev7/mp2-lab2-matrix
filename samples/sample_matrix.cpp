// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------
void matAddMat()
{
	cout << "Введите размерность матрицы: ";
	size_t sz = 0;
	cin >> sz;
	TDynamicMatrix<int> a(sz), b(sz), c(sz);
	cout << "Введите первую матрицу: ";
	cin >> a;
	cout << "Введите вторую матрицу: ";
	cin >> b;
	cout << a << endl;
	cout << "\t + " << "\n\n";
	cout << b << endl;
	cout << "\t = " << "\n\n";
	c = a + b;
	cout << c << endl;
}
void matMulScal()
{
	cout << "Введите размерность матрицы: ";
	size_t sz = 0;
	cin >> sz;
	TDynamicMatrix<int> a(sz), c(sz);
	cout << "Введите первую матрицу: ";
	cin >> a;
	int num = 0;
	cout << "Введите число: ";
	cin >> num;
	cout << a << endl;
	cout << "\t * " << "\n\n";
	cout << "\t" << num << "\n\n";
	cout << "\t = " << "\n\n";
	c = a * num;
	cout << c << endl;
}
void matMul()
{
	cout << "Введите размерность матрицы: ";
	size_t sz = 0;
	cin >> sz;
	TDynamicMatrix<int> a(sz), b(sz), c(sz);
	cout << "Введите первую матрицу: ";
	cin >> a;
	cout << "Введите вторую матрицу: ";
	cin >> b;
	cout << a << endl;
	cout << "\t * " << "\n\n";
	cout << b << endl;
	cout << "\t = " << "\n\n";
	c = a * b;
	cout << c << endl;
}
void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Тестирование класс работы с матрицами"
		<< endl;
	cout << "Выберите операцию (введите номер): " << endl;
	cout << "1.Матрица * матрица" << endl;
	cout << "2.Матрица + матрица" << endl;
	cout << "3.Матрица * число" << endl;
	
	size_t choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 1:
		matMul();
		break;
	case 2:
		matAddMat();
		break;
	case 3:
		matMulScal();
		break;
	default:
		cout << "Неверный номер!";
		break;
	}
}
//---------------------------------------------------------------------------
