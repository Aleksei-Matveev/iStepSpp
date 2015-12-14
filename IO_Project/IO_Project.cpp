// IO_Project.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

/*
char                    1	�� -128 �� 127
unsigned char           1	�� 0 �� 255
signed char             1	�� -128 �� 127
int                     4	�� -2 147 483 647 �� 2 147 483 647
unsigned int            4	�� 0 �� 4 294 967 295
signed int              4	�� ��, ��� int
short int               2	�� -32 768 �� 32 767
unsigned short int	2	�� 0 �� 65 535
signed short int	2	�� ��, ��� short int
long int                4	�� -2 147 483 647 �� 2 147 483 647
long long int           8	�� -(2^63-1) �� (2^63-1), �������� ���������� C99
signed long int         4	�� ��, ��� long int
unsigned long int	4	�� 0 �� 4 294 967 295
unsigned long long int	8	�� 0 �� (2^64-1), �������� � C99
float                   4	�� 1E-37 �� 1E+37, � ��������� �� ����� 6 �������� ���������� ����
double                  8	�� 1E-308 �� 1E+308, � ��������� �� ����� 10 �������� ���������� ����
*/

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	int printf(const char *format [,argument]...);
	format
	���������� ��������.
	argument
	�������������� ���������.
	���������� ����� ������������ �������� ��� ������������� �������� � ������ ������.
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
	����������� ������ �������.
	argument
	�������������� ���������.
	���������� ���������� ������� ��������������� � ����������� �����, �� ������ �����������, �� �� ����������� ����.
	������������ �������� 0 ��������� �� ���������� ����������� �����.
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
