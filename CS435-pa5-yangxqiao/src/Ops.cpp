#include "Ops.h"
#include "Machine.h"
#include "Exceptions.h"

void Exit::Execute(Machine& machine)
{
    machine.setFlag("exit", true);
}


void MovI::Execute(Machine& machine)
{
    std::string regName = std::get<0>(mParameters);
    if(regName == "sc")
    {
        NonFatalExp exp(10);
        throw NonFatalExp(exp);
    }
    else if(regName == "r0")
    {
        NonFatalExp exp(11);
        throw NonFatalExp(exp);
    }
    int value = std::get<1>(mParameters);
    if(regName != "tc" || (value < 7 && value > 0))
    {
        machine.setRegister(regName, value);
    }
    else{
        NonFatalExp exp(14);
        throw NonFatalExp(exp);
    }
}


void Add::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    std::string regTwo = std::get<1>(mParameters);
    std::string regThree = std::get<2>(mParameters);
    int valueTwo = machine.getRegister(regTwo);
    int valueThree = machine.getRegister(regThree);
    int64_t result = static_cast<int64_t >(valueTwo) + static_cast<int64_t >(valueThree);
    if(result > INT32_MAX)
    {
        NonFatalExp exp(12);
        machine.setRegister(regOne, valueThree+valueTwo);
        throw NonFatalExp(exp);
    }
    else if(result < INT32_MIN)
    {
        NonFatalExp exp(13);
        machine.setRegister(regOne, valueThree+valueTwo);
        throw NonFatalExp(exp);
    }
    machine.setRegister(regOne, valueThree+valueTwo);
}


void Mov::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    if(regOne == "sc")
    {
        NonFatalExp exp(10);
        throw NonFatalExp(exp);
    }
    else if(regOne == "r0")
    {
        NonFatalExp exp(11);
        throw NonFatalExp(exp);
    }

    std::string regTwo = std::get<1>(mParameters);
    int valueTwo = machine.getRegister(regTwo);
    machine.setRegister(regOne, valueTwo);
}


void Sub::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    std::string regTwo = std::get<1>(mParameters);
    std::string regThree = std::get<2>(mParameters);
    int valueTwo = machine.getRegister(regTwo);
    int valueThree = machine.getRegister(regThree);
    int64_t result = static_cast<int64_t >(valueTwo)-static_cast<int64_t >(valueThree);
    if(result > INT32_MAX)
    {
        NonFatalExp exp(12);
        machine.setRegister(regOne, valueTwo-valueThree);
        throw NonFatalExp(exp);
    }
    else if(result < INT32_MIN)
    {
        NonFatalExp exp(13);
        machine.setRegister(regOne, valueTwo-valueThree);
        throw NonFatalExp(exp);
    }

    machine.setRegister(regOne, valueTwo-valueThree);

}

void Mul::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    std::string regTwo = std::get<1>(mParameters);
    std::string regThree = std::get<2>(mParameters);
    int valueTwo = machine.getRegister(regTwo);
    int valueThree = machine.getRegister(regThree);
    int64_t result = static_cast<int64_t >(valueThree)*static_cast<int64_t >(valueTwo);
    if(result > INT32_MAX)
    {
        NonFatalExp exp(12);
        machine.setRegister(regOne, valueTwo*valueThree);
        throw NonFatalExp(exp);
    }
    else if(result < INT32_MIN)
    {
        NonFatalExp exp(13);
        machine.setRegister(regOne, valueTwo*valueThree);
        throw NonFatalExp(exp);
    }
    machine.setRegister(regOne, valueTwo*valueThree);
}


void Div::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    std::string regTwo = std::get<1>(mParameters);
    std::string regThree = std::get<2>(mParameters);
    int valueTwo = machine.getRegister(regTwo);
    int valueThree = machine.getRegister(regThree);
    if(valueThree == 0)
    {
        FatalExp exp(102);
        throw exp;
    }
    int64_t result = static_cast<int64_t >(valueTwo)/static_cast<int64_t >(valueThree);
    if(result > INT32_MAX)
    {
        NonFatalExp exp(12);
        machine.setRegister(regOne, valueTwo/valueThree);
        throw NonFatalExp(exp);
    }
    else if(result < INT32_MIN)
    {
        NonFatalExp exp(13);
        machine.setRegister(regOne, valueTwo/valueThree);
        throw NonFatalExp(exp);
    }
    machine.setRegister(regOne, valueTwo/valueThree);
}

void Inc::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    int valueOne = machine.getRegister(regOne);
    int64_t result = static_cast<int64_t >(valueOne)+static_cast<int64_t >(1);
    if(result > INT32_MAX)
    {
        NonFatalExp exp(12);
        machine.setRegister(regOne, valueOne+1);
        throw NonFatalExp(exp);
    }
    machine.setRegister(regOne, valueOne+1);

}


void Dec::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    int valueOne = machine.getRegister(regOne);
    int64_t result = static_cast<int64_t >(valueOne) - static_cast<int64_t >(1);
    if(result < INT32_MIN)
    {
        NonFatalExp exp(13);
        machine.setRegister(regOne, valueOne-1);
        throw NonFatalExp(exp);
    }
    machine.setRegister(regOne, valueOne-1);
}


void Jmp::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    int valueOne = machine.getRegister(regOne);
    machine.setRegister("pc", valueOne);
}


void Cmpeq::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    int valueOne = machine.getRegister(regOne);
    std::string regTwo = std::get<1>(mParameters);
    int valueTwo = machine.getRegister(regTwo);
    machine.setFlag("test", valueTwo == valueOne);
}


void Cmplt::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    int valueOne = machine.getRegister(regOne);
    std::string regTwo = std::get<1>(mParameters);
    int valueTwo = machine.getRegister(regTwo);
    machine.setFlag("test", valueTwo > valueOne);
}


void Jt::Execute(Machine& machine)
{
    bool test = machine.getFlag("test");
    std::string regOne = std::get<0>(mParameters);
    int valueOne = machine.getRegister(regOne);
    if(test)
    {
        machine.setRegister("pc", valueOne);
    }
}


void Jnt::Execute(Machine& machine)
{
    bool test = machine.getFlag("test");
    std::string regOne = std::get<0>(mParameters);
    int valueOne = machine.getRegister(regOne);
    if(!test)
    {
        machine.setRegister("pc", valueOne);
    }
}


void Push::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    int valueOne = machine.getRegister(regOne);
    machine.pushStack(valueOne);
    int scval = machine.getRegister("sc");
    machine.setRegister("sc", scval+1);
}


void Pop::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    int newVal = machine.popStack();
    machine.setRegister(regOne, newVal);
    int scval = machine.getRegister("sc");
    machine.setRegister("sc", scval-1);
}


void Load::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    if(regOne == "sc")
    {
        NonFatalExp exp(10);
        throw NonFatalExp(exp);
    }
    else if(regOne == "r0")
    {
        NonFatalExp exp(11);
        throw NonFatalExp(exp);
    }

    std::string regTwo = std::get<1>(mParameters);
    int valueTwo = machine.getRegister(regTwo);
    if(valueTwo < 0 || valueTwo >= machine.getRegister("sc"))
    {
        FatalExp exp(100);
        throw exp;
    }

    int newVal = machine.getStack(valueTwo);
    machine.setRegister(regOne, newVal);
}


void Store::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    std::string regTwo = std::get<1>(mParameters);
    int valueTwo = machine.getRegister(regTwo);
    int valueOne = machine.getRegister(regOne);
    if(valueOne < 0 || valueOne >= machine.getRegister("sc"))
    {
        FatalExp exp(100);
        throw exp;
    }

    machine.setStack(valueOne, valueTwo);

}


void Loadi::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    if(regOne == "sc")
    {
        NonFatalExp exp(10);
        throw NonFatalExp(exp);
    }
    else if(regOne == "r0")
    {
        NonFatalExp exp(11);
        throw NonFatalExp(exp);
    }

    int index = std::get<1>(mParameters);
    if(index < 0 || index >= machine.getRegister("sc"))
    {
        FatalExp exp(100);
        throw exp;
    }

    int newVal = machine.getStack(index);
    machine.setRegister(regOne, newVal);
}


void Storei::Execute(Machine& machine)
{
    int index = std::get<0>(mParameters);
    std::string regTwo = std::get<1>(mParameters);
    int valueTwo = machine.getRegister(regTwo);
    if(index < 0 || index >= machine.getRegister("sc"))
    {
        FatalExp exp(100);
        throw exp;
    }
    machine.setStack(index, valueTwo);
}


void Loadsc::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    if(regOne == "sc")
    {
        NonFatalExp exp(10);
        throw NonFatalExp(exp);
    }
    else if(regOne == "r0")
    {
        NonFatalExp exp(11);
        throw NonFatalExp(exp);
    }

    std::string regTwo = std::get<1>(mParameters);
    int index = machine.getRegister("sc") - machine.getRegister(regTwo) - 1;
    if(index < 0 || index >= machine.getRegister("sc"))
    {
        FatalExp exp(100);
        throw exp;
    }
    int newVal = machine.getStack(index);
    machine.setRegister(regOne, newVal);

}


void Storesc::Execute(Machine& machine)
{
    std::string regOne = std::get<0>(mParameters);
    std::string regTwo = std::get<1>(mParameters);
    int valueTwo = machine.getRegister(regTwo);
    int index = machine.getRegister("sc") - machine.getRegister(regOne) - 1;
    if(index < 0 || index >= machine.getRegister("sc"))
    {
        FatalExp exp(100);
        throw exp;
    }

    machine.setStack(index, valueTwo);
}


void Pendown::Execute(Machine& machine)
{
    machine.setFlag("pen", true);
}


void Penup::Execute(Machine& machine)
{
    machine.setFlag("pen", false);
}


void FWD::Execute(Machine& machine)
{
    std::string reg = std::get<0>(mParameters);
    machine.exeFWD(reg);
}


void Back::Execute(Machine& machine)
{
    std::string reg = std::get<0>(mParameters);
    machine.exeBack(reg);
}
