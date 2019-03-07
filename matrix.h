#pragma once
#include "vector.h"
#include "Satur.h"

class matrix {
protected:
	vector **arr;
	int len =5;
	int wid = 5;
public:
	matrix(int =5,int=5);
	matrix(const matrix &);
	~matrix();

	inline int get_l() const { //число строк
		return len;
	}

	inline int get_w() const { //число столбцов
		return wid;
	}

	vector & operator & (int i) { //получение адреса вектора
		return *arr[i];
	}

	vector &operator[] (int) const; //оператор индексации вектора 
	matrix& operator=(float); //присваивания флоат всем элементам матрицы
	matrix& operator =(const matrix &); //оператор присваивания
	operator float (); //преобразователь матрицы к вещественному типу
	operator vector (); //преобразователь матрицы к вектору
	friend matrix operator +(matrix &, matrix &); //оператор сложения матриц
	friend matrix operator -(matrix &, matrix &); //оператор вычитания матриц
	matrix& operator *(float tmp);
	friend ostream& operator<<(ostream&, const matrix&);
};