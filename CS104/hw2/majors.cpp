#include <iostream>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include "setops.h"

using namespace std;

int main(int argc, char * argv[])
{
	ifstream ifile(argv[1]);
	ifstream mfile(argv[2]);
	ofstream ofile(argv[3]);
	
	if(ifile.fail())
	{
		cout << "Cannot open " << argv[1] << endl;
		return 0;
	}

	if(mfile.fail())
	{
		cout << "Cannot open " << argv[2] << endl;
		return 0;
	}

	map< string, set<string> > all_student_names_and_majors;
	string line;
	while(getline(ifile, line))
	{
		if(line.length() != 0)
		{
			stringstream ss(line);

			string line_of_name;
			getline(ss, line_of_name, ',');
			stringstream sst(line_of_name);
			string my_name = "";
			string part_of_name;
			int temp = 0;
			while(sst >> part_of_name)
			{
				if(temp == 0)
				{
					my_name = my_name + part_of_name;	
					temp++;				
				}
				else
				{
					my_name = my_name + " " + part_of_name;
					temp++;
				}
			}

			string line_of_majors;
			getline(ss, line_of_majors);
			stringstream sstr(line_of_majors);
			string my_major;
			set<string> all_my_majors;
			while(sstr >> my_major)
			{	
				for(unsigned int i = 0; i < my_major.length(); i++)
				{
					my_major[i] = tolower(my_major[i]);
				}

				set<string>::iterator it = all_my_majors.find(my_major);

				if(it == all_my_majors.end())
				{
					all_my_majors.insert(my_major);
				}
			}

			map< string, set<string> >::iterator im = 
			all_student_names_and_majors.find(my_name);

			if(im == all_student_names_and_majors.end())
			{
				all_student_names_and_majors.insert(make_pair(
					my_name, all_my_majors));
			}
			else
			{
				set<string> new_set;
				new_set = im->second | all_my_majors;
				im->second = new_set;
			}
		}
	}

	while(getline(mfile, line))
	{
		if(line.length() != 0)
		{
			ofile << line << endl;
			stringstream ss(line);
			string major;
			set<string> target_majors;
			while(ss >> major)
			{
				for(unsigned int i = 0; i < major.length(); i++)
				{
					major[i] = tolower(major[i]);
				}
				set<string>::iterator it = target_majors.find(major);
				if(it == target_majors.end())
				{
					target_majors.insert(major);
				}
			}

			set<string>::iterator ih;

			map< string, set<string> >::iterator im;

			for(im = all_student_names_and_majors.begin(); 
				im != all_student_names_and_majors.end(); 
				++im)
			{
				set<string> temp_str;
				temp_str = target_majors & im->second;
				set<string> temp_cmp;
				temp_cmp = target_majors - temp_str;
				if(temp_cmp.empty())
				{
					ofile << im->first << endl;
				}
			}

			ofile << endl;
		}
	}

	ifile.close();
	mfile.close();
	ofile.close();
	return 0;
}