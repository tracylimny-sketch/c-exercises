#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n <= 1) return 1;       // Base case
    return n * factorial(n - 1);
}
long long recursiveSum(int n) {
    if (n <= 0) return 0;       // Base case
    return n + recursiveSum(n - 1);
}

int main() {
    int n;
    cout << "Enter a number from 0 to 20 for factorial: ";
    cin >> n;
    if (n < 0 || n > 20) {
        cout << "Please enter a value between 0 and 20.\n";
        return 1;
    }
    cout << n << "! = " << factorial(n) << '\n';
    cout << "Recursive sum from 1 to " << n << " = "
         << recursiveSum(n) << '\n';
    return 0;
}