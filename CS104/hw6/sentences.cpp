#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void readWords(char* filename, vector<vector<string> >& words);

// client interface
void generateSentences(vector<vector<string> >& words, ofstream& ofile);

// recursive helper function
void genHelper(vector<vector<string> >& words,
	       ofstream& ofile,
	       int currentOption,
	       string sentence,
	       int& numSentences);

void readWords(char* filename,vector<vector<string> >& words)
{
  ifstream ifile(filename);

  string line;
  while(getline(ifile, line, '\n'))
  {
    stringstream ss(line);
    vector<string> temp;
    string word;
    while(ss >> word)
    {
      temp.push_back(word);
    }

    words.push_back(temp);
  }
}

void generateSentences(vector<vector<string> >& words, ofstream& ofile)
{
  int numSentences = 0;

  string sentence = "The";

  genHelper(words, ofile, 0, sentence, numSentences);

  ofile << numSentences << " sentences.";
}

void genHelper(vector<vector<string> >& words,
	       ofstream& ofile,
	       int currentOption,
	       string sentence,
	       int& numSentences)
{
    if(currentOption == 4)
    {
      ofile << sentence << "." << endl;
      numSentences++;
    }
    else if(currentOption == 0 || currentOption == 3)
    {
      genHelper(words, ofile, currentOption+1, sentence, numSentences);
      for(unsigned int i = 0; i < words[currentOption].size(); ++i)
      {
        genHelper(words, ofile, currentOption+1, sentence + " " + words[currentOption][i], numSentences);
      }
    }
    else if(currentOption == 1 || currentOption == 2)
    {
      for(unsigned int i = 0; i < words[currentOption].size(); ++i)
      {
        genHelper(words, ofile, currentOption+1, sentence + " " + words[currentOption][i], numSentences);
      }
    }
    
}

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Usage ./sentences input_file output_file" << endl;
  }
  vector<vector<string> > words;

  // Parse the file
  readWords(argv[1], words);

  // Check the status of parsing
  if(words.size() < 4){
    cerr << "Input file requires 4 lines of words" << endl;
    return 1;
  }

  // Open the output file
  ofstream ofile(argv[2]);
 
  // generate all the sentence options writing them to ofile
  generateSentences(words, ofile);

  ofile.close();

  return 0;
}
