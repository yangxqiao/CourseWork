#include "Node.h"
#include "parser.hpp"

void NBlock::CodeGen(CodeContext& context)
{
    for(unsigned int i = 0; i < mStatements.size(); i++)
    {
        mStatements[i]->CodeGen(context);
    }
}

void NData::CodeGen(CodeContext& context)
{
    for(unsigned int i = 0; i < mDecls.size(); i++)
    {
        mDecls[i]->CodeGen(context);
    }
}

void NProgram::CodeGen(CodeContext& context)
{
    mData->CodeGen(context);
    mMain->CodeGen(context);
    std::string op = "exit";
    context.addOps(op);
}

void NNumeric::CodeGen(CodeContext& context)
{
}

void NVarDecl::CodeGen(CodeContext& context)
{
    std::string op = "push r0";
    context.addOps(op);
    context.addStack(mName);
}

void NArrayDecl::CodeGen(CodeContext& context)
{
    std::string op = "push r0";
    for(int i = 0; i < mSize->GetValue(); i++)
    {
        context.addOps(op);
    }
    context.addStack(mName);
}

void NNumericExpr::CodeGen(CodeContext& context)
{
    std::string op = "movi %" + std::to_string(context.getVirReg()) + "," + std::to_string(mNumeric->GetValue());
    context.addOps(op);
    context.updateIntervals(context.getVirReg());
    mResultRegister = std::to_string(context.getVirReg());
    context.incVirReg();
}

void NVarExpr::CodeGen(CodeContext& context)
{
    std::string op = "loadi %" + std::to_string(context.getVirReg()) + "," + std::to_string(context.getStackIndex(mName));
    context.addOps(op);
    context.updateIntervals(context.getVirReg());
    mResultRegister = std::to_string(context.getVirReg());
    context.incVirReg();
}

void NBinaryExpr::CodeGen(CodeContext& context)
{
    mLhs->CodeGen(context);
    mRhs->CodeGen(context);
    std::string op;
    switch (mType) {
        case TADD:
        {
            op = "add %" + std::to_string(context.getVirReg()) + ",%" + mLhs->GetResultRegister() + ",%" + mRhs->GetResultRegister();
            break;
        }
        case TSUB:
        {
            op = "sub %" + std::to_string(context.getVirReg()) + ",%" + mLhs->GetResultRegister() + ",%" + mRhs->GetResultRegister();
            break;
        }
        case TDIV:
        {
            op = "div %" + std::to_string(context.getVirReg()) + ",%" + mLhs->GetResultRegister() + ",%" + mRhs->GetResultRegister();
            break;
        }
        case TMUL:
        {
            op = "mul %" + std::to_string(context.getVirReg()) + ",%" + mLhs->GetResultRegister() + ",%" + mRhs->GetResultRegister();
            break;
        }
        default:
            break;
    }
    context.addOps(op);
    
    context.updateIntervals(context.getVirReg());
    context.updateIntervals(std::stoi(mLhs->GetResultRegister()));
    context.updateIntervals(std::stoi(mRhs->GetResultRegister()));
    
    mResultRegister = std::to_string(context.getVirReg());
    context.incVirReg();
}

void NArrayExpr::CodeGen(CodeContext& context)
{
    mSubscript->CodeGen(context);
    std::string op = "movi %" + std::to_string(context.getVirReg()) + "," + std::to_string(context.getStackIndex(mName));
    context.addOps(op);
    
    context.updateIntervals(context.getVirReg());
    
    context.incVirReg();
    
    std::string op2 = "add %" + std::to_string(context.getVirReg()) + ",%" + std::to_string(context.getVirReg()-1) + ",%" + mSubscript->GetResultRegister();
    context.addOps(op2);
    
    context.updateIntervals(context.getVirReg());
    context.updateIntervals(context.getVirReg()-1);
    context.updateIntervals(std::stoi(mSubscript->GetResultRegister()));
    
    context.incVirReg();
    
    std::string op3 = "load %" + std::to_string(context.getVirReg()) + ",%" + std::to_string(context.getVirReg()-1);
    mResultRegister = std::to_string(context.getVirReg());
    context.addOps(op3);
    
    context.updateIntervals(context.getVirReg());
    context.updateIntervals(context.getVirReg()-1);
    
    context.incVirReg();
}

void NAssignVarStmt::CodeGen(CodeContext& context)
{
    mRhs->CodeGen(context);
    std::string op = "storei " + std::to_string(context.getStackIndex(mName)) + ",%" + mRhs->GetResultRegister();
    context.addOps(op);
    context.updateIntervals(std::stoi(mRhs->GetResultRegister()));
}

void NAssignArrayStmt::CodeGen(CodeContext& context)
{
    mRhs->CodeGen(context);
    mSubscript->CodeGen(context);
    std::string op = "movi %" + std::to_string(context.getVirReg()) + "," + std::to_string(context.getStackIndex(mName));
    context.addOps(op);
    
    context.updateIntervals(context.getVirReg());
    
    context.incVirReg();
    std::string op2 = "add %" + std::to_string(context.getVirReg()) + ",%" + std::to_string(context.getVirReg()-1) + ",%" + mSubscript->GetResultRegister();
    context.addOps(op2);
    
    context.updateIntervals(context.getVirReg());
    context.updateIntervals(context.getVirReg()-1);
    context.updateIntervals(std::stoi(mSubscript->GetResultRegister()));
    
    context.incVirReg();
    std::string op3 = "store %" + std::to_string(context.getVirReg()-1) + ",%" + mRhs->GetResultRegister();
    context.addOps(op3);
    
    context.updateIntervals(context.getVirReg()-1);
    context.updateIntervals(std::stoi(mRhs->GetResultRegister()));
}

void NIncStmt::CodeGen(CodeContext& context)
{
    std::string op = "loadi %" + std::to_string(context.getVirReg()) + "," + std::to_string(context.getStackIndex(mName));
    context.addOps(op);
    
    context.updateIntervals(context.getVirReg());
    
    std::string op2 = "inc %" + std::to_string(context.getVirReg());
    context.addOps(op2);
    
    context.updateIntervals(context.getVirReg());
    
    std::string op3 = "storei " + std::to_string(context.getStackIndex(mName)) + ",%" + std::to_string(context.getVirReg());
    context.addOps(op3);
    
    context.updateIntervals(context.getVirReg());
    
    context.incVirReg();
}

void NDecStmt::CodeGen(CodeContext& context)
{
    std::string op = "loadi %" + std::to_string(context.getVirReg()) + "," + std::to_string(context.getStackIndex(mName));
    context.addOps(op);
    
    context.updateIntervals(context.getVirReg());
    
    std::string op2 = "dec %" + std::to_string(context.getVirReg());
    context.addOps(op2);
    
    context.updateIntervals(context.getVirReg());
    
    std::string op3 = "storei " + std::to_string(context.getStackIndex(mName)) + ",%" + std::to_string(context.getVirReg());
    context.addOps(op3);
    
    context.updateIntervals(context.getVirReg());
    
    context.incVirReg();
}

void NComparison::CodeGen(CodeContext& context)
{
    mLhs->CodeGen(context);
    mRhs->CodeGen(context);
    std::string op;
    if (mType == TISEQUAL) {
        op = "cmpeq %" + mLhs->GetResultRegister() + ",%" + mRhs->GetResultRegister();
    }
    else{
        op = "cmplt %" + mLhs->GetResultRegister() + ",%" + mRhs->GetResultRegister();
    }
    
    context.addOps(op);
    context.updateIntervals(std::stoi(mLhs->GetResultRegister()));
    context.updateIntervals(std::stoi(mRhs->GetResultRegister()));
}

void NIfStmt::CodeGen(CodeContext& context)
{
    mComp->CodeGen(context);
    std::string op1 = "movi %" + std::to_string(context.getVirReg()) + ",";
    context.addOps(op1);
    context.updateIntervals(context.getVirReg());
    int index = context.getOpIndex();
    
    std::string op2 = "jnt %" + std::to_string(context.getVirReg());
    context.addOps(op2);
    context.updateIntervals(context.getVirReg());
    context.incVirReg();
    
    mIfBlock->CodeGen(context);
    if (mElseBlock == nullptr) {
        int lineToMoveOp1 = context.getOpIndex();
        context.modifyOp(index, lineToMoveOp1+1);
    }
    else{
        std::string op3 = "movi %" + std::to_string(context.getVirReg()) + ",";
        context.addOps(op3);
        context.updateIntervals(context.getVirReg());
        int indexOp3 = context.getOpIndex();
        
        std::string op4 = "jmp %" +  std::to_string(context.getVirReg());
        context.addOps(op4);
        context.updateIntervals(context.getVirReg());
        context.incVirReg();
        
        mElseBlock->CodeGen(context);
        int lineToMoveOp = context.getOpIndex();
        context.modifyOp(indexOp3, lineToMoveOp+1);
        context.modifyOp(index, lineToMoveOp-1);
    }
}

void NWhileStmt::CodeGen(CodeContext& context)
{
    int lineToMoveOp3 = context.getOpIndex();
    
    mComp->CodeGen(context);
    std::string op1 = "movi %" + std::to_string(context.getVirReg()) + ",";
    context.addOps(op1);
    context.updateIntervals(context.getVirReg());
    int indexOp1 = context.getOpIndex();
    
    std::string op2 = "jnt %" + std::to_string(context.getVirReg());
    context.addOps(op2);
    context.updateIntervals(context.getVirReg());
    context.incVirReg();
    
    mBlock->CodeGen(context);
    
    std::string op3 = "movi %" + std::to_string(context.getVirReg()) + ",";
    context.addOps(op3);
    context.updateIntervals(context.getVirReg());
    int indexOp3 = context.getOpIndex();
    
    std::string op4 = "jmp %" +  std::to_string(context.getVirReg());
    context.addOps(op4);
    context.updateIntervals(context.getVirReg());
    context.incVirReg();

    context.modifyOp(indexOp3, lineToMoveOp3+1);
    
    int lineToMoveOp1 = context.getOpIndex();
    context.modifyOp(indexOp1, lineToMoveOp1+1);
}

void NPenUpStmt::CodeGen(CodeContext& context)
{
    std::string op = "penup";
    context.addOps(op);
}

void NPenDownStmt::CodeGen(CodeContext& context)
{
    std::string op = "pendown";
    context.addOps(op);
}

void NSetPosStmt::CodeGen(CodeContext& context)
{
    mXExpr->CodeGen(context);
    mYExpr->CodeGen(context);
    std::string opX = "mov tx,%" + mXExpr->GetResultRegister();
    std::string opY = "mov ty,%" + mYExpr->GetResultRegister();
    context.addOps(opX);
    context.updateIntervals(std::stoi(mXExpr->GetResultRegister()));
    context.addOps(opY);
    context.updateIntervals(std::stoi(mYExpr->GetResultRegister()));
}

void NSetColorStmt::CodeGen(CodeContext& context)
{
    mColor->CodeGen(context);
    std::string opC = "mov tc,%" + mColor->GetResultRegister();
    context.addOps(opC);
    context.updateIntervals(std::stoi(mColor->GetResultRegister()));
}

void NFwdStmt::CodeGen(CodeContext& context)
{
    mParam->CodeGen(context);
    std::string op = "fwd %" + mParam->GetResultRegister();
    context.addOps(op);
    context.updateIntervals(std::stoi(mParam->GetResultRegister()));
}

void NBackStmt::CodeGen(CodeContext& context)
{
    mParam->CodeGen(context);
    std::string op = "back %" + mParam->GetResultRegister();
    context.addOps(op);
    context.updateIntervals(std::stoi(mParam->GetResultRegister()));
}

void NRotStmt::CodeGen(CodeContext& context)
{
    mParam->CodeGen(context);
    std::string op = "add tr,tr,%" + mParam->GetResultRegister();
    context.addOps(op);
    context.updateIntervals(std::stoi(mParam->GetResultRegister()));
}
