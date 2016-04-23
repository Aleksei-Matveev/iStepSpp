// IO_Stream.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	double values[] = { 1.23, 35.36, 653.7, 4358.24 };
	for (int i = 0; i < 4; i++)	{
		cout.width(10);	// Выравниваем длину
		cout << values[i] << '\n';
	}
	system("pause");
	return 0;
}
