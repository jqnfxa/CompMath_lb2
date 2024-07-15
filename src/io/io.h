#ifndef IO_H
#define IO_H

#include <stddef.h>
#include <stdbool.h>


bool read_array(double **array, size_t *size, const char *filename);

#endif // IO_H
