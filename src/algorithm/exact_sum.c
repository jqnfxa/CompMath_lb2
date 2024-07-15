#include <gmp.h>

#include "exact_sum.h"


long double exact_sum(const double *array, size_t size)
{
	if (array == NULL)
	{
		return 0.0;
	}

	mpf_t sum;
	mpf_t temp;
	mpf_init2(sum, 40960); // Initialize sum with 40960 bits of precision
	mpf_init2(temp, 40960); // Initialize temp with 40960 bits of precision
	mpf_set_d(sum, 0.0); // Set sum to 0.0

	for (size_t i = 0; i < size; ++i)
	{
		mpf_set_d(temp, array[i]); // Convert double to mpf_t
		mpf_add(sum, sum, temp); // Add to sum
	}

	long double double_approx = mpf_get_d(sum); // Convert mpf_t to double

	mpf_clear(sum); // Clean up sum
	mpf_clear(temp); // Clean up temp

	return double_approx; // Return the sum as a double
}
