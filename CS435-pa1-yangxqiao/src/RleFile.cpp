#include "RleFile.h"
#include "RleData.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

void RleFile::CreateArchive(const std::string& source)
{
    // Requires <fstream>
    std::ifstream::pos_type size;
    char* memblock;
    // Open the file for input, in binary mode, and start ATE (at the end)
    std::ifstream file (source, std::ios::in|std::ios::binary|std::ios::ate);
    if (file.is_open())
    {
        size = file.tellg(); // Save the size of the file
        memblock = new char[static_cast<unsigned int>(size)];
        file.seekg(0, std::ios::beg); // Seek back to start of file
        file.read(memblock, size);
        file.close();
        // File data is now in memblock array
        mRleData.Compress(memblock, static_cast<unsigned int>(size));
        
        mHeader.mFileName = source;
        mHeader.mFileNameLength = source.length();
        mHeader.mFileSize = static_cast<unsigned int>(size);


        // Open the file for output, in binary mode, and overwrite an existing file
        std::string filename = source + ".rl1";
        std::ofstream arc(filename, std::ios::out|std::ios::binary|std::ios::trunc);
        if (arc.is_open())
        {
            // Use arc.write function to write data here
            arc.write(mHeader.mSig, 4);
            arc.write(reinterpret_cast<char*>(&(mHeader.mFileSize)), 4);
            arc.write(reinterpret_cast<char*>(&(mHeader.mFileNameLength)), 1);
            arc.write(mHeader.mFileName.c_str(), source.size());
            arc.write(mRleData.mData, mRleData.mSize);
            arc.close();
        }
        // Make sure to clean up!
        delete[] memblock;
    }
}

void RleFile::ExtractArchive(const std::string& source)
{
    // Requires <fstream>
    std::ifstream::pos_type size;
    char* memblock;
    // Open the file for input, in binary mode, and start ATE (at the end)
    std::ifstream file (source, std::ios::in|std::ios::binary|std::ios::ate);
    if (file.is_open())
    {
        size = file.tellg(); // Save the size of the file
        memblock = new char[static_cast<unsigned int>(size)];
        file.seekg(0, std::ios::beg); // Seek back to start of file
        file.read(memblock, size);
        file.close();

        mHeader.mFileSize = *(reinterpret_cast<int*>(&memblock[4]));
        mHeader.mFileNameLength = memblock[8];

        mHeader.mFileName = "";
        for(unsigned char i = 0; i < mHeader.mFileNameLength; i++)
        {
            mHeader.mFileName = mHeader.mFileName + memblock[9+i];
        }

        size_t inSize = static_cast<unsigned int>(size) - 9 - mHeader.mFileName.length();
        mRleData.Decompress(&(memblock[9+mHeader.mFileName.length()]), inSize, mHeader.mFileSize);


        // Open the file for output, in binary mode, and overwrite an existing file
        std::ofstream arc(mHeader.mFileName, std::ios::out|std::ios::binary|std::ios::trunc);
        if (arc.is_open())
        {
            arc.write(mRleData.mData, mRleData.mSize);
            arc.close();
        }

        // Make sure to clean up!
        delete[] memblock;
    }
}
