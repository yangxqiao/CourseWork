//
//  NWPairwise.hpp
//  main
//
//  Created by Chelseaqiao on 10/20/19.
//

#ifndef NWPairwise_hpp
#define NWPairwise_hpp

#include <cstdio>
#include <string>

class NWPairwise{
public:
    NWPairwise(std::string filename1, std::string filename2);
    void populateScore();
    void outputFile();
    
private:
    std::string dnaA;
    std::string dnaB;
    std::string resultA;
    std::string resultB;
    std::string headerA;
    std::string headerB;
    int finalR;
};

#endif /* NWPairwise_hpp */
