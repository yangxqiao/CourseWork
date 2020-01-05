#include <iostream>
#include <string>
#include <set>
#include "setops.h"

using namespace std;

// Computes the intersection of s1 and s2
set<string> operator&(const set<string>& s1, 
                                const set<string>& s2)
{
	set<string> s;
	set<string>::iterator it;
	for(it = s1.begin(); it != s1.end(); ++it)
	{
		set<string>::iterator im = s2.find(*it);
		if(im != s2.end())
		{
			s.insert(*it);
		}
	}
	return s;
}

// Computes the union of s1 and s2
set<string> operator|(const set<string>& s1, 
                                const set<string>& s2)
{
	set<string> s;
	set<string>::iterator it;
	set<string>::iterator im;
	
	for(it = s1.begin(); it != s1.end(); ++it)
	{
		s.insert(*it);
	}

	for(im = s2.begin(); im != s2.end(); ++im)
	{
		s.insert(*im);
	}

	return s;
}

// Computes the difference of s1 - s2
set<string> operator-(const set<string>& s1,
                                const set<string>& s2)
{
	set<string> s;
	set<string>::iterator it = s1.begin();
	for(it = s1.begin(); it != s1.end(); ++it)
	{
		set<string>::iterator im = s2.find(*it);
		if(im == s2.end())
		{
			s.insert(*it);
		}
	}
	return s;
}

