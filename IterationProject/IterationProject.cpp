// IterationProject.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale>

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, ".1251");
	/*
	Оператор цикла for(начало; условие; шаг) {тело цикла}
	*/
	int i = 0;
	for (i = 0; i < 10; i++) { // Цикл выполнится 10 раз
		if (i == 5) {
			printf("Пропустим 6 шаг\n");
			continue;
		}
		if (i > 7) {
			printf("Прервем выполнение цикла на 9 шаге\n");
			break;
		}
		printf("%d - шаг цикла\n", i + 1);
	}

	/*
	Оператор цикла while(условие) {тело цикла}
	*/
	while (i < 20) { // Цикл выполнится 13 раз
		printf("%d - шаг цикла\n", ++i - 8);
	}

	/*
	Оператор цикла do {тело цикла} while(условие)
	*/
	do {
		printf("%d - шаг цикла\n", ++i - 20);
	} while (i < 20); // Цикл выполнится 1 раз

	/*
	Объявление бесконечного цикла
	for (;;){}
	while (1){}
	do{} while(1);
	выход из бесконечного цикла возможен при помощи операторов break и return
	*/

	/*
	Простая программа угадай число
	*/
	srand(10);
	printf("Угадайте число от 1 до 10\n");
	int x = rand(), y = 0;
	for (i = 3; i > 0; i--) {
		printf("Введите число (осталось %d попытки)\t", i);
		scanf_s("%d", &y);
		if (y == x) {
			printf("Вы угадали это %d\n", x);
		}
		else {
			if (x > y) {
				printf("Искомое число больше\n");
			}
			else {
				printf("Искомое число меньше\n");
			}
		}
	}

	system("pause");
	return 0;
}

