#include <iostream>
using namespace std;

int selectRole() {
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                                               " << endl;
    cout << " Welcome and Please Select Your Role!          " << endl;
    cout << "                                               " << endl;
    cout << "===============================================" << endl;
    int choice = 0;
    while (true) {
        cout << "Select your role:" << endl;
        cout << "1. Owner" << endl;
        cout << "2. Staff" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3) {
            return choice;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}