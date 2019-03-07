#pragma once
#include <iostream>
#include <assert.h>
#include "MyFloat.h"

#define L_M 9999
#define L_E 5

class Satur : public MyFloat {
protected:
	bool flag = 0;
public:
	Satur(double w=0) : MyFloat(w) {
		know();
	}

	Satur(int dig, int num) : MyFloat(dig, num) {
		know();
	}

	Satur(const MyFloat &frst) : MyFloat(frst) {
		know();
	}

	operator float();
	void know();
	void check(Satur, Satur);
	friend ostream& operator<<(ostream&, Satur &);
	friend Satur operator+(Satur, Satur);
	friend Satur operator-(Satur, Satur);
	friend Satur operator*(Satur, Satur);
	friend Satur operator/(Satur, Satur);
	friend bool operator!=(Satur, Satur);
};

