#pragma once
#include <iostream>
#include "vector.h"
#include "Satur.h"
#include <initializer_list>
#include <iomanip>

vector::vector(int s) {
	if (s <= 0) error("Value of the array must be positive and integer.");
	sz = s;
	v = new Satur[s];
	if (v == 0) error("Array not initilized");
	for (int i = 0; i < size(); i++) v[i] = 0;
}

vector::~vector() {
	delete[] v;
}

vector::vector(const std::initializer_list<float> &list) : vector(list.size()) {
	int count = 0;
	for (auto &elem : list)
	{
		v[count] = elem;
		++count;
	}
}

vector::vector(const vector & obj)// : vector(obj.size())
{
	sz = obj.size();
	v = new Satur [sz];
	int s = size();
	for (int i = 0; i < s; i++) v[i] = obj.v[i];
}


vector vector::operator=(float dig) {
	int s = size();
	for (int i = 0; i < s; i++) v[i] = dig;
	return *this;
}

vector  operator + (vector &frst, vector & scnd) {
	if (frst.size() != scnd.size()) error("Arrays sizes do not match");
	vector tmp(frst.size());
	int s = tmp.size();
	for (int i = 0; i < s; i++) tmp.v[i] = frst[i] + scnd.v[i];
	return tmp;
}


bool vector:: operator ==(vector &obj) {
	if (this == &obj) return 1;
	if (size() != obj.size()) return 0;
	int s = size();
	for (int i = 0; i < s; i++) {
		if (v[i] != obj.v[i]) return 0;
	}
	return 1;
}

Satur & vector:: operator [](int i) {
	if (i < 0 || sz <= i)
		error("Index cannot be negative or less than array size");
	return v[i];
}

const vector vector::operator = (const vector &obj) {
	int s = obj.size();
	if (size() != s) {
		delete[] v;
		sz = obj.size();
		v = new Satur[s];
		if (v == 0) error("Array not initilized");
	}
	for (int i = 0; i < s; i++) v[i] = obj.v[i];
	return *this;
}

void error(const char *p) {
	printf(p);
	cout << endl;
	system("pause");
	exit(0);
}

ostream& operator<<(ostream& os, vector & tmp) {
	os << "| ";
	for (int i = 0; i < tmp.size(); i++) {
		os << tmp[i];
	}
	os << "\n";
	return os;
}

