#include <iostream>

class Fraction {
private:
    int numerator = 0;
    int denominator = 1;

    void simplify() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        int first = numerator;
        if (first < 0) {
            first = -first;
        }
        int second = denominator;

        while (second != 0) {
            int remainder = first % second;
            first = second;
            second = remainder;
        }

        if (first != 0) {
            numerator /= first;
            denominator /= first;
        }
    }

public:
    void input() {
        std::cin >> numerator >> denominator;
        while (denominator == 0) {
            std::cout << "Denominator cannot be zero. Enter again: ";
            std::cin >> denominator;
        }
        simplify();
    }

    void output() {
        std::cout << numerator;
        if (denominator != 1) {
            std::cout << '/' << denominator;
        }
    }

    bool isGreaterThan(Fraction other) {
        return numerator * other.denominator > other.numerator * denominator;
    }

    bool isZero() {
        return numerator == 0;
    }

    Fraction operator+(Fraction other) {
        Fraction result;
        result.numerator = numerator * other.denominator + other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

    Fraction operator-(Fraction other) {
        Fraction result;
        result.numerator = numerator * other.denominator - other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

    Fraction operator*(Fraction other) {
        Fraction result;
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

    Fraction operator/(Fraction other) {
        Fraction result;
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        result.simplify();
        return result;
    }
};

int main() {
    int choice;
    std::cout << "1. Simplify a fraction\n"
              << "2. Compare two fractions\n"
              << "3. Calculate with two fractions\n";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            Fraction value;
            value.input();
            value.output();
            std::cout << '\n';
            break;
        }
        case 2: {
            Fraction first;
            Fraction second;
            first.input();
            second.input();

            if (first.isGreaterThan(second)) {
                first.output();
            } else {
                second.output();
            }
            std::cout << '\n';
            break;
        }
        case 3: {
            Fraction first;
            Fraction second;
            first.input();
            second.input();

            if (second.isZero()) {
                std::cout << "Cannot divide by zero\n";
                break;
            }

            Fraction result;
            std::cout << "sum: ";
            result = first + second;
            result.output();
            std::cout << "\ndifference: ";
            result = first - second;
            result.output();
            std::cout << "\nproduct: ";
            result = first * second;
            result.output();
            std::cout << "\nquotient: ";
            result = first / second;
            result.output();
            std::cout << '\n';
            break;
        }
        default:
            std::cout << "Invalid choice\n";
    }
    return 0;
}