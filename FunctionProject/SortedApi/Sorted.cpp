#include "stdafx.h"

extern int mass[100];

// Пузырьковая сортировка
void bubble_sort(int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (mass[j] > mass[j + 1]) {
				int b = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = b;
			}
		}
	}
}

template <typename T> void bubble_sort(T array[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				T b = array[j];
				array[j] = array[j + 1];
				array[j + 1] = b;
			}
		}
	}
}

// Сортировка вставками
void paste_sort(int size) {
	for (int j = 1; j < size - 1; j++) {
		int key = mass[j];
		int i = j - 1;
		while ((i >= 0) && (mass[i] > key)) {
			mass[i + 1] = mass[i];
			mass[i--] = key;
		}
	}
}

template <typename T> void paste_sort(T array[], int size) {
	for (int j = 1; j < size - 1; j++) {
		T key = array[j];
		int i = j - 1;
		while ((i >= 0) && (array[i] > key)) {
			array[i + 1] = array[i];
			array[i--] = key;
		}
	}
}

// Сортировка выбором
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
