#include<iostream>
#include "MyFloat.h"
#include "Satur.h"
#include "vector.h"
#include "matrix.h"

using namespace std;

void main() {
	matrix a(1,4), b(2,1), c;
	a = 0.5;
	cout << a << endl;
	cout << b << endl;
	b = a;
	cout << a.get_l() << " " << a.get_w()<<endl;
	cout << b.get_l() << " " << b.get_w();
	c = a + b;
	cout << c;
	system("pause");
}