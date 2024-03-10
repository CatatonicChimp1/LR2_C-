#include <iostream>
#include <vector>
#include <map>
#include <sstream>

int main() {
    std::map<int, std::vector<std::string>> students;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        int classNum;
        std::string lastName;

        if (iss >> classNum >> lastName) {
            students[classNum].push_back(lastName);
        }
    }

    // Выводим учеников 9 класса
    for (const std::string& student : students[9]) {
        std::cout << "9 " << student << std::endl;
    }

    // Выводим учеников 10 класса
    for (const std::string& student : students[10]) {
        std::cout << "10 " << student << std::endl;
    }

    // Выводим учеников 11 класса
    for (const std::string& student : students[11]) {
        std::cout << "11 " << student << std::endl;
    }

    return 0;
}
