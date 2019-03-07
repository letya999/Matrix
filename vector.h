#pragma once
#include "Satur.h"

class vector {
protected:
	Satur *v;
	int sz;
public:
	vector(int);
	vector() : vector(5) {}
	vector(const vector &);
	vector(const std::initializer_list<float> &list);
	~vector(); 

	inline int size() const {
		return sz;
	}

	inline Satur & elem(int i) {
		return v[i];
	}

	inline Satur & operator & (int i) {
		return *v;
	}

	friend ostream& operator<<(ostream&, vector &);
	vector operator = (float);
	friend vector operator +(vector &, vector &);
	Satur & operator [](const int);
	bool operator ==(vector &);
	const vector operator =(const vector &);
};

void error(const char *);
