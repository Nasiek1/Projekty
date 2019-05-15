#pragma once
#include<memory>
#include<vector>
#include<utility>
#include<vector>
#include"SyntaxErrorException.h"
class AbstractExpression
{	
protected:
	//std::vector<std::unique_ptr<AbstractExpression>> vectorAbstractExpr;
	std::unique_ptr<AbstractExpression> leftNode;
	std::unique_ptr<AbstractExpression> rightNode;
public:
	AbstractExpression();
	virtual double calculate(std::unique_ptr<AbstractExpression>& pRoot);
	virtual std::string emit();
	void setLeftNode(std::unique_ptr<AbstractExpression> & pLeft);
	void setRightNode(std::unique_ptr<AbstractExpression>& pRight);
	AbstractExpression& operator=(AbstractExpression&& expr);
	//std::unique_ptr<AbstractExpression>& getToken();
	std::unique_ptr<AbstractExpression>& getLeftNode();
	std::unique_ptr<AbstractExpression>& getRightNode();
	virtual void checkAST();
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::vector<std::unique_ptr<AbstractExpression>> & vectorExpr);
	virtual ~AbstractExpression();
};

