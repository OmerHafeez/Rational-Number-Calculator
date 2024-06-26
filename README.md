# RationalNumberCalculator

A C++ program to perform various operations on rational numbers, including addition, subtraction, multiplication, division, and comparison.

## Features

- Input and store rational numbers
- Perform arithmetic operations (addition, subtraction, multiplication, division)
- Compare rational numbers (equality, less than or equal, greater than or equal)
- Increment and decrement operators
- Simplify rational numbers

## Classes

### Rational

The `Rational` class represents a rational number with a numerator and a denominator. It includes the following features:

- Default and parameterized constructors
- Arithmetic operators: `+`, `-`, `*`, `/`
- Comparison operators: `==`, `!=`, `<=`, `>=`
- Increment and decrement operators: `++`, `--` (both prefix and postfix)
- Simplification of rational numbers
- Input and output stream operators: `>>`, `<<`

## Usage

### Input and Output

The program allows users to input two rational numbers and then perform various operations based on user choices from the menu.

### Menu Options

1. Enter values for Fraction 1
2. Enter values for Fraction 2
3. Perform Addition
4. Perform Subtraction
5. Perform Multiplication
6. Perform Division
7. Check Equality
8. Check Less Than or Equal
9. Check Greater Than or Equal
0. Exit

## Example

```cpp
#include <iostream>
#include "Rational.h"

using namespace std;

int main() {
    Rational frac1, frac2;
    int choice = -1;

    cout << "Enter values for Fraction 1:" << endl;
    cin >> frac1;

    cout << "Enter values for Fraction 2:" << endl;
    cin >> frac2;

    while (choice != 0) {
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
