#include <stdio.h>
#include <math.h>

int main()
{
	double diag1, diag2;
	printf("Please type in the lenght of the diagonals of the diamond shape (separated by spaces): ");
	scanf("%lf %lf", &diag1, &diag2);

	printf("\n\nThe area of the diamond shape is %.2f . \n", (diag1*diag2)/2);
	
	double side;
	side = (diag1/2)*(diag1/2) + (diag2/2)*(diag2/2);
	side = sqrt(side);

	printf("The perimeter of the diamond shape is %.2f . \n", 4*side);

	return 0;
}
