/*

Write a program to read an integer with max 3 digits and print the value in words(111 will be printed as one hundred and eleven)

*/

#include <stdio.h>
#include <string.h>

void init(char digit[10][25], char tens[10][25], char ten_to_twenty[10][25])
{
	strcpy(digit[1], "one");
	strcpy(digit[2], "two");
	strcpy(digit[3], "three");
	strcpy(digit[4], "four");
	strcpy(digit[5], "five");
	strcpy(digit[6], "six");
	strcpy(digit[7], "seven");
	strcpy(digit[8], "eight");
	strcpy(digit[9], "nine");

	strcpy(tens[2], "twenty");
	strcpy(tens[3], "thirty");
	strcpy(tens[4], "fourty");
	strcpy(tens[5], "fifty");
	strcpy(tens[6], "sixty");
	strcpy(tens[7], "seventy");
	strcpy(tens[8], "eighty");
	strcpy(tens[9], "ninety");
	
	strcpy(ten_to_twenty[0], "ten");
	strcpy(ten_to_twenty[1], "eleven");
	strcpy(ten_to_twenty[2], "twelve");
	strcpy(ten_to_twenty[3], "thirteen");
	strcpy(ten_to_twenty[4], "fourteen");
	strcpy(ten_to_twenty[5], "fifteen");
	strcpy(ten_to_twenty[6], "sixteen");
	strcpy(ten_to_twenty[7], "seventeen");
	strcpy(ten_to_twenty[8], "eighteen");
	strcpy(ten_to_twenty[9], "nineteen");
}

int read_number(int digits[3])
{

	for(int i=2; i>=0; i--)
		{
				char temp;
				scanf("%c", &temp);
				
				if(temp >= '0' && temp <='9')
					digits[i]=temp-'0';
				else 
					{
							printf("Wrong input! You need to type a 3 digits number ");
							return 0;
					}
		}
	return 1;

}

void print_number_with_words(char digit[10][25], char tens[10][25], char ten_to_twenty[10][25], int digits[3])
{
	for(int i=2; i>=0; i--)
		{
			switch(i){
				case 0: // digit
							if(digits[1] != 1 && digits[0] != 0) printf("%s ", digit[digits[i]]);
							break;

				case 1: // tens
							if(digits[1] == 0) continue;
							if(digits[1] != 1) printf("%s ", tens[digits[i]]);
							else printf("%s ", ten_to_twenty[digits[i-1]]);
							break;

				case 2: // hundreds 
							printf("%s hundred ", digit[digits[i]]);
							if(digits[0] || digits[1]) printf("and ");
	
							break;
			
			}
		}
}


int main()
{
	int digits[3];
	char digit[10][25], tens[10][25], ten_to_twenty[10][25];

	init(digit, tens, ten_to_twenty);
	if(read_number(digits))	print_number_with_words(digit, tens, ten_to_twenty, digits);

	return 0;
}
