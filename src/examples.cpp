//============================================================================
// Name        : examples.cpp
// Author      : Oscar A Gomez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

int F (int n)
{
	int g = 0;
	if (n == 1)
		return n;
	g = F (n - 1);
	if (n % 2)
		return g + n;
	return g - n;
}


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

   printf("%d\n", F (2));
   printf("%d\n", F (2147483647));

	int x=8; 
	unsigned int z=0x3e;
	printf("%d\n", x%3+z<<2);

 int i = 5;
    printf("%d\n", i = ++i == 6);
    printf("%d\n", i );

#if something == 0
int some = 0;
#endif
 
     int thing = 0;
	 printf("%d %d\n", some, thing);


	return 0;
}
