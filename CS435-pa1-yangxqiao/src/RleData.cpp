#include "RleData.h"
#include <queue>
#include <vector>
#include <iostream>

void RleData::Compress(const char* input, size_t inSize)
{
    int maxRunSize = 127;

    delete [] mData;
    mSize = 0;

    mData = new char[2*inSize];
    char* buffer = new char [2*inSize];

    // normal run
    int inputPos = 0;
    int bufferPos = 0;
    
    // identify equal char sequences
    while(inputPos < inSize)
    {
        int numEqualChar = 1;
        while((input[inputPos] == input[inputPos+1]) && (inputPos+1 < inSize))
        {
            inputPos++;
            numEqualChar++;
        }
        // check whether the sequence is longer than MaxRunSize
        while(numEqualChar > maxRunSize)
        {
            buffer[bufferPos] = maxRunSize;
            buffer[bufferPos+1] = input[inputPos];
            bufferPos += 2;
            numEqualChar -= maxRunSize;
        }
        if(numEqualChar != 0)
        {
            buffer[bufferPos] = numEqualChar;
            buffer[bufferPos+1] = input[inputPos];
            bufferPos+=2;
            inputPos++;
        }
    }

    int lengthBuffer = bufferPos;
    bufferPos = 0;

    while(bufferPos < lengthBuffer)
    {
        if(buffer[bufferPos] != 1)
        {
            mData[mSize] = buffer[bufferPos];
            bufferPos++;
            mSize++;
            mData[mSize] = buffer[bufferPos];
            bufferPos++;
            mSize ++;
        }
        else{
            int numDistinct = 0;
            std::vector<char> distinctChar;
            while((buffer[bufferPos] == 1) && (bufferPos < lengthBuffer))
            {
                distinctChar.emplace_back(buffer[bufferPos+1]);
                bufferPos += 2;
                numDistinct++;
            }

            if(numDistinct == 1)
            {
                mData[mSize] = numDistinct;
                mData[mSize+1] = buffer[bufferPos-1];
                mSize += 2;
            }
            else{
                // check whether the distinct char sequence is longer than MaxRunSize
                int divideMaxRunSize = numDistinct / maxRunSize;
                int remainder = numDistinct % maxRunSize;
                int vectorIndex = 0;
                for(int i = 0; i < divideMaxRunSize; i++)
                {
                    mData[mSize] = -1 * maxRunSize;
                    mSize++;
                    for(int j = 0; j < maxRunSize; j++)
                    {
                        mData[mSize] = distinctChar[vectorIndex];
                        vectorIndex++;
                        mSize++;
                    }
                }
                if(remainder == 1)
                {
                    mData[mSize] = remainder;
                    mSize++;
                    mData[mSize] = distinctChar[vectorIndex];
                    mSize++;
                }
                else if(remainder > 1)
                {
                    mData[mSize] = -1 * remainder;
                    mSize++;
                    for(int i = 0; i < remainder; i++)
                    {
                        mData[mSize] = distinctChar[vectorIndex];
                        vectorIndex++;
                        mSize++;
                    }
                }
            }
        }
    }

    delete [] buffer;
}

void RleData::Decompress(const char* input, size_t inSize, size_t outSize)
{
    if(mSize != 0)
    {
        delete [] mData;
    }
    mSize = outSize;
    mData = new char[outSize];
    
    int index = 0;
    int i = 0;
    while(i < inSize)
    {
        if(input[i] > 0)
        {
            for(int j = 0; j < input[i]; j++)
            {
                mData[index] = input[i+1];
                index++;
            }
            i += 2;
        }
        else
        {
            int totalDistinctChar = input[i] * -1;
            for(int k = 0; k < totalDistinctChar; k++)
            {
                mData[index] = input[i+1+k];
                index++;
            }
            i = i+totalDistinctChar+1;
        }
    }
}

std::ostream& operator<< (std::ostream& stream, const RleData& rhs)
{
	for (int i = 0; i < rhs.mSize; i++)
	{
		stream << rhs.mData[i];
	}
	return stream;
}
