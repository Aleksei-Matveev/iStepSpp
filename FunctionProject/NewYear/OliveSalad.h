/*
http://gotovim-doma.by/view.php?r=146-recept-Salat-Olive
������
������� ��� ������� ������� (����� �������� �������� �������) - 200-250�,
��������� (�������) - 4 ��,
������� - 1 ��,
���� - 4 ��,
������ ������������ (���������) - 4 ��,
������� ������� - 1 �����,
�������
*/

const struct OliveSalad
{
	float snag = 0.4;
	float potato = 0.25;	
	float carrot = 0.04;
	int eggs = 4;
	int cuke = 4;
	char pea = 1;
	char mayo = 1;
} olveSaladRecipe;

static OliveSalad olveSaladCurrent = olveSaladRecipe;

int Inicialize(OliveSalad*);

int CurrencyOliveSalad();

void PrintOliveSalad();
