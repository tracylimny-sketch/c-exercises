#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number for its multiplication table: ";
    cin >> n;
    for (int i = 1; i <= 12; ++i)
        cout << n << " x " << i << " = " << n * i << '\n';

    cout << "\nEnter n to calculate sum from 1 to n: ";
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) sum += i;
    cout << "Sum = " << sum << '\n';

    cout << "\nNumbers from 1 to 20 (skip multiples of 3):\n";
    for (int i = 1; i <= 20; ++i) {
        if (i % 3 == 0) continue;
        cout << i << " ";
    }

    cout << "\n\nStop at the first number divisible by both 5 and 7:\n";
    for (int i = 1; i <= 100; ++i) {
        if (i % 5 == 0 && i % 7 == 0) {
            cout << "Stopped at " << i << '\n';
            break;
        }
    }

    cout << "\nThe same multiplication table using while:\n";
    int i = 1;
    while (i <= 12) {
        cout << n << " x " << i << " = " << n * i << '\n';
        ++i;
    }
    return 0;
}