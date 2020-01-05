//
//  DNATranslator.hpp
//  main
//
//  Created by Chelseaqiao on 10/20/19.
//

#ifndef DNATranslator_hpp
#define DNATranslator_hpp

#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>

class DNATranslator{
public:
    DNATranslator(std::string DNA);
    void getCodonsNum();
    void outputFile(std::string header);
    
private:
    int msize;
    int total;
    std::string mDNA;
    std::unordered_map<char, int> mCodonsNum;
};

#endif /* DNATranslator_hpp */
