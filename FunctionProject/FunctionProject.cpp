// FunctionProject.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int sort_array[100];

template <typename T, typename R> T Min(T A, R B);

template <class T, class R> T Max(T A, R B);

int mass[100] = { 10, 45, 14, 32, 5, 15, 11, 69, 78, 12, 45 };

int i, N = sizeof(mass) / sizeof(int);

static int sum = mass[0];

void StartInicializeMass();

template <typename T> T Sum(T A);

void printMass();

int _tmain(int argc, _TCHAR* argv[])
{
	StartInicializeMass();

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
		min = Min(min, mass[i]);
		max = Max(max, mass[i]);
		Sum(mass[i]);
	}
	float sr_s = float(sum / N), sr_n = float(sum / (N - 1));
	printf("\nmin = %8d,\tmax = %8d,\tsum = %8d\nsr_s = %8.4f,\tsr_n = %8.4f\n", min, max, sum, sr_s, sr_n);

	system("pause");

	return 0;
}

template <typename T, typename R> T Min(T A, R B) {
	return (A > B) ? (B) : (A);
}

template <class T, class R> T Max(T A, R B) {
	return (A < B) ? (B) : (A);
}

void StartInicializeMass() {
	srand(mass[0]);
	extern int i;
	for (i = 11; i < N; i++) {
		mass[i] = (unsigned char)rand();
	}
}

template <typename T> T Sum(T A) {
	A += sum;
	sum = A;
	return A;
}

void printMass() {
	printf("\n");
	for (int i = 0; i < N; ++i) {
		printf("%8d", mass[i]);
		if (!(i % 9)) printf("\n");
	}
}
