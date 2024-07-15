#include "kahan_sum.h"


double kahan_sum(const double *array, size_t size)
{
	if (array == NULL)
	{
		return 0.0;
	}

	double sum = 0.0, error = 0.0;
	double cur_sum, s;

	for (size_t i = 0; i < size; ++i)
	{
    		cur_sum = array[i] + error;

		s = sum + cur_sum;
		error = cur_sum - (s - sum);
    		sum = s;
  	}

	return sum;
}
