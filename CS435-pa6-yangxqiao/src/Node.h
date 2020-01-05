#pragma once
#include <vector>
#include <string>
#include <ostream>
#include <map>

struct CodeContext
{
	// TODO: Add members as needed
    CodeContext(std::vector<std::string>& Ops,
                std::map<std::string, int>& Stack,
                int lastVirReg);
                
    void addOps(std::string& op);
    void addStack(std::string& name);
    int getVirReg();
    void incVirReg();
    int getStackIndex(std::string& key);
    std::vector<std::string> getOps();
    int getOpIndex();
    void modifyOp(int index, int addContent);
    void updateIntervals(int reg);
    std::map<int, std::vector<int> > getIntervals();
    std::map<int, std::vector<int>> opEnd();
    
    std::vector<std::string> mOps;
    std::map<std::string, int> mStack;
    int lastVirReg;
    std::map<int, std::vector<int> > mIntervals;
};

class Node
{
public:
	virtual void OutputAST(std::ostream& stream, int depth) const = 0;
	virtual void CodeGen(CodeContext& context) = 0;
protected:
	void OutputMargin(std::ostream& stream, int depth) const;
};

class NDecl : public Node
{
};

class NData : public Node
{
public:
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
	void AddDecl(NDecl* decl);
private:
	std::vector<NDecl*> mDecls;
};

class NStatement : public Node
{
};

class NBlock : public Node
{
public:
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
	void AddStatement(NStatement* statement);
private:
	std::vector<NStatement*> mStatements;
};

class NProgram : public Node
{
public:
	NProgram(NData* data, NBlock* main)
		:mData(data)
		,mMain(main)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	NData* mData;
	NBlock* mMain;
};

class NNumeric : public Node
{
public:
	NNumeric(std::string& value)
		:mValue(std::stoi(value))
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;

	int GetValue() const { return mValue; }
private:
	int mValue;
};

class NVarDecl : public NDecl
{
public:
	NVarDecl(std::string& name)
		:mName(name)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	std::string mName;
};

class NArrayDecl : public NDecl
{
public:
	NArrayDecl(std::string& name, NNumeric* size)
		:mName(name)
		,mSize(size)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	std::string mName;
	NNumeric* mSize;
};

class NExpr : public Node
{
public:
	const std::string& GetResultRegister() const { return mResultRegister; }
protected:
	std::string mResultRegister;
};

class NNumericExpr : public NExpr
{
public:
	NNumericExpr(NNumeric* num)
		:mNumeric(num)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	NNumeric* mNumeric;
};

class NVarExpr : public NExpr
{
public:
	NVarExpr(std::string& name)
		:mName(name)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	std::string mName;
};

class NBinaryExpr : public NExpr
{
public:
	NBinaryExpr(NExpr* lhs, int type, NExpr* rhs)
		:mLhs(lhs)
		,mRhs(rhs)
		,mType(type)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	NExpr* mLhs;
	NExpr* mRhs;
	int mType;
};

class NArrayExpr : public NExpr
{
public:
	NArrayExpr(std::string& name, NExpr* subscript)
		:mName(name)
		,mSubscript(subscript)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	std::string mName;
	NExpr* mSubscript;
};

class NAssignVarStmt : public NStatement
{
public:
	NAssignVarStmt(std::string& name, NExpr* rhs)
		:mName(name)
		,mRhs(rhs)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	std::string mName;
	NExpr* mRhs;
};

class NAssignArrayStmt : public NStatement
{
public:
	NAssignArrayStmt(std::string& name, NExpr* subscript, NExpr* rhs)
		:mName(name)
		,mSubscript(subscript)
		,mRhs(rhs)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	std::string mName;
	NExpr* mSubscript;
	NExpr* mRhs;
};

class NIncStmt : public NStatement
{
public:
	NIncStmt(std::string& name)
		:mName(name)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	std::string mName;
};

class NDecStmt : public NStatement
{
public:
	NDecStmt(std::string& name)
		:mName(name)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	std::string mName;
};

class NComparison : public Node
{
public:
	NComparison(NExpr* lhs, int type, NExpr* rhs)
		:mLhs(lhs)
		,mRhs(rhs)
		,mType(type)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	NExpr* mLhs;
	NExpr* mRhs;
	int mType;
};

class NIfStmt : public NStatement
{
public:
	NIfStmt(NComparison* comp, NBlock* ifBlock, NBlock* elseBlock)
		:mComp(comp)
		,mIfBlock(ifBlock)
		,mElseBlock(elseBlock)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	NComparison* mComp;
	NBlock* mIfBlock;
	NBlock* mElseBlock;
};

class NWhileStmt : public NStatement
{
public:
	NWhileStmt(NComparison* comp, NBlock* block)
		:mComp(comp)
		,mBlock(block)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	NComparison* mComp;
	NBlock* mBlock;
};

class NPenUpStmt : public NStatement
{
public:
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
};

class NPenDownStmt : public NStatement
{
public:
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
};

class NSetPosStmt : public NStatement
{
public:
	NSetPosStmt(NExpr* x, NExpr* y)
		:mXExpr(x)
		,mYExpr(y)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	NExpr* mXExpr;
	NExpr* mYExpr;
};

class NSetColorStmt : public NStatement
{
public:
	NSetColorStmt(NExpr* color)
		:mColor(color)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	NExpr* mColor;
};

class NFwdStmt : public NStatement
{
public:
	NFwdStmt(NExpr* param)
		:mParam(param)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	NExpr* mParam;
};

class NBackStmt : public NStatement
{
public:
	NBackStmt(NExpr* param)
		:mParam(param)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	NExpr* mParam;
};

class NRotStmt : public NStatement
{
public:
	NRotStmt(NExpr* param)
		:mParam(param)
	{ }
	void OutputAST(std::ostream& stream, int depth) const override;
	void CodeGen(CodeContext& context) override;
private:
	NExpr* mParam;
};
