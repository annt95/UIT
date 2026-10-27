#include <iostream>
#include <string>

class Date {
private:
    int day_;
    int month_;
    int year_;

public:
    void input() {
        char slash;
        std::cin >> day_ >> slash >> month_ >> slash >> year_;
    }

    void print() const {
        std::cout << day_ << '/' << month_ << '/' << year_;
    }

    bool isEarlierThan(Date other) {
        if (year_ != other.year_) {
            return year_ < other.year_;
        }
        if (month_ != other.month_) {
            return month_ < other.month_;
        }
        return day_ < other.day_;
    }
};

class Employee {
public:
    void read() {
        std::cin >> id;
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cin >> gender;
        birthDate.input();
    }

    void print() const {
        std::cout << id << " | " << name << " | " << gender << " | Birth date: ";
        birthDate.print();
        std::cout << '\n';
    }

    bool wasBornBefore(Employee other) {
        return birthDate.isEarlierThan(other.birthDate);
    }

private:
    std::string id;
    std::string name;
    std::string gender;
    Date birthDate;
};

int main() {
    Employee first;
    Employee second;
    first.read();
    second.read();

    if (first.wasBornBefore(second)) {
        second.print();
    } else if (second.wasBornBefore(first)) {
        first.print();
    } else {
        first.print();
        second.print();
    }
    return 0;
}
