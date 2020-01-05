#include "cmdhandler.h"
#include "util.h"
#include "tweet.h"
#include "datetime.h"
#include <sstream>
#include <string>
#include <vector>
using namespace std;

QuitHandler::QuitHandler()
{

}

QuitHandler::QuitHandler(Handler* next)
  : Handler(next)
{

}

bool QuitHandler::canHandle(const std::string& cmd) const
{
	return cmd == "QUIT";

}

Handler::HANDLER_STATUS_T QuitHandler::process(TwitEng* eng, std::istream& instr) const
{
	eng->dumpFeeds();
	return HANDLER_QUIT;
}

AndHandler::AndHandler()
{

}

AndHandler::AndHandler(Handler* next)
  : Handler(next)
{

}

bool AndHandler::canHandle(const std::string& cmd) const
{
	return cmd == "AND";

}

Handler::HANDLER_STATUS_T AndHandler::process(TwitEng* eng, std::istream& instr) const
{
	int strategy = 0;
	vector<string> hashtags;
	string single_hashtag;
	while(instr >> single_hashtag)
	{
		hashtags.push_back(single_hashtag);
	}
	vector<Tweet*> all_related_tweets;
    all_related_tweets = eng->search(hashtags, strategy);
    displayHits(all_related_tweets);

    return HANDLER_OK;
}

OrHandler::OrHandler()
{

}

OrHandler::OrHandler(Handler* next)
  : Handler(next)
{

}

bool OrHandler::canHandle(const std::string& cmd) const
{
	return cmd == "OR";

}

Handler::HANDLER_STATUS_T OrHandler::process(TwitEng* eng, std::istream& instr) const
{
	int strategy = 1;
	vector<string> hashtags;
	string single_hashtag;
	while(instr >> single_hashtag)
	{
		hashtags.push_back(single_hashtag);
	}
	vector<Tweet*> all_related_tweets;
    all_related_tweets = eng->search(hashtags, strategy);
    displayHits(all_related_tweets);

    return HANDLER_OK;
}

TweetHandler::TweetHandler()
{

}

TweetHandler::TweetHandler(Handler* next)
  : Handler(next)
{

}

bool TweetHandler::canHandle(const std::string& cmd) const
{
	return cmd == "TWEET";

}

Handler::HANDLER_STATUS_T TweetHandler::process(TwitEng* eng, std::istream& instr) const
{
	// get the name of poster of this tweet
	string tweet_line;
	getline(instr, tweet_line, '\n');
	tweet_line = trim(tweet_line);
	
	if(tweet_line.size() != 0)
	{
		stringstream ss(tweet_line);
		string temp_name;
		ss >> temp_name;
		stringstream sname(temp_name);
		string name;
		sname >> name;

		// get the real text of the tweet
		string temp_text;
		getline(ss, temp_text, '\n');
		string text = "";
		text = trim(temp_text);

		DateTime time_of_this_tweet;

		eng->addTweet(name, time_of_this_tweet, text);
	}

	return HANDLER_OK;
}

