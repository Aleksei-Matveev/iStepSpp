// MemoryManager.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int *mass;

int _tmain(int argc, _TCHAR* argv[]) {
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
	return 0;
}

