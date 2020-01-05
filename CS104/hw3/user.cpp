#include <string>
#include <set>
#include <list>
#include <vector>
#include <algorithm>
#include "tweet.h"
#include "user.h"

using namespace std;

User::User(string name)
{
	this->name_ = name;
}

/**
* Destructor
*/
User::~User()
{
	list<Tweet*>::iterator it;
	for(it = posted_tweets.begin(); it != posted_tweets.end(); ++it)
	{
		delete *it;
	}
}

/**
* Gets the name of the user 
* 
* @return name of the user 
*/
string User::name() const
{
	return this->name_;
}

/**
* Gets all the followers of this user  
* 
* @return Set of Users who follow this user
*/
set<User*> User::followers() const
{
	return this->followers_;
}

/**
* Gets all the users whom this user follows  
* 
* @return Set of Users whom this user follows
*/
set<User*> User::following() const
{
	return this->following_;
}

/**
* Gets all the tweets this user has posted
* 
* @return List of tweets this user has posted
*/
list<Tweet*> User::tweets() const
{
	return this->posted_tweets;
}

/**
* Adds a follower to this users set of followers
* 
* @param u User to add as a follower
*/
void User::addFollower(User* u)
{
	this->followers_.insert(u);
}

/**
* Adds another user to the set whom this User follows
* 
* @param u User that the user will now follow
*/
void User::addFollowing(User* u)
{
	this->following_.insert(u);
}

/**
* Adds the given tweet as a post from this user
* 
* @param t new Tweet posted by this user
*/
void User::addTweet(Tweet* t)
{
	this->posted_tweets.push_back(t);
}

/**
* Produces the list of Tweets that represent this users feed/timeline
*  It should contain in timestamp order all the tweets from
*  this user and all the tweets from all the users whom this user follows
*
* @return vector of pointers to all the tweets from this user
*         and those they follow in timestamp order
*/
vector<Tweet*> User::getFeed()
{
	vector<Tweet*> sorted_tweets;
	list<Tweet*>::iterator it;

	for(it = posted_tweets.begin(); it != posted_tweets.end(); ++it)
	{
		sorted_tweets.push_back(*it);
	}
	
	set<User*> following = this->following();
	set<User*>::iterator ib;
	for(ib = following.begin(); ib != following.end(); ++ib)
	{
		list<Tweet*> following_tweet = (*ib)->tweets();
		list<Tweet*>::iterator ia;
		for(ia = following_tweet.begin(); ia != following_tweet.end(); ++ia)
		{
			sorted_tweets.push_back(*ia);
		}
	}

	sort(sorted_tweets.begin(), sorted_tweets.end(), TweetComp());
	return sorted_tweets;
}