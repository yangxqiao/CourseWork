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
	if(!eng->get_current_login_status())
	{
		cout << "No user logged in." << endl;
		return HANDLER_ERROR;
	}
	string tweet_line;
	getline(instr, tweet_line, '\n');
	tweet_line = trim(tweet_line);
	
	if(tweet_line.size() != 0)
	{
		stringstream ss(tweet_line);
		// get the real text of the tweet
		string username = eng->get_current_user();
		string temp_text;
		getline(ss, temp_text, '\n');
		string text = "";
		text = trim(temp_text);

		DateTime time_of_this_tweet;

		eng->addTweet(username, time_of_this_tweet, text);
	}

	return HANDLER_OK;
}


FollowHandler::FollowHandler()
{

}

FollowHandler::FollowHandler(Handler* next)
  : Handler(next)
{

}

bool FollowHandler::canHandle(const std::string& cmd) const{
	return cmd == "FOLLOW";
}

Handler::HANDLER_STATUS_T FollowHandler::process(TwitEng* eng, std::istream& instr) const
{
	if(!eng->get_current_login_status())
	{
		cout << "No user logged in." << endl;
		return HANDLER_ERROR;
	}
	string names;
	getline(instr, names, '\n');
	names = trim(names);
	
	if(names.size() != 0)
	{
		string name_to_follow;
		stringstream ss(names);
		ss >> name_to_follow;

		eng->addFollower(name_to_follow);
	}
	return HANDLER_OK;
}



SaveHandler::SaveHandler()
{

}

SaveHandler::SaveHandler(Handler* next)
  : Handler(next)
{

}

bool SaveHandler::canHandle(const std::string& cmd) const{
	return cmd == "SAVE";
}

Handler::HANDLER_STATUS_T SaveHandler::process(TwitEng* eng, std::istream& instr) const
{
	string filename;
	getline(instr, filename, '\n');
	filename = trim(filename);

	if(filename.size() != 0)
	{
		eng->saveDatabase(filename);
	}
	
	return HANDLER_OK;
}


SCCHandler::SCCHandler()
{

}

SCCHandler::SCCHandler(Handler* next)
  : Handler(next)
{

}

bool SCCHandler::canHandle(const std::string& cmd) const{
	return cmd == "SCC";
}

Handler::HANDLER_STATUS_T SCCHandler::process(TwitEng* eng, std::istream& instr) const
{
	string filename;
	getline(instr, filename, '\n');
	filename = trim(filename);

	if(filename.size() != 0)
	{
		eng->getSCC(filename);
	}
	
	return HANDLER_OK;
}


TrendingHandler::TrendingHandler()
{

}

TrendingHandler::TrendingHandler(Handler* next)
  : Handler(next)
{

}

bool TrendingHandler::canHandle(const std::string& cmd) const{
	return cmd == "TRENDING";
}

Handler::HANDLER_STATUS_T TrendingHandler::process(TwitEng* eng, std::istream& instr) const
{
	int num_hashtags;
	string num;
	getline(instr, num, '\n');
	num = trim(num);
	if(num.size() != 0)
	{
		stringstream ss(num);
		ss >> num_hashtags;
		if(num_hashtags < 0)
		{
			return HANDLER_ERROR;
		}
		eng->getHashtags(num_hashtags);
	}

	return HANDLER_OK;
}


LoginHandler::LoginHandler()
{

}

LoginHandler::LoginHandler(Handler* next)
  : Handler(next)
{

}

bool LoginHandler::canHandle(const std::string& cmd) const{
	return cmd == "LOGIN";
}

Handler::HANDLER_STATUS_T LoginHandler::process(TwitEng* eng, std::istream& instr) const
{
	string line;
	getline(instr, line, '\n');
	line = trim(line);
	if(line.size() != 0)
	{
		stringstream ss(line);
		string username;
		string password;
		ss >> username >> password;
		bool result = eng->check_Login(username, password);
		if(!result)
		{
			cout << "Invalid username/password." << endl;
			return HANDLER_ERROR;
		}
	}
	cout << "Login successful." << endl;
	return HANDLER_OK;
}


LogoutHandler::LogoutHandler()
{

}

LogoutHandler::LogoutHandler(Handler* next)
  : Handler(next)
{

}

bool LogoutHandler::canHandle(const std::string& cmd) const{
	return cmd == "LOGOUT";
}

Handler::HANDLER_STATUS_T LogoutHandler::process(TwitEng* eng, std::istream& instr) const
{
	eng->logout();
	return HANDLER_OK;
}
