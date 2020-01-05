#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char * argv[])
{
	ifstream ifile(argv[1]);
	if(ifile.fail())
	{
		cout << "Cannot open the file." << endl;
		return 0;
	}

	int num_tweet = 0;
	vector<string> users;
	vector<string> hashtags;

	string newline;
	while(getline(ifile, newline, '\n'))
	{
		if(newline != "")
		{
			num_tweet++;
			stringstream ss(newline);
			string word;
			while(ss >> word)
			{
				if(word[0] == '@')
				{
					string user = word.substr(1, word.size()-1);
					bool found = false;
					for(unsigned int i = 0; i < users.size(); i++)
					{
						if(users[i] == user)
						{
							found = true;
							break;
						}
					}
					if(!found)
					{
						users.push_back(user);
					}
				}
				if(word[0] == '#')
				{
					string hashtag = word.substr(1, word.size()-1);
					bool found = false;
					for(unsigned int i = 0; i < hashtags.size(); i++)
					{
						if(hashtags[i] == hashtag)
						{
							found = true;
							break;
						}
					}
					if(!found)
					{
						hashtags.push_back(hashtag);
					}
				}
			}
		}
	}

	cout << "1. Number of tweets=" << num_tweet << endl;
	cout << "2. Unique users" << endl;
	for(unsigned int i = 0; i < users.size(); i++)
	{
		cout << users[i] << endl;
	}
	cout << "3. Unique hashtags" << endl;
	for(unsigned int i = 0; i < hashtags.size(); i++)
	{
		cout << hashtags[i] << endl;
	}

	ifile.close();
	return 0;
}