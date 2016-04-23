// IO_Stream.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <iomanip>
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
	for (int i = 0; i < 4; i++)	{
		cout.width(10);
		cout.fill('*'); // Заполнители
		cout << values[i] << endl; // Переход на ноовую строку
	}
	cout.fill('_');
	system("pause");
	char *names[] = { "Zoot", "Jimmy", "Al", "Stan" };
	for (int i = 0; i < 4; i++) 
		cout << setw(6) << names[i] // Длина names 6 символов
			<< setw(10) << values[i] << endl; // Длина values 10 символов
	cout.fill(' ');
	system("pause");
	for (int i = 0; i < 4; i++)
		cout << setiosflags(ios::left) // Выравнивание по левому краю
		<< setw(6) << names[i]
		<< resetiosflags(ios::left) // Отмена выравнивания по левому краю
		<< setw(10) << values[i] << endl;
	system("pause");
	cout << setiosflags(ios::fixed); // Фиксируем точный вывод
	for (int i = 0; i < 4; i++)
		cout << setiosflags(ios::left)
		<< setw(6)
		<< names[i]
		<< resetiosflags(ios::left)
		<< setw(10)
		<< setprecision(1) // Количество цифр после запятой
		<< values[i]
		<< endl;
	system("pause");
	int mass[] = { 123, 3536, -6537, 435824 };
	for (int i = 0; i < 4; i++)
		cout << setiosflags(ios::left)
		<< setw(6)
		<< names[i]
		<< resetiosflags(ios::left)
		<< setw(10)
		<< hex
		<< mass[i]
		<< setfill('.')
		<< setw(10)
		<< dec
		<< mass[i]
		<< setfill(' ')
		<< setw(14)
		<< oct
		<< mass[i]
		<< endl;
	system("pause");
	return 0;
}
