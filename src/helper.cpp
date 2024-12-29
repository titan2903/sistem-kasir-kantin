#include "../includes/helper.h"
#include <iostream>
#include "../includes/menu_data.h"
using namespace std;

void updatePenguranganStokOtomatis(const string& menu, int pengurangan) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] == menu) {
            jumlah_stock[i] -= pengurangan;
        }
    }
}

void updatePenambahanMenuTerjualOtomatis(const string& menu, int penambahan) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] == menu) {
            menu_terjual[i] += penambahan;
            tanggal_terjual[i] = time(0);
        }
    }
}

bool foundExistingMenuPesanan(const string& menu) {
    bool found = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] == menu) {
            found = true;
        }
    }

    return found;
}

bool checkStockMoreThenZero(const string& menu) {
    bool found = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] == menu && jumlah_stock[i] > 0) {
             found = true;
        }
    }

    return found;
}

bool foundExistingStockMenu(const string& menu) {
    bool found = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu_terdaftar[i] == menu) {
             found = true;
        }
    }

    return found;
}

int calculateTimeDifferenceInMinutes(time_t akhir, time_t awal) {
    return difftime(akhir, awal) / 60;
}