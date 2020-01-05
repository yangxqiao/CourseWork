#include "SrcMain.h"
#include "FileReader.h"
#include "DNATranslator.h"
#include "NWPairwise.h"
#include <iostream>

using std::string;

void ProcessCommandArgs(int argc, const char* argv[])
{
	if(argc == 2)
    {
        string filename = argv[1];
        FileReader myfile(filename);
        std::string dna = myfile.getContent();
        std::string header = myfile.getHeader();
        DNATranslator myDNA(dna);
        myDNA.getCodonsNum();
        myDNA.outputFile(header);
    }
    if(argc == 3)
    {
        string file1 = argv[1];
        string file2 = argv[2];
        NWPairwise myPairwise(file1, file2);
        myPairwise.populateScore();
        myPairwise.outputFile();
    }
}
