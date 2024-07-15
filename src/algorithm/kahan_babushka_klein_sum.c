#include <math.h>

#include "kahan_babushka_klein_sum.h"


double kbk_order_2_sum(const double *array, size_t size)
{
	if (array == NULL)
	{
		return 0.0;
	}

	double sum = 0.0;
	volatile double cs = 0.0;
	volatile double ccs = 0.0;
	volatile double c = 0.0;
	volatile double cc = 0.0;
	volatile double t;

	for (size_t i = 0; i < size; ++i)
	{
		t = sum + array[i];

		if (fabsl(sum) >= fabsl(array[i]))
		{
			c = (sum - t) + array[i];
		}
		else
		{
			c = (array[i] - t) + sum;
		}

		sum = t;
		t = cs + c;

		if (fabsl(cs) >= fabsl(c))
		{
			cc = (cs - t) + c;
		}
		else
		{
			cc = (c - t) + cs;
		}

		cs = t;
		ccs = ccs + cc;
	}

	return sum + cs + ccs;
}


double kbk_order_3_sum(const double *array, size_t size)
{
	if (array == NULL)
	{
		return 0.0;
	}

	double sum = 0.0;
	volatile double cs = 0.0;
	volatile double ccs = 0.0;
	volatile double ccs2 = 0.0;
	volatile double c = 0.0;
	volatile double cc = 0.0;
	volatile double t;

	for (size_t i = 0; i < size; ++i)
	{
		t = sum + array[i];

		if (fabsl(sum) >= fabsl(array[i]))
		{
			c = (sum - t) + array[i];
		}
		else
		{
			c = (array[i] - t) + sum;
		}

		sum = t;
		t = cs + c;

		if (fabsl(cs) >= fabsl(c))
		{
			cc = (cs - t) + c;
		}
		else
		{
			cc = (c - t) + cs;
		}

		cs = t;
		t = ccs + cc;

		if (fabsl(ccs) >= fabsl(cc))
		{
			ccs2 = (ccs - t) + cc;
		}
		else
		{
			ccs2 = (cc - t) + ccs;
		}

		ccs = t;
	}

	return sum + cs + ccs + ccs2;
}


double kbk_order_4_sum(const double *array, size_t size)
{
	if (array == NULL)
	{
		return 0.0;
	}

	double sum = 0.0;
	volatile double cs = 0.0;
	volatile double ccs = 0.0;
	volatile double ccs2 = 0.0;
	volatile double ccs3 = 0.0;
	volatile double c = 0.0;
	volatile double cc = 0.0;
	volatile double t;

	for (size_t i = 0; i < size; ++i)
	{
		t = sum + array[i];

		if (fabsl(sum) >= fabsl(array[i]))
		{
			c = (sum - t) + array[i];
		}
		else
		{
			c = (array[i] - t) + sum;
		}

		sum = t;
		t = cs + c;

		if (fabsl(cs) >= fabsl(c))
		{
			cc = (cs - t) + c;
		}
		else
		{
			cc = (c - t) + cs;
		}

		cs = t;
		t = ccs + cc;

		if (fabsl(ccs) >= fabsl(cc))
		{
			ccs2 = (ccs - t) + cc;
		}
		else
		{
			ccs2 = (cc - t) + ccs;
		}

		ccs = t;
		t = ccs2 + ccs2;

		if (fabsl(ccs2) >= fabsl(ccs2))
		{
			ccs3 = (ccs2 - t) + ccs2;
		}
		else
		{
			ccs3 = (ccs2 - t) + ccs2;
		}

		ccs2 = t;
	}

	return sum + cs + ccs + ccs2 + ccs3;
}
