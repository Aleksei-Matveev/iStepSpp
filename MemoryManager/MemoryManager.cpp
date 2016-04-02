// MemoryManager.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int(**func)(int*, int*);

void primer();

int *compare__(int *mass1, int* &mass2, int &size, int(__cdecl *func)(int*, int*)) {
	return ((size == 0) || func(mass1, mass2)) ? ((--size <= 0) ? (NULL) : (compare__(mass1, ++mass2, size, func))) : (mass2);
}

template <typename T>
T compare_(T mass1, T &mass2, int &size) {
	return compare__(mass1, mass2, size, func[0]);
}

int _tmain(int argc, _TCHAR* argv[]) {
	void **buffer = __c_mass__((void*)1, 3);
	func = new (int(*[1])(int*, int*));
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
			int size = 2000;
			ptr[1] = (int*)buffer[1];
			if (compare_(ptr[0], ptr[1], size)) {
#if BUF_COUNT <=50
				buffer[2] = realloc(buffer[2], (buffer[2]) ? (_msize(buffer[2]) + 4) : (4));
				static int *ptrbuff = (int*)buffer[2];
#endif
				*ptrbuff = *ptr[1];
				ptrbuff++;
			}
		}
		buffer[2] = realloc(buffer[2], ptrbuff - (int*)buffer[2]);
		printf("%8d\n", (!buffer[2]) ? (0) : (_msize(buffer[2])));
	}
	system("pause");
	delete[] buffer;
	delete[] func;
	return 0;
}

int *mass;

void primer() {
	void *ptr = calloc(256, 4);
	printf("calloc - Ok%16d\n", _msize(ptr));
	if (ptr) {
		srand((int)ptr); // Инициализация массива в зависимости от адреса выделенного буфера
		mass = static_cast<int*>(ptr);
		for (int i = 0; i < 256; i++) mass[i] = rand(); // Тут понятно
		// Удалим 100 элемент
		printf("%8d%8d%8d%8d\n", mass[98], mass[99], mass[100], mass[101]);
		if (!memcpy_s(&mass[99], 156, &mass[100], 155)) {
			printf("delete - Ok\n");
			// Проверим
			printf("%8d%8d%8d%8d\n", mass[98], mass[99], mass[100], mass[101]);
		}
		ptr = realloc(ptr, 1024 + 1024); // Добавим
		if (ptr) {
			printf("realloc - Ok%16d\n", _msize(ptr));
			mass = static_cast<int*>(ptr);
			for (int i = 0; i < 512; i++) mass[i] = rand(); // Заново
			// Для проверки хватит и 30
			int k = 0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 10; j++, k++) printf("%6d", mass[k]);
				printf("\n");
			}
			// Удаляем каждый второй
			for (int i = 1; i < 512; i += 2)
				if (memcpy_s(&mass[i], 512 - i, &mass[i + 1], 511 - i)) {
				printf("Error\n");
				break;
				}
			// Снова проверяем
			k = 0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 10; j++, k++) printf("%6d", mass[k]);
				printf("\n");
			}
		}
		system("pause");
		free(ptr);
		ptr = NULL;
	}
	ptr = malloc(1024);
	if (ptr) {
		system("pause");
		free(ptr);
	}
}
