#include "Node.h"

void NBlock::AddStatement(NStatement* statement)
{
	mStatements.emplace_back(statement);
}

void NData::AddDecl(NDecl* decl)
{
	mDecls.emplace_back(decl);
}


CodeContext::CodeContext(std::vector<std::string>& Ops,
                         std::map<std::string, int>& Stack,
                         int lastVirReg)
: mOps(Ops), mStack(Stack), lastVirReg(lastVirReg)
{
    
}

void CodeContext::addOps(std::string& op){
    mOps.emplace_back(op);
}

void CodeContext::addStack(std::string& name)
{
    int index = mStack.size();
    mStack.insert(std::make_pair(name, index));
}

int CodeContext::getVirReg(){
    return lastVirReg;
}

void CodeContext::incVirReg(){
    lastVirReg++;
}

int CodeContext::getStackIndex(std::string& key){
    return mStack[key];
}

std::vector<std::string> CodeContext::getOps(){
    return mOps;
}

int CodeContext::getOpIndex(){
    return mOps.size()-1;
}


void CodeContext::modifyOp(int index, int addContent){
    mOps[index] += std::to_string(addContent);
}

void CodeContext::updateIntervals(int reg){
    int instruction = mOps.size()-1;
    auto it = mIntervals.find(reg);
    if(it != mIntervals.end())
    {
        it->second.emplace_back(instruction);
    }
    else{
        std::vector<int> temp;
        temp.emplace_back(instruction);
        mIntervals.insert(std::make_pair(reg, temp));
    }
}

std::map<int, std::vector<int> > CodeContext::getIntervals()
{
    return mIntervals;
}


std::map<int, std::vector<int>> CodeContext::opEnd(){
    std::map<int, std::vector<int>> output;
    for(auto it = mIntervals.begin(); it != mIntervals.end(); ++it)
    {
        int back = it->second.back();
        auto jt = output.find(back);
        if(jt != output.end())
        {
            jt->second.emplace_back(it->first);
        }
        else{
            std::vector<int> temp;
            temp.emplace_back(it->first);
            output.insert(std::make_pair(back, temp));
        }
    }
    return output;
}
