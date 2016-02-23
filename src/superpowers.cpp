/*
 * superpowers.cpp
 *
 *  Created on: Nov 11, 2015
 *      Author: oagomez
 */


#include <iostream>
#include <limits>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <vector>
#include <stdio.h>      /* printf */
#include <errno.h>      /* errno, EDOM */
#include <fenv.h>       /* feclearexcept, fetestexcept, FE_ALL_EXCEPT, FE_INVALID */

#pragma STDC FENV_ACCESS on

typedef unsigned long long int ULLINT;
typedef std::unordered_set<ULLINT>  MySet;


ULLINT power2 (ULLINT x, ULLINT y)
{
	if (y == 0)
		return 1;

	ULLINT temp;
	temp = power2 (x, y / 2);
	if (temp == 0 || (std::numeric_limits<ULLINT>::max() / temp) < temp)
		return 0;

	if ((y % 2) == 0)
		return temp * temp;
	else
	{
		temp = temp * temp;
		if (x != 0 && (std::numeric_limits<ULLINT>::max() / x) < temp)
			return 0;
		return x * temp * temp;
	}
}

ULLINT mypow(ULLINT val, ULLINT exp)
{
	return power2(val,exp);//res;
}

int main (int argc, const char * argv[])
{
	MySet superPowers1;
	int x = 0;
	ULLINT max_ull = std::numeric_limits<ULLINT>::max();

	std::priority_queue<ULLINT, std::vector <ULLINT>, std::greater<ULLINT> > superPowers;
	for (ULLINT n = 2; n <= 64; n++)
	{
		for (ULLINT m = 2; m <= 64; m++)
		{
			if (true || (n % m == 0 && n != m))
			{
				for (ULLINT x = 2; x <= 256*1024; x++)
				{
					unsigned long long int spx = mypow(x,n);
					if (spx != 0)
					{
						unsigned long long int y = mypow(x,n/m);
						unsigned long long int spy = mypow(y,m);

						if (x != y && spx == spy)
						{
							superPowers1.insert(spx);
							//9625380786450625
							/*if ( spx == 9625380786450624  )
							{
								std::cout <<"\tx:"<< x << " n:" << n << " " << mypow(x,n)   <<" <=> "<< mypow(y,m) << " y:" << y <<" m:"<< m << " " << spx<< std::endl;
							}*/
						}
						else
						{
							std::cout <<"\tx:"<< x << " n:" << n << " " << mypow(x,n)   <<" <=> "<< mypow(y,m) << " y:" << y <<" m:"<< m << " " << spx<< std::endl;
						}
					}
					else
					{
						//std::cout <<"\tx:"<< x << " n:" << n << " " << mypow(x,n) << " " << max_ull  << std::endl;
						break;
					}
				}
			}
		}
	}

	for (const unsigned long long int& x: superPowers1) superPowers.push(x);

	std::cout << "1\n";
	while(!superPowers.empty())
	{
		std::cout << superPowers.top() << "\n";
		superPowers.pop();
	}


	return 0;
}

