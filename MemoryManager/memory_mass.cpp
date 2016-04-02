#include "stdafx.h"

void __init(void *mass, int size_el) {
	srand((unsigned int)mass);
	for (int i = 0, *ptr = (int*)mass; i < _msize(mass) / size_el; i++, ptr++)
		*ptr = rand();
}

int __compare_equally_int(int *A, int *B) {
	return (*A > *B) ? (1) : ((*A < *B) ? (-1) : (0));
}

int __compare_mod_int(int *A, int *B) {
	int res = 0, lh = 0;
	int **ptr = &A;
	while (*ptr) {
		if (!**ptr) {
			res |= zero << lh;
		} else if (**ptr > 0) res |= positive << lh;
		else res |= negative << lh;
		if (**ptr % 2) res |= odd << lh;
		else res |= even << lh;
		lh += 8;
		ptr++;
	}
	return res;
}

void __init_compare_ptr(int(__cdecl **mass)(int*, int*), int size) {
	*mass = __compare_equally_int;
}
