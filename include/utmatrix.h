﻿// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора

#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Шаблон вектора
template <class ValType>
class TVector
{
protected:
    ValType* pVector, * pVector2;
    int Size;       // размер вектора
    int StartIndex; // индекс первого элемента вектора
public:
    TVector(int s = 10, int si = 0);
    TVector(const TVector& v);                // конструктор копирования
    ~TVector();
    int GetSize() { return Size; } // размер вектора
    int GetStartIndex() { return StartIndex; } // индекс первого элемента
    ValType& operator[](int pos);             // доступ
    bool operator==(const TVector& v) const;  // сравнение
    bool operator!=(const TVector& v) const;  // сравнение
    TVector& operator=(const TVector& v);     // присваивание

    TVector<ValType>& enter();

    // скалярные операции
    TVector  operator+(const ValType& val);   // прибавить скаляр
    TVector  operator-(const ValType& val);   // вычесть скаляр
    TVector  operator*(const ValType& val);   // умножить на скаляр

    // векторные операции
    TVector  operator+(const TVector& v);     // сложение
    TVector  operator-(const TVector& v);     // вычитание
    ValType  operator*(const TVector& v);     // скалярное произведение

    // ввод-вывод
    friend istream& operator>>(istream& in, TVector& v)
    {
        for (int i = 0; i < v.Size; i++)
            in >> v.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TVector& v)
    {
        for (int i = 0; i < v.Size; i++)
            out << v.pVector[i] << ' ';
        return out;
    }
};
template <class ValType>
TVector<ValType>& TVector<ValType>::enter()
{
    double max, min;
    cout << "Enter a range of numbers" << endl;
    cout << "min: ";
    cin >> min;
    cout << "max: ";
    cin >> max;
    while (min > max)
    {
        cout << "The range of numbers is entered incorrectly, try again" << endl;
        cout << "min: ";
        cin >> min;
        cout << "max: ";
        cin >> max;
    }
    for (int i = 0; i < Size; i++)
    {
        pVector[i] = min + (max - min) * (ValType)rand() / RAND_MAX;
    }
    return (*this);
}

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
}

template <class ValType> //конструктор копирования +++
TVector<ValType>::TVector(const TVector<ValType>& v)
{
    {
        pVector = new ValType[v.Size];
        Size = v.Size;
        for (int i = 0; i < Size; i++)
        {
            pVector[i] = v.pVector[i];
        }
    }
}

template <class ValType>
TVector<ValType>::~TVector()//дестр++
{
    delete[]pVector;
}

template <class ValType> // доступ++
ValType& TVector<ValType>::operator[](int pos)
{
    if (pos < 0 || pos >= Size)
    {
        throw pos;
    }
    return pVector[pos];
}

template <class ValType> // сравнение+
bool TVector<ValType>::operator==(const TVector& v) const
{
    if (Size != v.Size)
    {
        return false;
    }
    for (int i = 0; i < Size; i++)
    {
        if (pVector[i] != v.pVector[i])
        {
            return false;
        }
    }
    return true;
}

template <class ValType> // сравнение+
bool TVector<ValType>::operator!=(const TVector& v) const
{
    if (Size != v.Size)
    {
        return true;
    }
    for (int i = 0; i < Size; i++)
    {
        if (pVector[i] != v.pVector[i])
        {
            return true;
        }
    }
    return false;
}

template <class ValType> // присваивание+
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
    delete[] pVector;
    Size = v.Size;
    pVector = new ValType[Size];
    for (int i = 0; i < Size; i++)
    {
        pVector[i] = v.pVector[i];
    }
    return (*this);
}

template <class ValType> // прибавить скаляр+
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
    TVector<ValType> v(Size);
    for (int i = 0; i < v.Size; i++)
    {
        v.pVector[i] = pVector[i] + val;
    }
    return v;
}

template <class ValType> // вычесть скаляр+
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
    TVector<ValType> v(Size);
    for (int i = 0; i < v.Size; i++)
    {
        v.pVector[i] = pVector[i] - val;
    }
    return v;
}

template <class ValType> // умножить на скаляр+
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
    TVector<ValType> v(Size);
    for (int i = 0; i < v.Size; i++)
    {
        v.pVector[i] = pVector[i] * val;
    }
    return v;
}

template <class ValType> // сложение+
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
    if (Size != v.Size)
    {
        throw v.Size;
    }
    TVector<ValType> res(Size);
    for (int i = 0; i < Size; i++)
    {
        res.pVector[i] = pVector[i] + v.pVector[i];
    }
    return res;
}

template <class ValType> // вычитание+
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
    if (Size != v.Size)
    {
        throw v.Size;
    }
    TVector<ValType> res(Size);
    for (int i = 0; i < Size; i++)
    {
        res.pVector[i] = pVector[i] - v.pVector[i];
    }
    return res;
}

template <class ValType> // скалярное произведение+
ValType TVector<ValType>::operator*(const TVector<ValType>& v)
{
    if (Size != v.Size)
    {
        throw v.Size;
    }
    ValType res = pVector[0] * v.pVector[0];
    for (int i = 1; i < Size; i++)
    {
        res += pVector[i] * v.pVector[i];
    }
    return res;
}

// Верхнетреугольная матрица
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
  TMatrix(int s = 10);                           
  TMatrix(const TMatrix &mt);                    // копирование
  TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа
  bool operator==(const TMatrix &mt) const;      // сравнение
  bool operator!=(const TMatrix &mt) const;      // сравнение
  TMatrix& operator= (const TMatrix &mt);        // присваивание
  TMatrix  operator+ (const TMatrix &mt);        // сложение
  TMatrix  operator- (const TMatrix &mt);        // вычитание

  // ввод / вывод
  friend istream& operator>>(istream &in, TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      in >> mt.pVector[i];
    return in;
  }
  friend ostream & operator<<( ostream &out, const TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      out << mt.pVector[i] << endl;
    return out;
  }
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
    if ((s < 0) || (s > MAX_MATRIX_SIZE))
        throw "incorrect size";
    for (int i = 0; i < s; i++)
        pVector[i] = TVector<ValType>(s, i);
    for (int i = 0; i < s; i++)
        for (int j = i; j < s; j++)
            pVector[i][j] = 0;
} /*-------------------------------------------------------------------------*/

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) :
    TVector<TVector<ValType> >(mt) {}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) :
    TVector<TVector<ValType> >(mt) {}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
    if (Size != mt.Size)
        return false;
    for (int i = StartIndex; i < Size; i++)
        if (pVector[i] != mt.pVector[i])
            return false;
    return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
    return !(*this == mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
    if (this != &mt)
    {
        if (Size != mt.Size)
        {
            delete[] pVector;
            pVector = new TVector<ValType>[mt.Size];
        }
        Size = mt.Size;
        for (int i = 0; i < Size; i++)
            pVector[i] = mt.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
    if (Size != mt.Size)
        throw "incorrect size";
    return TVector<TVector<ValType> >::operator+(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
    if (Size != mt.Size)
        throw "incorrect size";
    return TVector<TVector<ValType> >::operator-(mt);
} /*-------------------------------------------------------------------------*/

// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif

