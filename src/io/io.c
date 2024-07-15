#include <stdio.h>
#include <stdlib.h>

#include "io.h"


bool read_array(double **array, size_t *size, const char *filename)
{
	if (array == NULL || size == NULL || filename == NULL)
	{
		return false;
	}

	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		return false;
	}

	fscanf(file, "%ld", size);

	if (size == 0)
	{
		fclose(file);
		return false;
	}

	*array = (double *)malloc(sizeof(double) * *size);

	if (*array == NULL)
	{
		fclose(file);
		return false;
	}

	for (size_t i = 0; i < *size; ++i)
	{
		fscanf(file, "%lf", &((*array)[i]));
	}

	return true;
}
