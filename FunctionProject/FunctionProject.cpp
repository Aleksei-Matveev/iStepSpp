// FunctionProject.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int sort_array[100];

#define min(A, B) (A > B) ? (B) : (A); 

int inline Max(int A, int B) {
	if (A > B) return A;
	return B;
}

int mass[100] = { 10, 45, 14, 32, 5, 15, 11, 69, 78, 12, 45 };

int i, N = sizeof(mass) / sizeof(int);

static int sum = mass[0];

void StartInicializeMass();

int Sum(int A);

void printMass();

	int _tmain(int argc, _TCHAR* argv[])
{
	StartInicializeMass();

	selection_sort(20);
	
	printMass();

	int k = 0;
	for (i = 11; i < N; i++) {
		if (k != i / 10) {
			k = i / 10;
			srand(mass[k]);
		}
		if (mass[i] % 2)
			mass[i] += (unsigned char)rand();
		else mass[i] -= (unsigned char)rand();
	}

	printMass();

	int min = mass[0], max = mass[0];
	for (i = 1; i < N; i++) {
		min = min(min, mass[i]);
		max = Max(max, mass[i]);
		Sum(mass[i]);
	}
	float sr_s = float(sum / N), sr_n = float(sum / (N - 1));
	printf("\nmin = %8d,\tmax = %8d,\tsum = %8d\nsr_s = %8.4f,\tsr_n = %8.4f\n", min, max, sum, sr_s, sr_n);

	system("pause");

	return 0;
}

void StartInicializeMass() {
	srand(mass[0]);
	extern int i;
	for (i = 11; i < N; i++) {
		mass[i] = (unsigned char)rand();
	}
}

int Sum(int A) {
	sum += A;
	return sum;
}

void printMass() {
	printf("\n");
	for (i = 0; i < N; ++i) {
		printf("%8d", mass[i]);
		if (!(i % 9)) printf("\n");
	}
}
