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

	inline int get_l() const { //����� �����
		return len;
	}

	inline int get_w() const { //����� ��������
		return wid;
	}

	vector & operator & (int i) { //��������� ������ �������
		return *arr[i];
	}

	vector &operator[] (int) const; //�������� ���������� ������� 
	matrix& operator=(float); //������������ ����� ���� ��������� �������
	matrix& operator =(const matrix &); //�������� ������������
	operator float (); //��������������� ������� � ������������� ����
	operator vector (); //��������������� ������� � �������
	friend matrix operator +(matrix &, matrix &); //�������� �������� ������
	friend matrix operator -(matrix &, matrix &); //�������� ��������� ������
	matrix& operator *(float tmp);
	friend ostream& operator<<(ostream&, const matrix&);
};