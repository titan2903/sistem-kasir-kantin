#include "../includes/helper.h"
#include <iostream>
#include "../includes/menu_data.h"  // Adjust path if incorrect
using namespace std;

void updatePenguranganStokOtomatis(const string& menu, int pengurangan) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] == menu) {
            jumlah_stock[i] -= pengurangan;
        }
    }
}
