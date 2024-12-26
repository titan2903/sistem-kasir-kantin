#include <iostream>
#include "../includes/menu_data.h"
using namespace std;

void rushHourManagement();
void foodManagement();
void pengelolaanJamSibuk();
void kapasitasLayanan();
void kontrolStok();
void analisisMenu();

//! Pengelolaan Jam Sibuk
int hitungTotalPesananPerPeriodeIstirahat();
int lihatStokMakananMenjelangIstirahat();

//! Kapasitas Layanan
int lihatRataRataWaktuLayananPerHari();
int lihatJumlahPesananPerJenisMakanan();

//! Kontrol Stok
int updateStokMakananTersedia();
int lihatSisaStokPerMenu();

//! Analisis Menu
int lihatTotalPenjualanPerMenu();
int lihatMenuYangPalingLakuPerHari();

void ownerMenu() {
    int choice = 0;
    while (true) {
        cout << "\nMenu Owner:" << endl;
        cout << "1. Rush Hour Management" << endl;
        cout << "2. Food Management" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                rushHourManagement();
                break;
            case 2:
                foodManagement();
                break;
            case 3:
                cout << "Exiting Owner Menu." << endl;
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

void rushHourManagement() {
    int choice = 0;
    while (true) {
        cout << "\nRush Hour Management:" << endl;
        cout << "1. Pengelolaan Jam Sibuk" << endl;
        cout << "2. Kapasitas Layanan" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pengelolaanJamSibuk();
                break;
            case 2:
                kapasitasLayanan();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

void foodManagement() {
    int choice = 0;
    while (true) {
        cout << "\nFood Management:" << endl;
        cout << "1. Kontrol Stok" << endl;
        cout << "2. Analisis Menu" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                kontrolStok();
                break;
            case 2:
                analisisMenu();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

void pengelolaanJamSibuk() {
    int choice = 0;
    while (true) {
        cout << "\nPengelolaan Jam Sibuk:" << endl;
        cout << "1. Lihat total pesanan per periode istirahat" << endl;
        cout << "2. Lihat stok makanan menjelang istirahat" << endl;
        cout << "3. Back to Rush Hour Management" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Total pesanan per istirahat: " << hitungTotalPesananPerPeriodeIstirahat() << endl;
                break;
            case 2:
                lihatStokMakananMenjelangIstirahat();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

int hitungTotalPesananPerPeriodeIstirahat() {
    return 0;
}

int lihatStokMakananMenjelangIstirahat() {
    cout << "Stock Makanan Menjelang Istirahat:" << endl;
    return 0;
}

void kapasitasLayanan() {
    int choice = 0;
    while (true) {
        cout << "\nKapasitas Layanan:" << endl;
        cout << "1. Lihat rata-rata waktu layanan per hari" << endl;
        cout << "2. Lihat jumlah pesanan per jenis makanan" << endl;
        cout << "3. Back to Rush Hour Management" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Rata-rata waktu layanan per hari: " << lihatRataRataWaktuLayananPerHari() << endl;
                break;
            case 2:
                lihatJumlahPesananPerJenisMakanan();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

int lihatRataRataWaktuLayananPerHari() {
    return 0;
}

int lihatJumlahPesananPerJenisMakanan() {
    cout << "Jumlah pesanan per jenis makanan:" << endl;
    return 0;
}

void kontrolStok() {
    int choice = 0;
    while (true) {
        cout << "\nKontrol Stok:" << endl;
        cout << "1. Update stok makanan tersedia" << endl;
        cout << "2. Lihat sisa stok per menu" << endl;
        cout << "3. Back to Food Management" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                updateStokMakananTersedia();
                break;
            case 2:
                lihatSisaStokPerMenu();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

int updateStokMakananTersedia() {
    //! Implement the functionality here
    return 0;
}

int lihatSisaStokPerMenu() {
    cout << "Stok Per Menu saat ini:" << endl;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "") {
            cout << "Menu: " << nama_menu[i] << ", Jumlah: " << jumlah_stock[i] << ", Harga: " <<  harga[i] << endl;
        }
    }
    return 0;
}

void analisisMenu() {
    int choice = 0;
    while (true) {
        cout << "\nAnalisis Menu:" << endl;
        cout << "1. Lihat total penjualan per menu" << endl;
        cout << "2. Lihat menu yang paling laku per hari" << endl;
        cout << "3. Back to Food Management" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lihatTotalPenjualanPerMenu();
                break;
            case 2:
                lihatMenuYangPalingLakuPerHari();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

int lihatTotalPenjualanPerMenu() {
    cout << "Total penjualan per menu:" << endl;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if(nama_menu[i] != "") {
            cout << "Menu: " << nama_menu[i] << ", Total Penjualan: " << menu_terjual[i] << endl;
        }
    }
    return 0;
}

int lihatMenuYangPalingLakuPerHari() {
    cout << "Menu yang paling laku per hari:" << endl;
    //! Implement the functionality here
    return 0;
}