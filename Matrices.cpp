#include "Matrices.h"

namespace Matrices
{
	Matrix::Matrix(int _rows, int _cols)
	{
		a.resize(_rows);
		for (int i = 0; i < _rows; i++)
		{
			a[i].resize(_cols, 0);
		}
		rows = _rows;
		cols = _cols;


	}

	Matrix operator+(const Matrix& a, const Matrix& b)
	{
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			throw runtime_error("Error: dimensions must agree");
		}
		Matrix c(a.getRows(),a.getCols());
		for (int i = 0; i < a.getRows(); i++)
		{
			for (int j = 0; j < a.getCols(); j++)
			{
				c(i,j) = a(i, j) + b(i, j);
			}
		}

		return c;
	}

	Matrix operator*(const Matrix& a, const Matrix& b)
	{
		Matrix c(a.getRows(), b.getCols());
		if (a.getCols() != b.getRows())
		{
			throw runtime_error("Error: dimensions must agree");
		}
		for (int i = 0; i < a.getRows(); i++)
		{
			for (int k = 0; k < b.getCols(); k++)
			{
				double sum = 0;
				for (int j = 0; j < a.getCols(); j++)
				{
					sum += a(i, j) * b(j, k);
				}
				c(i,k) = sum;
			}

		}
		return c;
	}

	bool operator==(const Matrix& a, const Matrix& b)
	{
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			return false;
		}
		for (int i = 0; i < a.getRows(); i++)
		{
			for (int j = 0; j < a.getCols(); j++)
			{
				if (abs(a(i, j) - b(i, j)) >= 0.001)
				{
					return false;
				}
			}
		}
		return true;
	}

	bool operator!=(const Matrix& a, const Matrix& b)
	{
		return !(a == b);
	}

	ostream& operator<<(ostream& os, const Matrix& a)
	{
		for (int i = 0; i < a.getRows(); i++)
		{
			for (int j = 0; j < a.getCols(); j++)
			{
				os << setw(10) << a(i, j)<<" ";
			}
			os << endl;
		}
		return os;

	}

}
