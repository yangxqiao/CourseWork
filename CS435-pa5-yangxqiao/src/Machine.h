#pragma once
#include "Ops.h"
#include <memory>
#include <vector>
#include <map>
#include <fstream>
#include "../img/bitmap_image.hpp"

class Machine
{
public:
	Machine();
    void createOperation(std::string filename);
    int getRegister(const std::string& name);
    bool getFlag(const std::string& name);
    void setRegister(std::string name, int value);
    void setFlag(std::string name, bool value);
    void Execute();
    void printLog(std::ofstream& ofile, std::string opName);
    void pushStack(int value);
    int getStack(int index);
    int popStack();
    void setStack(int index, int value);
    void printStack(std::ofstream& stackfile);
    void exeFWD(const std::string& reg);
    void exeBack(const std::string& reg);
    void changePenColor();

private:
	std::vector<std::shared_ptr<Op>> mOps;
    std::map <std::string, std::function<std::shared_ptr<Op>()>> opMap;
    std::map <std::string, int> mRegs;
    std::map <std::string, bool> mFlags;
    std::vector<int> mStack;
    bitmap_image bImage;
    image_drawer imgDrawer;
    
};

template <typename T>
std::shared_ptr<Op> CreateOp()
{
    return std::make_shared<T>();
}
