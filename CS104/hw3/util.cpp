#include <string>
#include <cctype>
#include <set>
#include "util.h"
#include "tweet.h"

using namespace std;

void convLower(string& s)
{
  for(unsigned int i=0; i < s.size(); i++){
    s[i] = tolower(s[i]);
  }
}

void convUpper(string& s)
{
  for(unsigned int i=0; i < s.size(); i++){
    s[i] = toupper(s[i]);
  }
}

void displayHits(vector<Tweet*>& hits)
{
  if(hits.size() > 0){
    sort(hits.begin(), hits.end(), TweetComp());
    cout << hits.size() << " matches:" << endl;
    for(vector<Tweet*>::iterator it = hits.begin(); it != hits.end(); ++it){
      cout << (**it) << endl;
    }
  }
  else {
    cout << "No matches." << endl;
  }
}

set<Tweet*> operator&(const set<Tweet*>& t1, const set<Tweet*>& t2)
{
    set<Tweet*> final_t;
    set<Tweet*>::iterator it;
    for(it = t1.begin(); it != t1.end(); ++it)
    {
        set<Tweet*>::iterator im = t2.find(*it);
        if(im != t2.end())
        {
            final_t.insert(*it);
        }        
    }
    return final_t;
}

set<Tweet*> operator|(const set<Tweet*>& t1, const set<Tweet*>& t2)
{
    set<Tweet*> final_t;
    set<Tweet*>::iterator it;
    set<Tweet*>::iterator im;
    
    for(it = t1.begin(); it != t1.end(); ++it)
    {
        final_t.insert(*it);
    }

    for(im = t2.begin(); im != t2.end(); ++im)
    {
        final_t.insert(*im);
    }

    return final_t;
}
