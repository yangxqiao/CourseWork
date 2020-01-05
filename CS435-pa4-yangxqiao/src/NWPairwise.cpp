//
//  NWPairwise.cpp
//  main
//
//  Created by Chelseaqiao on 10/20/19.
//

#include "NWPairwise.h"
#include "FileReader.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

NWPairwise::NWPairwise(std::string filename1, std::string filename2)
{
    FileReader fileA(filename1);
    FileReader fileB(filename2);
    dnaA = fileA.getContent();
    dnaB = fileB.getContent();
    headerA = fileA.getHeader();
    headerB = fileB.getHeader();
    resultA = "";
    resultB = "";
    finalR = 0;
}

void NWPairwise::populateScore(){
    enum myEnum : char{
        AboveLeft,
        Left,
        Above
    };

    auto row = dnaA.size() + 1; // dnaA is vertical
    auto col = dnaB.size() + 1; // dnaB is horizontal

    std::vector<std::vector<short>> gridScore(row);
    std::vector<std::vector<char>> gridDir(row);

    for(auto i = 0; i < row; i++)
    {
        gridScore[i].resize(col);
        gridDir[i].resize(col);
    }

    gridScore[0][0] = 0;
    for(auto i = 1; i < col; i++)
    {
        gridScore[0][i] = -1 * i;
        gridDir[0][i] = Left;
    }

    for(auto i = 1; i < row; i++)
    {
        gridScore[i][0] = -1 * i;
        gridDir[i][0] = Above;
    }

    int val1; // Score of neighbor cell to the above left + (match or mismatch score)
    int val2; // Score of neighbor cell to the left + gap score
    int val3; // Score of neighbor cell above + gap score
    for(auto i = 1; i < row; i++)
    {
        for(auto j = 1; j < col; j++)
        {
            if(dnaA[i-1] == dnaB[j-1])
            {
                val1 = gridScore[i-1][j-1] + 1;
            }
            else{
                val1 = gridScore[i-1][j-1] - 1;
            }
            val2 = gridScore[i][j-1] - 1;
            val3 = gridScore[i-1][j] - 1;

            int temp;
            temp = std::max(val1, val2);
            gridScore[i][j] = std::max(temp, val3);
            if(gridScore[i][j] == val1)
            {
                gridDir[i][j] = AboveLeft;
            }
            else if(gridScore[i][j] == val3)
            {
                gridDir[i][j] = Above;
            }
            else{
                gridDir[i][j] = Left;
            }
        }
    }
    
    auto currRow = row - 1;
    auto currCol = col - 1;
    while(currRow != 0 || currCol != 0)
    {
        char dir = gridDir[currRow][currCol];
        if(dir == AboveLeft) {
            resultA += dnaA[currRow-1];
            resultB += dnaB[currCol-1];
            currRow--;
            currCol--;
        }
        else if(dir == Left)
        {
            resultB += dnaB[currCol-1];
            resultA += '_';
            currCol--;
        }
        else if(dir == Above)
        {
            resultA += dnaA[currRow-1];
            resultB += '_';
            currRow--;
        }
        else{
            std::cout << "Wrong direction assigned." << std::endl;
        }
    }

    std::reverse(resultA.begin(), resultA.end());
    std::reverse(resultB.begin(), resultB.end());

    finalR = gridScore[row-1][col-1];
}

void NWPairwise::outputFile(){
    std::ofstream ofile("match.result");
    ofile << "A: " << headerA << std::endl;
    ofile << "B: " << headerB << std::endl;
    ofile << "Score: " << finalR << std::endl;
    ofile << std::endl;
    
    std::string temp;
    for(auto i = 0; i < resultA.size(); i++)
    {
        if(resultA[i] == resultB[i])
        {
            temp += '|';
        }
        else{
            temp += ' ';
        }
    }
    
    int lineSize = 70;
    for(auto i = 0; i < resultA.size(); i+=lineSize)
    {
        ofile << resultA.substr(i, lineSize) << std::endl;
        ofile << temp.substr(i, lineSize) << std::endl;
        ofile << resultB.substr(i, lineSize) << std::endl;
        ofile << std::endl;
    }
    ofile << std::endl;
    ofile.close();
}

