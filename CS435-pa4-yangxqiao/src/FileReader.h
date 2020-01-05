//
//  FileReader.hpp
//  pa3
//
//  Created by Chelseaqiao on 10/20/19.
//

#ifndef FileReader_hpp
#define FileReader_hpp

#include <cstdio>
#include <string>

class FileReader{
    
public:
    FileReader(std::string source);
    std::string getHeader();
    std::string getContent();
    
private:
    std::string mheader;
    std::string mcontent;
    
};

#endif /* FileReader_hpp */
