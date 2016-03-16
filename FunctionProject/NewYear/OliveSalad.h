/*
http://gotovim-doma.by/view.php?r=146-recept-Salat-Olive
—остав
ветчина или варена€ колбаса (можно заменить отварной курицей) - 200-250г,
картофель (средний) - 4 шт,
морковь - 1 шт,
€йца - 4 шт,
огурцы маринованные (корнишоны) - 4 шт,
горошек зеленый - 1 банка,
майонез
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
