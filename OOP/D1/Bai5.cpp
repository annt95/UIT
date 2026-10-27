#include <iomanip>
#include <iostream>
#include <string>

class Student {
public:
    void input() {
        std::cin >> id;
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cin >> mathScore >> literatureScore;
    }

    double getAverage() {
        return (mathScore + literatureScore) / 2.0;
    }

    void print() {
        std::cout << id << " | " << name
                  << " | Math: " << mathScore
                  << " | Literature: " << literatureScore
                  << " | Average: " << std::fixed << std::setprecision(2)
                  << getAverage() << '\n';
    }

private:
    std::string id;
    std::string name;
    double mathScore = 0.0;
    double literatureScore = 0.0;
};

int main() {
    Student first;
    Student second;
    first.input();
    second.input();

    double firstAverage = first.getAverage();
    double secondAverage = second.getAverage();
    if (firstAverage >= secondAverage) {
        first.print();
    }
    if (secondAverage >= firstAverage) {
        second.print();
    }
    return 0;
}
