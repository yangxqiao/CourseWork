#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "stack.h"

using namespace std;

int main(int argc, char* argv[])
{
	ifstream ifile(argv[1]);

	if(ifile.fail())
	{
		cout << "Cannot open the input file." << endl;
		return 0;
	}

	ofstream ofile(argv[2]);

	if(ofile.fail())
	{
		cout << "Cannot open the output file." << endl;
		return 0;
	}

	string line;
	getline(ifile, line);
	stringstream ss(line);

	Stack<int> my_laundry;
	int num;
	while(ss >> num)
	{
		if(num == 0 || num == -1)
		{
			my_laundry.push(num);
		}
		else if(num > 0)
		{
			int size = my_laundry.size();
			if(size >= num)
			{
				for(int i = 0; i < num; i++)
				{
					int towel = my_laundry.top();
					my_laundry.pop();
					if(towel == 0)
					{
						ofile << "black" << " ";
					}
					else if(towel == -1)
					{
						ofile << "white" << " ";
					}
				}
				ofile << endl;
			}
			else if(num > size)
			{
				for(int i = 0; i < size; i++)
				{
					int towel = my_laundry.top();
					my_laundry.pop();
					if(towel == 0)
					{
						ofile << "black" << " ";
					}
					else if(towel == -1)
					{
						ofile << "white" << " ";
					}					
				}
				ofile << endl;
			}
		}
	}

	ofile.close();
	return 0;
}