//
//  DictionaryAttack.h
//  pa4
//
//  Created by Chelseaqiao on 10/8/19.
//

#ifndef PassphraseBruteForce_h
#define PassphraseBruteForce_h


#include <fstream>
#include "HashTable.hpp"
#include <tbb/parallel_for_each.h>
#include <tbb/parallel_for.h>
#include "sha1.h"
#include <string>
#include <vector>

using std::endl;

class PassphraseBruteForce
{

public:
    PassphraseBruteForce(int tableCap)
    :table(tableCap) {

    }
    
    void InitiateHashTable(std::ifstream& pfile){
        std::string password;
        while(static_cast<bool>(std::getline(pfile, password, '\n')))
        {
            encryptedPassword.emplace_back(password);
            table.Insert(password, "");
        }
    }

    void ReadAllWords(std::ifstream& wpfile)
    {
        std::string newline;
        while(static_cast<bool>(std::getline(wpfile, newline, '\n')))
        {
            allWords.emplace_back(newline);
        }
    }
    
    void UpdateHashTableWithPermutation(std::ifstream& wpfile)
    {
        ReadAllWords(wpfile);
        tbb::parallel_for(tbb::blocked_range<size_t>(0, allWords.size()),
                          [this](const tbb::blocked_range<size_t> &range)
                          {
            std::string hexStr;
            hexStr.resize(40);
            std::string word1;
            std::string word2;
            std::string word3;
            std::string word4;
            unsigned char hash[20];
            for (size_t i = range.begin(); i < range.end(); ++i) {
                word1 = allWords[i];
                
                for(size_t j = 0; j < allWords.size(); ++j){
                    word2 = word1;
                    word2 += allWords[j];

                    for(size_t k = 0; k < allWords.size(); ++k){
                        word3 = word2;
                        word3 += allWords[k];

                        for(size_t r = 0; r < allWords.size(); ++r){
                            word4 = word3;
                            word4 += allWords[r];
                            sha1::Calc(word4.c_str(), word4.length(), hash);
                            sha1::ToHexString(hash, &hexStr[0]);
                            std::string* newPtr = table.Find(hexStr);
                            if(newPtr != nullptr)
                            {
                                *newPtr = word4;
                            }
                        }
                    }
                }
            }
        });
    }

    void PrintHashTable(std::ofstream& ofile)
    {
        for(unsigned int i = 0; i < encryptedPassword.size(); ++i)
        {
            ofile << encryptedPassword[i] << "," << *table.Find(encryptedPassword[i]) << endl;
        }
    }

private:
    HashTable<std::string> table;
    std::vector<std::string> allWords;
    std::vector<std::string> encryptedPassword;
};
    
#endif /* PassphraseBruteForce_h */
