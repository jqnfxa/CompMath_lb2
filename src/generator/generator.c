#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char **argv)
{
	if (argc < 4)
	{
		fprintf(stderr, "Usage: %s <n> <low> <high>\n", argv[0]);
		return 1;
	}

	srand(time(NULL));

	size_t size = atoi(argv[1]);
	double low = atof(argv[2]);
	double high = atof(argv[3]);

	double *array = (double *)malloc(sizeof(double) * size);

	if (array == NULL)
	{
		fprintf(stderr, "failed to allocate memory for array\n");
		return 1;
	}

	for (size_t i = 0; i < size / 4; ++i)
	{
		array[i] = low;
	}

	for (size_t i = 2 * size / 4; i < 3 * size / 4; ++i)
	{
		array[i] = 1;
	}

	for (size_t i = size / 4; i < 2 * size / 4; ++i)
	{
		array[i] = high;
	}

	for (size_t i = 3 * size / 4; i < size; ++i)
	{
		array[i] = -1;
	}

	/*for (size_t i = size - 1; i > 0; --i)
	{
		size_t j = rand() % (i + 1);

		double temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}*/

	printf("%lu\n", size);

	for (size_t i = 0; i < size; ++i)
	{
		printf("%lf ", array[i]);
	}

	return 0;
}
