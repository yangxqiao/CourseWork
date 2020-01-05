//
//  DNATranslator.cpp
//  main
//
//  Created by Chelseaqiao on 10/20/19.
//

#include "DNATranslator.h"
#include <fstream>
#include <iostream>

static char mtable[24][4] = {
        {0, 0, 1, 0},
        {2, 0, 1, 0},
        {0, 0, 1, 'M'},
        {4, 9, 14, 19},
        {5, 6, 7, 8},
        {'F', 'F', 'L', 'L'},
        {'S', 'S', 'S', 'S'},
        {'Y', 'Y', 0, 0},
        {'C', 'C', 0, 'W'},
        {10, 11, 12, 13},
        {'L', 'L', 'L', 'L'},
        {'P', 'P', 'P', 'P'},
        {'H', 'H', 'Q', 'Q'},
        {'R', 'R', 'R', 'R'},
        {15, 16, 17, 18},
        {'I', 'I', 'I', 'M'},
        {'T', 'T', 'T', 'T'},
        {'N', 'N', 'K', 'K'},
        {'S', 'S', 'R', 'R'},
        {20, 21, 22, 23},
        {'V', 'V', 'V', 'V'},
        {'A', 'A', 'A', 'A'},
        {'D', 'D', 'E', 'E'},
        {'G', 'G', 'G', 'G'}
};


static std::vector<std::string> mName = {
    "Alanine",
    "Cysteine",
    "Aspartic acid",
    "Glutamic acid",
    "Phenylalanine",
    "Glycine",
    "Histidine",
    "Isoleucine",
    "Lysine",
    "Leucine",
    "Methionine",
    "Asparagine",
    "Proline",
    "Glutamine",
    "Arginine",
    "Serine",
    "Threonine",
    "Valine",
    "Tryptophan",
    "Tyrosine"
};


DNATranslator::DNATranslator(std::string DNA)
    : msize(DNA.size())
    , total(0)
    , mDNA(DNA)
{
    mCodonsNum.reserve(20);
    mCodonsNum.insert(std::make_pair('Y', 0));
    mCodonsNum.insert(std::make_pair('W', 0));
    mCodonsNum.insert(std::make_pair('V', 0));
    mCodonsNum.insert(std::make_pair('T', 0));
    mCodonsNum.insert(std::make_pair('S', 0));
    mCodonsNum.insert(std::make_pair('R', 0));
    mCodonsNum.insert(std::make_pair('Q', 0));
    mCodonsNum.insert(std::make_pair('P', 0));
    mCodonsNum.insert(std::make_pair('N', 0));
    mCodonsNum.insert(std::make_pair('M', 0));
    mCodonsNum.insert(std::make_pair('L', 0));
    mCodonsNum.insert(std::make_pair('K', 0));
    mCodonsNum.insert(std::make_pair('I', 0));
    mCodonsNum.insert(std::make_pair('H', 0));
    mCodonsNum.insert(std::make_pair('G', 0));
    mCodonsNum.insert(std::make_pair('F', 0));
    mCodonsNum.insert(std::make_pair('E', 0));
    mCodonsNum.insert(std::make_pair('D', 0));
    mCodonsNum.insert(std::make_pair('C', 0));
    mCodonsNum.insert(std::make_pair('A', 0));
}

void DNATranslator::DNATranslator::getCodonsNum(){
    int index = 0;
    int state = 0;
    char c;
    int col;
    char result;
    do{
        c = mDNA[index];
        if(c == 'T'){
            col = 0;
        }
        else if(c == 'C')
        {
            col = 1;
        }
        else if(c == 'A')
        {
            col = 2;
        }
        else{
            col = 3;
        }
        result = mtable[state][col];
        if(result < 24){
            state = result;
        }
        else
        {
            state = 3;
            mCodonsNum[result]++;
            total++;
        }
        index++;
    }while(index < msize);
}

void DNATranslator::outputFile(std::string header){
    std::ofstream ofile("amino.txt");
    ofile << header << '\n';
    ofile << "Total amino acids produced: " << total << '\n';
    int index = 0;
    for(auto i = mCodonsNum.begin(); i != mCodonsNum.end(); ++i)
    {
        ofile << '(' << i->first << ')' << ' ' << mName[index] << ": " << i->second;
        if(index != 19)
        {
            ofile << std::endl;
        }
        index++;
    }
}
