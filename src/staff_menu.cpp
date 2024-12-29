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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        }
            
    }    
}

void inputPesananPelanggan() {
    cout << "\nMembuat Pesanan Pelanggan:" << endl;

    bool isMenuAvailable = false;
    cout << "\nStock Menu yang tersedia saat ini:" << endl;
    for (int i = 0; i < currentItemStockCount; i++) {
        if(nama_menu[i] != "" && jumlah_stock[i] > 0) {
            cout << endl;
            cout << "Menu: " << nama_menu[i] << endl
                << "Harga: Rp" << harga[i] << endl
                << "Jumlah Stock: " << jumlah_stock[i] << endl;
            isMenuAvailable = true;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada menu yang tersedia, silakan tambahkan stock menu terlebih dahulu." << endl;
        return;
    }

    cout << endl;

    int total_pesanan = 0;
    while (true) {
        cout << "\nMasukkan jumlah pesanan yang ingin di input: ";
        if (cin >> total_pesanan && total_pesanan > 0 && (total_pesanan + currentItemPesananCount) <= MAX_ITEMS) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break; 
        } else {
            cout << "Jumlah pesanan harus lebih dari 0 dan tidak melebihi batas maksimum (" << MAX_ITEMS << "), silakan coba lagi.\n";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }

    for (int i = currentItemPesananCount; i < total_pesanan + currentItemPesananCount; i++) {
        cout << "Pesanan " << (i + 1) << ":" << endl;

        int tempOrderNumber;
        bool isUnique;

        // Validate unique nomor pesanan
        do {
            cout << "Nomor Pesanan: ";
            if (cin >> tempOrderNumber) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                isUnique = true;

                for (int j = 0; j < MAX_ITEMS; j++) {
                    if (nomor_pesanan[j] > 0 && nomor_pesanan[j] == tempOrderNumber) {
                        cout << "Nomor Pesanan " << tempOrderNumber << " sudah ada, silakan masukkan nomor lain." << endl;
                        isUnique = false;
                        break;
                    }
                }

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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                isUnique = false;
            }
        } while (!isUnique);

        nomor_pesanan[i] = tempOrderNumber;

        bool menuFound = false;
        bool stockAvailable = false;
        while (true) {
            cout << "Menu yang Dipesan: ";
            getline(cin, menu_dipesan[i]);
            if (!menu_dipesan[i].empty()) {
                menuFound = foundExistingMenuPesanan(menu_dipesan[i]);
                stockAvailable = checkStockMoreThenZero(menu_dipesan[i]);
                if (menuFound) {
                    if (stockAvailable) {
                        break;
                    } else {
                        cout << "Stok untuk menu " << menu_dipesan[i] << " habis, silakan pilih menu lain." << endl;
                    }
                } else {
                    cout << "Menu " << menu_dipesan[i] << " tidak ditemukan, silakan coba lagi." << endl;
                }
            } else {
                cout << "Nama menu tidak boleh kosong, silakan masukkan lagi." << endl;
            }
        }

        while (true) {
            cout << "Jumlah Pesanan: ";
            if (cin >> jumlah_pesanan[i] && jumlah_pesanan[i] > 0) {
                bool validOrder = false; 
                for (int j = 0; j < MAX_ITEMS; j++) {
                    if (nama_menu[j] == menu_dipesan[i]) {
                        if (jumlah_pesanan[i] > jumlah_stock[j]) {
                            cout << "Jumlah pesanan melebihi stok yang tersedia, silakan input pesanan kurang dari stock tersedia (" << jumlah_stock[j] << " tersedia)." << endl;
                        } else {
                            updatePenguranganStokOtomatis(menu_dipesan[i], jumlah_pesanan[i]);
                            updatePenambahanMenuTerjualOtomatis(menu_dipesan[i], jumlah_pesanan[i]);
                            total_harga[i] = harga[j] * jumlah_pesanan[i];
                            validOrder = true;
                            break;
                        }
                    }
                }
                if (validOrder) {
                    cin.ignore();  
                    break;
                }
            } else {
                cout << "Jumlah pesanan harus lebih dari 0, silakan coba lagi." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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

        status_menu[i] = STATUS_TIDAK_SIAP;
        waktu_pesan[i] = time(0);

        cout << "\nPesanan dengan nomor " << nomor_pesanan[i] << " berhasil dibuat." << endl
            << "Menu yang dipesan: " << menu_dipesan[i] << "." << endl
            << "Total yang perlu dibayarkan: Rp" << total_harga[i] << "." << endl
            << "Pesanan akan diproses setelah periode istirahat " << periode_istirahat[i] << "." << endl
            << "Waktu Pesan: " << ctime(&waktu_pesan[i]) << endl;
        cout << endl;
    }

    currentItemPesananCount += total_pesanan;
}

void lihatPesananPelanggan() {
    cout << "\nPesanan Pelanggan:" << endl;

    bool isPesananAvailable = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (menu_dipesan[i] != "") {
            cout << "Detail Pesanan:" << endl
                << "  Nomor Pesanan: " << nomor_pesanan[i] << endl
                << "  Menu Dipesan: " << menu_dipesan[i] << endl
                << "  Jumlah Pesanan: " << jumlah_pesanan[i] << endl
                << "  Periode Istirahat: " << periode_istirahat[i] << endl
                << "  Status Pesanan: " << status_menu[i] << endl
                << "  Total Harga: Rp" << total_harga[i] << endl
                << "  Waktu Pesan: " << ctime(&waktu_pesan[i]) << endl;
            cout << endl;
            isPesananAvailable = true;
        }
    }

    if (!isPesananAvailable) {
        cout << "Tidak ada pesanan pelanggan yang tersedia." << endl;
    }
}

void lihatStatusStokSaatIni() {
    cout << "\nStatus Stock Saat Ini:" << endl;

    bool isMenuAvailable = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "") {
            cout << "Informasi Menu:" << endl
                << "  Menu: " << nama_menu[i] << endl
                << "  Jumlah Stok: " << jumlah_stock[i] << endl
                << "  Menu Terjual: " << menu_terjual[i] << endl
                << "  Harga: Rp" << harga[i] << endl
                << "  Tanggal Dibuat: " << ctime(&tanggal_dibuat[i]) << endl;
            cout << endl;
            isMenuAvailable = true;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada data stock menu yang tersedia." << endl;
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        }
    }
}

void inputStokAwalPerMenu() {
    cout << "\nMembuat stok awal untuk setiap menu:" << endl;

    bool isMenuAvailable = false;

    cout << "\nStock Menu yang tersedia saat ini:" << endl;
    for (int i = 0; i < currentItemStockCount; i++)
    {
        if(nama_menu[i] != "") {
            cout << endl;
            cout << "Menu: " << nama_menu[i] << endl
                << "Jumlah Stock: " << jumlah_stock[i] << endl;
            isMenuAvailable = true;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada menu yang tersedia." << endl;
    }

    cout << endl;

    int max_item_menus = 0;
    while (true) {
        cout << "\nMasukkan jumlah menu yang ingin diinput: ";
        if (cin >> max_item_menus && max_item_menus > 0 && (currentItemStockCount + max_item_menus) <= MAX_ITEMS) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        } else {
            cout << "Jumlah menu harus lebih dari 0 dan total tidak melebihi " << MAX_ITEMS << ", silakan coba lagi." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    for (int i = currentItemStockCount; i < currentItemStockCount + max_item_menus; i++) {
        cout << "Menu " << (i + 1) << ":" << endl;

        // Validate menu name
        bool foundStockMenu = false;
        while (true) {
            cout << "Nama Menu: ";
            getline(cin, nama_menu[i]);
            if (!nama_menu[i].empty()) {
                foundStockMenu = foundExistingStockMenu(nama_menu[i]);
                if (foundStockMenu) {
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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                if (harga[i] > 0) {
                    break;
                } else {
                    cout << "Harga harus lebih dari 0, silakan coba lagi." << endl;
                }
            } else {
                cout << "Input tidak valid, silakan masukkan angka." << endl;
                cin.clear();  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            }
        }

        // Validate jumlah stok
        while (true) {
            cout << "Jumlah Stok: ";
            if (cin >> jumlah_stock[i]) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                if (jumlah_stock[i] >= 0) {
                    break;
                } else {
                    cout << "Jumlah stok tidak boleh negatif, silakan coba lagi." << endl;
                }
            } else {
                cout << "Input tidak valid, silakan masukkan angka." << endl;
                cin.clear();  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            }
        }

        menu_terjual[i] = 0;  // Inisialisasi menu terjual sebagai 0
        tanggal_dibuat[i] = time(0);  // Set the creation time to the current time
        tanggal_terjual[i] = 0;  // Inisialisasi tanggal terjual sebagai 0
        
        cout << "Menu " << nama_menu[i] << " berhasil terdaftar dengan jumlah stock sebanyak " << jumlah_stock[i] << endl;
        cout << endl;
    }

    currentItemStockCount += max_item_menus;
}

void melihatStokMenuYangTelahTerdaftar() {
    cout << "\nStok Menu saat ini:" << endl;

    bool isMenuAvailable = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "") {
            cout << "Detail Menu:" << endl
                << "  Nama Menu: " << nama_menu[i] << endl
                << "  Harga: Rp" << harga[i] << endl
                << "  Jumlah Stock: " << jumlah_stock[i] << endl
                << "  Menu Terjual: " << menu_terjual[i] << endl
                << "  Tanggal Dibuat: " << ctime(&tanggal_dibuat[i]) << endl;
            cout << endl;
            isMenuAvailable = true;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada stock menu yang terdaftar." << endl;
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (choice) {
                case 1:
                    catatWaktuProduksiMenu();
                    break;
                case 2:
                    melihatWaktuProduksiSetiapMenu();
                    break;
                case 3:
                    return;
                default:
                    cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        }
    }
}

void catatWaktuProduksiMenu() {
    cout << "\nMencatat Waktu Produksi Menu:" << endl;

    int data_pesanan = 0;
    cout << "\nList menu pesanan yang belum memiliki Waktu Produksi:" << endl;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (waktu_produksi[i] == 0 && status_menu[i] == STATUS_SIAP) {
            cout << "Informasi Pesanan:" << endl
                << "  Nomor Pesanan: " << nomor_pesanan[i] << endl
                << "  Menu: " << menu_dipesan[i] << endl
                << "  Waktu Produksi: " << waktu_produksi[i] << " Menit" << endl;
            cout << endl;
            data_pesanan++;
        }
    }

    int input_nomor_pesanan;
    if(data_pesanan > 0) {
        bool isUpdated = false;
        while (!isUpdated) {
            cout << "Input Nomor Pesanan yang akan dicatat waktu produksinya: ";
            while (true) {
                if (cin >> input_nomor_pesanan) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                    if (input_nomor_pesanan > 0) {
                        break;
                    } else {
                        cout << "Nomor pesanan harus diatas 0, silakan coba lagi." << endl;
                    }
                } else {
                    cout << "Input tidak valid, silakan masukkan angka." << endl;
                    cin.clear();  
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                }
            }

            if (input_nomor_pesanan > 0) {
                for (int i = 0; i < MAX_ITEMS; i++) {
                    if (nomor_pesanan[i] == input_nomor_pesanan && status_menu[i] == STATUS_SIAP && waktu_produksi[i] == 0) {
                        waktu_produksi[i] = calculateTimeDifferenceInMinutes(waktu_selesai[i], waktu_pesan[i]);
                        cout << "Waktu Produksi untuk " << menu_dipesan[i] << " diperbarui menjadi " << waktu_produksi[i] << " Menit." << endl;
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
        cout << endl;
        cout << "Tidak ada data pesanan yang bisa dicatat waktu produksinya." << endl;
    }
    
}

void melihatWaktuProduksiSetiapMenu() {
    cout << "\nWaktu Produksi Setiap Menu:" << endl;

    bool isMenuAvailable = false;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (status_menu[i] == STATUS_SIAP) {
            cout << endl;
            cout << "Menu: " << menu_dipesan[i] << endl
                << "Waktu Produksi: " << waktu_produksi[i] << "Menit" << endl;
            cout << endl;
            isMenuAvailable = true;
        }
    }

    if(!isMenuAvailable) {
        cout << "Tidak ada data pesanan yang siap untuk diproduksi." << endl;
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        }
    }
}

void checklistMenuSiapJual() {
    cout << "\nMelakukan Checklist Menu Siap Dijual atau Disajikan:" << endl;

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
                    waktu_selesai[i] = time(0);
                    cout << "Status menu " << menu_dipesan[i] << " telah diubah menjadi 'siap' dijual atau disajikan." << endl;
                } else {
                    cout << "Status menu " << menu_dipesan[i] << " tetap 'tidak siap' dijual atau disajikan." << endl;
                }
            }
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada menu yang perlu di Checklist." << endl;
    }
}


void melihatMenuTerchecklist() {
    cout << "\nList menu yang sudah siap" << endl;

    bool isMenuAvailable = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (menu_dipesan[i] != "" && status_menu[i] == STATUS_SIAP) {
            cout << "Menu: " << menu_dipesan[i] << endl
            << "Status Menu: " << status_menu[i] << endl
            << "Waktu Siap: " << ctime(&waktu_selesai[i]) << endl;
            cout << endl;
            isMenuAvailable = true;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada menu yang tersedia." << endl;
    }
}