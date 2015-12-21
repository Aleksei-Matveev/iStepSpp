#include "stdafx.h"

extern int mass[100];

void selection_sort(int size) {
	for (int idx_i = 0; idx_i < size - 1; idx_i++) {
		int min_idx = idx_i;
		for (int idx_j = idx_i + 1; idx_j < size; idx_j++) {
			if (mass[idx_j] < mass[min_idx]) {
				min_idx = idx_j;
			}
		}

		if (min_idx != idx_i) {
			swap(mass[idx_i], mass[min_idx]);
		}
	}
}

template <typename T> void selection_sort(T array[], int size) {
	for (int idx_i = 0; idx_i < size - 1; idx_i++) {
		int min_idx = idx_i;
		for (int idx_j = idx_i + 1; idx_j < size; idx_j++) {
			if (array[idx_j] < array[min_idx]) {
				min_idx = idx_j;
			}
		}

		if (min_idx != idx_i) {
			swap(array[idx_i], array[min_idx]);
		}
	}
}

template <typename T> void swap(T &A, T &B) {
	T a = A;
	A = B;
	B = a;
}
