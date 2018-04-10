/* NetId: ml6095
 * Name: Meisi LI
 * Homework 1, B: Simple Sum, Large part
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	int number;
	int c;
	int sum = 0;
	while((c=getchar())!=EOF){
		//variable to indicate sign of input number
		bool negative = false;
		number = 0;

		// extract current character from buffer
		// c = getchar();
		if (c=='-')
		{
			// number is negative
			negative = true;

			// extract the next character from the buffer
			c = getchar();
		}

		// Keep on extracting characters if they are integers
		// i.e ASCII Value lies from '0'(48) to '9' (57)
		for (; (c>47 && c<58); c=getchar())
			number = number *10 + c - 48;

		// if scanned input has a negative sign, negate the
		// value of the input number
		if (negative)
			number *= -1;

		sum += number;

		if (c == '\n'){
			printf("%d\n", sum);
			sum = 0;
		}

	}
	return 0;
}