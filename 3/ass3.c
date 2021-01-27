#include <stdio.h>
#include <math.h>
#include "ass3.h"

int counter = 0;


int digitCount(int number)
{//counting efficiancy
	int count = 0;
	while (number != 0)
	{
		number = number / 10;
		count++;
	}
	return count;
}

int maxDigits(int arr[][MAX], int size1, int size2)
{//making the sizes of the numbers in the arrays equle 
	int maxCount = 0, CurrentDigitCount = 0;
	maxCount = digitCount(arr[0][0]);
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			CurrentDigitCount = digitCount(arr[i][j]);
			if (maxCount < CurrentDigitCount)
				maxCount = CurrentDigitCount;
		}
	}
	return maxCount;
}

double iterPow(double x, int y)
{
	double zero = 0;//chaking conditions of base and pow
	if ((y < 0) && (x == 0))
		return 1 / zero;
	double base;
	base = x;
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	int sign = 1;
	if (y < 0)
		sign = -1;
	for (int i = 1; i < y * sign; i++)
	{
		counter++;
		x *= base;
	}
	if (sign == 1)
		return x;
	return 1 / x;
}

double recPow(double x, int y)
{//usig the second formul
	counter++;
	int flag = 0;
	double zero = 0;
	if ((y < 0) && (x == 0))
		return 1 / zero;
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	if (y < 0) {//if y<0 make it y>0 
		y = y * (-1);
		flag = 1;
	}
	if (flag)//if is true make it fractions
		return (x * recPow(1 / x, y + 1));
	return x * recPow(x, y - 1);
}

double recEffiPow(double x, int y)
{//using the 3 formul
	int flag = 0;
	counter++;
	double zero = 0;
	if ((y < 0) && (x == 0))
		return 1 / zero;//illigele
	if (y < 0) {
		y = y * (-1);
		x = 1 / x;//make the num fractions
	}
	if (y == 1)
		return x;
	if (y == 0)
		return 1;
	if (x == 0)
		return 0;
	else if (y % 2 == 0)//if even make the result using the formul
	{
		x = recEffiPow(x, (int)(y / 2));
		return x * x;
	}
	else {//if odd make the result using the formul
		double z = recEffiPow(x, (int)((y - 1) / 2));
		return z *z *x ;
	}
}

int isPermutation(int arr1[], int size1, int arr2[], int size2)
{//cheking if the sizes are equal
	int count = 0;
	if (size1 != size2)//conpearing the the arrays in size and from the inside
		return 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (arr1[i] == arr2[j])
			{
				count++;
				arr2[j] = -1; // This assignment is to sign that we already compared to this cell.
				break;
			}
		}
	}
	if (count == size1)
		return 1;
	return 0;
}

void printArr2D(int arr[][MAX], int size1, int size2)
{
	int MaxDigits = maxDigits(arr, size1, size2);
	int currentDigit = 0, missingDigits = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{//making the zeros for the short nums
			currentDigit = digitCount(arr[i][j]);
			missingDigits = MaxDigits - currentDigit;
			for (int k = 0; k < missingDigits; k++)
				printf("%d", 0);
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}