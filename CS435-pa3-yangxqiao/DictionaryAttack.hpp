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
#include <string>

void InitializeHashTable(){
    std::string newline;
    while(static_cast<bool>(std::getline(dfile, newline, '\n')))
    {
        if(!newline.empty())
        {
            unsigned char hash[20];
            sha1::Calc(newline.c_str(), newline.length(), hash);
            
            std::string hexStr;
            hexStr.resize(40);
            sha1::ToHexString(hash, &hexStr[0]);
            table->Insert(hexStr, newline);
        }
    }
}

#endif /* DictionaryAttack_h */
