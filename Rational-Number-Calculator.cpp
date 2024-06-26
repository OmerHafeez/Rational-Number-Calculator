#include <iostream>

using namespace std;

class Rational {
private:
    int nume, denume;

public:
    Rational() : nume(0), denume(1) { }

    Rational(int nume, int denume) : nume(nume), denume(denume) { }

    static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    static void simplify(int& numerator, int& denominator) {
        if (numerator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }

    Rational operator+(const Rational& other) const {
        int resultantNumerator = (nume * other.denume) + (other.nume * denume);
        int resultantDenominator = denume * other.denume;
        simplify(resultantNumerator, resultantDenominator);
        return Rational(resultantNumerator, resultantDenominator);
    }

    Rational operator-(const Rational& other) const {
        int resultantNumerator = (nume * other.denume) - (other.nume * denume);
        int resultantDenominator = denume * other.denume;
        simplify(resultantNumerator, resultantDenominator);
        return Rational(resultantNumerator, resultantDenominator);
    }

    Rational operator*(const Rational& other) const {
        int resultantNumerator = nume * other.nume;
        int resultantDenominator = denume * other.denume;
        simplify(resultantNumerator, resultantDenominator);
        return Rational(resultantNumerator, resultantDenominator);
    }

    Rational operator/(const Rational& other) const {
        int resultantNumerator = nume * other.denume;
        int resultantDenominator = denume * other.nume;
        simplify(resultantNumerator, resultantDenominator);
        return Rational(resultantNumerator, resultantDenominator);
    }

    bool operator==(const Rational& other) const {
        return (nume == other.nume) && (denume == other.denume);
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    bool operator<=(const Rational& other) const {
        int crossProduct1 = nume * other.denume;
        int crossProduct2 = other.nume * denume;
        return crossProduct1 <= crossProduct2;
    }

    bool operator>=(const Rational& other) const {
        int crossProduct1 = nume * other.denume;
        int crossProduct2 = other.nume * denume;
        return crossProduct1 >= crossProduct2;
    }

    Rational& operator++() {
        nume++;
        denume++;
        simplify(nume, denume);
        return *this;
    }

    Rational operator++(int) {
        Rational temp(*this);
        nume++;
        denume++;
        simplify(nume, denume);
        return temp;
    }

    Rational& operator--() {
        nume--;
        denume--;
        simplify(nume, denume);
        return *this;
    }

    Rational operator--(int) {
        Rational temp(*this);
        nume--;
        denume--;
        simplify(nume, denume);
        return temp;
    }

    Rational& operator=(const Rational& other) {
        if (this != &other) {
            nume = other.nume;
            denume = other.denume;
        }
        return *this;
    }

    Rational& operator+=(const Rational& other) {
        *this = *this + other;
        return *this;
    }

    Rational& operator-=(const Rational& other) {
        *this = *this - other;
        return *this;
    }

    Rational& operator*=(const Rational& other) {
        *this = *this * other;
        return *this;
    }

    Rational& operator/=(const Rational& other) {
        *this = *this / other;
        return *this;
    }

    friend istream& operator>>(istream& in, Rational& rational);
    friend ostream& operator<<(ostream& out, const Rational& rational);
};

istream& operator>>(istream& in, Rational& rational) {
    cout << "Enter numerator: ";
    in >> rational.nume;

    cout << "Enter denominator (must be positive): ";
    in >> rational.denume;

    if (rational.denume <= 0) {
        cout << "Invalid denominator. Setting denominator to 1." << endl;
        rational.denume = 1;
    }

    Rational::simplify(rational.nume, rational.denume);

    return in;
}

ostream& operator<<(ostream& out, const Rational& rational) {
    out << rational.nume << "/" << rational.denume;
    return out;
}

int main() {
    Rational frac1, frac2;
    int choice= -1;

    cout << "Enter values for Fraction 1:" << endl;
    cin >> frac1;

    cout << "Enter values for Fraction 2:" << endl;
    cin >> frac2;
    while (choice !=0) {
        cout << endl;
        cout << endl;
        cout << "Rational Number Calculator Menu:" << endl;
        cout << "1. Enter values for Fraction 1" << endl;
        cout << "2. Enter values for Fraction 2" << endl;
        cout << "3. Perform Addition" << endl;
        cout << "4. Perform Subtraction" << endl;
        cout << "5. Perform Multiplication" << endl;
        cout << "6. Perform Division" << endl;
        cout << "7. Check Equality" << endl;
        cout << "8. Check Less Than or Equal" << endl;
        cout << "9. Check Greater Than or Equal" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter values for Fraction 1:" << endl;
            cin >> frac1;
            break;

        case 2:
            cout << "Enter values for Fraction 2:" << endl;
            cin >> frac2;
            break;

        case 3:
            cout << "Result obtained after Addition is " << (frac1 + frac2) << endl;
            break;

        case 4:
            cout << "Result obtained after Subtraction is " << (frac1 - frac2) << endl;
            break;

        case 5:
            cout << "Result obtained after Multiplication is " << (frac1 * frac2) << endl;
            break;

        case 6:
            cout << "Result obtained after Division is " << (frac1 / frac2) << endl;
            break;

        case 7:
            if (frac1 == frac2)
                cout << "Frac1 and Frac2 are Equal" << endl;
            else
                cout << "Frac1 and Frac2 are Not Equal" << endl;
            break;

        case 8:
            if (frac1 <= frac2)
                cout << "Fraction 1 is less than or Equal to Fraction 2 " << endl;
            else
                cout << " Fraction 1 is Greater than Fraction 2 " << endl;
            break;

        case 9:
            if (frac1 >= frac2)
                cout << "Fraction 1 is Greater than or Equal to Fraction 2 " << endl;
            else
                cout << "Fraction 2 is Less than Fraction 1 " << endl;
            break;

        case 0:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
