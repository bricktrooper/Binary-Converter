#include <stdio.h>
#include <limits.h>
#include <math.h>

#define NOT_AN_INT -1
#define OVERFLOW_INT -2
#define QUIT 0
#define VALID_INPUT 1

void printBinary(unsigned int number);
signed char parseInt(char input[], unsigned int *number);

int main()
{
	char input[100];
	unsigned int number = 0;
	signed char directive = 1;

	printf("WELCOME!\n");
	printf("Enter positive integer numbers to convert to binary (Enter 'Q' to quit)\n");

	do
	{
		for (int i = 0; i < 100; i++)
		{
			input[i] = '\0';
		}

		printf("Please enter a positive integer number: ");

		scanf("\n");
		scanf("%[^\n]%*c", input);
		
		directive = parseInt(input, &number);

		if (directive == NOT_AN_INT)
		{
			printf("INVALID INPUT - ONLY POSITIVE INTEGERS ARE ALLOWED\n");
		}
		else if (directive == OVERFLOW_INT)
		{
			printf("INVALID INPUT - INTEGER VALUE IS TOO LARGE\n");
		}
		else if (directive == QUIT)
		{
			printf("Goodbye!\n");
		}
		else
		{
			printf("Decimal:   %u\nBinary:    ", number);
			printBinary(number);
		}
	}
	while (directive != QUIT);

	return directive;
}

void printBinary(unsigned int number)
{
	if (number == 0)
	{
		printf("0\n");
		return;
	}

	int numberOfBits = (log(number) / log(2)) + 1;

	for (int n = numberOfBits - 1; n >= 0; n--)
	{
		printf("%d", ((number >> n) & 1));

		if (n % 4 == 0)
		{
			printf(" ");
		}
	}

	printf("\n");
}

signed char parseInt(char input[], unsigned int *number)
{
	unsigned int digit = 0;
	unsigned char numberOfDigits = 0;
	const unsigned char MAX_NUMBER_OF_DIGITS = 10;

	*number = 0;

	if ((input[0] == 'q' || input[0] == 'Q') && input[1] == 0)
	{
		return QUIT;
	}

	for (int i = 0; input[i] != 0; i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			switch (input[i])
			{
				case '0':
				
					digit = 0;
					break;
				
				case '1':
				
					digit = 1;
					break;
				
				case '2':

					digit = 2;
					break;

				case '3':

					digit = 3;
					break;

				case '4':

					digit = 4;
					break;

				case '5':

					digit = 5;
					break;

				case '6':

					digit = 6;
					break;

				case '7':

					digit = 7;
					break;

				case '8':

					digit = 8;
					break;

				case '9':

					digit = 9; 
					break;
			}

			if ((UINT_MAX - (*number * 10) < digit) || (numberOfDigits >= MAX_NUMBER_OF_DIGITS))
			{
				return OVERFLOW_INT;
			}
			else
			{
				*number = (*number * 10) + digit;
				numberOfDigits++;
			}
		}
		else
		{
			return NOT_AN_INT;
		}
	}

	return VALID_INPUT;
}
