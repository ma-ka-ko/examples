/*
 * subsequences.cpp
 *
 *  Created on: Nov 19, 2015
 *      Author: oagomez
 *
 *  http://codeforces.com/problemset/problem/597/C
 */

#include <iostream>
#include <vector>

template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
	os << "[";
	for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
	{
		os << " " << *ii;
	}
	os << "]";
	return os;
}

std::vector<std::vector<int> > find_subsequences(int pivot, const int *seq, int start, int n, int k)
{
/*	std::cout << "\n pivot : " << pivot;
	std::cout << "\n start : " << start << " = " << seq[start];
	std::cout << "\n k     : " << k << std::endl;
	std::cout << "[";
	for (int i =start; i< n; i++) std::cout << seq[i] << " ";
	std::cout << "]";
	std::cout << std::endl;
*/

	std::vector<std::vector<int> > sss;

	//if (k==0) return sss;
	std::vector<int>  subseq;
	if( k == 0)
	{
		subseq.push_back(pivot);
		sss.push_back(subseq);
		subseq.clear();
		return sss;
	}


	for (int i=start; i<n; i++)
	{
		if (pivot < seq[i])
		{
			if(k==1)
			{
				subseq.push_back(pivot);
				subseq.push_back(seq[i]);
				sss.push_back(subseq);
				subseq.clear();
			}
			else
			{
				std::vector<std::vector<int> > rss = find_subsequences(seq[i],seq,i+1,n,k-1);
				for(auto r = rss.begin();r!= rss.end(); r++)
				{
					r->insert(r->begin(),pivot);
					sss.push_back(*r);
				}

			}
		}
	}


//	std::cout << "\n sss: " << sss;
//	std::cout << "\n**********************\n";
	return sss;
}

std::vector<std::vector<int>> find_subsequences( const int *seq, int start, int n, int k)
{
	std::vector<std::vector<int>> sss;
	for(int i=start; i<n; i++)
	{
		std::vector<std::vector<int>> rss = find_subsequences(seq[i],seq,i+1,n,k-1);
		for(auto r = rss.begin();r!= rss.end(); r++)
		{
			sss.push_back(*r);
		}
	}
	return sss;
}



int main (int argc, char *argv[])
{
	int n,k;
	int * seq;
	std::cin >> n;
	std::cin >> k;
//	std::cout << n << " " << k << std::endl;
	seq = new int [n];
	for (int i =0; i< n; i++)
	{
		std::cin >> seq[i];
	}
/*	for (int i =0; i< n; i++)
	{
		std::cout << seq[i] << " ";//std::endl;
	}
*/	//std::cout << "\n-----------------------\n";

	//int res = find_subsequences(n,k,seq);
	std::vector<std::vector<int>> vres = find_subsequences(seq,0,n,k+1);
//	std::cout << "\n-----------------------\n";
	int i=1;
	for (auto v=vres.begin(); v!= vres.end(); v++)
		std::cout << i++ <<": " << *v << std::endl;


	//std::cout << res << std::endl;

	delete [] seq;
	return 0;
}


