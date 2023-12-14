#include <string>
#include <vector>
#include <utility>
#include <map>
#include "TStack.h"

using namespace std;

class TArithmeticExpression {
private:
    string infix;
    string postfix;

    vector<string> lexemes;
    map<string, int> priority;
    map<string, double> operands;

    void parse();
    void toPostfix();

public:
    TArithmeticExpression(string expression = "");

    string getInfix() const { return infix; }
    string getPostfix() const { return postfix; }

    vector<string> getOperands() const;
    double calculate();
};