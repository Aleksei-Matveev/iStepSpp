// HouseMassive.cpp: ���������� ����� ����� ��� ����������� ����������.
//

/*
���������� ���� �� �������, ����� �� ����������� ��������� ������.

������ ��������� ������������, ���� � ���� ������������ ������ �������.
���� �� ��������� ���������� ������ �������, �� �� ��������� ������, ����� ����� ������ �������. 

����:
1. (������������ �������)
���������� ��������� ����������� �� ������������� ����������� ��������
������� ������������ � �������� �������, ������ �� ����� ������������ ��� ������ ������������(�)
���������� ��������� ���������� ����������� ��� ������ �������� (��� ���������, ������� ���������� ������������ ��� ��� ����������)
2. (����������)
� ��������� �������� ������(�), ���������� ����� � ���������
3. (����� ����)
�������� ���������� ���������� ������� �� �������� �������� ��� ������� ����������, ��� ����� ������������ ��� ���������� �������
������� �������� ������� � �� ���������� ������� �������
4. (��� ����)
���������� ���������� ��������� ��� ���������� ��� ��������� ������� � ��� ��������� ���������� ������ ����

�������!!!!
*/

#include "stdafx.h"

int bubble_sort(int *mass, int size);

void inicialize(int *mass, int size, int _start);

void print_mass(int mass[10][10], int size1, int size2);

int i_mass[10][10];

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, ".1251");
	inicialize(i_mass[0], 100, 22);
	print_mass(i_mass, 10, 10);
	int mass[10];
	int _bool = 0;
	do {
		if (_bool) for (int i = 0; i < &i_mass[i][9] - &i_mass[i][0]; i++) bubble_sort(i_mass[i], 10);
		for (int i = 0; i < sizeof(mass) / sizeof(int); i++) mass[0] = i_mass[i][0];
		_bool = bubble_sort(mass, 10);
	} while (_bool);
	print_mass(i_mass, 10, 10);
	system("pause");
	return 0;
}

int bubble_sort(int *mass, int size) {
	int _bool = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (mass[j] > mass[j + 1]) {
				int b = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = b;
				_bool++;
			}
		}
	}
	return _bool;
}

void inicialize(int *mass, int size, int _start) {
	srand(_start);
	for (int i = 0; i < size; i++) mass[i] = (unsigned char)rand();
}

void print_mass(int mass[10][10], int size1, int size2) {
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) printf("%4d", mass[i][j]);
		printf("\n");
	}
	printf("\n");
}
