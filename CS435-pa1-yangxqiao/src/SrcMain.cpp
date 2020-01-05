#include "SrcMain.h"
#include <string>
#include "RleFile.h"

void ProcessCommandArgs(int argc, const char* argv[])
{
	// TODO: Process argc and argv, and use to compress/decompress files
    if(argc == 2)
    {
        std::string filename = argv[1];
        int filenameLength = filename.size();
        RleFile r;
        if(filename.substr(filenameLength-4, 4) == ".rl1")
        {
            r.ExtractArchive(filename);
        }
        else{
            r.CreateArchive(filename);
        }
    }
}
