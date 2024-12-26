#include <iostream>
#include <limits>
#include "../includes/menu_data.h"
using namespace std;

void rushHourManagement();
void foodManagement();
void pengelolaanJamSibuk();
void kapasitasLayanan();
void kontrolStok();
void analisisMenu();

//! Pengelolaan Jam Sibuk
void hitungTotalPesananPerPeriodeIstirahat();
void lihatStokMakananMenjelangIstirahat();

//! Kapasitas Layanan
void lihatRataRataWaktuLayananPerHari();
void lihatJumlahPesananPerJenisMakanan();

//! Kontrol Stok
int updateStokMakananTersedia();
void lihatSisaStokPerMenu();

//! Analisis Menu
void lihatTotalPenjualanPerMenu();
void lihatMenuYangPalingLakuPerHari();

void ownerMenu() {
    int choice = 0;
    while (true) {
        cout << "\nMenu Owner:" << endl;
        cout << "1. Rush Hour Management" << endl;
        cout << "2. Food Management" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih menu: ";

        if(cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
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
        } else {
            cout << "Invalid input, please enter a number." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
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
        
        if(cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
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
        } else {
            cout << "Invalid input, please enter a number." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
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
        
        if(cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
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
        } else {
            cout << "Invalid input, please enter a number." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
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
        
        if(cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            switch (choice) {
                case 1:
                    hitungTotalPesananPerPeriodeIstirahat();
                    break;
                case 2:
                    lihatStokMakananMenjelangIstirahat();
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

void hitungTotalPesananPerPeriodeIstirahat() {
    cout << "Total pesanan per periode istirahat:" << endl;
    int jam_istirahat = 0;

    while (true) {
        cout << "Pilih Jam Istirahat (1, 2 atau 3): ";
        if (cin >> jam_istirahat) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            if (jam_istirahat >= 1 && jam_istirahat <= 3) {
                break;
            } else {
                cout << "Invalid choice, please try again." << endl;
            }
        } else {
            cout << "Invalid input, please enter a number." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
    
    int total_pesanan = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (periode_istirahat[i] == jam_istirahat) {
            total_pesanan += jumlah_pesanan[i];
        }
    }

    cout << "Total pesanan per istirahat " << jam_istirahat << ": " << total_pesanan << " Pesanan" << endl;
}

void lihatStokMakananMenjelangIstirahat() {
    cout << "Stock Makanan Menjelang Istirahat:" << endl;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "") {
            cout << "Menu: " << nama_menu[i] << ", Jumlah: " << jumlah_stock[i] << ", Harga: " <<  harga[i] << ", Status Menu: " << status_menu[i] << endl;
        }
    }
}

void kapasitasLayanan() {
    int choice = 0;
    while (true) {
        cout << "\nKapasitas Layanan:" << endl;
        cout << "1. Lihat rata-rata waktu layanan per hari" << endl;
        cout << "2. Lihat jumlah pesanan per jenis makanan" << endl;
        cout << "3. Back to Rush Hour Management" << endl;
        cout << "Select an option: ";
        
        if(cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            switch (choice) {
                case 1:
                    lihatRataRataWaktuLayananPerHari();
                    break;
                case 2:
                    lihatJumlahPesananPerJenisMakanan();
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

void lihatRataRataWaktuLayananPerHari() {
    int total_waktu_layanan = 0;
    int count = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "") {
            total_waktu_layanan += waktu_persiapan[i];
            count += 1;  
        }
    }
    
    if (count > 0) {  // To avoid division by zero
        double rata_rata_waktu = static_cast<double>(total_waktu_layanan) / count;  // Calculate average
        std::cout << "Rata-rata waktu layanan per hari: " << rata_rata_waktu << " Menit" << std::endl;
    } else {
        std::cout << "Tidak ada item menu yang tersedia untuk menghitung waktu rata-rata." << std::endl;
    }

}

void lihatJumlahPesananPerJenisMakanan() {
    cout << "Jumlah pesanan per jenis makanan:" << endl;
    for (int i = 0; i < MAX_ITEMS; i++) {
        bool counted = false;
        for (int j = 0; j < i; j++) {
            if (menu_dipesan[i] == menu_dipesan[j]) {
                counted = true;
                break;
            }
        }
        
        if (counted) continue;

        int total_pesanan = 0;
        for (int k = 0; k < MAX_ITEMS; k++) {
            if (menu_dipesan[i] == menu_dipesan[k]) {
                total_pesanan += jumlah_pesanan[k];
            }
        }
        
        cout << "Menu: " << menu_dipesan[i] << ", Jumlah Pesanan: " << total_pesanan << endl;
    }
}

void kontrolStok() {
    int choice = 0;
    while (true) {
        cout << "\nKontrol Stok:" << endl;
        cout << "1. Update stok makanan tersedia" << endl;
        cout << "2. Lihat sisa stok per menu" << endl;
        cout << "3. Back to Food Management" << endl;
        cout << "Select an option: ";
        
        if(cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
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
        } else {
            cout << "Invalid input, please enter a number." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
}

int updateStokMakananTersedia() {
    //! Implement the functionality here
    return 0;
}

void lihatSisaStokPerMenu() {
    cout << "Stok Per Menu saat ini:" << endl;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "") {
            cout << "Menu: " << nama_menu[i] << ", Jumlah: " << jumlah_stock[i] << ", Harga: " <<  harga[i] << endl;
        }
    }
}

void analisisMenu() {
    int choice = 0;
    while (true) {
        cout << "\nAnalisis Menu:" << endl;
        cout << "1. Lihat total penjualan per menu" << endl;
        cout << "2. Lihat menu yang paling laku per hari" << endl;
        cout << "3. Back to Food Management" << endl;
        cout << "Select an option: ";
        
        if(cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
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
        } else {
            cout << "Invalid input, please enter a number." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
}

void lihatTotalPenjualanPerMenu() {
    cout << "Total penjualan per menu:" << endl;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if(nama_menu[i] != "") {
            cout << "Menu: " << nama_menu[i] << ", Total Penjualan: " << menu_terjual[i] << endl;
        }
    }
}

void lihatMenuYangPalingLakuPerHari() {
    std::cout << "Menu yang paling laku per hari:" << std::endl;
    
    int maxSales = menu_terjual[0];
    for (int i = 1; i < MAX_ITEMS; i++) {
        if (menu_terjual[i] > maxSales) {
            maxSales = menu_terjual[i];
        }
    }

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (menu_terjual[i] == maxSales) {
            std::cout << nama_menu[i] << " - Terjual Sebanyak: " << menu_terjual[i] << std::endl;
        }
    }
}