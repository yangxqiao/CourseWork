//
//  DictionaryAttack.h
//  pa4
//
//  Created by Chelseaqiao on 10/8/19.
//


#ifndef DictionaryAttack_h
#define DictionaryAttack_h


#include <fstream>
#include "HashTable.hpp"
#include "sha1.h"
#include <string>

using std::endl;

class DictionaryAttack
{

public:
    DictionaryAttack(int dictionaryCap)
    :table(dictionaryCap)
    {

    }
    
    void HashStringInsertTable(std::string newline)
    {
        unsigned char hash[20];
        sha1::Calc(newline.c_str(), newline.length(), hash);
        
        std::string hexStr;
        hexStr.resize(40);
        sha1::ToHexString(hash, &hexStr[0]);
        table.Insert(hexStr, newline);
    }

    void InitializeHashTable(std::ifstream& dfile){
        std::string newline;
        while(static_cast<bool>(std::getline(dfile, newline, '\n')))
        {
            if(!newline.empty())
            {
                HashStringInsertTable(newline);
            }
        }
    }

    void PrintPassword(std::ofstream& ofile, std::ifstream& pfile)
    {
        std::string password;
        while(static_cast<bool>(std::getline(pfile, password, '\n')))
        {
            if(!password.empty())
            {
                ofile << password << "," << *table.Find(password) << endl;
            }
        }
    }
    

private:
    HashTable<std::string> table;
};
    

#endif /* DictionaryAttack_h */
