#include <iostream>
#include <string>
#include "../includes/menu_data.h"
using namespace std;

//! Function prototypes for staff operations
void staffMenu();
void serviceOperation();
void kitchenOperation();
void prosesPenjualan();
void persiapanMenu();
void produksiMenu();
void kontrolKualitas();

//! Proses Penjualan
int inputPesananPelanggan();
int lihatStatusStok();

//! Persiapan Menu
int inputStokAwalPerMenu();
int updatePenguranganStokOtomatis();

//! Produksi Menu
int catatWaktuProduksiMenu();
int inputPorsiStandarPerMenu();

//! Kontrol Kualitas
int checklistMenuSiapJual();

void staffMenu() {
    int choice = 0;
    while (true) {
        cout << "\nMenu Staff:" << endl;
        cout << "1. Service Operation" << endl;
        cout << "2. Kitchen Operation" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                serviceOperation();
                break;
            case 2:
                kitchenOperation();
                break;
            case 3:
                cout << "Exiting Staff Menu." << endl;
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

void serviceOperation() {
    int choice = 0;
    while (true) {
        cout << "\nService Operation:" << endl;
        cout << "1. Proses Penjualan" << endl;
        cout << "2. Persiapan Menu" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                prosesPenjualan();
                break;
            case 2:
                persiapanMenu();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

void kitchenOperation() {
    int choice = 0;
    while (true) {
        cout << "\nKitchen Operation:" << endl;
        cout << "1. Produksi Menu" << endl;
        cout << "2. Kontrol Kualitas" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                produksiMenu();
                break;
            case 2:
                kontrolKualitas();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

void prosesPenjualan() {
    int choice = 0;
    while (true) {
        cout << "\nProses Penjualan Options:" << endl;
        cout << "1. Input Pesanan Pelanggan" << endl;
        cout << "2. Lihat Status Stok" << endl;
        cout << "3. Back to Service Operation" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputPesananPelanggan();
                break;
            case 2:
                lihatStatusStok();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }    
}

int inputPesananPelanggan() {
    cout << "Input Pesanan Pelanggan:" << endl;
    return 0;
}

int lihatStatusStok() {
    cout << "Status Stock Saat Ini:" << endl;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "") {
            cout << "Menu: " << nama_menu[i] << ", Jumlah: " << jumlah_stock[i] << ", Harga: " <<  harga[i] << ", Status Menu: " << status_menu[i] << ", Waktu Persiapan: " << waktu_persiapan[i] << ", Menu Terjual: " << menu_terjual[i] << endl;
        }
    }
    return 0;
}

void persiapanMenu() {
    int choice = 0;
    while (true) {
        cout << "\nPersiapan Menu Options:" << endl;
        cout << "1. Input stok awal per menu" << endl;
        cout << "2. Update pengurangan stok otomatis" << endl;
        cout << "3. Back to Service Operation" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputStokAwalPerMenu();
                break;
            case 2:
                updatePenguranganStokOtomatis();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

int inputStokAwalPerMenu() {
    cout << "Masukkan informasi stok awal untuk setiap menu:" << endl;
    int max_item_menus = 0;
    cout << "Masukkan jumlah menu yang ingin di input: ";
    cin >> max_item_menus;
    cin.ignore(); // Mengabaikan newline yang tersisa setelah membaca integer

    if (max_item_menus > MAX_ITEMS) {
        cout << "Jumlah menu melebihi batas maksimum." << endl;
        return 1;
    }

    for (int i = 0; i < max_item_menus; i++) {
        cout << "Menu " << (i + 1) << ":" << endl;
        cout << "Nama Menu: ";
        getline(cin, nama_menu[i]);  // Menggunakan getline setelah cin.ignore()

        cout << "Harga: ";
        cin >> harga[i];
        cout << "Jumlah Stok: ";
        cin >> jumlah_stock[i];
        cin.ignore();  // Mengabaikan newline yang tersisa setelah membaca integer

        status_menu[i] = "tidak siap"; // Inisialisasi menu status sebagai "tidak siap"
        waktu_persiapan[i] = 0;  // Inisialisasi waktu persiapan sebagai 0
        menu_terjual[i] = 0;  // Inisialisasi menu terjual sebagai 0

        cout << endl;
    }
    return 0;
}

int updatePenguranganStokOtomatis() {
    return 0;
}

void produksiMenu() {
    int choice = 0;
    while (true) {
        cout << "\nProduksi Menu Options:" << endl;
        cout << "1. Catat waktu produksi menu" << endl;
        cout << "2. Input porsi standar per menu" << endl;
        cout << "3. Back to Kitchen Operation" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                catatWaktuProduksiMenu();
                break;
            case 2:
                inputPorsiStandarPerMenu();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

int catatWaktuProduksiMenu() {
    cout << "Input Waktu Produksi Menu:" << endl;
    return 0;
}

int inputPorsiStandarPerMenu() {
    cout << "Input Posi Standart Per Menu:" << endl;
    return 0;
}

void kontrolKualitas() {
    int choice = 0;
    while (true) {
        cout << "\nKontrol Kualitas Options:" << endl;
        cout << "1. Checklist menu siap jual" << endl;
        cout << "2. Back to Kitchen Operation" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checklistMenuSiapJual();
                break;
            case 2:
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

int checklistMenuSiapJual() {
    cout << "Update Status Menu Siap Dijual:" << endl;
    return 0;
}
