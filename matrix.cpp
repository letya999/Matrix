#include "matrix.h"
#include "vector.h"
#include "Satur.h"

matrix::matrix(int l, int w) {
	if (l <= 0 || w <= 0) error("Matrix size must be non-negative");
	arr = new vector*[w];
	for (int i = 0; i < w; i++) {
		arr[i] = new vector(l);
	}
	len = l;
	wid = w;
}

matrix::matrix(const matrix &tmp) {
	len = tmp.get_l();
	wid = tmp.get_w();
	arr = new vector*[wid];
	for (int i = 0; i < wid; i++) {
		arr[i] = new vector(len);
	}
	for (int i = 0; i < wid; i++)
		*arr[i] = *tmp.arr[i];
}

vector & matrix::operator[] (int i) const{
	if(i > get_w() || i<0) error("Matrix index must be non-negative and less zero");
	return *arr[i];
}

matrix::~matrix() { 
	for (int i = 0; i < wid; i++)
		delete arr[i];
	delete arr;
}

matrix::operator float() {
	float tmp = 0;
	for (int i = 0; i < wid; i++)
		for (int j = 0; j < len; j++)
			tmp += arr[i]->elem(j);
	return tmp;
}

matrix::operator vector() {
	vector tmp = get_l();
	for (int j = 0; j < wid; j++)
		tmp = tmp + *arr[j];
	return tmp;
}

matrix& matrix::operator=(float dig) {
	for (int i = 0; i < wid; i++)
		for (int j = 0; j < len; j++)
			arr[i]->elem(j) = dig;
	return *this;
}

matrix& matrix::operator = (const matrix &obj) {
	if (this == &obj) return *this;
		int l = obj.get_l();
		int w = obj.get_w();
		if (wid < w) {
			this->~matrix();
			arr = new vector*[w];
			for (int i = 0; i < w; i++)
			{
				arr[i] = new vector(l);
			}
			len = l;
			wid = w;
			if (*arr == 0) error("Array not initilized");
		}
		if (wid > w) {
			for (int i = w+1; i < wid; i++) delete arr[i];
			wid = w;
		}
		for (int i = 0; i < wid; i++)
			*arr[i] = *obj.arr[i];
	return *this;
}

matrix operator+(matrix &frst, matrix & scnd) {
	int l = frst.get_l();
	int w = frst.get_w();
	if (w!= scnd.get_w() || l!= scnd.get_l()) 
		error("Matrix sizes do not match");
	matrix tmp(l, w);
	for (int i = 0; i < w; i++)
		tmp[i] = frst[i] + scnd[i];
	return tmp;
}

matrix & matrix::operator*(float tmp) {
	for (int i = 0; i < wid; i++)
		for (int j = 0; j < len; j++)
			arr[i]->elem(j) = Satur(tmp * (float)arr[i]->elem(j));
	return *this;
}

matrix operator-(matrix &frst, matrix & scnd) {
	int l = frst.get_l();
	int w = frst.get_w();
	if (l != scnd.get_w() || l != scnd.get_l())
		error("Matrix sizes do not match");
	matrix tmp(l, w);
	for (int i = 0; i < w; i++)
		for (int j = 0; j < l; j++)
			tmp[i][j] = frst[i][j] - scnd[i][j];
	return tmp;
}

ostream & operator << (ostream& os, const matrix& tmp) {
	int w = tmp.get_w();
	os << "\n";
	for (int i = 0; i < w; i++) {
		os << tmp[i];
		os << "\n";
	}
	return os;
}