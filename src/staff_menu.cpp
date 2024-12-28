#include <iostream>
#include <limits>
#include "../includes/menu_data.h"
#include "../includes/helper.h"
#include "../includes/const.h"
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
void lihatStatusStokSaatIni();

//! Persiapan Menu
void inputStokAwalPerMenu();
void melihatStokMenuYangTelahTerdaftar();

//! Produksi Menu
void catatWaktuProduksiMenu();
void melihatWaktuProduksiSetiapMenu();

//! Feature (inputPorsiStandarPerMenu) di Tekeout Berdasarkan diskusi dengan Pak Hedy
// void inputPorsiStandarPerMenu();

//! Kontrol Kualitas
void checklistMenuSiapJual();
void melihatMenuTerchecklist();

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
                        cout << "Pilihan tidak valid, silakan coba lagi." << endl;
                }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  
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
                        cout << "Pilihan tidak valid, silakan coba lagi." << endl;
                }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  
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
                        cout << "Pilihan tidak valid, silakan coba lagi." << endl;
                }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  
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
                        lihatStatusStokSaatIni();
                        break;
                    case 4:
                        return;
                    default:
                        cout << "Pilihan tidak valid, silakan coba lagi." << endl;
                }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
            
    }    
}

void inputPesananPelanggan() {
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

        int tempOrderNumber;
        bool isUnique;

        // Validate unique nomor pesanan
        do {
            cout << "Nomor Pesanan: ";
            if (cin >> tempOrderNumber) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
                isUnique = true;  // Assume the number is unique unless found otherwise

                // Combine the checks into a single loop
                for (int j = 0; j < MAX_ITEMS; j++) {
                    // Check if the order number is already used and is a valid number (greater than 0)
                    if (nomor_pesanan[j] > 0 && nomor_pesanan[j] == tempOrderNumber) {
                        cout << "Nomor Pesanan " << tempOrderNumber << " sudah ada, silakan masukkan nomor lain." << endl;
                        isUnique = false;
                        break;
                    }
                }

                // If the order number is still considered unique, check against newly entered numbers
                if (isUnique) {
                    for (int k = 0; k < i; k++) {
                        if (nomor_pesanan[k] == tempOrderNumber) {
                            cout << "Nomor Pesanan " << tempOrderNumber << " sudah ada, silakan masukkan nomor lain." << endl;
                            isUnique = false;
                            break;
                        }
                    }
                }
            } else {
                cout << "Input tidak valid, silakan masukkan angka." << endl;
                cin.clear();  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
                isUnique = false;
            }
        } while (!isUnique);

        nomor_pesanan[i] = tempOrderNumber; // Set the validated unique order number

        // Validate menu item exists
        bool menuFound = false;
        while (true) {
            cout << "Menu yang Dipesan: ";
            getline(cin, menu_dipesan[i]);
            if (!menu_dipesan[i].empty()) {
                // Check if the menu exists in the list
                menuFound = foundExistingMenuPesanan(menu_dipesan[i]);
                if (menuFound) {
                    break;  // Break the loop if the menu is found
                } else {
                    cout << "Menu " << menu_dipesan[i] << " tidak ditemukan, silakan coba lagi." << endl;
                }
            } else {
                cout << "Nama menu tidak boleh kosong, silakan masukkan lagi." << endl;
            }
        }

        // Validate order quantity
        while (true) {
            cout << "Jumlah Pesanan: ";
            if (cin >> jumlah_pesanan[i] && jumlah_pesanan[i] > 0) {
                bool validOrder = false;  // Flag to track if the order is valid
                for (int j = 0; j < MAX_ITEMS; j++) {
                    if (nama_menu[j] == menu_dipesan[i]) {  // Check if the menu matches
                        if (jumlah_pesanan[i] > jumlah_stock[j]) {
                            cout << "Jumlah pesanan melebihi stok yang tersedia, silakan input pesanan kurang dari stock tersedia (" << jumlah_stock[j] << " tersedia)." << endl;
                        } else {
                            validOrder = true;  // Set flag to true if order is valid
                            break;  // Break the inner loop since a valid order quantity is found
                        }
                    }
                }
                if (validOrder) {
                    cin.ignore();  // Clear the input buffer
                    break;  // Break the outer loop if the order is valid
                }
            } else {
                cout << "Jumlah pesanan harus lebih dari 0, silakan coba lagi." << endl;
                cin.clear();  // Clear any error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
            }
        }

        // Validate break period
        while (true) {
            cout << "Periode Istirahat (1, 2, atau 3): ";
            if (cin >> periode_istirahat[i] && (periode_istirahat[i] >= 1 && periode_istirahat[i] <= 3)) {
                cin.ignore();
                break;
            } else {
                cout << "Periode harus antara 1 dan 3, silakan coba lagi." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        status_menu[i] = STATUS_TIDAK_SIAP;  // Set the status to STATUS_TIDAK_SIAP by default
        waktu_pesan[i] = time(0);  // Set the order time to the current time

        updatePenguranganStokOtomatis(menu_dipesan[i], jumlah_pesanan[i]);
        updatePenambahanMenuTerjualOtomatis(menu_dipesan[i], jumlah_pesanan[i]);

        cout << endl;  // Mencetak baris kosong sebagai pemisah
    }
}

void lihatPesananPelanggan() {
    cout << "Pesanan Pelanggan:" << endl;

    bool isPesananAvailable = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (menu_dipesan[i] != "") {
            cout << "Nomor Pesanan: " << nomor_pesanan[i] << ", Menu Dipesan: " << menu_dipesan[i] << ", Jumlah Pesanan: " << jumlah_pesanan[i] << ", Periode Istirahat: " << periode_istirahat[i] << ", Status Pesanan: " << status_menu[i] << ", Waktu Pesan: " << ctime(&waktu_pesan[i]) << endl;
            isPesananAvailable = true;
        }
    }

    if (!isPesananAvailable) {
        cout << "Tidak ada pesanan yang tersedia." << endl;
        return;
    }
}

void lihatStatusStokSaatIni() {
    cout << "Status Stock Saat Ini:" << endl;

    bool isMenuAvailable = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "") {
            cout << "Menu: " << nama_menu[i] << ", Jumlah: " << jumlah_stock[i] << ", Menu Terjual: " << menu_terjual[i] << endl;
            isMenuAvailable = true;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada data stock menu yang tersedia." << endl;
        return;
    }
}

void persiapanMenu() {
    int choice = 0;
    while (true) {
        cout << "\nPersiapan Menu Options:" << endl;
        cout << "1. Input stok awal per menu" << endl;
        cout << "2. Melihat stock yang telah terdaftar" << endl;
        cout << "3. Back to Service Operation" << endl;
        cout << "Select an option: ";
        
        if (cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            switch (choice) {
                case 1:
                    inputStokAwalPerMenu();
                    break;
                case 2:
                    melihatStokMenuYangTelahTerdaftar();
                    break;
                case 3:
                    return;
                default:
                    cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  
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

        // Validate menu name
        bool isUnique = true;
        while (true) {
            cout << "Nama Menu: ";
            getline(cin, nama_menu[i]);
            if (!nama_menu[i].empty()) {
                isUnique = foundExistingStockMenu(nama_menu[i]);
                if (isUnique) {
                    cout << "Menu " << nama_menu[i] << " sudah ada, silakan masukkan nama lain." << endl;
                } else {
                    nama_menu_terdaftar[i] = nama_menu[i];
                    break;
                }
            } else {
                cout << "Nama menu tidak boleh kosong, silakan masukkan lagi." << endl;
            }
        }

        // Validate harga
        while (true) {
            cout << "Harga: ";
            if (cin >> harga[i]) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
                if (harga[i] > 0) {
                    break;
                } else {
                    cout << "Harga harus lebih dari 0, silakan coba lagi." << endl;
                }
            } else {
                cout << "Input tidak valid, silakan masukkan angka." << endl;
                cin.clear();  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
            }
        }

        // Validate jumlah stok
        while (true) {
            cout << "Jumlah Stok: ";
            if (cin >> jumlah_stock[i]) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
                if (jumlah_stock[i] >= 0) {
                    break;
                } else {
                    cout << "Jumlah stok tidak boleh negatif, silakan coba lagi." << endl;
                }
            } else {
                cout << "Input tidak valid, silakan masukkan angka." << endl;
                cin.clear();  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
            }
        }

        menu_terjual[i] = 0;  // Inisialisasi menu terjual sebagai 0
        tanggal_dibuat[i] = time(0);  // Set the creation time to the current time

        cout << endl;
    }
}

void melihatStokMenuYangTelahTerdaftar() {
    cout << "Stok Menu saat ini:" << endl;

    bool isMenuAvailable = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "") {
            cout << "Menu: " << nama_menu[i] <<", Harga: " << harga[i] << ", Jumlah Stock: " << jumlah_stock[i] << ", Terjual: " << menu_terjual[i] << ", Tanggal Dibuat: " << ctime(&tanggal_dibuat[i]) << endl;
            isMenuAvailable = true;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada menu yang tersedia." << endl;
        return;
    }
}

void produksiMenu() {
    int choice = 0;
    while (true) {
        cout << "\nProduksi Menu Options:" << endl;
        cout << "1. Catat waktu produksi menu" << endl;
        cout << "2. Melihat waktu produksi setiap menu" << endl;
        cout << "3. Back to Kitchen Operation" << endl;
        cout << "Select an option: ";
        
        if (cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input 
            switch (choice) {
                case 1:
                    catatWaktuProduksiMenu();
                    break;
                case 2:
                    melihatWaktuProduksiSetiapMenu();
                case 3:
                    return;
                default:
                    cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
}

void catatWaktuProduksiMenu() {
    cout << "Mencatat Waktu Produksi Menu:" << endl;

    int data_pesanan = 0;
    cout << "\nList menu pesanan yang belum memiliki Waktu Produksi:" << endl;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (waktu_produksi[i] == 0 && status_menu[i] == STATUS_SIAP) {
            cout << "Nomor Pesanan: " << nomor_pesanan[i] << ", Menu " << menu_dipesan[i] << ", Waktu Produksi: " << waktu_produksi[i] << endl;
            data_pesanan++;
        }
    }
    cout << endl;  // Print a blank line as a separator

    int input_nomor_pesanan;

    // !Dummy data deleted SOON
    // Simpan waktu saat ini ke 'awal'
    time_t awal, akhir;
    time(&awal);
    // Tambahkan selisih waktu ke 'akhir' (misalnya, tambahkan 900 detik atau 15 menit)
    akhir = awal + 900;  // 15 menit kemudian

    if(data_pesanan > 0) {
        bool isUpdated = false;
        while (!isUpdated) {
            cout << "Input Nomor Pesanan yang akan dicatat waktu produksinya: ";
            while (true) {
                cout << "Jumlah Stok: ";
                if (cin >> input_nomor_pesanan) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
                    if (input_nomor_pesanan > 0) {
                        break;
                    } else {
                        cout << "Nomor pesanan harus diatas 0, silakan coba lagi." << endl;
                    }
                } else {
                    cout << "Input tidak valid, silakan masukkan angka." << endl;
                    cin.clear();  
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
                }
            }

            if (input_nomor_pesanan > 0) {
                for (int i = 0; i < MAX_ITEMS; i++) {
                    if (nomor_pesanan[i] == input_nomor_pesanan && status_menu[i] == STATUS_SIAP && waktu_produksi[i] == 0) {
                        // waktu_produksi[i] = calculateTimeDifferenceInMinutes(waktu_selesai[i], waktu_pesan[i]);
                        waktu_produksi[i] = calculateTimeDifferenceInMinutes(akhir, awal);
                        cout << "Waktu Produksi untuk " << menu_dipesan[i] << " diperbarui menjadi " << waktu_produksi[i] << " menit." << endl;
                        isUpdated = true;
                        break;
                    }
                }
                if (!isUpdated) {
                    cout << "Nomor Pesanan " << input_nomor_pesanan << " tidak ditemukan, tidak siap atau waktu produksi sudah ditentukan, silakan coba lagi." << endl;
                }
            } else {
                cout << "Nomor menu tidak boleh minus atau 0, silakan masukkan lagi." << endl;
            }
        }
    } else {
        cout << "Tidak ada data pesanan yang bisa dicatat waktu produksinya." << endl;
    }
    
}

void melihatWaktuProduksiSetiapMenu() {
    cout << "Waktu Produksi Setiap Menu:" << endl;

    bool isMenuAvailable = false;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (status_menu[i] == STATUS_SIAP) {
            cout << "Menu: " << menu_dipesan[i] << ", Waktu Produksi: " << waktu_produksi[i] << " menit" << endl;
            isMenuAvailable = true;
        }
    }

    if(!isMenuAvailable) {
        cout << "Tidak ada data pesanan yang siap untuk diproduksi." << endl;
        return;
    }
}

//! Feature (inputPorsiStandarPerMenu) di Tekeout Berdasarkan diskusi dengan Pak Hedy
// void inputPorsiStandarPerMenu() {
//     cout << "Input Posi Standart Per Menu:" << endl;
// }

void kontrolKualitas() {
    int choice = 0;
    while (true) {
        cout << "\nKontrol Kualitas Options:" << endl;
        cout << "1. Checklist menu siap dijual / disajikan" << endl;
        cout << "2. Melihat menu yang sudah di checklist" << endl;
        cout << "3. Back to Kitchen Operation" << endl;
        cout << "Select an option: ";
        
        if (cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            switch (choice) {
                case 1:
                    checklistMenuSiapJual();
                    break;
                case 2:
                    melihatMenuTerchecklist();
                    break;
                case 3:
                    return;
                default:
                    cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
}

void checklistMenuSiapJual() {
    cout << "Melakukan Checklist Menu Siap Dijual atau Disajikan:" << endl;

    bool isMenuAvailable = false;

    for(int i = 0; i < MAX_ITEMS; i++) {
        if (menu_dipesan[i] != "") {
            if (status_menu[i] == STATUS_TIDAK_SIAP) {
                isMenuAvailable = true;
                cout << "Menu " << menu_dipesan[i] << " belum siap dijual atau disajikan." << endl;
                cout << "Apakah menu " << menu_dipesan[i] << " sudah siap dijual atau disajikan? (y/n): ";
                string choice;

                cin >> choice;
                while (true) {
                    if (choice == "y" || choice == "n") {
                        break;
                    } else {
                        cout << "Pilihan tidak valid, silakan masukkan 'y' atau 'n'." << endl;
                        cout << "Apakah menu " << menu_dipesan[i] << " sudah siap dijual atau disajikan? (y/n): ";
                        cin >> choice;
                    }
                }
                if (choice == "y") {
                    status_menu[i] = STATUS_SIAP;
                    waktu_selesai[i] = time(0); // Set the completion time to the current time
                    cout << "Status menu " << menu_dipesan[i] << " telah diubah menjadi 'siap' dijual atau disajikan." << endl;
                } else {
                    cout << "Status menu " << menu_dipesan[i] << " tetap 'tidak siap' dijual atau disajikan." << endl;
                }
            }
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada menu yang perlu di Checklist." << endl;
        return;
    }
}


void melihatMenuTerchecklist() {
    cout << "List menu yang sudah siap" << endl;

    bool isMenuAvailable = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (menu_dipesan[i] != "" && status_menu[i] == STATUS_SIAP) {
            cout << "Menu: " << menu_dipesan[i] << ", Status Menu: " << status_menu[i] << ", Waktu Siap: " << ctime(&waktu_selesai[i]);
            isMenuAvailable = true;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada menu yang tersedia." << endl;
    }
}