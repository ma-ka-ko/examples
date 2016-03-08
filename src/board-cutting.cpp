/*
 * board-cutting.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: oagomez
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define TRACES 0

void display(int m, int n, vector<int> & cy, vector<int> & cx)
{
	if (TRACES)
	{
		cout << " ----------------------- " << endl;
		cout << m << " " << n << endl;
		for (auto i: cy) cout << i << " ";
		cout << endl;
		for (auto i: cx) cout << i << " ";
				cout << endl;
	}
}

int cut(int m, int n, vector<int> & cy, vector<int> & cx)
{
	int MOD_VAL = 1000000000 + 7 ;
	unsigned long long int cost =0;
	sort(cx.begin(),cx.end());//, std::greater<int>());
	sort(cy.begin(),cy.end());//, std::greater<int>());
	display(m,n,cy,cx);
	size_t x = 0;
	size_t y = 0;
	if (TRACES) cout << " ----------------------- " << endl;
	if (TRACES) cout << "Sizes: " << cx.size() <<" " << cy.size() << endl;
	if (TRACES) cout << "x y" << " ----| "<< "vx vy "<<endl;
	while( cx.size() > 0  && cy.size() > 0 )
	{
		if (TRACES) cout << x <<" " << y << " ----|  ";
		if (TRACES) cout << cx.back() <<" " << cy.back() ;
		unsigned long long int round_cost =0 ;

		if(cx.back() > cy.back())
		{
			round_cost = (y+1) * cx.back();
			x++;
			cx.pop_back();
		}
		else
		{
			round_cost = (x+1) * cy.back();
			y++;
			cy.pop_back();
		}
		cost =  ((cost % MOD_VAL)  +  (round_cost% MOD_VAL ) ) % MOD_VAL;
		if(TRACES) cout << " ----|  +"<< round_cost<< " " << cost << endl;
	}

	while(cx.size() > 0)
	{
		int round_cost = (y+1) * cx.back();
		x++;
		cx.pop_back();
		cost =  ((cost % MOD_VAL)  +  (round_cost% MOD_VAL ) ) % MOD_VAL;
	}

	while(cy.size() > 0)
	{
		int round_cost = (x+1) * cy.back();
		y++;
		cy.pop_back();
		cost =  ((cost % MOD_VAL)  +  (round_cost% MOD_VAL ) ) % MOD_VAL;
	}
	return cost;
}

int main()
{
	int T;
	std::cin >> T;
	for (int t =0; t<T; t++)
	{
		int m,n;
		std::cin >> m;
		std::cin >> n;
		vector<int> cy;
		int tmp;
		for (int y=0; y<m-1;y++)
		{
			std::cin >> tmp;
			cy.push_back(tmp);
		}
		vector<int> cx;
		for (int x=0; x<n-1;x++)
		{
			std::cin >> tmp;
			cx.push_back(tmp);

		}

		display(m,n,cy,cx);
		int cost =  cut(m,n,cy,cx);
		cout << cost << endl;


	}
	return 0;
}

