/*
 * a-lockers.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: oagomez
 */


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 10

void display(int cityLength, int cityWidth, const vector<vector<int> >& v)
{
	for (int i = 0; i < cityLength; i++)
	{
		for (int j = 0; j < cityWidth; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

vector < vector < int > > getLockerDistanceGrid(int cityLength, int cityWidth, vector < int > lockerXCoordinates, vector < int > lockerYCoordinates)
{

	cout << cityLength << " x " << cityWidth << endl;
	vector<int>::iterator itx = lockerXCoordinates.begin();
	vector<int>::iterator ity = lockerYCoordinates.begin();
	while (itx != lockerXCoordinates.end() && ity != lockerYCoordinates.end())
	{
		cout << *itx << "," << *ity << endl;
		itx++; ity++;
	}

	vector < vector < int > > v(cityLength,vector<int>(cityWidth));
	for(int i=0; i< cityLength; i++)
		for (int j=0;j<cityWidth; j++)
		{
			v[i][j] = INF;
		}


	itx = lockerXCoordinates.begin();
	ity = lockerYCoordinates.begin();
	while (itx != lockerXCoordinates.end() && ity != lockerYCoordinates.end())
	{
		v[*itx-1][*ity-1] = 0;
		itx++;
		ity++;
	}

	display(cityLength, cityWidth, v);

	bool changed = true;
	while(changed)
	{
		changed = false;
		cout << " ------------------------ " <<endl;
		for(int i=0; i< cityLength; i++)
		{
			for (int j=0;j<cityWidth; j++)
			if (v[i][j] != 0)
				{
					int left = INF;
					int right= INF;
					int up   = INF;
					int down = INF;
					if (i>0)            left = v[i-1][j];
					if (i<cityLength-1) right= v[i+1][j];
					if (j>0)            up   = v[i][j-1];
					if (j<cityWidth-1)  down = v[i][j+1];
					int mymin =min(min(left,right),min(up,down));
					if (v[i][j] != mymin +1) changed = true;
					v[i][j] = mymin +1;
				}
		}
		display(cityLength, cityWidth, v);
	}

	return v;

}

int main ()
{
	int cityLength = 3;
	int cityWidth  = 5;
	vector < int > lockerXCoordinates = {2};
	vector < int > lockerYCoordinates = {3};
	vector < vector < int > >  v = getLockerDistanceGrid(cityLength,cityWidth,lockerXCoordinates,lockerYCoordinates);


}
