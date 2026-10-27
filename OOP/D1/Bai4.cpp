#include <iomanip>
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

    bool isLeapYear() {
        return year_ % 400 == 0 || (year_ % 4 == 0 && year_ % 100 != 0);
    }

    int daysInMonth() {
        if (month_ == 2) {
            if (isLeapYear()) {
                return 29;
            }
            return 28;
        }
        if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) {
            return 30;
        }
        return 31;
    }

    bool isValid() {
        if (year_ < 1 || month_ < 1 || month_ > 12 || day_ < 1) {
            return false;
        }
        return day_ <= daysInMonth();
    }

    void nextDay() {
        if (day_ < daysInMonth()) {
            day_++;
        } else if (month_ < 12) {
            day_ = 1;
            month_++;
        } else {
            day_ = 1;
            month_ = 1;
            year_++;
        }
    }

    void print() {
        std::cout << day_ << '/' << month_ << '/' << year_;
    }
};

class Student {
public:
    void read() {
        std::cin >> id;
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cin >> mathScore >> literatureScore;
    }

    void print() const {
        std::cout << id << '\n'
                  << name << '\n'
                  << "Math: " << mathScore << '\n'
                  << "Literature: " << literatureScore << '\n'
                  << "Average: " << std::fixed << std::setprecision(2) << average() << '\n';
    }

private:
    double average() const {
        return (mathScore + literatureScore) / 2.0;
    }

    std::string id;
    std::string name;
    double mathScore = 0.0;
    double literatureScore = 0.0;
};

void runNextDay() {
    Date date;
    date.input();

    if (!date.isValid()) {
        std::cout << "Invalid date\n";
        return;
    }
    date.nextDay();
    date.print();
    std::cout << '\n';
}

void runStudent() {
    Student student;
    student.read();
    student.print();
}

int main() {
    int choice;
    std::cout << "1. Next day\n"
              << "2. Student information\n";
    std::cin >> choice;

    switch (choice) {
        case 1:
            runNextDay();
            break;
        case 2:
            runStudent();
            break;
        default:
            std::cout << "Invalid choice\n";
    }
    return 0;
}