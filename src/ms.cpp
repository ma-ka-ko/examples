/*
 * ms.cpp
 *
 *  Created on: Mar 1, 2016
 *      Author: oagomez
 */

#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <map>




using namespace std;

template <typename A, typename B>
std::ostream &operator<<(std::ostream &s, const std::vector<std::pair<A,B>> &vct)
{
	s << "[ ";
	for(typename std::vector<std::pair<A,B>>::const_iterator it = vct.begin(); it != vct.end(); it++)
		s << "(" << it->first << "," << it->second << ")";

	s << " ]\n";
	return s;
}



template <typename T>
std::ostream &operator<<(std::ostream &s, const std::vector<T> &vct)
{
	s << "[ ";
	copy(vct.begin(), vct.end(), std::ostream_iterator<T>(s, " "));
	s << " ]\n";
	return s;
}

template <typename T,typename U>
std::ostream &operator<<(std::ostream &s, const std::map<T,U> &mp)
{
	s << "[ ";
	for(typename map<T,U>::const_iterator it = mp.begin(); it != mp.end(); it++)
		s << "(" << it->first << "," << it->second << ")";
	s << " ]\n";
	return s;
}

void Reformat( vector<string> & phoneNumbers )
{
	for (vector<string>::iterator ph = phoneNumbers.begin(); ph != phoneNumbers.end(); ph++)
	{
		if((*ph)[3] == '-')
			*ph = ph->substr(4,4)+ph->substr(0,3)+ph->substr(7,4) ;
		else
			*ph = ph->substr(3,3)+"-"+ph->substr(0,3)+"-"+ph->substr(6,3) ;

	}

}

vector<int> sum_arrays(vector<int> a, vector<int> b)
{
	vector<int> result;
	for(size_t i=0; i< a.size(); i++)
	{
		result.push_back(a[i]+b[i]);
	}
	return result;
}

//template <typename T, typename U>
bool sort_by_second(std::pair< const char,int> first, std::pair<const char,int> second)
{
	return first.second > second.second;
}

void no_repeat (string &s)
{
	map<char,int> mymap;
	for(size_t i=0; i< s.size(); i++)
	{
		mymap[s[i]]++;
	}
	//cout << mymap;
	std::vector<std::pair<char,int> > v(mymap.begin(),mymap.end());
	sort(v.begin(),v.end(),&sort_by_second);
	cout << "  "<< v;
	size_t r = 0;
	size_t f = 1;
	size_t o = 0;
	while(r < v.size() && f < v.size())
	{
		while(v[r].second > 0)
		{
			cout << v[r].first  << " - " << v[r].second << endl;
			s[o] = v[r].first;
			o++;
			v[r].second --;
			while(f < v.size() && v[f].second == 0) f++;
			if(f < v.size())
			{
				cout << v[f].first << " - " << v[f].second << endl;
				s[o] = v[f].first;
				o++;
				v[f].second --;
			}
			else if (v[r].second > 0)
				cout << "Invalid Input " << endl;

		}
		r=f;
		f++;
	}
}

vector<int> merge(vector<int> a,vector<int> b)
{
	//cout << "-------------------------------------------------------" << endl;
	vector<int> r;
	size_t x = 0;
	size_t y = 0;

	//cout <<a;
	//cout <<b;

	while(x < a.size() && y < b.size() )
	{
		//cout << a[x] << " " << b[y] << " | " << r;
		if(a[x] < b[y] )
		{
			r.push_back(a[x]);
			x++;
		}
		else
		{
			r.push_back(b[y]);
			y++;
		}
	}
	for (;x < a.size();x++)
		r.push_back(a[x]);

	for (;y < b.size();y++)
			r.push_back(b[y]);

	//cout << r;
	return r;
}

vector<int> merge(vector<int> a,vector<int> b ,vector<int> c)
{
	vector<int> r = merge(a,b);
	r = merge(r,c);
	return r;

}

bool myFunction(char first, char second)
{
	cout << first << " vs " << second << endl;
	return first < second;
}

int main()
{
	vector<string> pn;
	pn.push_back("xxxyyyzzzz");
	pn.push_back("XXX-YYY-ZZZZ");
	Reformat(pn);
	cout << pn;
	cout << "-------------------------------------------------------" << endl;
	vector<int> a = {1,2,3,4,5};
	vector<int> b = {2,4,6,8,10};
	vector<int> r = sum_arrays(a,b);
	cout << r;
	cout << "-------------------------------------------------------" << endl;
	vector<string> strings = {"aaa123","123aaaaa","bbbaaaa123aaa1b23aabab","guadalajara"};
	for (size_t c = 0; c<strings.size(); c++)
	{
		string s = strings[c];
		cout << s ;//<< endl;
		no_repeat(s);
		cout << s << endl;
		cout << "==========" << endl;

	}

	cout << "-------------------------------------------------------" << endl;

	vector<int> r2 = merge(a,b,r);
	cout << r2 ;


	return 0;
}

/*
public class P

{
    public string Name;
    public P[] Acquaintances;
    public P(string name, P[] acquaintances)
    {
        if ( String.IsNullOrWhiteSpace( name ) )
        {
            throw new ArgumentException( "Name cannot be null or white space.", "name" );
        }
        this.Name = name;
        this.Acquaintances = acquaintances;
    }

    public bool Mystery( string name )
    {
        if ( String.IsNullOrWhiteSpace( name ) )
        {
            throw new ArgumentException( "Name cannot be null or white space.", "name" );
        }

        Stack<Person> myStack = new Stack<P>();
        foreach ( P acquaintance in this.Acquaintances )
        {
            myStack.Push( acquaintance );
        }

        do
        {
            var person = myStack.Pop();
            if ( person.Name.Equals( name ) )
            {
                return true;
            }

            foreach ( P acquaintance in person.Acquaintances )
            {
                myStack.Push( acquaintance );
            }
        } while ( myStack.Count >= 0 );
        return false;
    }
}
*/


