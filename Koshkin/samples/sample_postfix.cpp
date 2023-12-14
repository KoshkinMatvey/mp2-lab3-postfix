#include <iostream>
#include "Postfix.h"

using namespace std;

int main()
{
	string expression = "((13.4 - 4.7) / 2 + 5.7) - (10.5 * (9.4 - 8.7))"; 
	double res = 0.0;

	//cout << "Enter expression: ";
	//getline(cin, expression);
	TArithmeticExpression postfix(expression);
	cout << expression << endl;
	cout << "Expression: " << postfix.getInfix() << endl;
	cout << "Postfix: " << postfix.getPostfix() << endl;
	res = postfix.calculate();
	cout << "Result: " << res << endl;

	return 0;
}
