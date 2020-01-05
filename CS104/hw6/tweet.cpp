#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include "datetime.h"
#include "user.h"
#include "tweet.h"
#include "util.h"

using namespace std;

Tweet::Tweet()
{

}

/**
* Constructor 
*/
Tweet::Tweet(User* user, const DateTime& time, const string& text)
	: time_(time), text_(text)
{
	this->user_ = user;
	stringstream ss(this->text_);
	string word;
	while(ss >> word)
	{
		if(word[0] == '#')
		{
			word = word.substr(1, word.size()-1);
			convLower(word);
			this->hashtags_.insert(word);
		}
	}
}

/**
* Gets the timestamp of this tweet
*
* @return timestamp of the tweet
*/
DateTime const & Tweet::time() const
{
	return this->time_;
}

/**
* Gets the actual text of this tweet
*
* @return text of the tweet
*/
string const & Tweet::text() const
{
	return this->text_;
}

/**
* Returns the hashtagged words without the '#' sign
*
*/
set<string> Tweet::hashTags() const
{
	return this->hashtags_;
}

/**
* Return true if this Tweet's timestamp is less-than other's
*
* @return result of less-than comparison of tweet's timestamp
*/
bool Tweet::operator<(const Tweet& other) const
{
	return this->time_ < other.time_;
}

/**
* Outputs the tweet to the given ostream in format:
*   YYYY-MM-DD HH::MM::SS username tweet_text
*
* @return the ostream passed in as an argument
*/
ostream& operator<<(ostream& os, const Tweet& t)
{
	os << t.time_ << " " << t.user_->name() << " " << t.text_;
	return os;
}

/* Create any other public or private helper functions you deem 
 necessary */

User* Tweet::user() const
{
	return this->user_;
}