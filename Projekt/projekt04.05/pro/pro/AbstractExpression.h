#pragma once
#include<memory>
#include<vector>
#include<utility>
class Parser;
class AbstractExpression
{	
	
protected:
	std::unique_ptr<Parser> parser;
	std::unique_ptr<AbstractExpression> leftNode;
	std::unique_ptr<AbstractExpression> rightNode;
	
public:
	//auto clone() const { return std::unique_ptr<AbstractExpression>(clone_impl()); }
	AbstractExpression();
	AbstractExpression(const std::string & newData);
	//virtual std::unique_ptr<AbstractExpression> clone() const = 0;
	void setLeftNode(std::unique_ptr<AbstractExpression> & pLeft);
	void setRightNode(std::unique_ptr<AbstractExpression>& pRight);
	AbstractExpression& operator=(AbstractExpression&& expr);
	std::unique_ptr<AbstractExpression> getToken();
	std::unique_ptr<Parser>& getParser();
	std::unique_ptr<AbstractExpression>& getLeftNode();
	std::unique_ptr<AbstractExpression>& getRightNode();
	virtual void buildAST(std::unique_ptr<AbstractExpression> & pRoot, std::string & newData);
	virtual ~AbstractExpression();
};

