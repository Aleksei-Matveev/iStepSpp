// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
/*github.com/stoma-siarhei/iStepSpp/
blob/master/IO_Stream/IO_Stream.cpp*/

int _tmain(int argc, _TCHAR* argv[])
{
	int sumVx = 1200 * 1.39, sumPl = sumVx / 12, sumOs = 0;
	int dX = sumPl, dY = sumVx;
	srand(103);
	cout << "__________________________________" << endl;
	int i = 1;
	while (sumVx > 0) {
		sumOs = sumVx - sumPl;
		cout << setw(4) << i <<
			setw(10) << sumVx <<
			setw(10) << sumPl <<
			setw(10) << sumOs <<
			endl;
		int ver = (char)rand();
		switch (ver < 0)
		{
		case (0) :
			sumVx = sumOs;
			sumPl = dX;
			for (int j = 1; j <= 31; j++) {
				sumVx += sumVx * 1.39 / 365;
				if (j < 13) continue;
				switch (i % 12) {
				case (2) :
					if (j > 28) break;
				case (4) :
				case (6) :
				case (9) :
				case (11) :
						  if (j > 30) break;
				}
				int ver = (unsigned char)rand() % 2;
				if (ver) break;
			}
			break;
		default:
			sumVx += sumPl * 0.5;
			if (sumVx > sumPl) sumPl += dX;
			break;
		}
		if (sumPl > sumVx) sumPl = sumVx;
		i++;
	}
	system("pause");
	return 0;
}

