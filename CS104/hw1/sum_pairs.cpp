#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char * argv[])
{
	ifstream ifile(argv[1]);
	ofstream ofile(argv[2]);
	if(ifile.fail())
	{
		ofile << '0' << endl;
		return 0;
	}

	string line;
	int num_int;
	getline(ifile, line);
	if(ifile.fail())
	{
		ofile << '0' << endl;
		return 0;
	}

	stringstream ss(line);
	ss >> num_int;
	if(num_int == 0)
	{
		ofile << '0' << endl;
		return 0;
	}

	int* int_array = new int[num_int];
	int cnt = 0;
	for(int i = 0; i < num_int; i++)
	{
		getline(ifile, line);
		stringstream strstr(line);
		int temp;
		strstr >> temp;
		int_array[cnt] = temp;
		cnt++;
	}

	if(num_int%2 == 0)
	{
		for(int i = 0; i < num_int/2; i++)
		{
			int sum = int_array[i] + int_array[num_int-1-i];
			ofile << sum << endl;
		}
	}
	else{
		for(int i = 0; i <= num_int/2; i++)
		{
			int sum = int_array[i] + int_array[num_int-1-i];
			ofile << sum << endl;
		}
	}

	delete [] int_array;
	ifile.close();
	ofile.close();
}