#include "stdafx.h"

extern float masOlive[34];

void Inicialize() {
	masOlive[0] = masOlive[20] = 0.25;		// 0,25 килограмм колбасы
	masOlive[1] = masOlive[21] = 60000;		// стоимость за килограмм
	masOlive[2] = masOlive[22] = 0.4;		// 0,4 кг картошки
	masOlive[3] = masOlive[23] = 3700;		// стоимость за килограмм
	masOlive[4] = masOlive[24] = 0.08;		// 0,08 кг марковки
	masOlive[5] = masOlive[25] = 5500;		// стоимость за килограмм
	masOlive[6] = masOlive[26] = 4;			// 4 шт €иц
	masOlive[7] = masOlive[27] = 17500;		// стоимость за дес€ток
	masOlive[8] = masOlive[28] = 0.05;		// 0,05 кг корнишонов
	masOlive[9] = masOlive[29] = 26000;		// стоимость за банку - 0,3 кг
	masOlive[10] = masOlive[30] = 1;		// 1 банка зеленого горошка
	masOlive[11] = masOlive[31] = 11500;	// стоимость за банку
	masOlive[12] = masOlive[32] = 1;		// 1 упаковка майонеза
	masOlive[13] = masOlive[33] = 15500;	// стоимость за упаковку
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
	printf("варена€ колбаса - %6d г\n", m);
	m = masOlive[22] * 1000;
	printf("картофель(средний) - %6d г\n", m);
	m = masOlive[24] * 1000;
	printf("морковь - %6d г\n", m);
	m = masOlive[26];
	printf("€йца - %6d шт\n", m);
	m = masOlive[28] / 0.012;
	printf("огурцы маринованные - %6d шт\n", m);
	m = masOlive[30];
	printf("горошек зеленый - %6d банка\n", m);
	m = masOlive[32];
	printf("майонез - %6d упаковка\n", m);
}
