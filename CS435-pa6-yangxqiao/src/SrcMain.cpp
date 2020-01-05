#include "SrcMain.h"
#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include "Node.h"
#include <fstream>
#include <cstring>
#include <cstdio>
#include <string>

extern int proccparse(); // NOLINT
struct yy_buffer_state; // NOLINT
extern void procc_flush_buffer(yy_buffer_state* b); // NOLINT
extern int procclex_destroy(); // NOLINT
extern FILE* proccin; // NOLINT

extern int gLineNumber;
extern NProgram* gProgram;
bool gSyntaxError = false;

// CHANGE ANYTHING ABOVE THIS LINE AT YOUR OWN RISK!!!!

int ProcessCommandArgs(int argc, const char* argv[])
{
	gLineNumber = 1;
	gSyntaxError = false;
	if (argc < 2)
	{
		std::cout << "You must pass the input file as a command line parameter." << std::endl;
		return 1;
	}

	// Read input from the first command line parameter
	proccin = fopen(argv[1], "r");
	if (proccin == nullptr)
	{
		std::cout << "File not found: " << argv[1] << std::endl;
		return 1;
	}
	procc_flush_buffer(nullptr);

	// Start the parse
	proccparse();

	if (gProgram != nullptr && argc == 3)
	{
		// TODO: Add any needed code for Parts 2, 3, and 4!!!
        std::ofstream ofile("ast.txt");
        gProgram->OutputAST(ofile, 0);
        ofile.close();
        
        if(strcmp(argv[2], "emit") == 0)
        {
            std::vector<std::string> ops;
            std::map<std::string, int> stack;
            int lastVirReg = 0;
            
            CodeContext context(ops, stack, lastVirReg);
            gProgram->CodeGen(context);
            
            std::ofstream efile("emit.txt");
            for(unsigned int i = 0; i < context.getOps().size(); i++)
            {
                efile << context.getOps()[i] << std::endl;
            }
            efile.close();
        }
        if(strcmp(argv[2], "reg") == 0)
        {
            std::vector<std::string> ops;
            std::map<std::string, int> stack;
            int lastVirReg = 0;
            
            CodeContext context(ops, stack, lastVirReg);
            gProgram->CodeGen(context);
            
            std::ofstream rfile("reg.txt");
            rfile << "INTERVALS:" << std::endl;
            std::map<int, std::vector<int> > intervals = context.getIntervals();
            for(auto it = intervals.begin(); it != intervals.end(); ++it)
            {
                rfile << "%" << it->first << ":" << it->second.front() << "," << it->second.back() << std::endl;
            }
            
            rfile << "ALLOCATION:" << std::endl;
            std::map<std::string, bool> realReg;
            realReg.insert(std::make_pair("r1", true));
            realReg.insert(std::make_pair("r2", true));
            realReg.insert(std::make_pair("r3", true));
            realReg.insert(std::make_pair("r4", true));
            realReg.insert(std::make_pair("r5", true));
            realReg.insert(std::make_pair("r6", true));
            realReg.insert(std::make_pair("r7", true));
           
            std::map<std::string, std::string> virRealReg;
            std::map<int, std::vector<int>> regEnd = context.opEnd();
            int lastCheck = 0;
            for(auto it = intervals.begin(); it != intervals.end(); ++it)
            {
                int start = it->second.front();
                for(int k = lastCheck+1; k <= start; k++)
                {
                    auto check = regEnd.find(k);
                    if(check != regEnd.end())
                    {
                        for(unsigned int i = 0; i < check->second.size(); i++)
                        {
                            std::string reg = "%" + std::to_string(check->second[i]);
                            auto temp = virRealReg.find(reg);
                            std::string realreg;
                            if(temp != virRealReg.end())
                            {
                                realreg = temp->second;
                            }
                            auto name = realReg.find(realreg);
                            if(name != realReg.end())
                            {
                                name->second = true;
                            }
                            
                        }
                    }
                }
                std::string real;
                for(auto ig = realReg.begin(); ig != realReg.end(); ++ig)
                {
                    if(ig->second)
                    {
                        real = ig->first;
                        ig->second = false;
                        break;
                    }
                }
                std::string vir = "%" + std::to_string(it->first);
                virRealReg.insert(std::make_pair(vir, real));
                rfile << vir << ":" << real << std::endl;
                
                lastCheck = start;
            }
            rfile.close();
            
            std::ofstream efile("emit.txt");
            std::vector<std::string> instructions = context.getOps();
            for(auto m = 0; m < instructions.size(); m++)
            {
                for(auto gt = virRealReg.begin(); gt != virRealReg.end(); ++gt)
                {
                    
                    int found = static_cast<int>(instructions[m].find(gt->first));
                    int end = found + gt->first.size();

                    if(end == instructions[m].length())
                    {
                        instructions[m].replace(found, gt->first.length(), gt->second);
                    }
                    else if(instructions[m][end] == ',')
                    {
                        instructions[m].replace(found, gt->first.length(), gt->second);
                    }
                }
                efile << instructions[m] << std::endl;
            }
            
            efile.close();
            
        }
	}
	else
	{
		// (Just a useful separator for debug cout statements in grammar)
		std::cout << "**********************************************\n";
	}

	// Close the file stream
	fclose(proccin);
	// Destroy lexer so it reinitializes
	procclex_destroy();
	// Return 1 if syntax error, 0 otherwise
	return static_cast<int>(gSyntaxError);
}

void proccerror(const char* s) // NOLINT
{
	std::cout << s << " on line " << gLineNumber << std::endl;
	gSyntaxError = true;
}
