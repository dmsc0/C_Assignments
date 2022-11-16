/*

Use Eratosthenes's sieve to determine all prime numbers less than a given integer. (https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init(int list[], int num, int *len)
{
	list[0] = 2;
	*len+=1;
	for(int i=1; 2*i+1<=num; i++)
		{
			list[i] = 2*i+1;
			*len+=1;
		}
}

void print_list(int list[], int len)
{
	for(int i=0; i<len; i++)
		printf("%d ", list[i]);
	printf("\n");
}

void shifting_to_left(int list[], int len, int i)
{
	while(i<len)
	{
		list[i]=list[i+1];	
		i++;
	}
}

void remove_zeroes(int list[], int* len)
{
	int i=0;
	while(i<*len)
	{
		while(i<*len && list[i] == 0) 
			{
				*len-=1;
				shifting_to_left(list, *len, i);
			}
		i++;
	}
	if(list[*len-1]==0) *len -= 1;

}

void remove_non_prime(int list[], int* len)
{
	for(int i = 1; i < *len-1 && list[i]*list[i] <= list[*len-1]; i++)
		{
			int j=i+1;
			while(j < *len)
				{
					if(list[i] != 0 && list[j] % list[i] == 0) list[j]=0;
					j++;
				}	
		}

	remove_zeroes(list, len);
}
	
int main()
{
	int number;
	char temp[256];
	scanf("%s", temp);
	
	for(int i=0; i<strlen(temp); i++)
		if(temp[i] <'0' || temp[i] >'9')
			{
				printf("You need to enter a positive number!");
				return 0;
			}
	
	char *ptr;
	number = strtol(temp, &ptr, 10);

	int Eratostene[number];
	int len = 0; 
	
	init(Eratostene, number, &len);

	if (number < 2) {printf("There are no prime numbers up to %d.\n", number); return 0;}
	if (number == 2) {printf("The only prime number is 2.\n"); return 0;}
	remove_non_prime(Eratostene, &len);
	
	printf("Eratosthenes's sieve up to number %d, looks like: ", number);	
	print_list(Eratostene, len);
	return 0;
}
