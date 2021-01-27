#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define ENTER 10
#define TRUE 0
#define FALSE 1


int isCorner(int i, int j, int res) {
	if ((i == 0 && j == 0)
		|| (i == 0 && j == res - 1)
		|| (i == res - 1 && j == 0)
		|| (i == res - 1 && j == res - 1)) {
		return 1;
	}
	else {
		return 0;
	}
}

void draw() {
	int a;
	int res;
	int i, j;
	int corner = 0;

	printf("Enter a number:");
	scanf("%d", &a);
	res = a * 2 + 1;
	if (a == 0) {
		printf("X");
		return;
	}
	for (i = 0; i < res; i++) {
		for (j = 0; j < res; j++) {
			if ((i == 0 && j == 0)
				|| (i == 0 && j == res - 1)
				|| (i == res - 1 && j == 0)
				|| (i == res - 1 && j == res - 1))
			{
				corner = 1;
			}
			else
			{
				corner = 0;
			}

			if (corner == 1) {
				printf("+");
			}
			else {
				if (j == 0 || j == res - 1) {
					printf("|");
				}
				else {
					if (j == (res / 2) & i == (res / 2)) {
						printf("X");
					}
					else if (i == j) {
						printf("\\");
					}
					else if (j == res - i - 1) {
						printf("/");
					}
					else {
						if ((i == 0 || i == res - 1) && (corner == 0)) {
							printf("-");
						}
						else {
							printf(" ");
						}
					}
				}
			}
		}
		printf("\n");
	}
}

void isEvenLength() {
	char key;
	int len;
	int count = 0;
	printf("Enter text:");
	scanf(" %c", &key);
	while (key != ENTER)
	{
		scanf("%c", &key);
		count = count + 1;
	}
	while (count >= 0) {
		if (count == 1) {
			printf("Your text's length is odd ");
		}
		else if (count == 0) {
			printf("Your text's length is even");
		}
		count = count - 2;
	}
}
	

void identifyText() {
	int isFirst = 1;
	char f = 0;
	char s = 0;
	int dec = 0;
	int inc = 0;
	int answer = 0;
	int status = 3; //0 - decrease, 1 - increase, 2 - constant ,3-mix

	printf("Enter text:");
	scanf(" %c", &f);
	char break_line = '1';
	while (f != 10) {
		if (isFirst) {
			s = f;
		}

		if (s < f) {
			inc = 1;
		}
		if (s > f) {
			dec = 1;
		}

		isFirst = 0;
		s = f;
		if (f < 'a' || f > 'z') {
			answer = -1;
		}

		scanf("%c", &f);

	}

	if (answer == -1) {
		printf("Your text is invalid");
	}
	else if ((inc == 1) && (dec == 0)) {
		printf("Your text is increasing");
	}
	else if ((inc==0)&&(dec==0)) {
		printf("Your text is constant");
	}
	else if ((inc == 0) && (dec == 1)) {
		printf("Your text is decreasing ");
	}
	else if ((inc == 1) && (dec == 1)) {
		printf("Your text is mixed ");
	}

	return 0;
}


void hexToDec() {
	int sum = 0;
	char digit;
	int place = 0;
	int invalid = 0;

	printf("Enter a reversed number in base 16: ");

	scanf("%c", &digit);
	scanf("%c", &digit);
	while (10 != digit)
	{
		if (48 <= digit && digit <= 57)
		{
			digit = digit - 48;
			sum = sum + (int)digit * pow(16, place);
		}
		else if (65 <= digit && digit <= 70)
		{
			digit = digit - 55;
			sum = sum + digit * pow(16, place);
		}
		else if (97 <= digit && digit <= 102)
		{
			digit = digit - 87;
			sum = sum + digit * pow(16, place);
		}
		else
		{
			printf("Error! %c is not a valid digit in base 16\n", digit);
			invalid = 1;
		}

		place++;
		(void)scanf("%c", &digit);
	}

	if (0 == invalid)
	{
		printf("%d", sum);
	}

}

void baseToDec() {
	//your code is here...
}

void bitCount() {
	int original_num = 0;
	int amount_of_ones = 0;
	int number = 0;

	printf("Enter a number: ");
	scanf("%d", &number);
	original_num = number;
	while (number != 0)
	{
		amount_of_ones += number % 2;
		number /= 2;
	}

	printf("The bit count of %d is %d", original_num, amount_of_ones);
}

void main() {
	int choice;
	do {
		printf("\nChoose an option:\n1: Draw\n2: Even or Odd\n3: Text type\
                \n4: Hex to Dec\n5: Base to Dec\n6: Count bits\n0: Exit\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1: draw();
			break;
		case 2: isEvenLength();
			break;
		case 3: identifyText();
			break;
		case 4: hexToDec();
			break;
		case 5: baseToDec();
			break;
		case 6: bitCount();
		case 0: break;
		default: printf("Wrong option!\n");
		}
	} while (choice != 0);
}