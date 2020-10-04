// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
using namespace std;
//---------------------------------------------------------------------------

void main()
{
  TMatrix<int> a(5), b(5), c(5);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки представления треугольных матриц"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
}
//---------------------------------------------------------------------------*/

/*template <class ValType>
void Print(TVector<ValType>& v)
{
	cout << "Choose operation" << endl;
	if (v.GetSize() <= 4)
	{
		cout << "1. Enter from the keyboard\n2. Random\n";
		int operation;
		cin >> operation;
		if (operation == 1)
		{
			cin >> v;
		}
		else
		{
			v.enter();
		}
	}
	else
	{
		v.enter();
	}
};
template <class ValType>
void operations(TVector<ValType>& v, int number)
{
	int temp;
	Print(v);
	cout << "Your vector:\n" << v << endl;
	while (true)
	{
		cout << "Choose the operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Exit" << endl;
		cin >> number;
		switch (number)
		{
		case 1:
		{
			int num;
			cout << "1.Vector+vector\n2.Vector+number\n";
			cin >> num;
			if (num == 1)
			{
				int size2;
				cout << "Enter a size of 2 vector: \n";
				cin >> size2;
				TVector<ValType> v2(size2), res;
				Print(v2);
				cout << "Your vector:\n" << v2 << endl;
				try
				{
					res = v + v2;
					if (v.GetSize() <= 4)
					{
						cout << "Result:\n" << res << endl;
					}
				}
				catch (int size)
				{
					cout << "Size of vector 1 = " << v.GetSize() << endl << "Size of vector 2 = " << size2 << endl << "Different sizes" << endl;
				}
			}
			else
			{
				TVector<ValType> res;
				ValType n;
				cout << "Enter a number:\n";
				cin >> n;
				cout << "Your number: " << n << endl;
				res = v + n;
				if (v.GetSize() <= 4)
				{
					cout << "Result:\n" << res << endl;
				}
			}
			break;
		}
		case 2:
		{
			int num;
			cout << "1.Vector-vector\n2.Vector-number\n";
			cin >> num;
			if (num == 1)
			{
				int size2;
				cout << "Enter a size of 2 vector: \n";
				cin >> size2;
				TVector<ValType> v2(size2), res;
				Print(v2);
				cout << "Your vector:\n" << v2 << endl;
				try
				{
					res = v - v2;
					if (v.GetSize() <= 4)
					{
						cout << "Result:\n" << res << endl;
					}
				}
				catch (int size)
				{
					cout << "Size of vector 1 = " << v.GetSize() << endl << "Size of vector 2 = " << size2 << endl << "Different sizes" << endl;
				}
			}
			else
			{
				TVector<ValType> res;
				ValType n;
				cout << "Enter a number:\n";
				cin >> n;
				cout << "Your number: " << n << endl;
				res = v - n;
				if (v.GetSize() <= 4)
				{
					cout << "Result:\n" << res << endl;
				}
			}
			break;
		}
		case 3:
		{
			int num;
			cout << "1.Vector*vector\n2.Vector*number\n";
			cin >> num;
			if (num == 1)
			{
				int size2;
				cout << "Enter a size of 2 vector: \n";
				cin >> size2;
				TVector<ValType> v2(size2);
				ValType res;
				Print(v2);
				cout << "Your vector:\n" << v2 << endl;
				try
				{
					res = v * v2;
					if (v.GetSize() <= 4)
					{
						cout << "Result:\n" << res << endl;
					}
				}
				catch (int size)
				{
					cout << "Size of vector 1 = " << v.GetSize() << endl << "Size of vector 2 = " << size2 << endl << "Different sizes" << endl;
				}
			}
			else
			{
				TVector<ValType> res;
				ValType n;
				cout << "Enter a number:\n";
				cin >> n;
				cout << "Your number: " << n << endl;
				res = v * n;
				if (v.GetSize() <= 4)
				{
					cout << "Result:\n" << res << endl;
				}
			}
			break;
		}
		case 4:
		{
			exit(0);
		}
		}
	}
}
void main()
{
	int size, number=0;
	while (true)
	{
		cout << "Enter a size of vector:" << endl;
		cin >> size;
		if (size >0)
		{
			try
			{
				TVector<int> v(size);
				operations(v, number);
			}
			catch (int size)
			{
				cout << "Size of vector can't be <=0" << size;
			}
		}
		
	}
}*/
