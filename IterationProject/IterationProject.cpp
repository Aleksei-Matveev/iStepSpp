// IterationProject.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale>

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, ".1251");
	/*
	�������� ����� for(������; �������; ���) {���� �����}
	*/
	int i = 0;
	for (i = 0; i < 10; i++) { // ���� ���������� 10 ���
		if (i == 5) {
			printf("��������� 6 ���\n");
			continue;
		}
		if (i > 7) {
			printf("������� ���������� ����� �� 9 ����\n");
			break;
		}
		printf("%d - ��� �����\n", i + 1);
	}

	/*
	�������� ����� while(�������) {���� �����}
	*/
	while (i < 20) { // ���� ���������� 13 ���
		printf("%d - ��� �����\n", ++i - 8);
	}

	/*
	�������� ����� do {���� �����} while(�������)
	*/
	do {
		printf("%d - ��� �����\n", ++i - 20);
	} while (i < 20); // ���� ���������� 1 ���

	/*
	���������� ������������ �����
	for (;;){}
	while (1){}
	do{} while(1);
	����� �� ������������ ����� �������� ��� ������ ���������� break � return
	*/

	/*
	������� ��������� ������ �����
	*/
	srand(10);
	printf("�������� ����� �� 1 �� 10\n");
	int x = rand(), y = 0;
	for (i = 3; i > 0; i--) {
		printf("������� ����� (�������� %d �������)\t", i);
		scanf_s("%d", &y);
		if (y == x) {
			printf("�� ������� ��� %d\n", x);
		}
		else {
			if (x > y) {
				printf("������� ����� ������\n");
			}
			else {
				printf("������� ����� ������\n");
			}
		}
	}

	system("pause");
	return 0;
}

