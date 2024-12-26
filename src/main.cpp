#include <iostream>
#include "../includes/role.h"
#include "../includes/owner_menu.h"
#include "../includes/staff_menu.h"
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