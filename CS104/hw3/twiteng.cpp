#include <map>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "user.h"
#include "datetime.h"
#include "tweet.h"
#include "twiteng.h"
#include "util.h"

using namespace std;

TwitEng::TwitEng()
{

}

TwitEng::~TwitEng()
{
	map<string, User*>::iterator it;
	for(it = all_users.begin(); it != all_users.end(); ++it)
	{
		delete it->second;
	}
}
/**
* Parses the Twitter database and populates internal structures
* @param filename of the database file
* @return true if there is an error, false if successful
*/
bool TwitEng::parse(char* filename)
{
	ifstream ifile(filename);

	if(ifile.fail())
	{
		return true;
	}
	// get the first line that has the number or users
	
	int num_user = 0;
	ifile >> num_user;
	if(ifile.fail() || num_user == 0)
	{
		return true;
	}
	string line;
	getline(ifile, line, '\n');
	// use the for loop to get the names of all the users and their followers
	for(int i = 0; i < num_user; i++)
	{
		string name_line;
		getline(ifile, name_line, '\n');
		name_line = trim(name_line);
		if(name_line.size() == 0)
		{
			return true;
		}
		else
		{
			stringstream sname(name_line);
			string username;
			sname >> username;
			map<string, User*>::iterator it = all_users.find(username);
			if(it == all_users.end())
			{
				User *new_user = new User(username);
				all_users.insert(make_pair(username, new_user));
			}
			
			string follower_name;
			while(sname >> follower_name)
			{
				map<string, User*>::iterator ib = all_users.find(follower_name);
				
				if(ib == all_users.end())
				{
					User *new_follower = new User(follower_name);
					all_users.insert(make_pair(follower_name, new_follower));
				}
				
				map<string, User*>::iterator it = all_users.find(username);
				map<string, User*>::iterator ia = all_users.find(follower_name);
				it->second->addFollowing(ia->second);
				ia->second->addFollower(it->second);
			}
		}
	}

		// start to get the tweets
	string tweet_line;
	while(getline(ifile, tweet_line, '\n'))
	{
		tweet_line = trim(tweet_line);
		if(tweet_line != "")
		{
			// get the time of the tweet
			stringstream stweet(tweet_line);
			string year;
			stweet >> year;
			string time;
			stweet >> time;
			time = year + ' ' + time;
			stringstream stime(time);
			DateTime time_of_this_tweet;
			stime >> time_of_this_tweet;
			
			// get the name of whom post this tweet
			string temp_name;
			stweet >> temp_name;
			stringstream sname(temp_name);
			string name;
			sname >> name;

			// check if the name exist
			map<string, User*>::iterator it = all_users.find(name);
			if(it == all_users.end())
			{
				return true;
			}
			else
			{
				// get the real text
				string temp_text;
				getline(stweet, temp_text, '\n');
				string text = "";
				text = trim(temp_text);
				// add the tweet
				this->addTweet(name, time_of_this_tweet, text);				
			}
		}
	}
	return false;
}

/**
* Allocates a tweet from its parts and adds it to internal structures
* @param username of the user who made the tweet
* @param timestamp of the tweet
* @param text is the actual text of the tweet as a single string
*/
void TwitEng::addTweet(const string& username, const DateTime& time, const string& text)
{
	map<string, User*>::iterator it = all_users.find(username);
	if(it != all_users.end())
	{
		Tweet *new_tweet = new Tweet(it->second, time, text);
		it->second->addTweet(new_tweet);	

		// add hashtags and corresponding tweets
		set<string> hashtag_of_this_tweet = new_tweet->hashTags();
		set<string>::iterator ia;
		for(ia = hashtag_of_this_tweet.begin(); ia != hashtag_of_this_tweet.end(); ++ia)
		{
			map<string, set<Tweet*> >::iterator ib = all_hashtags.find(*ia);
			if(ib != all_hashtags.end())
			{
				ib->second.insert(new_tweet);
			}			
			else
			{
				set<Tweet*> new_set_tweets;
				new_set_tweets.insert(new_tweet);
				all_hashtags.insert(make_pair(*ia, new_set_tweets));
			}
		}
	}
}

/**s
* Searches for tweets with the given words and strategy
* @param words is the hashtag terms in any case without the '#'
* @param strategy 0=AND, 1=OR
* @return the tweets that match the search
*/
vector<Tweet*> TwitEng::search(vector<string>& terms, int strategy)
{
	set<Tweet*> found_hashtags;
	for(unsigned int i = 0; i < terms.size(); i++)
	{
		convLower(terms[i]);
		map<string, set<Tweet*> >::iterator it = all_hashtags.find(terms[i]);
		if(it != all_hashtags.end())
		{
			if(strategy == 0)
			{
				if(i == 0)
				{
					found_hashtags = it->second;
				}
				else
				{
					found_hashtags = found_hashtags & it->second;						
				}	
			}
			else
			{
				found_hashtags = found_hashtags | it->second;
			}

		}
	}

	vector<Tweet*> final_results;
	if(found_hashtags.size() != 0)
	{
		set<Tweet*>::iterator ia;
		for(ia = found_hashtags.begin(); ia != found_hashtags.end(); ++ia)
		{
			final_results.push_back(*ia);
		}
	}
	return final_results;
}


/**
* Dump feeds of each user to their own file
*/
void TwitEng::dumpFeeds()
{
	map<string, User*>::iterator it;
	for(it = all_users.begin(); it != all_users.end(); ++it)
	{
		// assign proper file name

		string temp = it->first + ".feed";
		const char* filename = temp.c_str();
		ofstream ofile(filename);
		
		vector<Tweet*> sorted_tweets;
		sorted_tweets = it->second->getFeed();

		ofile << it->first << endl;

		for(unsigned int i = 0; i < sorted_tweets.size(); i++)
		{
			ofile << *sorted_tweets[i] << endl;
		}

		ofile.close();
	}
}