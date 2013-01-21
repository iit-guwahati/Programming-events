/* Program to find the number of trailing zeroes in a factorial of a number 
 * The function is as follows 
 * Z(n) = int(n/5) + int(n/5/5) + int (n/5/5/5) + .... 
 * Note that here int() is a replacement for floor function.
 */

//#include<iostream>
#include<cstdio>

unsigned int zeroes(unsigned int n)
{
	unsigned int all = 0;
	unsigned int temp = 1;
	while(1)
	{
		temp = 5*temp;
	
		if ( n/temp == 0)
			break;
		else
			all = all + n/temp;
	}

	return all;
}

int main()
{
	unsigned int t;
	scanf ("%u", &t);
	unsigned int n;
	while (t--)
	{
		scanf("%d",&n);
		printf("%d\n", zeroes(n));
	}
}
