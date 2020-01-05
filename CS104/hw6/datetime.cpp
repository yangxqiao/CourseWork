#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip> 
#include "datetime.h"

using namespace std;

DateTime::DateTime()
{
	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime(&rawtime);
	
	this->year = timeinfo->tm_year + 1900;
	this->month = timeinfo->tm_mon + 1;
	this->day = timeinfo->tm_mday;
	this->hour = timeinfo->tm_hour;
	this->min = timeinfo->tm_min;
	this->sec = timeinfo->tm_sec;
}

/**
* Alternative constructor 
*/
DateTime::DateTime(int hh, int mm, int ss, int year, int month, int day)
{
	this->hour = hh;
	this->min = mm;
	this->sec = ss;
	this->year = year;
	this->month = month;
	this->day = day;
}

/**
* Return true if the timestamp is less-than other's
*
* @return result of less-than comparison of timestamp
*/
bool DateTime::operator<(const DateTime& other) const
{
	if(this->year < other.year)
	{
		return true;
	}
	else if(this->year == other.year)
	{
		if(this->month < other.month)
		{
			return true;
		}
		else if(this->month == other.month)
		{
			if(this->day < other.day)
			{
				return true;
			}
			else if(this->day == other.day)
			{
				if(this->hour < other.hour)
				{
					return true;
				}
				else if(this->hour == other.hour)
				{
					if(this->min < other.min)
					{
						return true;
					}
					else if(this->min == other.min)
					{
						if(this->sec < other.sec)
						{
							return true;
						}
					}
				}
			}
		}
	}

	return false;
}

/**
* Outputs the timestamp to the given ostream in format:
*   YYYY-MM-DD HH::MM::SS
*
* @return the ostream passed in as an argument
*/
ostream& operator<<(ostream& os, const DateTime& other)
{
	os << setfill ('0') << setw(4) << other.year;
	os << '-';
	os << setfill ('0') << setw(2) << other.month;
	os << '-';
	os << setfill ('0') << setw(2) << other.day;
	os << ' ';
	os << setfill ('0') << setw(2) << other.hour;
	os << ':';
	os << setfill ('0') << setw(2) << other.min;
	os << ':';
	os << setfill ('0') << setw(2) << other.sec;
	return os;
}

/**
* Inputs the timestamp to the given istream expecting the format:
*   YYYY-MM-DD HH::MM::SS
*  Returns if an error in the format with the DateTime set to the
*   current system time/date
*   
*
* @return the istream passed in as an argument
*/
istream& operator>>(istream& is, DateTime& dt)
{
	bool input = false;
	string year;
	getline(is, year, '-');
	if(year.size() == 4 && !is.fail())
	{	
		string month;
		getline(is, month, '-');
		if(month.size() == 2 && !is.fail())
		{	
			string day;
			getline(is, day, ' ');
			if(day.size() == 2 && !is.fail())
			{	
				string hour;
				getline(is, hour, ':');
				if(hour.size() == 2 && !is.fail())
				{
					string min;
					getline(is, min, ':');
					if(min.size() == 2 && !is.fail())
					{
						string sec;
						getline(is, sec, '\n');
						if(sec.size() == 2 && !is.fail())
						{
							stringstream syear(year);
							syear >> dt.year;
							
							stringstream smonth(month);
							smonth >> dt.month;

							stringstream sday(day);
							sday >> dt.day;

							stringstream shour(hour);
							shour >> dt.hour;

							stringstream smin(min);
							smin >> dt.min;

							stringstream ssec(sec);
							ssec >> dt.sec;

							input = true;
						}
					}
				}				
			}
		}
	}

	if(input == false)
	{
		time_t rawtime;
		struct tm * timeinfo;
		time (&rawtime);
		timeinfo = localtime(&rawtime);
		
		dt.year = timeinfo->tm_year + 1900;
		dt.month = timeinfo->tm_mon + 1;
		dt.day = timeinfo->tm_mday;
		dt.hour = timeinfo->tm_hour;
		dt.min = timeinfo->tm_min;
		dt.sec = timeinfo->tm_sec;
	}

	return is;
}