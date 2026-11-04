#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

    double num1, num2;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "\n========== CALCULATOR ==========" << endl;

    cout << "Sum: " << num1 + num2 << endl;

    cout << "Difference: " << num1 - num2 << endl;

    cout << "Product: " << num1 * num2 << endl;

    if (num2 != 0) {
        cout << "Quotient: " << num1 / num2 << endl;
    }
    else {
        cout << "Division by zero is not allowed." << endl;
    }

    int a, b;

    cout << "\nEnter two integers: ";
    cin >> a >> b;

    if (b != 0) {
        cout << "Remainder: " << a % b << endl;
    }
    else {
        cout << "Remainder cannot be calculated because divisor is zero." << endl;
    }

    cout << "\nSquare root of first number: "
         << sqrt(num1) << endl;

    cout << "Power of first number squared: "
         << pow(num1, 2) << endl;

    cout << "Minimum number: "
         << min(num1, num2) << endl;

    cout << "Maximum number: "
         << max(num1, num2) << endl;

    cout << "================================" << endl;

    return 0;
}
