/*
 * grid-challenge.cpp
 * https://www.hackerrank.com/challenges/grid-challenge
 *
 *  Created on: Feb 23, 2016
 *      Author: oagomez
 */



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define TRACES 0

void debug(char * msg)
{
	if(TRACES)
	{
		std::cout << msg << std::endl;
	}

}

void print_matrix(char ** G, int n)
{
	if(TRACES)
	{
		for (int i =0; i< n; i++)
		{
			for(int j =0; j< n; j++)
			{
				std::cout << G[i][j];
			}
			std::cout << std::endl;
		}
	}
}

void delete_matrix(char **G, int n)
{
	if (G != NULL)
	{
		for (int i =0; i< n; i++)
		{
			if (G[i]!= NULL)
				delete G[i];
		}
		delete G;
	}
}


bool is_sorted(char ** G, int n)
{
	bool sorted = true;
	for (int i =0; i< n; i++)
	{
		for(int j =0; j< n - 1; j++)
		{
			sorted = sorted && (G[i][j] <= G[i][j+1]);
			if(TRACES && !sorted)
				std::cout << G[i][j] << " <= " << G[i][j+1] << " = "<< (G[i][j] <= G[i][j+1]) << endl;
			sorted = sorted && (G[j][i] <= G[j+1][i]);
			if(TRACES && !sorted)
				std::cout << G[j][i] << " <= " << G[j+1][i] << " = "<< (G[j][i] <= G[j+1][i])<< endl;
		}

	}
	return sorted;
}



int compare_rows (const void* a, const void *b)
{
	return  ( (*(char**)a)[0] - (*(char**)b)[0] );
}

int compare (const void* a, const void *b)
{
	return  ( (*(char*)a) - (*(char*)b) );
}

int main()
{
	int T,n;
	char ** G;
	std::cin >> T;
	for (int t =0; t<T; t++)
	{
		std::cin >> n;
		if (TRACES) std::cout << t << " ----------- " << n << std::endl;

		G = new char * [n];
//		for (int i =0; i< n; i++)
//				G[i] = new char[n];
		for (int i =0; i< n; i++)
		{
			G[i] = new char[n];
			for(int j =0; j< n; j++)
			{
				std::cin >> G[i][j];
			}
		}
		print_matrix(G,n);
		for (int g=0; g< n; g++)
			qsort(G[g],n,sizeof(char),compare);
		if (TRACES) std::cout<<"******************************" <<endl;
		print_matrix(G,n);
		if (is_sorted(G,n) )
			std::cout << "YES" <<std::endl;
		else
			std::cout << "NO" <<std::endl;
		delete_matrix(G,n);
	}
	return 0;
}
