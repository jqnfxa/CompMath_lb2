#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "algorithm/exact_sum.h"
#include "algorithm/kahan_sum.h"
#include "algorithm/ogita_oishi_sum.h"
#include "algorithm/kahan_babushka_klein_sum.h"
#include "algorithm/naive_sum.h"
#include "io/io.h"


#define GET_EXP(x) (((*(unsigned long long*)(&x))&0x7FFFFFFFFFFFFFFFULL)>>52)


double get_ulp (double x)
{
	return ldexp (1.0, GET_EXP(x)-1075);
}

double error(double lhs, double rhs)
{
	return fabs(lhs - rhs) / get_ulp(rhs);
}


int main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "usage: %s <file>\n", argv[0]);
		return 1;
	}


	size_t size;
	double *array = NULL;

	if (!read_array(&array, &size, argv[1]))
	{
		fprintf(stderr, "failed to read array from: %s\n", argv[1]);
		return 1;
	}

	const double exact = exact_sum(array, size);

	printf("Exact: %.12lf\n", exact);
	printf("Naive sum: %lf\n", error(naive_sum(array, size), exact));
	printf("Kahan sum: %lf\n", error(kahan_sum(array, size), exact));
	printf("Roo sum: %lf\n", error(ogita_oishi_sum(array, size), exact));
	printf("Kbk2 sum: %lf\n", error(kbk_order_2_sum(array, size), exact));
	printf("Kbk3 sum: %lf\n", error(kbk_order_3_sum(array, size), exact));

	printf("\n\nExact sum (double approx): %.12Lf\n", exact_sum(array, size));
	printf("Naive sum: %.12lf\n", naive_sum(array, size));
	printf("Kahan sum: %.12lf\n", kahan_sum(array, size));
	printf("Roo sum: %.12lf\n", ogita_oishi_sum(array, size));
	printf("Kbk2 sum: %.12lf\n", kbk_order_2_sum(array, size));
	printf("Kbk3 sum: %.12lf\n", kbk_order_3_sum(array, size));

	free(array);
	return 0;
}
