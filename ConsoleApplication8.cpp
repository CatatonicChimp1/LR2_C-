#include <iostream>
#include <stack>

bool isBalanced(const std::string& sequence) {
    std::stack<char> brackets;

    for (char bracket : sequence) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            brackets.push(bracket);
        }
        else {
            if (brackets.empty()) {
                return false; // Несбалансировано: закрывающая скобка без соответствующей открывающей
            }

            char topBracket = brackets.top();
            brackets.pop();

            if ((bracket == ')' && topBracket != '(') ||
                (bracket == ']' && topBracket != '[') ||
                (bracket == '}' && topBracket != '{')) {
                return false; // Несбалансировано: неправильная пара скобок
            }
        }
    }

    return brackets.empty(); // Сбалансировано, если все открывающие скобки были закрыты
}

int main() {
    std::string input;
    std::cin >> input;

    if (isBalanced(input)) {
        std::cout << "yes" << std::endl;
    }
    else {
        std::cout << "no" << std::endl;
    }

    return 0;
}
