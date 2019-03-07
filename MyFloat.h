#pragma once
#include <cmath>
#define SIZE 4
using namespace std;

class MyFloat
{
protected:
	int m;
	int e;
public:
	MyFloat(double w=0) {
		if (w == 0) {
			m = 0;
			e = 0;
			return;
		}
		else {
			e = -1;
			while (w >= 1) {
				w /= 10;
				e++;
			}
			while (w < 0.1) {
				w *= 10;
				e--;
			}
			m = (int)(w * pow(10, SIZE));
		}
		MyFloat(m, e);
	}

	MyFloat(int dig, int num) {
		if(dig == 0) {
			m = 0;
			e = 0;
			return;
		}
		while(dig >= pow(10, SIZE)) {
			dig /= 10;
			num++;
		}
		while(dig < pow(10, SIZE-1)) {
			dig *= 10;
			num--;
		}
		m = dig, e = num;
	}

	void print();
	friend MyFloat operator+(MyFloat, MyFloat);
	friend MyFloat operator-(MyFloat, MyFloat);
	friend MyFloat operator*(MyFloat, MyFloat);
	friend MyFloat operator/(MyFloat, MyFloat);
	friend bool operator ==(MyFloat, MyFloat);
};


