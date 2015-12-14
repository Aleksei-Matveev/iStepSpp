// IO_Project.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

/*
char                    1	от -128 до 127
unsigned char           1	от 0 до 255
signed char             1	от -128 до 127
int                     4	от -2 147 483 647 до 2 147 483 647
unsigned int            4	от 0 до 4 294 967 295
signed int              4	то же, что int
short int               2	от -32 768 до 32 767
unsigned short int	2	от 0 до 65 535
signed short int	2	то же, что short int
long int                4	от -2 147 483 647 до 2 147 483 647
long long int           8	от -(2^63-1) до (2^63-1), добавлен стандартом C99
signed long int         4	то же, что long int
unsigned long int	4	от 0 до 4 294 967 295
unsigned long long int	8	от 0 до (2^64-1), добавлен в C99
float                   4	от 1E-37 до 1E+37, с точностью не менее 6 значащих дес€тичных цифр
double                  8	от 1E-308 до 1E+308, с точностью не менее 10 значащих дес€тичных цифр
*/

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	int printf(const char *format [,argument]...);
	format
	”правление форматом.
	argument
	Ќеоб€зательные аргументы.
	¬озвращает число напечатанных символов или отрицательное значение в случае ошибки.
	*/
	int      count = -9234;
	double   fp = 251.7366;

	// Display integers
	printf("Integer formats:\n"
		"   Decimal: %d  Justified: %.6d  "
		"Unsigned: %u\n",
		count, count, count, count);

	// Display decimals
	printf("Decimal %d as:\n   Hex: %Xh  "
		"C hex: 0x%x  Octal: %o\n",
		count, count, count, count);

	// Display in different radixes
	printf("Digits 10 equal:\n   Hex: %i  "
		"Octal: %i  Decimal: %i\n",
		0x10, 010, 10);

	// Display real numbers
	printf("Real numbers:\n   %f %.2f %e %E\n",
		fp, fp, fp, fp);

	// Display pointer
	printf("\nAddress as:   %p\n", &count);

	/*
	int scanf_s(const char *format[,argument]...);
	format
	”правл€юща€ строка формата.
	argument
	Ќеоб€зательные аргументы.
	¬озвращает количество успешно преобразованных и присвоенных полей, не счита€ прочитанные, но не присвоенные пол€.
	¬озвращаемое значение 0 указывает на отсутствие присвоенных полей.
	*/

	int      i,
		result;
	char     c;

	result = scanf_s("%d %Lf %c", &i, &fp, &c, 1);
	printf("The number of fields input is %d\n", result);
	printf("The contents are: %d %f %c\n", i, fp, c);

	system("pause");
	return 0;
}
