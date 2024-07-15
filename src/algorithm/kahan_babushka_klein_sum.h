#ifndef KAHAN_BABUSHKA_KLEIN_H
#define KAHAN_BABUSHKA_KLEIN_H

#include <stddef.h>


double kbk_order_2_sum(const double *array, size_t size);

double kbk_order_3_sum(const double *array, size_t size);

double kbk_order_4_sum(const double *array, size_t size);

#endif // KAHAN_BABUSHKA_KLEIN_H
