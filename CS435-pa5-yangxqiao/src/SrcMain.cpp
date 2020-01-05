#include "SrcMain.h"
#include <iostream>
#include "Machine.h"

void ProcessCommandArgs(int argc, const char* argv[])
{
	// TODO
    Machine myMachine;
    myMachine.createOperation(argv[1]);
    myMachine.Execute();
}
