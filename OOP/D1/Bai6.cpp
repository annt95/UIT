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

class Student {
public:
    void read() {
        std::cin >> id;
        std::cin.ignore();
        std::getline(std::cin, name);
        birthDate.input();
        std::cin >> averageScore;
    }

    void print() const {
        std::cout << id << " | " << name << " | Birth date: ";
        birthDate.print();
        std::cout << " | Average: " << averageScore << '\n';
    }

    bool wasBornBefore(Student other) {
        return birthDate.isEarlierThan(other.birthDate);
    }

private:
    std::string id;
    std::string name;
    Date birthDate;
    double averageScore = 0.0;
};

int main() {
    Student first;
    Student second;
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
