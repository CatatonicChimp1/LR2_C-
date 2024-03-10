#include <iostream>
#include <stack>
#include <sstream>

int evaluatePostfix(const std::string& expression) {
    std::stack<int> operands;

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
            operands.push(std::stoi(token));
        }
        else {
            int operand2 = operands.top();
            operands.pop();

            int operand1 = operands.top();
            operands.pop();

            switch (token[0]) {
            case '+':
                operands.push(operand1 + operand2);
                break;
            case '-':
                operands.push(operand1 - operand2);
                break;
            case '*':
                operands.push(operand1 * operand2);
                break;
            }
        }
    }

    return operands.top();
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::cout << evaluatePostfix(input) << std::endl;

    return 0;
}
