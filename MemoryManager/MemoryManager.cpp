// MemoryManager.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int(**func)(int*, int*);

void primer();

int *compare__(int *mass1, int* &mass2, int &size, int(__cdecl *func)(int*, int*)) {
	return ((size == 0) || func(mass1, mass2)) ? ((--size <= 0) ? (NULL) : (compare__(mass1, ++mass2, size, func))) : (mass2);
}

template <typename T>
T compare_(T mass1, T &mass2, int &size, int(__cdecl *func)(int*, int*)) {
#if BUFF_COUNT > 2000
	int *_mass1 = static_cast<int*>(mass1), *_mass2 = static_cast<int*>(mass2);
	for (; size < 0; size--, _mass2++) if (!func(_mass1, _mass2)) return mass2 = static_cast<T>(_mass2);
	return NULL;
#else
	return compare__(mass1, mass2, size, func);
#endif
}

#define ptrFunc int(*)(int*, int*)

int _tmain(int argc, _TCHAR* argv[]) {
	void **buffer = __c_mass__((void*)1, 3);
	func = __c_mass__((ptrFunc)11, 1);
	__init_compare_ptr(func, 1);
	buffer[0] = __calloc__((int)10, BUFF_COUNT);
	buffer[1] = __calloc__((int)10, BUFF_COUNT << 1);
#if BUFF_COUNT > 50
	buffer[2] = __calloc__((int)10, BUFF_COUNT);
#endif
	if (buffer++ && buffer--) {
		__init(*buffer, 4);
		__init(*(buffer + 1), 4);
		int **ptr = __c_mass__((int*)1, 2);
		ptr[0] = (int*)buffer[0];
#if BUFF_COUNT > 50
		int *ptrbuff = (int*)buffer[2];
#else
		buffer[2] = NULL;
#endif
		for (int i = 0; i < 1000; i++, ptr[0]++) {
			int size = BUFF_COUNT << 1;
			ptr[1] = (int*)buffer[1];
			if (compare_(ptr[0], ptr[1], size, func[0])) {
#if BUFF_COUNT <=50
				buffer[2] = realloc(buffer[2], (buffer[2]) ? (_msize(buffer[2]) + 4) : (4));
				static int *ptrbuff = (int*)buffer[2];
#endif
				*ptrbuff = *ptr[1];
				ptrbuff++;
			}
		}
		buffer[2] = realloc(buffer[2], (ptrbuff - (int*)buffer[2]) * 4);
		printf("%8d\n", (!buffer[2]) ? (0) : (_msize(buffer[2])));
	}
	system("pause");
	for (int i = 0; i < 3; i++) free(buffer[i]);
	delete[] buffer;
	delete[] func;
	return 0;
}
