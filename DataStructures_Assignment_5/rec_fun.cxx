#include <iostream>
#include <string>
#include <cassert>
#include "rec_fun.h"
using namespace std;

namespace M_munoz_05
{
	void binary_print(ostream& outs, unsigned int n)
	{
		assert(n >= 0);

		if (n == 0)
		{
			outs << 0;
			return;
		}

		if (n == 1)
		{
			outs << 1;
			return;
		}
		else
		{
			binary_print(cout, n/2);
			cout << n % 2;
		}
	}

	void triangle(ostream& outs, unsigned int m, unsigned int n)
	{
		if (m > n)
		{
			return;
		}
		else
		{
			for (unsigned int i = 0; i < m; i++)
			{
				outs << "*";
			}

			outs << endl;
			triangle(cout, m + 1, n);
			for (unsigned int i = 0; i < m; i++)
			{
				outs << "*";
			}

			outs << endl;
		}
	}

	double power(double x, int n)
	{
		double product;


		if (x == 0)
			assert(n > 0);

		if (n == 0)
		{
			return 1;
		}

		if ((n % 2) == 0)
		{
			product = power(x, (n / 2));
			return product * product;
		}
		else if ((n % 2) == 1)
		{
			product = power(x, (n / 2));
			return x * product * product;
		}
		else
		{
			return 1 / power(x, -n);
		}

	}

	void indented_sentences(size_t m, size_t n)
	{
		if (m > n)
		{
			return;
		}
		else
		{
			for (unsigned int i = 0; i < m; i++)
			{
				cout << " ";
			}

			cout << "This was written by calling number " << m << ".\n";
			indented_sentences(m + 1, n);

			for (unsigned int i = 0; i < m; i++)
			{
				cout << " ";
			}
			cout << "This was ALSO written by calling number " << m << ".\n";
		}
	}
}