#include "naive_sum.h"


double naive_sum(const double *array, size_t size)
{
	if (array == NULL)
	{
		return 0.0;
	}

	double sum = 0.0;

	for (size_t i = 0; i < size; ++i)
	{
		sum += array[i];
	}

	return sum;
}
