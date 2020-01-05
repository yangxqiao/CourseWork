#include "SrcMain.h"
#include "HashTable.hpp"
#include "DictionaryAttack.hpp"
#include "PassphraseBruteForce.hpp"
#include "sha1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
//#include <algorithm>

using std::cout;
using std::endl;


void ProcessCommandArgs(int argc, const char* argv[])
{
    std::ofstream ofile("solved.txt");
    
    if(std::strcmp(argv[1], "dictionary") == 0)
    {
        std::ifstream dfile(argv[3]);
        std::ifstream pfile(argv[4]);
        DictionaryAttack dA = DictionaryAttack(std::stoi(argv[2]));
        dA.InitializeHashTable(dfile);
        dA.PrintPassword(ofile, pfile);
    }
    
    else if(std::strcmp(argv[1], "phrases") == 0)
    {
        std::ifstream wpfile(argv[3]);
        std::ifstream pfile(argv[4]);
        PassphraseBruteForce pBF = PassphraseBruteForce(std::stoi(argv[2]));

        pBF.InitiateHashTable(pfile);
        pBF.UpdateHashTableWithPermutation(wpfile);
        pBF.PrintHashTable(ofile);

    }
}
