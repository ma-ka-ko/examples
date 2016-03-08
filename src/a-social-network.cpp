/*
 * a-social-network.cpp
 *
 * Created on: Feb 24, 2016
 *   Author: oagomez
 */


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

//#include <iostream>
#include <iterator>
//#include <sstream>
//#include <fstream>

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::set<T> &lst)
{
	s << "{ ";
	copy(lst.begin(), lst.end(), std::ostream_iterator<T>(s, " "));
	s << "}\n";
	return s;
}

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::list<T> &lst)
{
	s << "[ ";
	copy(lst.begin(), lst.end(), std::ostream_iterator<T>(s, " "));
	s << "]\n";
	return s;
}


template <typename A, typename B>
std::ostream &operator<<(std::ostream &s, const std::vector<std::pair<A,B>> &vct)
{
	s << "[ ";
	//for(typename std::vector<std::pair<A,B>>::const_iterator it = vct.begin(); it != vct.end(); it++)
	for(auto it = vct.begin(); it != vct.end(); it++)
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

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
using namespace std;

vector<string> getDirectFriendsForUser(string user)
{
	int fn = (rand() % 15) + 1;
	vector<string> friends= vector<string>();
	for(int i=0;i<fn;i++)
	{
		friends.push_back(SSTR((rand() % fn)+1));
	}
	return friends;
}

vector<string> getAttendedCoursesForUser(string user)
{
	int cn = (rand() % 15) + 1;
	vector<string> courses= vector<string>();
	for(int i=0;i<(rand() % cn)+1;i++)
	{
		courses.push_back(SSTR((rand() % cn)+1000));
	}
	return courses;
}


bool myFunction(std::pair<string,int> first, std::pair<string,int> second)
{
	return first.second > second.second;
}

vector<string> getRankedCourses(string user)
{
	vector<string> rankedCourses;
	set<string> friends;
	set<string> mycourses;
	vector<string> temp_courses = getAttendedCoursesForUser(user);
	cout <<"temp_courses: " << temp_courses ;
	mycourses.insert(temp_courses.begin(),temp_courses.end());

	map<string,int> courses;
	vector<string> friends1 = getDirectFriendsForUser(user);
	for(vector<string>::iterator it = friends1.begin(); it != friends1.end(); it++)
	{
		friends.insert(*it);
		vector<string> friends2 =  getDirectFriendsForUser(*it);
		friends.insert(friends2.begin(),friends2.end());
	}

	cout << "friends: " << friends ;
	for(set<string>::iterator it = friends.begin(); it != friends.end(); it++)
	{
		vector<string> user_courses = getAttendedCoursesForUser(*it);
		for(vector<string>::iterator course = user_courses.begin(); course != user_courses.end(); course++)
		{
			courses[*course]++;
		}
	}

	std::vector<std::pair<string,int> > myVec(courses.begin(),courses.end());
	sort(myVec.begin(),myVec.end(),&myFunction);

	cout << "All Courses: " <<myVec;

	//for(std::vector<std::pair<string,int> >::iterator  c=myVec.begin(); c != myVec.end(); c++)
	for(auto  c=myVec.begin(); c != myVec.end(); c++)
	{
		if(mycourses.find(c->first) == mycourses.end())
		{
			//cout << c->first << " , " << c->second << endl;
			rankedCourses.push_back(c->first);
		}
	}


	return rankedCourses;

}

int main()
{
	vector<string> res = getRankedCourses("makako");
	cout << endl << "RESULT:" << res << endl;
	return 0;
}
