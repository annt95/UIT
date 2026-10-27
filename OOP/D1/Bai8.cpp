#include <iostream>
#include <string>
#include <vector>

class Employee {
public:
    void input() {
        std::string baseSalaryText;
        std::string bonusText;

        std::getline(std::cin, id, '|');
        std::getline(std::cin, name, '|');
        std::getline(std::cin, department, '|');
        std::getline(std::cin, baseSalaryText, '|');
        std::getline(std::cin, bonusText);
        baseSalary = std::stoll(baseSalaryText);
        bonus = std::stoll(bonusText);
    }

    long long netSalary() {
        return baseSalary + bonus;
    }

    void print() {
        std::cout << id << " | " << name << " | " << department
                  << " | base: " << baseSalary
                  << " | bonus: " << bonus
                  << " | net: " << netSalary() << '\n';
    }

    long long getBaseSalary() {
        return baseSalary;
    }

    long long getBonus() {
        return bonus;
    }

    bool shouldComeAfter(Employee other) {
        if (department != other.department) {
            return department > other.department;
        }
        return id < other.id;
    }

private:
    std::string id;
    std::string name;
    std::string department;
    long long baseSalary = 0;
    long long bonus = 0;
};

int main() {
    int count;
    std::cin >> count;
    std::cin.ignore();

    std::vector<Employee> employees(count);
    for (int i = 0; i < count; ++i) {
        employees[i].input();
    }

    long long totalNetSalary = 0;
    long long minimumBaseSalary = 0;
    int bonusCount = 0;
    if (count > 0) {
        minimumBaseSalary = employees[0].getBaseSalary();
    }
    for (int i = 0; i < count; ++i) {
        Employee employee = employees[i];
        totalNetSalary += employee.netSalary();
        if (employee.getBaseSalary() < minimumBaseSalary) {
            minimumBaseSalary = employee.getBaseSalary();
        }
        if (employee.getBonus() >= 1200000) {
            ++bonusCount;
        }
    }

    std::cout << "Total net salary: " << totalNetSalary << '\n';
    std::cout << "Employees with minimum base salary:\n";
    for (int i = 0; i < count; ++i) {
        if (employees[i].getBaseSalary() == minimumBaseSalary) {
            employees[i].print();
        }
    }

    std::cout << "Bonus >= 1200000: " << bonusCount << '\n';
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (employees[j].shouldComeAfter(employees[j + 1])) {
                Employee temporary = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temporary;
            }
        }
    }

    std::cout << "Sorted employees:\n";
    for (int i = 0; i < count; ++i) {
        employees[i].print();
    }
    return 0;
}
