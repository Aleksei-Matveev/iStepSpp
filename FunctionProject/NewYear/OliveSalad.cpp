#include "stdafx.h"

extern float masOlive[34];

void Inicialize() {
	masOlive[0] = masOlive[20] = 0.25;		// 0,25 ��������� �������
	masOlive[1] = masOlive[21] = 60000;		// ��������� �� ���������
	masOlive[2] = masOlive[22] = 0.4;		// 0,4 �� ��������
	masOlive[3] = masOlive[23] = 3700;		// ��������� �� ���������
	masOlive[4] = masOlive[24] = 0.08;		// 0,08 �� ��������
	masOlive[5] = masOlive[25] = 5500;		// ��������� �� ���������
	masOlive[6] = masOlive[26] = 4;			// 4 �� ���
	masOlive[7] = masOlive[27] = 17500;		// ��������� �� �������
	masOlive[8] = masOlive[28] = 0.05;		// 0,05 �� ����������
	masOlive[9] = masOlive[29] = 26000;		// ��������� �� ����� - 0,3 ��
	masOlive[10] = masOlive[30] = 1;		// 1 ����� �������� �������
	masOlive[11] = masOlive[31] = 11500;	// ��������� �� �����
	masOlive[12] = masOlive[32] = 1;		// 1 �������� ��������
	masOlive[13] = masOlive[33] = 15500;	// ��������� �� ��������
}

int SumOlive(int Index) {
	static float sumOlive = 0;
	register int sum, k;
	switch (Index)
	{
	case (21) :
	case (23) :
	case (25) : {
		sumOlive += masOlive[Index] * masOlive[Index - 1] / 100;
		break;
	}
	case (27) :
	{
		k = masOlive[Index - 1];
		if (k % 10) sumOlive += masOlive[Index] * (k / 10 + 1);
		else sumOlive += masOlive[Index] * (k / 10);
		break;
	}
	case (29) :
	{
		k = masOlive[Index - 1] * 1000;
		if (k % 300) sumOlive += masOlive[Index] * (k / 300 + 1);
		else sumOlive += masOlive[Index] * (k / 300);
		break;
	}
	case (31) :
	case (33) :
	{
		k = masOlive[Index - 1] * 10;
		if (k % 10) sumOlive += masOlive[Index] * (k / 10 + 1);
		else sumOlive += masOlive[Index] * (k / 10);
		break;
	}
	default:
		break;
	}
	sum = sumOlive;
	if (sumOlive - sum < 0.50) sumOlive = sum;
	else sumOlive = sum + 1;
	if (Index < 21) sumOlive = 0;
	else sum = sumOlive * 100;
	return (Index > 20) ? (SumOlive(Index - 2)) : (sum);
}

int CurrencyOliveSalad() {
	if (masOlive[20] == 0) Inicialize();
	return SumOlive(33);
}

void PrintOliveSalad() {
	int m = masOlive[20] * 1000;
	printf("������� ������� - %6d �\n", m);
	m = masOlive[22] * 1000;
	printf("���������(�������) - %6d �\n", m);
	m = masOlive[24] * 1000;
	printf("������� - %6d �\n", m);
	m = masOlive[26];
	printf("���� - %6d ��\n", m);
	m = masOlive[28] / 0.012;
	printf("������ ������������ - %6d ��\n", m);
	m = masOlive[30];
	printf("������� ������� - %6d �����\n", m);
	m = masOlive[32];
	printf("������� - %6d ��������\n", m);
}
