#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    double a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Addition = " << a + b << '\n';
    cout << "Subtraction = " << a - b << '\n';
    cout << "Multiplication = " << a * b << '\n';
    if (b != 0) {
        cout << "Division = " << a / b << '\n';
        cout << "Remainder (integers) = "
             << static_cast<int>(a) % static_cast<int>(b) << '\n';
    } else {
        cout << "Division and remainder by zero are not allowed.\n";
    }

    cout << "Square root of first number = " << sqrt(a) << '\n';
    cout << "First number squared = " << pow(a, 2) << '\n';
    cout << "Smaller number = " << min(a, b) << '\n';
    cout << "Larger number = " << max(a, b) << '\n';

    double radius;
    cout << "Enter radius of a circle: ";
    cin >> radius;
    cout << "Circle area = " << 3.14159 * radius * radius << '\n';
    return 0;
}