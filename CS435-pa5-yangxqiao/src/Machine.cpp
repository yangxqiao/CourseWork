#include "Machine.h"
#include <fstream>
#include <iostream>
#include "Exceptions.h"

using std::endl;
using std::cout;

Machine::Machine()
    : bImage(320, 240),
      imgDrawer(bImage)
{
	// TODO
    opMap.emplace("movi", &CreateOp<MovI>);
    opMap.emplace("exit", &CreateOp<Exit>);
    opMap.emplace("add", &CreateOp<Add>);
    opMap.emplace("mov", &CreateOp<Mov>);
    opMap.emplace("sub", &CreateOp<Sub>);
    opMap.emplace("mul", &CreateOp<Mul>);
    opMap.emplace("div", &CreateOp<Div>);
    opMap.emplace("inc", &CreateOp<Inc>);
    opMap.emplace("dec", &CreateOp<Dec>);
    opMap.emplace("jmp", &CreateOp<Jmp>);
    opMap.emplace("cmpeq", &CreateOp<Cmpeq>);
    opMap.emplace("cmplt", &CreateOp<Cmplt>);
    opMap.emplace("jt", &CreateOp<Jt>);
    opMap.emplace("jnt", &CreateOp<Jnt>);
    opMap.emplace("push", &CreateOp<Push>);
    opMap.emplace("pop", &CreateOp<Pop>);
    opMap.emplace("load", &CreateOp<Load>);
    opMap.emplace("store", &CreateOp<Store>);
    opMap.emplace("loadi", &CreateOp<Loadi>);
    opMap.emplace("storei", &CreateOp<Storei>);
    opMap.emplace("loadsc", &CreateOp<Loadsc>);
    opMap.emplace("storesc", &CreateOp<Storesc>);
    opMap.emplace("pendown", &CreateOp<Pendown>);
    opMap.emplace("penup", &CreateOp<Penup>);
    opMap.emplace("fwd", &CreateOp<FWD>);
    opMap.emplace("back", &CreateOp<Back>);
    
    // initialize all registers
    mRegs.insert(std::make_pair("r0", 0));
    mRegs.insert(std::make_pair("r1", 0));
    mRegs.insert(std::make_pair("r2", 0));
    mRegs.insert(std::make_pair("r3", 0));
    mRegs.insert(std::make_pair("r4", 0));
    mRegs.insert(std::make_pair("r5", 0));
    mRegs.insert(std::make_pair("r6", 0));
    mRegs.insert(std::make_pair("r7", 0));
    mRegs.insert(std::make_pair("pc", 0));
    mRegs.insert(std::make_pair("sc", 0));
    mRegs.insert(std::make_pair("ex", 0));
    mRegs.insert(std::make_pair("tx", 0));
    mRegs.insert(std::make_pair("ty", 0));
    mRegs.insert(std::make_pair("tr", 0));
    mRegs.insert(std::make_pair("tc", 0));

    // initialize all flags
    mFlags.insert(std::make_pair("exit", false));
    mFlags.insert(std::make_pair("test", false));
    mFlags.insert(std::make_pair("pen", false));
    
    // initialize the image
    bImage.set_all_channels(0, 0, 0);
    imgDrawer.pen_width(1);
    imgDrawer.pen_color(255, 255, 255);
}

void Machine::createOperation(std::string filename){
    std::ifstream ifile(filename);
    
    std::string line;
    while(static_cast<bool>(std::getline(ifile, line, '\n')))
    {
        std::string opName;
        std::string params;
        std::size_t pos = line.find(" ");
        if(pos == -1)
        {
            opName = line;
            params = "";
        }
        else{
            opName = line.substr(0, pos);
            params = line.substr(pos+1);
        }
        
        std::shared_ptr<Op> ptr = opMap.at(opName)();
        ptr->Parse(params);
        mOps.push_back(ptr);
    }
    
    ifile.close();
}


int Machine::getRegister(const std::string& name){
    auto it = mRegs.find(name);
    if(it == mRegs.end())
    {
        cout << "Cannot find this register" << endl;
        return -1;
    }
    return it->second;
}

bool Machine::getFlag(const std::string& name){
    auto it = mFlags.find(name);
    if(it == mFlags.end())
    {
        cout << "Cannot find this flag." << endl;
        return false;
    }
    return it->second;
}

void Machine::setRegister(std::string name, int value)
{
    auto it = mRegs.find(name);
    it->second = value;
}

void Machine::setFlag(std::string name, bool value){
    auto it = mFlags.find(name);
    it->second = value;
}

void Machine::Execute()
{
    std::ofstream ofile("log.txt");
    std::ofstream stackfile("stack.txt");
    while(!getFlag("exit"))
    {
        int pcValue = getRegister("pc");
        std::shared_ptr<Op> ptr = mOps[pcValue];
        std::string opName = ptr->GetName();
        printLog(ofile, opName);
        printStack(stackfile);
        setRegister("pc", pcValue+1);
        try {
            ptr->Execute(*this);
        }
        catch (NonFatalExp& e) {
            setRegister("ex", e.getCode());
            cout << e.message() << endl;
        }
        catch (FatalExp& e){
            setRegister("ex", e.getCode());
            cout << e.message() << endl;
            setFlag("exit", true);
        }
    }
    printLog(ofile, "");
    printStack(stackfile);
    bImage.save_image("output.bmp");
}

void Machine::printLog(std::ofstream& ofile, std::string opName)
{
    
    ofile << "********************" << '\n';
    ofile << "r0=" << getRegister("r0") << '\n';
    ofile << "r1=" << getRegister("r1") << '\n';
    ofile << "r2=" << getRegister("r2") << '\n';
    ofile << "r3=" << getRegister("r3") << '\n';
    ofile << "r4=" << getRegister("r4") << '\n';
    ofile << "r5=" << getRegister("r5") << '\n';
    ofile << "r6=" << getRegister("r6") << '\n';
    ofile << "r7=" << getRegister("r7") << '\n';
    ofile << "pc=" << getRegister("pc") << '\n';
    ofile << "sc=" << getRegister("sc") << '\n';
    ofile << "ex=" << getRegister("ex") << '\n';
    ofile << "tx=" << getRegister("tx") << '\n';
    ofile << "ty=" << getRegister("ty") << '\n';
    ofile << "tr=" << getRegister("tr") << '\n';
    ofile << "tc=" << getRegister("tc") << '\n';
    ofile << "exit=" << getFlag("exit") << '\n';
    ofile << "test=" << getFlag("test") << '\n';
    ofile << "pen=" << getFlag("pen") << '\n';
    
    if(!opName.empty())
    {
        ofile << "Executing: " << opName << '\n';
    }
}


void Machine::pushStack(int value){
    if(mStack.size() == 256)
    {
        FatalExp exp(101);
        throw exp;
    }

    mStack.emplace_back(value);

}

int Machine::getStack(int index){
    return mStack[index];
}

int Machine::popStack(){
    if(mStack.empty())
    {
        FatalExp exp(103);
        throw exp;
    }

    int value = mStack.back();
    mStack.pop_back();
    return value;
}

void Machine::setStack(int index, int value){
    mStack[index] = value;
}


void Machine::printStack(std::ofstream& stackfile){
    stackfile << "pc: " << getRegister("pc") << " Stack: ";
    for(auto i = 0; i < mStack.size(); i++)
    {
        stackfile << mStack[i] << " ";
    }
    stackfile << '\n';
}


void Machine::exeFWD(const std::string& reg){
    changePenColor();
    int tx = getRegister("tx");
    int ty = getRegister("ty");
    int target = getRegister(reg);
    float angle = getRegister("tr") * 0.0174533f;
    int endx = tx + static_cast<int>(std::cos(angle) * target);
    int endy = ty + static_cast<int>(std::sin(angle) * target);
    bool pen = getFlag("pen");
    if(pen)
    {
        imgDrawer.line_segment(tx, ty, endx, endy);
    }
    setRegister("tx", endx);
    setRegister("ty", endy);
}


void Machine::exeBack(const std::string& reg){
    changePenColor();
    int tx = getRegister("tx");
    int ty = getRegister("ty");
    int target = -1 * getRegister(reg);
    float angle = getRegister("tr") * 0.0174533f;
    int endx = tx + static_cast<int>(std::cos(angle) * target);
    int endy = ty + static_cast<int>(std::sin(angle) * target);
    bool pen = getFlag("pen");
    if(pen)
    {
        imgDrawer.line_segment(tx, ty, endx, endy);
    }
    setRegister("tx", endx);
    setRegister("ty", endy);
}


void Machine::changePenColor(){
    int color = getRegister("tc");
    if(color < 0 || color > 7)
    {
        NonFatalExp exp(14);
        throw exp;
    }
    switch (color) {
        case 0:
            imgDrawer.pen_color(255, 255, 255);
            break;
        case 1:
            imgDrawer.pen_color(255, 255, 0);
            break;
        case 2:
            imgDrawer.pen_color(255, 0, 255);
            break;
        case 3:
            imgDrawer.pen_color(255, 0, 0);
            break;
        case 4:
            imgDrawer.pen_color(0, 255, 255);
            break;
        case 5:
            imgDrawer.pen_color(0, 255, 0);
            break;
        case 6:
            imgDrawer.pen_color(0, 0, 255);
            break;
        case 7:
            imgDrawer.pen_color(0, 0, 0);
            break;
        default:
            break;
    }
}
