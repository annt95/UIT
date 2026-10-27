#include <iostream>
#include <string>

class Employee {
private:
    std::string id;
    std::string fullName;
    std::string gender;
    int birthYear;

public:
    void input() {
        std::cout << "Employee ID: ";
        std::getline(std::cin, id);

        std::cout << "Full name: ";
        std::getline(std::cin, fullName);

        std::cout << "Gender: ";
        std::getline(std::cin, gender);

        std::cout << "Birth year: ";
        std::cin >> birthYear;
    }

    void output() {
        std::cout << "Employee information:\n";
        std::cout << "ID: " << id << '\n';
        std::cout << "Full name: " << fullName << '\n';
        std::cout << "Gender: " << gender << '\n';
        std::cout << "Birth year: " << birthYear << '\n';
    }
};

int main() {
    Employee employee;
    employee.input();
    employee.output();
    return 0;
}