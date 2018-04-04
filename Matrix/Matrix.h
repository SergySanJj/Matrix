#pragma once

#ifndef Matrix_H_
#define Matrix_H_

#include <iostream>
#include <algorithm>
using namespace std;

#define WRONGSIZE 1

struct TNode
{
	TNode* _right = nullptr;
	TNode* _down = nullptr;

	float _data = 0.0f;
};

class Matrix
{
public:
	Matrix(size_t n, size_t m);
	~Matrix();

	//operator = (const Matrix& from);

	size_t get_m() { return _m; }
	size_t get_n() { return _n; }

	void set(size_t i, size_t j, float value);
	float get(size_t i, size_t j);

	void copyFrom(Matrix& M);
	void multiplyBy(Matrix& M);
	void pow(int power);

	void fill();
	void print();
private:
	size_t _n;
	size_t _m;
	TNode* _first = nullptr;

	TNode* getEl(size_t i, size_t j);
	void resize(size_t n, size_t m);
	void clear();
};

#endif // !Matrix_H_


