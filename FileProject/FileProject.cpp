// FileProject.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

struct MyStruct
{
	int mode;
	char *str;
	float chislo;
};

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *tFile = fopen("myfile.txt", "w+");
	fprintf(tFile, "%s", "Привет мир из файла");
	system("pause");
	fclose(tFile);
	if (fopen_s(&tFile, "myFile.txt", "r")) return 0;
	setlocale(LC_ALL, ".1251");
	char *ch = new char[100];
	fseek(tFile, 0, SEEK_SET);
	while (!feof(tFile)) {
		fscanf_s(tFile, "%20s", ch, 100);
		printf("%s\n", ch);
	}
	system("pause");
	delete[] ch;
	_fcloseall();
	if (fopen_s(&tFile, "myFile.txt", "w+")) return 0;
	fprintf(tFile, "%s", "Привет опять из файла");
	if (freopen_s(&tFile, "myFile.txt", "r", tFile)) return 0;
	ch = new char[100];
	fseek(tFile, 0, SEEK_SET);
	while (!feof(tFile)) {
		fscanf_s(tFile, "%20s", ch, 100);
		printf("%s\n", ch);
	}
	system("pause");
	delete[] ch;
	_fcloseall();
	if (fopen_s(&tFile, "myFile.dat", "a+b")) return 0;
	fseek(tFile, 0, SEEK_SET);
	ch = new char[100];
	strcpy_s(ch, 100, "Привет снова из файла");
	MyStruct *str = new MyStruct;
	str->chislo = 10.5;
	str->mode = 10;
	str->str = new char[100];
	strcpy_s(str->str, 100, ch);
	str->mode = strlen(str->str);
	fwrite(&str->chislo, sizeof(str->chislo), 1, tFile);
	fwrite(&str->mode, sizeof(str->mode), 1, tFile);
	fwrite(str->str, 1, strlen(str->str) + 1, tFile);
	delete[] str->str;
	delete str;
	if (freopen_s(&tFile, "myFile.dat", "r+b", tFile)) return 0;
	fseek(tFile, 0, SEEK_SET);
	str = new MyStruct;
	while (!feof(tFile)) {
		fread_s(&str->chislo, sizeof(str->chislo), sizeof(str->chislo), 1, tFile);
		fread_s(&str->mode, sizeof(str->mode), sizeof(str->mode), 1, tFile);
		fpos_t pos;
		fgetpos(tFile, &pos);
		printf("%d, %f, %d\n", str->mode, str->chislo, pos);
		str->str = new char[100];
		fread_s(str->str, 100, 1, str->mode + 1, tFile);
		printf("%s\n", str->str);
		delete[] str->str;
	}
	delete str;
	system("pause");
	delete[] ch;
	fclose(tFile);
	return 0;
}

