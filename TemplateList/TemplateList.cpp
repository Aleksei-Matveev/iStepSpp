// TemplateList.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

static int _tmain(int argc, _TCHAR* argv[]) {
	int A = 10;
	for (int i = 0; i < 100; i++) {
		add_Element(rand());
	}
	for (int i = 6; i < 200; i += 3) {
		int d = getElement(A, i);
		if (d) printf("%8d", A);
	}
	system("pause");
	clearElement(&A);
	return 0;
}
