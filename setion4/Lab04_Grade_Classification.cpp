#include <iostream>
using namespace std;

int main() {
    char again;
    do {
        double mark;
        cout << "Enter mark (0-100): ";
        cin >> mark;

        if (mark < 0 || mark > 100) {
            cout << "Invalid mark. Enter a value from 0 to 100.\n";
        } else {
            char grade;
            if (mark >= 80) grade = 'A';
            else if (mark >= 70) grade = 'B';
            else if (mark >= 60) grade = 'C';
            else if (mark >= 50) grade = 'D';
            else grade = 'F';

            cout << "Grade: " << grade << '\n';
            cout << (mark >= 50 ? "PASS\n" : "FAIL\n");
        }
        cout << "Check another mark? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
    return 0;
}