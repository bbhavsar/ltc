#include "common.hh"
#include <stack>
#include <math.h>

int precedence(char op) {
    cout << op << endl;

    assert(op == '^' || op == '*' || op == '/' || op == '+' || op == '-' || op == '(');

    switch (op) {
        case '(':
            return 4;
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
    }

    return -1;
}

string convertInfixToPostfix(const string& infix) {
    stringstream result;
    stack<char> operators;

    int i = 0;
    while (i < infix.length()) {
        if (isspace(infix[i])) {
            i++;
        } else if (isdigit(infix[i])) {
            string operand;
            while (i < infix.length() && isdigit(infix[i])) {
                operand += infix[i];
                i++;
            }
            result << operand << " ";
        } else if (infix[i] == '(') {
            operators.push('(');
            i++;
        } else if (infix[i] == ')') {
            while (!operators.empty()) {
                char top =  operators.top();
                operators.pop();
                if (top == '(') {
                    break;
                }
                result << top << " ";
            }
            i++;
        } else {
            do {
                if (operators.empty() || (precedence(infix[i]) >= precedence(operators.top()))) {
                    operators.push(infix[i++]);
                    break;
                }
                result << operators.top() << " ";
                operators.pop();
            } while (true);
        }
    }

    while (!operators.empty()) {
        result << operators.top() << " ";
        operators.pop();
    }

    return result.str();
}

double eval(char op, double operand1, double operand2) {
    assert(op == '^' || op == '*' || op == '/' || op == '+' || op == '-');
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '^':
            return pow(operand1,operand2);
    }
    return 0;
}

double evaluatePostfix(string postfix) {
    stack<double> operands;

    int i = 0;
    while (i < postfix.length()) {
        if (isspace(postfix[i])) {
            i++;
        } else if (isdigit(postfix[i])) {
            string operand;
            while (i < postfix.length() && isdigit(postfix[i])) {
                operand += postfix[i];
                i++;
            }
            operands.push(stoi(operand));
        } else {
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();
            double result = eval(postfix[i], operand1, operand2);
            operands.push(result);
            i++;
        }
    }

    assert(operands.size() == 1);
    return operands.top();
}


int main() {
    // cout << evaluatePostfix(convertInfixToPostfix("3*4 / 2 ^ 2 ")) << endl;
    cout << evaluatePostfix(convertInfixToPostfix("(1+(4+5+2)-3)+(6+8)")) << endl;

    return 0;
}

