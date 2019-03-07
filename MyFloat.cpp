#include <iostream>
#include <cmath>
#include "MyFloat.h"

using namespace std;

void MyFloat::print(void) {
	if(e>=0)
	  cout << m << "e+" << (e-SIZE + 1) << " ";
	else
	  cout << m << "e" << (e - SIZE + 1) << " ";
}

MyFloat operator+(MyFloat frst, MyFloat scnd) {
	MyFloat res;
	if(frst.e >= scnd.e) {
		res.e = frst.e;
        scnd.m /= pow(10, frst.e - scnd.e);
	}
	else {
		res.e = scnd.e;
        frst.m /= pow(10, scnd.e - frst.e);
	}
	res.m = frst.m + scnd.m;
	return res;
}

MyFloat operator-(MyFloat frst, MyFloat scnd) {
	
	scnd.m = -scnd.m;
	MyFloat tmp = operator+(frst, scnd);
	MyFloat result(tmp.m, tmp.e);
	return result;
}

MyFloat operator*(MyFloat frst, MyFloat scnd) {
	MyFloat res;
	res.m = frst.m * scnd.m;
	res.m /= 1000;
	res.e = frst.e + scnd.e;
	return res;
}

MyFloat operator/(MyFloat frst, MyFloat scnd) {
	frst.m *= pow(10, frst.e);
	scnd.m *= pow(10, scnd.e);
	MyFloat res = (float)frst.m / scnd.m;
	return res;
}

bool operator ==(MyFloat frst, MyFloat scnd) {
	if ((frst.m == scnd.m) && (frst.e == scnd.e)) return 1;
	return 0;
}




