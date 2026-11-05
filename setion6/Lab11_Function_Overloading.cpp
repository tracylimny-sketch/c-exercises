#include <iostream>
#include <iomanip>
using namespace std;

double area(double side) { return side * side; }
double area(double length, double width) { return length * width; }
double circleArea(double radius) { return 3.14159 * radius * radius; }

void printResult(double value) {
    cout << fixed << setprecision(2) << "Area = " << value << '\n';
}
void printResult(const string& shape, double value) {
    cout << fixed << setprecision(2) << shape << " area = " << value << '\n';
}

int main() {
    int choice;
    double x, y;
    cout << "1. Square  2. Rectangle  3. Circle\nChoose: ";
    cin >> choice;
    if (choice == 1) {
        cout << "Enter side: "; cin >> x;
        printResult("Square", area(x));
    } else if (choice == 2) {
        cout << "Enter length and width: "; cin >> x >> y;
        printResult("Rectangle", area(x, y));
    } else if (choice == 3) {
        cout << "Enter radius: "; cin >> x;
        printResult("Circle", circleArea(x));
    } else cout << "Invalid choice.\n";
    return 0;
}