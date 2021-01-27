
#include <stdio.h>

void draw() {
	// Variable declartion
	int x,i;
	char letters[8] = { 'a','b','c','d','e','f','g' };
	printf("Enter a number: ");
	scanf("%d", &x);
	if (x == 0) {
		printf("X\n");
		return;
	}
	//For the first and last indexes i wrote '+' and in the rest i wrote -.
	for ( i = 0; i < 2 * x + 1; i++)
	{
		if ((i == 0) || (i == 2 * x))
			printf("+");
		else
			printf("-");
	}
	printf("\n");
	for (i = 0; i < 2 * x - 1; i++)
	{//tengles lines and +
		for(int j = 0 ; j < 2*x+1;j++)
		{
			if ((i == (2 * x - 1) / 2) && (j == i +1 )) 
				printf("X");//creating the X it should be on the line of j=I+1 (it is a kind of line ) in dot i
			else if ((j == 0) || (j == 2 * x))
				printf("|");
			else if (j == i + 1)
				printf("%s",letters);

			else if (j == 2 * x - i - 1)
				printf("/");
			else
				printf(" ");
		}
		printf("\n");
	}
	for (i = 0; i < 2 * x + 1; i++)
	{	//For the first and last indexes i wrote '+' and in the rest i wrote -.
		if ((i == 0) || (i == 2 * x))
			printf("+");
		else
			printf("-");
	}
	       printf("\n");
}

void isEvenLength() {
	char key;
	int count = 0;
	printf("Enter text:");
	scanf(" %c", &key);
	while (key != 10)
	{//till there no enterf
		scanf("%c", &key);
		count = count + 1;
	}
	while (count >= 0) {//till no 0 
		if (count == 0) {
			printf(" Your text's length is even");
		}//if 0 even
		if (count == 1) {
			printf(" Your text's length is odd");
		}//if 1 odd

		count = count - 2;
	}//minusing 2 till 0
	printf("\n");
}

void identifyText() {
	int isFirst = 1;
	char first = 0;
	char second = 0;
	int dec = 0;
	int inc = 0;
	int answer = 0;
	int status = 3; //0 - decrease, 1 - increase, 2 - constant ,3-mix

	printf("Enter text:");
	scanf(" %c", &first);
	while (first != 10) {//till no enter
		if (isFirst) {
			second = first;
		}
		if (second < first) {//if first num >second num 
			inc = 1;  
		}
		if (second > first) {
			dec = 1;
		}

		isFirst = 0;//saving the char and chacking the next one 
		second = first;
		if (first < 'a' || first > 'z') {//when letter is not in the rang between a-z
			answer = -1;
		}

		scanf("%c", &first);

	}
	//printing the outputs
	if (answer == -1) {
		printf(" your text is invalid");
	}
	else if ((inc == 1) && (dec == 0)) {
		printf(" your text is increasing");
	}
	else if ((inc == 0) && (dec == 0)) {
		printf(" your text is constant");
	}
	else if ((inc == 0) && (dec == 1)) {
		printf(" your text is decreasing");
	}
	else if ((inc == 1) && (dec == 1)) {
		printf(" your text is mixed");
	}
	printf("\n");
}

void hexToDec() {
	int sum = 0;
	char digit;
	int place = 0;
	int invalid = 0, powerSum = 1;

	printf("Enter a reversed number in base 16: ");

	scanf(" %c", &digit);
	while (10 != digit)
	{//checking what kind of digit we got in husky 0-9
		if ('0' <= digit && digit <= '9')
		{
			digit = digit - '0';
			while (place != 0)
			{//creating the option of "hezka"
				powerSum *= 16;
				--place;
			}//making the dec
			sum = sum + (int)digit * powerSum;
		}
		else if ('A' <= digit && digit <= 'F')//if it is in this ranges in the husky A-F
		{
			digit = digit - 'A'+10;//making it nums betweet 1-9
			while (place != 0)
			{
				powerSum *= 16;
				--place;
			}
			sum = sum + (int)digit * powerSum;
		}
		else if ('a' <= digit && digit <= 'f')
		{//a-f making 1-9
			digit = digit - 'a'+10;
			while (place != 0)
			{
				powerSum *= 16;
				--place; //hezha
			}
			sum = sum + (int)digit * powerSum;
		}//suming
		else
		{//other cases that we dont want
			printf(" Error! %c is not a valid digit in base 16\n", digit);
			invalid = 1;
		}

		place++;//ading to the place so we can make th hezka
		(void)scanf("%c", &digit);//scaning th next digits 
	}

	if (0 == invalid)//if it isent our eror we can print the sum
	{
		printf("%d\n", sum);
	}

}

void baseToDec() {
	int sum = 0;
	char digit;
	int place = 0;
	int powerSum = 1;
	int base;
	int flage=1;
	printf("Enter a base (2-10): ");//asking for base
	scanf(" %d", &base);//scaning
	printf("Enter a reversed number in base %d: ",base);//asking for num
	scanf(" %c", &digit);//scaning
	
	while (10 != digit)//till isnt enter
	{
		digit = digit - '0';//making digit number 1-9
		if (digit >= base) {//making eror 
			printf("Error! %c is not a valid digit in base %d \n", (digit+48), base);
			flage = 0;//in this case i dont want to print the result cause it is mistaken
		}
		else {
			while (place != 0)
			{//making hezka
				powerSum *= base;
				--place;
			}
			sum = sum + (int)digit * powerSum;
			place++;
		}
			scanf("%c", &digit);
		//scaning the next one
	}
	if (flage != 0) {//when i shodent get error
		printf("%d\n", sum);
	}
}

void bitCount() {
	int original_num = 0;
	int amount_of_ones = 0;
	int number = 0;

	printf("Enter a number: ");
	scanf("%d", &number);//scaning
	original_num = number;//saving my num
	while (number != 0)
	{
		amount_of_ones += number % 2;//adding the numbers that arn't 0 after modeling them
		number /= 2;
	}

	printf("The bit count of %d is %d\n", original_num, amount_of_ones);
}

void main() {
	int choice;
	do {
		printf("Choose an option:\n1: Draw\n2: Even or Odd\n3: Text type\
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
