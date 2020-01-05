//
//  FileReader.cpp
//  pa3
//
//  Created by Chelseaqiao on 10/20/19.
//

#include "FileReader.h"
#include <string>
#include <fstream>
#include <iostream>

FileReader::FileReader(std::string source){
    std::ifstream::pos_type size;
    // Open the file for input, in binary mode, and start ATE (at the end)
    std::ifstream tempfile(source, std::ios::in|std::ios::binary|std::ios::ate);
    if (tempfile.is_open())
    {
        size = tempfile.tellg(); // Save the size of the file
        mcontent.reserve(static_cast<unsigned int>(size));
        tempfile.close();
    }
 
    std::ifstream file(source);
    if(file.is_open())
    {
        std::string newline;
        std::getline(file, newline, '>');
        std::getline(file, mheader, '\n');
        char c;
        while(static_cast<bool>(file.get(c)))
        {
            if(c != '\n' && c != '\r' && c != '\xff')
            {
                mcontent += c;
            }
        }
    }
    else{
        std::cout << "Cannot open the file!" << std::endl;
    }
    file.close();
}

std::string FileReader::getHeader()
{
    return mheader;
}


std::string FileReader::getContent()
{
    return mcontent;
}
