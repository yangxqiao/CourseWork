#pragma once
#include <exception>

class NonFatalExp : public virtual std::exception
{
public:
    NonFatalExp(int code) : mcode(code)
    {
    }
    
    const char* message() {
        switch (mcode) {
            case 10:
                return "Invalid write to the sc register";
                break;
            case 11:
                return "Invalid write to the r0 register";
                break;
            case 12:
                return "Integer overflow";
                break;
            case 13:
                return "Integer underflow";
                break;
            case 14:
                return "Invalid color";
                break;
            default:
                break;
        }
        return nullptr;
    }
    
    int getCode(){
        return mcode;
    }
    
private:
    int mcode;
};


class FatalExp :  public virtual std::exception
{
public:
    FatalExp(int code) : mcode(code)
    {
    }
    
    const char* message(){
        switch (mcode) {
            case 100:
                return "Access violation";
                break;
            case 101:
                return "Stack overflow";
                break;
            case 102:
                return "Divide by zero";
                break;
            case 103:
                return "Pop when stack is empty (sc == 0)";
                break;
            default:
                break;
        }
        return nullptr;
    }
    
    
    int getCode(){
        return mcode;
    }
private:
    int mcode;
};
