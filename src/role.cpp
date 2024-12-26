#include <iostream>
#include <limits>
using namespace std;

int selectRole() {
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                                               " << endl;
    cout << " Welcome and Please Select Your Role!          " << endl;
    cout << "                                               " << endl;
    cout << "===============================================" << endl;

    int choice = 0;
    while (true) {
        cout << "\nSelect your role:" << endl;
        cout << "1. Owner" << endl;
        cout << "2. Staff" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        if (cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            if (choice >= 1 && choice <= 3) {
                return choice;
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
        } else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
}