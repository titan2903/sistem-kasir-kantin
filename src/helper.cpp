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

void medianWaktuProduksiHistoris(const string& tanggal, double waktu) {
    bool updated = false; //! Flag untuk menandai apakah ada pembaruan

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (historis_tanggal_layanan[i] == tanggal) {
            //! Jika historis_tanggal_layanan sama dengan tanggal, perbarui rata-rata
            rata_rata_waktu_layanan[i] = waktu;
            updated = true; //! Tandai bahwa pembaruan telah dilakukan
            break; //! Keluar dari loop setelah pembaruan
        }
    }

    //! Jika tidak ada pembaruan, cari tempat kosong untuk menambahkan data baru
    if (!updated) {
        for (int i = 0; i < MAX_ITEMS; i++) {
            if (historis_tanggal_layanan[i].empty()) { //! Cek apakah tempat kosong
                historis_tanggal_layanan[i] = tanggal; //! Tambahkan tanggal
                rata_rata_waktu_layanan[i] = waktu; //! Tambahkan waktu
                currentItemMedianWaktuProduksiHistoris++; //! Tambahkan jumlah item
                break; //! Keluar dari loop setelah menambahkan data
            }
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