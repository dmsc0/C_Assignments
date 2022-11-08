#include <stdio.h>

int main()
{
	int coin_of_1 = 0, coin_of_2 = 0, coin_of_5 = 0;
	int amount, copy_amount;
	
	printf("Please enter the amount you have to pay: ");
	scanf("%i", &copy_amount);

	amount = copy_amount;
	
	coin_of_5 = amount / 5;
	amount = amount % 5;

	coin_of_2 = amount / 2;
	amount = amount % 2;
	
	coin_of_1 = amount;

	amount = copy_amount;

	printf("\nIn order to pay %d, you'll need %d coins of 5, %d coins of 2 and %d coins of 1.", amount, coin_of_5, coin_of_2, coin_of_1);

	return 0;
}
