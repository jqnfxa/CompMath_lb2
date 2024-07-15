#include "ogita_oishi_sum.h"


double ogita_oishi_sum(const double *array, size_t size)
{
	if (array == NULL)
	{
		return 0.0;
	}

	double sum = 0.0;
	double c = 0.0;
	double error;

	double s;
	double bs;
	double as;

	for (size_t i = 0; i < size; ++i)
	{
		s = sum + array[i];
		bs = s - sum;
		as = s - bs;
		error = (array[i] - bs) + (sum - as);
		sum = s;
		c += error;
	}

	return sum + c;
}
