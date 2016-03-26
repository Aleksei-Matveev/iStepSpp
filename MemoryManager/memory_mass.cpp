#include "stdafx.h"

void __init(void *mass, int size_el) {
	srand((unsigned int)mass);
	for (int i = 0, *ptr = (int*)mass; i < _msize(mass) / size_el; i++, ptr++)
		*ptr = rand();
}

int __compare_equally_int(int *A, int *B) {
	return (*A > *B) ? (1) : ((*A < *B) ? (-1) : (0));
}

void __init_compare_ptr(int(__cdecl **mass)(int*, int*), int size) {
	*mass = __compare_equally_int;
}
