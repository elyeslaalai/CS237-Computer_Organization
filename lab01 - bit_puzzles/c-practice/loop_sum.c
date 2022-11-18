#include <stdio.h>

// calculates the sum of the numbers from 1 to lastNum and returns the sum
int sumUntil (int lastNum) {

	int sum = 0, counter = 0;

	for (i = 1; i <= lastNum; i++)
		sum += i;

	return sum;

}

// for a positive integer calculates the sum that
int main(int argc, char *argv[]) {

	int n = 0, numElements = 0;

	// reads in the the number of positive integers we are summing
	printf("Please enter a positive integer: \n");
	numElements = scanf("%d", &n);

	// if there is no input, or the input is not positive
	if ( numElements != 1 || n <= 0 )
		printf("Need to enter a positive integer!\n");
	// if conditions for sum are satisfied
	else
		printf("Sum from 1 to n: %d\n", sumUntil(n));

	return 0;

}
