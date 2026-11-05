#include <iostream>
using namespace std;

double average(double a, double b, double c) {
    return (a + b + c) / 3.0;
}
char grade(double avg) {
    if (avg >= 80) return 'A';
    if (avg >= 70) return 'B';
    if (avg >= 60) return 'C';
    if (avg >= 50) return 'D';
    return 'F';
}
bool isPass(double avg) { return avg >= 50; }
void printReport(double avg) {
    cout << "Average: " << avg << "\nGrade: " << grade(avg)
         << "\nResult: " << (isPass(avg) ? "PASS" : "FAIL") << '\n';
}

int main() {
    double a, b, c;
    cout << "Enter three marks: ";
    cin >> a >> b >> c;
    if (a < 0 || a > 100 || b < 0 || b > 100 || c < 0 || c > 100) {
        cout << "Marks must be between 0 and 100.\n";
        return 1;
    }
    double avg = average(a, b, c);
    printReport(avg);
    return 0;
}