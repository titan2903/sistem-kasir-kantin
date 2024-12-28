#include <iostream>
#include <limits>
using namespace std;

int selectRole() {
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                                                   " << endl;
    cout << "Selamat Datang dan Tolong Pilih Role Mu!           " << endl;
    cout << "                                                   " << endl;
    cout << "===================================================" << endl;

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
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid. Harap masukkan angka." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
}