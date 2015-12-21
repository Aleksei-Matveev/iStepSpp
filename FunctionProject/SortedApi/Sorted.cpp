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

// Пирамидальная сортировка
void heapsort(int size) {
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		shift_down(mass, i, size);

	for (i = size - 1; i >= 1; i--)	{
		swap(mass[0], mass[i]);
		shift_down(mass, 0, i);
	}
}

template <typename T> void heapsort(T array[], int size) {
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		shift_down(array, i, size);

	for (i = size - 1; i >= 1; i--)	{
		swap(array[0], array[i]);
		shift_down(array, 0, i);
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

// Быстрая сортировка
void shaker_sort(int size) {
	for (int left_idx = 0, right_idx = size - 1; left_idx < right_idx;) {
		for (int idx = left_idx; idx < right_idx; idx++) {
			if (mass[idx + 1] < mass[idx]) {
				swap(mass[idx], mass[idx + 1]);
			}
		}
		right_idx--;

		for (int idx = right_idx; idx > left_idx; idx--) {
			if (mass[idx - 1] > mass[idx]) {
				swap(mass[idx - 1], mass[idx]);
			}
		}
		left_idx++;
	}
}

template <typename T> void shaker_sort(T array[], int size) {
	for (int left_idx = 0, right_idx = size - 1; left_idx < right_idx;) {
		for (int idx = left_idx; idx < right_idx; idx++) {
			if (array[idx + 1] < array[idx]) {
				swap(array[idx], array[idx + 1]);
			}
		}
		right_idx--;

		for (int idx = right_idx; idx > left_idx; idx--) {
			if (array[idx - 1] > array[idx]) {
				swap(array[idx - 1], array[idx]);
			}
		}
		left_idx++;
	}
}

void shift_down(int i, int j) {
	int done = 0;
	int maxChild;

	while ((i * 2 + 1 < j) && (!done)) {
		if (i * 2 + 1 == j - 1)
			maxChild = i * 2 + 1;
		else if (a[i * 2 + 1] > a[i * 2 + 2])
			maxChild = i * 2 + 1;
		else
			maxChild = i * 2 + 2;

		if (mass[i] < mass[maxChild]) {
			swap(mass[i], mass[maxChild]);
			i = maxChild;
		}
		else
			done = 1;
	}
}

template <typename T> void shift_down(T array[], int i, int j) {
	bool done = false;
	int maxChild;

	while ((i * 2 + 1 < j) && (!done)) {
		if (i * 2 + 1 == j - 1)
			maxChild = i * 2 + 1;
		else if (a[i * 2 + 1] > a[i * 2 + 2])
			maxChild = i * 2 + 1;
		else
			maxChild = i * 2 + 2;

		if (array[i] < array[maxChild]) {
			swap(array[i], array[maxChild]);
			i = maxChild;
		}
		else
			done = true;
	}
}

template <typename T> void swap(T &A, T &B) {
	T a = A;
	A = B;
	B = a;
}
