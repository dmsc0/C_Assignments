#include <stdio.h>
#include <string.h>
#define MAX_ARRAY_LEN 200

void swap(int* a, int* b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}

int read_input(char* p, char* msg)
{
	printf("%s", msg);
	scanf("%s", p);
	
	for(int i = 0; i<strlen(p); i++)
		if(*(p+i) < '0' || *(p+i)>'9')
			{
				printf("\nYou need to enter a positive number!\n");
				return 0;
			}
	return 1;
}

int convert_str_to_int(char* p )
{
	int result = 0;
	for(int i = 0; i<strlen(p); i++)
			result = (*(p+i)-'0') + result * 10;

	return result;
}

void populate_matrix(int matrix[MAX_ARRAY_LEN][MAX_ARRAY_LEN], int rows, int columns)
{
	printf("Please enter %d values: ", rows * columns);
	for(int i=0; i<rows; i++)
		for(int j=0; j<columns; j++)
			scanf("%d", (*(matrix + i) + j));
}

void print_matrix(int matrix[MAX_ARRAY_LEN][MAX_ARRAY_LEN], int rows, int columns)
{
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<columns; j++)
				printf("%d ", *(*(matrix + i) + j));
		printf("\n");
	}
}

void transpose_matrix(int matrix[MAX_ARRAY_LEN][MAX_ARRAY_LEN], int* rows, int* columns)
{

	for(int i=0; i<*rows; i++)
		for(int j=0; j<*columns; j++)
			if(j<i)
				swap((*(matrix + j) + i), (*(matrix + i) + j));	
	
	swap(rows, columns);
}

int main()
{
	char str[256];

	while (!read_input(str, "Number of rows: "));		
	int matrix_rows = convert_str_to_int(str);

	while (!read_input(str, "Number of columns: "));		
	int matrix_columns = convert_str_to_int(str);

	int matrix[matrix_rows][matrix_columns];
	populate_matrix(matrix, matrix_rows, matrix_columns);
	
	printf("Matrix before transposing: \n");
	print_matrix(matrix, matrix_rows, matrix_columns);
	printf("\n");	

	printf("Matrix after transposing: \n");
	transpose_matrix(matrix, &matrix_rows, &matrix_columns);
	print_matrix(matrix, matrix_rows, matrix_columns);

	return 0;
}
