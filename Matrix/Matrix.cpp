#include "Matrix.h"


Matrix::Matrix(size_t n, size_t m): _n(n), _m(m)
{
	// assigne first column
	TNode** col = new TNode*[_n];
	_first = new TNode;
	col[0] = _first;
	
	for (size_t i = 1; i < _n; i++)
	{
		col[i] = new TNode;
		col[i - 1]->_down = col[i];

	}
	// assigne other
	if (_m > 1)
	{
		TNode** col2 = new TNode*[_n];
		for (size_t j = 1; j < _m; j++)
		{
			for (size_t i = 0; i < _n; i++)
			{
				col[i]->_right = new TNode;
				col2[i] = col[i]->_right;
				if (i > 0)
				{
					col2[i - 1]->_down = col2[i];
				}
			}

			for (size_t i = 0; i < _n; i++)
			{
				col[i] = col2[i];
			}
		}
		delete[] col2;
	}
	delete[] col;
}

Matrix::~Matrix()
{
	for (int i = _n; i >= 0; i--)
	{
		for (int j = _m; j >= 0; j--)
		{
			delete getEl(i, j);
		}
	}
}

void Matrix::set(size_t i, size_t j, float value)
{
	if (i >= _m || j >= _n)
		return;
	TNode* curr = _first;
	for (int col = 0; col < i; col++)
	{
		curr = curr->_down;
	}
	for (int row = 0; row < j; row++)
	{
		curr = curr->_right;
	}
	curr->_data = value;
}

float Matrix::get(size_t i, size_t j)
{
	if (i >= _m || j >= _n)
		return 0.0f;
	TNode* curr = _first;
	for (int col = 0; col < i; col++)
	{
		curr = curr->_down;
	}
	for (int row = 0; row < j; row++)
	{
		curr = curr->_right;
	}
	return curr->_data;
}

void Matrix::fill()
{
	float tmp;
	TNode* rowBegin = _first;
	TNode* curr = _first;
	for (size_t i = 0; i < _n; i++)
	{
		curr = rowBegin;
		for (size_t j = 0; j < _m; j++)
		{
			cin >> tmp;
			curr->_data = tmp;
			curr = curr->_right;
		}
		rowBegin = rowBegin->_down;
	}
}

void Matrix::print()
{
	TNode* rowBegin = _first;
	TNode* curr = _first;
	for (size_t i = 0; i < _n; i++)
	{
		curr = rowBegin;
		for (size_t j = 0; j < _m; j++)
		{
			cout << curr->_data << " ";
			curr = curr->_right;
		}
		rowBegin = rowBegin->_down;
		cout << "\n";
	}
}

TNode * Matrix::getEl(size_t i, size_t j)
{
	if (i >= _m || j >= _n)
		return nullptr;
	TNode* curr = _first;
	for (int col = 0; col < i; col++)
	{
		curr = curr->_down;
	}
	for (int row = 0; row < j; row++)
	{
		curr = curr->_right;
	}
	return curr;
}

void Matrix::resize(size_t n, size_t m)
{
	clear();
	_n = n;
	_m = m;

	// assigne first column
	TNode** col = new TNode*[_n];
	_first = new TNode;
	col[0] = _first;

	for (size_t i = 1; i < _n; i++)
	{
		col[i] = new TNode;
		col[i - 1]->_down = col[i];

	}
	// assigne other
	if (_m > 1)
	{
		TNode** col2 = new TNode*[_n];
		for (size_t j = 1; j < _m; j++)
		{
			for (size_t i = 0; i < _n; i++)
			{
				col[i]->_right = new TNode;
				col2[i] = col[i]->_right;
				if (i > 0)
				{
					col2[i - 1]->_down = col2[i];
				}
			}

			for (size_t i = 0; i < _n; i++)
			{
				col[i] = col2[i];
			}
		}
		delete[] col2;
	}
	delete[] col;
}

void Matrix::clear()
{
	for (int i = _n; i >= 0; i--)
	{
		for (int j = _m; j >= 0; j--)
		{
			delete getEl(i, j);
		}
	}
	_first = nullptr;
}

void Matrix::copyFrom(Matrix & M)
{
	resize(M.get_n(), M.get_m());
	
	TNode* rowBegin = _first;
	TNode* curr = _first;
	for (int i = 0; i < _n; i++)
	{
		curr = rowBegin;
		for (int j = 0; j < _m; j++)
		{
			curr->_data = M.get(i, j);
			curr = curr->_right;
		}
		rowBegin = rowBegin->_down;
	}
}

void Matrix::multiplyBy(Matrix & M)
{
	if (_m != M.get_n())
	{
		exit(WRONGSIZE);
	}
	Matrix resMat(_n,M.get_m());
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < M.get_m(); j++)
		{
			float tmp = 0.0f;
			for (int k = 0; k < _m; k++)
			{
				tmp += get(i, k)*M.get(k, j);
			}
			resMat.set(i, j, tmp);
		}
	}
	copyFrom(resMat);
}

void Matrix::pow(int power)
{
	Matrix tmpMat(_n, _m);
	tmpMat.copyFrom(*this);
	for (int i = 0; i < power-1; i++)
	{
		multiplyBy(tmpMat);
	}
}
