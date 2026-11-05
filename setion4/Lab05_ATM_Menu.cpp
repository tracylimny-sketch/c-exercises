#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double balance = 25000.0, amount;
    int choice;

    do {
        cout << "\n===== ATM MENU =====\n";
        cout << "1. Deposit\n2. Withdraw\n3. Check balance\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Amount to deposit: ";
                cin >> amount;
                if (amount > 0) {
                    balance += amount;
                    cout << "Deposit successful.\n";
                } else cout << "Amount must be positive.\n";
                break;
            case 2:
                cout << "Amount to withdraw: ";
                cin >> amount;
                if (amount <= 0) cout << "Amount must be positive.\n";
                else if (amount > balance) cout << "Insufficient balance.\n";
                else {
                    balance -= amount;
                    cout << "Withdrawal successful.\n";
                }
                break;
            case 3:
                cout << fixed << setprecision(2)
                     << "Current balance: " << balance << " FCFA\n";
                break;
            case 4:
                cout << "Thank you for using the ATM.\n";
                break;
            default:
                cout << "Invalid menu option.\n";
        }
    } while (choice != 4);
    return 0;
}