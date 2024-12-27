#include <iostream>
#include <limits>
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
void inputPesananPelanggan();
void lihatPesananPelanggan();
void lihatStatusStok();

//! Persiapan Menu
void inputStokAwalPerMenu();
int updatePenguranganStokOtomatis();

//! Produksi Menu
void catatWaktuProduksiMenu();
// void inputPorsiStandarPerMenu();

//! Kontrol Kualitas
void checklistMenuSiapJual();

void staffMenu() {
    int choice = 0;
    while (true) {
        cout << "\nMenu Staff:" << endl;
        cout << "1. Service Operation" << endl;
        cout << "2. Kitchen Operation" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih menu: ";
        
        if (cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
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
        } else {
            cout << "Invalid input, please enter a number." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
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
        
        if (cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
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
        } else {
            cout << "Invalid input, please enter a number." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
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
        
        if (cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
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
        } else {
            cout << "Invalid input, please enter a number." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
}

void prosesPenjualan() {
    int choice = 0;
    while (true) {
        cout << "\nProses Penjualan Options:" << endl;
        cout << "1. Input Pesanan Pelanggan" << endl;
        cout << "2. Melihat Pesanan Pelanggan" << endl;
        cout << "3. Lihat Status Stok" << endl;
        cout << "4. Back to Service Operation" << endl;
        cout << "Select an option: ";
        
        if (cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
                switch (choice) {
                    case 1:
                        inputPesananPelanggan();
                        break;
                    case 2:
                        lihatPesananPelanggan();
                        break;
                    case 3:
                        lihatStatusStok();
                        break;
                    case 4:
                        return;
                    default:
                        cout << "Invalid choice, please try again." << endl;
                }
        } else {
            cout << "Invalid input, please enter a number." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
            
    }    
}

void inputPesananPelanggan() { //! Butuh menambahkan validasi setiap inputan
    cout << "Membuat Pesanan Pelanggan:" << endl;

    int total_pesanan = 0;
    cout << "Masukkan jumlah pesanan yang ingin di input: ";
    cin >> total_pesanan;
    cin.ignore(); 

    if (total_pesanan > MAX_ITEMS) {
        cout << "Jumlah pesanan melebihi batas maksimum yang diizinkan (" << MAX_ITEMS << ")." << endl;
        return;
    }

    for (int i = 0; i < total_pesanan; i++) {
        cout << "Pesanan " << (i + 1) << ":" << endl;
        cout << "Nomor Pesanan: ";
        cin >> nomor_pesanan[i];
        cin.ignore(); 

        cout << "Menu yang Dipesan: ";
        getline(cin, menu_dipesan[i]);

        cout << "Jumlah Pesanan: ";
        cin >> jumlah_pesanan[i];
        cin.ignore(); 

        cout << "Periode Istirahat (1, 2, atau 3): ";
        cin >> periode_istirahat[i];
        cin.ignore(); 

        cout << endl;  // Mencetak baris kosong sebagai pemisah
    }
}

void lihatPesananPelanggan() {
    cout << "Pesanan Pelanggan:" << endl;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (menu_dipesan[i] != "") {
            cout << "Nomor Pesanan: " << nomor_pesanan[i] << ", Menu Dipesan: " << menu_dipesan[i] << ", Jumlah Pesanan: " << jumlah_pesanan[i] << ", Periode Istirahat: " << periode_istirahat[i] << endl;
        }
    }
}

void lihatStatusStok() {
    cout << "Status Stock Saat Ini:" << endl;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "") {
            cout << "Menu: " << nama_menu[i] << ", Jumlah: " << jumlah_stock[i] << ", Status Menu: " << status_menu[i] << ", Waktu Persiapan: " << waktu_persiapan[i] << ", Menu Terjual: " << menu_terjual[i] << endl;
        }
    }
}

void persiapanMenu() {
    int choice = 0;
    while (true) {
        cout << "\nPersiapan Menu Options:" << endl;
        cout << "1. Input stok awal per menu" << endl;
        cout << "2. Back to Service Operation" << endl;
        cout << "Select an option: ";
        
        if (cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            switch (choice) {
                case 1:
                    inputStokAwalPerMenu();
                    break;
                case 2:
                    return;
                default:
                    cout << "Invalid choice, please try again." << endl;
            }
        } else {
            cout << "Invalid input, please enter a number." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
}

void inputStokAwalPerMenu() { //! Butuh menambahkan validasi setiap inputan
    cout << "Membuat stok awal untuk setiap menu:" << endl;

    int max_item_menus = 0;
    cout << "Masukkan jumlah menu yang ingin di input: ";
    cin >> max_item_menus;
    cin.ignore();

    if (max_item_menus > MAX_ITEMS) {
        cout << "Jumlah Menu melebihi batas maksimum yang diizinkan (" << MAX_ITEMS << ")." << endl;
        return;
    }

    for (int i = 0; i < max_item_menus; i++) {
        cout << "Menu " << (i + 1) << ":" << endl;
        cout << "Nama Menu: ";
        getline(cin, nama_menu[i]);  // Menggunakan getline setelah cin.ignore()

        cout << "Harga: ";
        cin >> harga[i];
        cout << "Jumlah Stok: ";
        cin >> jumlah_stock[i];
        cin.ignore(); 

        status_menu[i] = "tidak siap"; // Inisialisasi menu status sebagai "tidak siap"
        waktu_persiapan[i] = 0;  // Inisialisasi waktu persiapan sebagai 0
        menu_terjual[i] = 0;  // Inisialisasi menu terjual sebagai 0

        cout << endl;
    }
}

int updatePenguranganStokOtomatis() {
    return 0;
}

void produksiMenu() {
    int choice = 0;
    while (true) {
        cout << "\nProduksi Menu Options:" << endl;
        cout << "1. Catat waktu produksi menu" << endl;
        cout << "2. Back to Kitchen Operation" << endl;
        cout << "Select an option: ";
        // cout << "2. Input porsi standar per menu" << endl;
        
        if (cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input 
            switch (choice) {
                case 1:
                    catatWaktuProduksiMenu();
                    break;
                case 2:
                    return;
                default:
                    cout << "Invalid choice, please try again." << endl;
            }
        } else {
            cout << "Invalid input, please enter a number." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
}

void catatWaktuProduksiMenu() {
    cout << "Mencatat Waktu Produksi Menu:" << endl;
}

//! Feature di Tekeout
// void inputPorsiStandarPerMenu() {
//     cout << "Input Posi Standart Per Menu:" << endl;
// }

void kontrolKualitas() {
    int choice = 0;
    while (true) {
        cout << "\nKontrol Kualitas Options:" << endl;
        cout << "1. Checklist menu siap jual" << endl;
        cout << "2. Back to Kitchen Operation" << endl;
        cout << "Select an option: ";
        
        if (cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            switch (choice) {
                case 1:
                    checklistMenuSiapJual();
                    break;
                case 2:
                    return;
                default:
                    cout << "Invalid choice, please try again." << endl;
            }
        } else {
            cout << "Invalid input, please enter a number." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
}

void checklistMenuSiapJual() {
    cout << "Melakukan Update Status Menu Siap Dijual:" << endl;
}
