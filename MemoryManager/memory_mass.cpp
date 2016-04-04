#include "stdafx.h"

#if _USE_OMP > 1
/*
	1. Open the project's Property Pages dialog box.
	2. Expand the Configuration Properties node.
	3. Expand the C/C++ node.
	4. Select the Language property page.
	5. Modify the OpenMP Support property.
	6. Убрать комментарий со строки #define _USE_OMP 4 в stdafx.h
	*/
void __init(void *mass, int size_el) {
	srand((unsigned int)mass);
	omp_set_num_threads(_USE_OMP);
	int i = 0, *ptr = (int*)mass, count = _msize(mass) / size_el;
#pragma omp parallel default(none) private(i) shared(ptr, count) 
	{
#pragma omp for
		for (i = 0; i < count; i++) {
			*ptr = rand();
#pragma omp atomic
			ptr++;
		}
	}
}
#else
void __init(void *mass, int size_el) {
	srand((unsigned int)mass);
	for (int i = 0, *ptr = (int*)mass; i < _msize(mass) / size_el; i++, ptr++)
		*ptr = rand();
}
#endif

int __compare_equally_int(int *A, int *B) {
	return (*A > *B) ? (1) : ((*A < *B) ? (-1) : (0));
}

int __compare_mod_int(int *A, int *B) {
	int res = 0, lh = 0;
	int **ptr = &A;
	while (*ptr) {
		if (!**ptr) {
			res |= zero << lh;
		}
		else if (**ptr > 0) res |= positive << lh;
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
