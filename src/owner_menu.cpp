#include <iostream>
#include <limits>
#include "../includes/menu_data.h"
#include "../includes/helper.h"
using namespace std;

void rushHourManagement();
void foodManagement();
void pengelolaanJamSibuk();
void kapasitasLayanan();
void kontrolStok();
void analisisMenu();

//! Pengelolaan Jam Sibuk
void melihatTotalPesananPerPeriodeIstirahat();
void hitungTotalPesananPerPeriodeIstirahat();
void lihatStokMenuMenjelangIstirahat();

//! Kapasitas Layanan
void lihatRataRataWaktuLayananPerHari();
void lihatJumlahPesananPerJenisMenu();

//! Kontrol Stok
void updateStokMenuTersedia();
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
                    cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
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
                    cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
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
                    cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
}

void pengelolaanJamSibuk() {
    int choice = 0;

    while (true) {
        cout << "\nPengelolaan Jam Sibuk:" << endl;
        cout << "1. Lihat semua total pesanan per periode istirahat" << endl;
        cout << "2. Lihat total pesanan per periode istirahat berdasarkan inputan" << endl;
        cout << "3. Lihat stok menu menjelang istirahat" << endl;
        cout << "4. Back to Rush Hour Management" << endl;
        cout << "Select an option: ";
        
        if(cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            switch (choice) {
                case 1:
                    melihatTotalPesananPerPeriodeIstirahat();
                    break;
                case 2:
                    hitungTotalPesananPerPeriodeIstirahat();
                    break;
                case 3:
                    lihatStokMenuMenjelangIstirahat();
                    break;
                case 4:
                    return;
                default:
                    cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
}

void melihatTotalPesananPerPeriodeIstirahat() {
    cout << "Melihat semua total pesanan per periode istirahat:" << endl;

    int total_pesanan_periode_1 = 0;
    int total_pesanan_periode_2 = 0;
    int total_pesanan_periode_3 = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (periode_istirahat[i] == 1) {
            total_pesanan_periode_1 += jumlah_pesanan[i];
        } else if (periode_istirahat[i] == 2) {
            total_pesanan_periode_2 += jumlah_pesanan[i];
        } else if (periode_istirahat[i] == 3) {
            total_pesanan_periode_3 += jumlah_pesanan[i];
        }
    }

    cout << "Total pesanan periode istirahat 1: " << total_pesanan_periode_1 << " Pesanan" << endl;
    cout << "Total pesanan periode istirahat 2: " << total_pesanan_periode_2 << " Pesanan" << endl;
    cout << "Total pesanan periode istirahat 3: " << total_pesanan_periode_3 << " Pesanan" << endl;
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
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
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

    if (total_pesanan == 0) {
        cout << "Tidak ada pesanan untuk periode istirahat " << jam_istirahat << "." << endl;
        return;
    }

    cout << "Total pesanan per istirahat " << jam_istirahat << ": " << total_pesanan << " Pesanan" << endl;
}

void lihatStokMenuMenjelangIstirahat() {
    cout << "Stock Menu Menjelang Istirahat:" << endl;

    bool isMenuAvailable = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "") {
            cout << "Menu: " << nama_menu[i] << ", Jumlah Stock: " << jumlah_stock[i] << ", Harga: " <<  harga[i] << endl;
            isMenuAvailable = true;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada data menu yang tersedia." << endl;
    }
}

void kapasitasLayanan() {
    int choice = 0;
    while (true) {
        cout << "\nKapasitas Layanan:" << endl;
        cout << "1. Lihat rata-rata waktu layanan per hari" << endl;
        cout << "2. Lihat jumlah pesanan per jenis menu" << endl;
        cout << "3. Back to Rush Hour Management" << endl;
        cout << "Select an option: ";
        
        if(cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            switch (choice) {
                case 1:
                    lihatRataRataWaktuLayananPerHari();
                    break;
                case 2:
                    lihatJumlahPesananPerJenisMenu();
                    break;
                case 3:
                    return;
                default:
                    cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
}

void lihatRataRataWaktuLayananPerHari() {
    int total_waktu_layanan = 0;
    int count = 0;

    string arr_tanggal[MAX_ITEMS];
    int waktu_layanan[MAX_ITEMS];
    bool visited[MAX_ITEMS] = {false};

    bool isDataAvailable = false;
    
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "" && waktu_pesan[i] != 0 && waktu_selesai[i] != 0) {
            cout << "waktu pesan: " << ctime(&waktu_pesan[i]) << endl;
            struct tm *timeinfo = localtime(&waktu_pesan[i]);
            char buffer[11];
            strftime(buffer, 11, "%Y/%m/%d", timeinfo); // Format tanggal menjadi yyyy/mm/dd
            string tanggal(buffer);

            cout << "tanggal: " << tanggal << endl;
            arr_tanggal[i] = tanggal;
            waktu_layanan[i] = calculateTimeDifferenceInMinutes(waktu_selesai[i], waktu_pesan[i]);
            isDataAvailable = true;
        }
    }

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (!arr_tanggal[i].empty() && !visited[i]) {
            int total_waktu = 0;
            int count = 0;
            for (int j = 0; j < MAX_ITEMS; j++) {
                if (arr_tanggal[i] == arr_tanggal[j] && !arr_tanggal[j].empty()) {
                    total_waktu += waktu_layanan[j];
                    count++;
                    visited[j] = true; // Mark this date as visited
                }
            }

            if (count > 0) {
                double rata_rata_waktu = static_cast<double>(total_waktu) / count;
                cout << "Rata Rata waktu layanan tanggal " << arr_tanggal[i] << " adalah " << rata_rata_waktu << " menit" << endl;
            } else {
                cout << "Tidak ada data waktu layanan yang tersedia." << endl;
                return;
            }
        }
    }

    if (!isDataAvailable) {
        cout << "Tidak ada data waktu layanan yang tersedia." << endl;
        return;
    }
}

void lihatJumlahPesananPerJenisMenu() {
    cout << "Jumlah pesanan per jenis menu:" << endl;

    bool isMenuAvailable = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] == "") {
            continue;
        }

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
                isMenuAvailable = true;
            }
        }

        if(isMenuAvailable) {
            cout << "Menu: " << menu_dipesan[i] << ", Jumlah Pesanan: " << total_pesanan << endl;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada data pesanan yang tersedia." << endl;
        return;
    }
}

void kontrolStok() {
    int choice = 0;
    while (true) {
        cout << "\nKontrol Stok:" << endl;
        cout << "1. Update stok menu tersedia" << endl;
        cout << "2. Lihat sisa stok per menu" << endl;
        cout << "3. Back to Food Management" << endl;
        cout << "Select an option: ";
        
        if(cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            switch (choice) {
                case 1:
                    updateStokMenuTersedia();
                    break;
                case 2:
                    lihatSisaStokPerMenu();
                    break;
                case 3:
                    return;
                default:
                    cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
}

void updateStokMenuTersedia() {
    cout << "Melakukan update stok menu tersedia:" << endl;

    cout << "\nMenu yang tersedia saat ini:" << endl;

    bool isMenuAvailable = false;
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if(nama_menu[i] != "") {
            isMenuAvailable = true;
            cout << "Menu: " << nama_menu[i] << ", Jumlah Stock: " << jumlah_stock[i] << endl;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada menu yang tersedia." << endl;
        return;
    }
    
    string menu;
    int jumlah;

    bool foundMenu = false;
    while(!foundMenu) {
        cout << "Masukkan Menu yang akan diupdate stoknya: ";
        getline(cin, menu);
        if (menu == "") {
            cout << "Nama Menu tidak boleh kosong." << endl;
        } else {
            for (int i = 0; i < MAX_ITEMS; i++) {
                if (nama_menu[i] == menu) {
                    foundMenu = true;
                    break;
                }
            }

            if(!foundMenu) {
                cout << "Menu " << menu << " tidak ditemukan." << endl;
            }
        }
    }

    while (true) {
        cout << "Masukkan jumlah stok (tidak boleh 0) yang akan diupdate: ";
        if (cin >> jumlah) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            if (jumlah >= 1) {
                break;
            } else {
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }

    bool found = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] == menu)
        {
            jumlah_stock[i] = jumlah;
            cout << "Stok dengan Menu " << menu << " berhasil diupdate menjadi " << jumlah << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Gagal melakukan update untuk Menu " << menu << endl;
        return;
    }
}

void lihatSisaStokPerMenu() {
    cout << "Stok Per Menu saat ini:" << endl;

    bool isMenuAvailable = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "") {
            cout << "Menu: " << nama_menu[i] << ", Jumlah Stock: " << jumlah_stock[i] << endl;
            isMenuAvailable = true;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada Menu yang tersedia." << endl;
        return;
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
                    cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the input
        }
    }
}

void lihatTotalPenjualanPerMenu() {
    cout << "Total penjualan per menu:" << endl;
    
    bool isMenuAvailable = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if(nama_menu[i] != "") {
            cout << "Menu: " << nama_menu[i] << ", Total Penjualan: " << menu_terjual[i] << endl;
            isMenuAvailable = true;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada data penjualan yang tersedia." << endl;
        return;
    }
}

void lihatMenuYangPalingLakuPerHari() {
    cout << "Menu yang paling laku per hari:" << endl;

    // Array untuk menyimpan tanggal yang telah diproses
    string processedDates[MAX_ITEMS];
    int processedCount = 0;

    // Array untuk menandai item yang sudah diproses
    bool processed[MAX_ITEMS] = {false};

    int maxSales = menu_terjual[0];
    for (int i = 1; i < MAX_ITEMS; i++) {
        if (menu_terjual[i] > maxSales) {
            maxSales = menu_terjual[i];
        }
    }

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (!nama_menu[i].empty() && !processed[i]) {
            struct tm *timeinfo = localtime(&tanggal_terjual[i]);
            char buffer[11];
            strftime(buffer, 11, "%Y/%m/%d", timeinfo);
            string tanggal(buffer);

            // Cek apakah tanggal sudah diproses
            bool isDateProcessed = false;
            for (int k = 0; k < processedCount; k++) {
                if (processedDates[k] == tanggal) {
                    isDateProcessed = true;
                    break;
                }
            }

            if (!isDateProcessed) {
                cout << "Tanggal: " << tanggal << endl;
                for (int j = i; j < MAX_ITEMS; j++) {
                    if (!nama_menu[j].empty() && maxSales == menu_terjual[j]) {
                        struct tm *compareTimeinfo = localtime(&tanggal_terjual[j]);
                        char compareBuffer[11];
                        strftime(compareBuffer, 11, "%Y/%m/%d", compareTimeinfo);
                        string compareDate(compareBuffer);

                        if (tanggal == compareDate) {
                            cout << "Menu: " << nama_menu[j] << ", Terjual Sebanyak: " << menu_terjual[j] << endl;
                            processed[j] = true;
                        }
                    }
                }
                processedDates[processedCount++] = tanggal; // Tandai tanggal ini sudah diproses
                cout << endl;
            }
        }
    }

    if (processedCount == 0) {
        cout << "Tidak ada data penjualan yang tersedia." << endl;
    }
}