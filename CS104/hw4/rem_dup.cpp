#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "rem_dup_lib.h"

using namespace std;

int main(int argc, char* argv[])
{
	ifstream ifile(argv[1]);

	if(ifile.fail())
	{
		cout << "Cannot open the input file." << endl;
		return 0;
	}

	string line;
	getline(ifile, line, '\n');
	stringstream ss(line);

	Item* head1 = NULL;
	
	int num;
	while(ss >> num)
	{
		if(head1 == NULL)
		{
			head1 = new Item(num, NULL);
		}
		else
		{
			Item* temp = head1;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}

			Item* newItem = new Item(num, NULL);
			temp->next = newItem;
		}
	}

	getline(ifile, line, '\n');
	stringstream sa(line);

	Item* head2 = NULL;
	while(sa >> num)
	{
		if(head2 == NULL)
		{
			head2 = new Item(num, NULL);
		}
		else
		{
			Item* temp = head2;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			Item* newItem = new Item(num, NULL);
			temp->next = newItem;
		}
	}

	removeConsecutive(head1);
	Item* head3 = concatenate(head1, head2);

	ofstream ofile(argv[2]);

	if(ofile.fail())
	{
		cout << "Cannot open the output file." << endl;
		return 0;
	}

	Item* temp = head3;
	while(temp != NULL)
	{
		ofile << temp->val << " ";
		temp = temp->next;
	}

	while(head3 != NULL)
	{
		Item* temp = head3;
		head3 = head3->next;
		delete temp;
	}

	return 0;
}
