#include "Postfix.h"

using namespace std;

void TArithmeticExpression::parse() 
{
	string currentLexeme = "";
	for (char symbol : infix) 
	{
		switch (symbol) 
		{
		case '-': case '+': case '/': case '*': case '(': case ')':
			if (currentLexeme != "") {
				lexemes.push_back(currentLexeme);
				currentLexeme = "";
			}

			currentLexeme += symbol;
			lexemes.push_back(currentLexeme);
			currentLexeme = "";
			break;
		default:
			if ((symbol >= '0' && symbol <= '9') || symbol == '.' || symbol == ',') 
			{
				currentLexeme += symbol;
			}
			break;
		}
	}
	if (currentLexeme != "") lexemes.push_back(currentLexeme);
}

void TArithmeticExpression::toPostfix()
{
	parse();
	TStack<string> stack;
	string stackItem;

	for (string item : lexemes)
	{
		switch (item[0])
		{
		case '(':
			stack.Push(item);
			break;
		case ')':
			stackItem = stack.Top();
			stack.Pop();
			while (stackItem[0] != '(')
			{
				postfix += stackItem;
				postfix += " ";
				stackItem = stack.Top();
				stack.Pop();
			}
			break;
		case '+': case '-': case '*': case '/':
			while (!stack.IsEmpty())
			{
				stackItem = stack.Top();
				stack.Pop();
				if (priority[item] <= priority[stackItem])
				{
					postfix += stackItem;
					postfix += " ";
				}
				else {
					stack.Push(stackItem);
					break;
				}
			}
			stack.Push(item);
			break;
		default:
			operands.insert({ item, 0.0 });
			postfix += item;
			postfix += " ";
			break;
		}
	}
	while (!stack.IsEmpty())
	{
		stackItem = stack.Top();
		stack.Pop();
		postfix += stackItem;
		postfix += " ";
	}

}

TArithmeticExpression::TArithmeticExpression(string expression) : infix(expression) {
	priority = { { "+", 1}, { "-", 1}, { "*", 2}, { "/", 2}, { "(", 0 } };
	toPostfix();
}

vector<string> TArithmeticExpression::getOperands() const {
	vector<string> res;
	for (const auto& item : operands) {
		res.push_back(item.first);
	}
	return res;
}

double TArithmeticExpression::calculate() {
	TStack<double> stack;
	double leftOperand, rightOperand;
	string currentLexeme = "";

	for (char symbol : postfix) {
		switch (symbol) {
		case '-':
			rightOperand = stack.Top();
			stack.Pop();
			leftOperand = stack.Top();
			stack.Pop();
			stack.Push(leftOperand - rightOperand);
			break;
		case '+':
			rightOperand = stack.Top();
			stack.Pop();
			leftOperand = stack.Top();
			stack.Pop();
			stack.Push(leftOperand + rightOperand);
			break;
		case '/':
			rightOperand = stack.Top();
			stack.Pop();
			leftOperand = stack.Top();
			stack.Pop();
			stack.Push(leftOperand / rightOperand);
			break;
		case '*':
			rightOperand = stack.Top();
			stack.Pop();
			leftOperand = stack.Top();
			stack.Pop();
			stack.Push(leftOperand * rightOperand);
			break;
		default:
			if ((symbol >= '0' && symbol <= '9') || symbol == '.' || symbol == ',') {
				currentLexeme += symbol;
			}
			else {
				if (currentLexeme != "") {
					stack.Push(stod(currentLexeme));
					currentLexeme = "";
				}
			}
			break;
		}
	}

	return stack.Top();
}