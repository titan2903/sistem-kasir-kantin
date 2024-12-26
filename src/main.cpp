#include <iostream>
#include <string>
#include "../includes/role.h" //! Include the header file
#include "../includes/owner_menu.h" //! Include the header file
#include "../includes/staff_menu.h" //! Include the header file
#include <limits>
using namespace std;

int main() {
    int role;
    while (true) {
        role = selectRole();
        switch (role) {
            case 1:
                ownerMenu();
                break;
            case 2:
                staffMenu();
                break;
            case 3:
                cout << "Thank You for Using Our Cashier System." << endl;
                return 0;
            default:
                break;
        }
    }
}