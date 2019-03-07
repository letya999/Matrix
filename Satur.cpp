#include "Satur.h"
#include <iostream>
#include <cmath>
#include "MyFloat.h"

using namespace std;

void Satur :: check(Satur frst, Satur scnd) {
	if (flag != 0 || frst.flag != 0)
		flag = 1;
}

void Satur :: know() {
	if (m == 0) {
		flag = 0;
		return;
	}
	if (e > L_E) {
		m = L_M;
		e = L_E;
		flag = 1;
	}

	if (e < -L_E) {
		m = L_M;
		e = -L_E;
		flag = 1;
	}
}

bool operator !=(Satur frst, Satur scnd) {
	if ( frst.flag !=0 == scnd.flag) return 0;
	if (frst != scnd) return 1;
	return 0;
}

Satur operator+(Satur frst, Satur scnd) {
	Satur tmp = operator+((MyFloat)frst, (MyFloat)scnd);
	int a = tmp.m, b = tmp.e;
	Satur obj(a, b);
	obj.check(frst, scnd);
	return obj;
}

Satur operator-(Satur frst, Satur scnd) {
	Satur obj = operator-((MyFloat)frst, (MyFloat)scnd);
	obj.check(frst, scnd);
	return obj;
}

Satur operator*(Satur frst, Satur scnd) {
	Satur obj = operator*((MyFloat)frst, (MyFloat)scnd);
	obj.check(frst, scnd);
	return obj;
}

Satur operator/(Satur frst, Satur scnd) {
	Satur obj = operator/((MyFloat)frst, (MyFloat)scnd);
	obj.check(frst, scnd);
	return obj;
}

ostream& operator<<(ostream& os, Satur & tmp) {
	if (tmp.e >= 0)
		os << tmp.m << "e+" << (tmp.e - SIZE + 1);
	else
		os << tmp.m << "e" << (tmp.e - SIZE + 1);
	if (tmp.flag) os << "*";
	os << " | ";
	return os;
}

Satur::operator float() {
	float tmp = (float) m;
	if (e - SIZE + 1 > 0)
		for (int i = 0; i < e - SIZE + 1; i++)
			tmp*= 10;
	if (e - SIZE + 1 <0)
		for (int i = 0; i < abs(e - SIZE + 1); i++)
			tmp/= 10;
	return tmp;
}