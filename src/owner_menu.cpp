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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        }
    }
}

void melihatTotalPesananPerPeriodeIstirahat() {
    cout << "\nMelihat semua total pesanan per periode istirahat:" << endl;

    string processedDates[MAX_ITEMS];
    int processedCount = 0;
    bool processed[MAX_ITEMS] = {false};
    bool isDataAvailable = false;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (!processed[i] && waktu_pesan[i] != 0) {
            struct tm *timeinfo = localtime(&waktu_pesan[i]);
            char buffer[11];
            strftime(buffer, 11, "%Y/%m/%d", timeinfo);
            string tanggal(buffer);

            bool isDateProcessed = false;
            for (int k = 0; k < processedCount; k++) {
                if (processedDates[k] == tanggal) {
                    isDateProcessed = true;
                    break;
                }
            }

            if (!isDateProcessed) {
                int total_pesanan_periode[4] = {0}; // Array untuk menampung total pesanan per periode

                for (int j = 0; j < MAX_ITEMS; j++) {
                    if (waktu_pesan[j] != 0 && !processed[j]) {
                        struct tm *compareTime = localtime(&waktu_pesan[j]);
                        char compareBuffer[11];
                        strftime(compareBuffer, 11, "%Y/%m/%d", compareTime);
                        string compareDate(compareBuffer);

                        if (compareDate == tanggal) {
                            if (periode_istirahat[j] >= 0 && periode_istirahat[j] <= 3) {
                                total_pesanan_periode[periode_istirahat[j]] += jumlah_pesanan[j];
                                processed[j] = true;
                                isDataAvailable = true;
                            }
                        }
                    }
                }

                if (isDataAvailable) {
                    cout << "Tanggal: " << tanggal << endl;
                    for (int p = 1; p <= 3; p++) {
                        cout << "Total pesanan periode istirahat " << p << ": " << total_pesanan_periode[p] << " Pesanan" << endl;
                    }
                    cout << endl;

                    processedDates[processedCount++] = tanggal;
                }
            }
        }
    }

    if (!isDataAvailable) {
        cout << "Tidak ada data penjualan yang tersedia." << endl;
    }
}

void hitungTotalPesananPerPeriodeIstirahat() {
    cout << "\nTotal pesanan per periode istirahat:" << endl;

    int jam_istirahat = 0;

    while (true) {
        cout << "Pilih Jam Istirahat (1, 2 atau 3): ";
        if (cin >> jam_istirahat) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            if (jam_istirahat >= 1 && jam_istirahat <= 3) {
                break;
            } else {
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
    cout << "\nStock Menu Menjelang Istirahat:" << endl;

    bool isMenuAvailable = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "") {
            cout << "Detail Menu:" << endl
            << "  Nama Menu: " << nama_menu[i] << endl
            << "  Jumlah Stock: " << jumlah_stock[i] << endl
            << "  Harga: Rp" << harga[i] << endl
            << "  Tanggal Dibuat: " << ctime(&tanggal_dibuat[i]) << endl;
            cout << endl;
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        }
    }
}

void lihatRataRataWaktuLayananPerHari() {
    cout << "\nRata-rata waktu layanan per Hari:" << endl;

    int total_waktu_layanan = 0;
    int count = 0;

    string arr_tanggal[MAX_ITEMS];
    int waktu_layanan[MAX_ITEMS];
    bool visited[MAX_ITEMS] = {false};

    bool isDataAvailable = false;
    
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "" && waktu_pesan[i] != 0 && waktu_selesai[i] != 0) {
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
                    visited[j] = true;
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
    }
}

void lihatJumlahPesananPerJenisMenu() {
    cout << "\nJumlah pesanan per jenis menu:" << endl;

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
        double total_pendapatan = 0;
        for (int k = 0; k < MAX_ITEMS; k++) {
            if (menu_dipesan[i] == menu_dipesan[k]) {
                total_pesanan += jumlah_pesanan[k];
                total_pendapatan += total_harga[k];
                isMenuAvailable = true;
            }
        }

        if(isMenuAvailable) {
            cout << endl;
            cout << "Menu: " << menu_dipesan[i] << endl
                << "Jumlah Pesanan: " << total_pesanan << endl
                << "Total Pendapatan: " << total_pendapatan << endl
                << "Periode Istirahat: " << periode_istirahat[i] << endl;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada data pesanan yang tersedia." << endl;
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        }
    }
}

void updateStokMenuTersedia() {
    cout << "\nMelakukan update stok menu tersedia:" << endl;
    
    bool isMenuAvailable = false;

    cout << "\nStock Menu yang tersedia saat ini:" << endl;
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if(nama_menu[i] != "") {
            cout << "Menu: " << nama_menu[i] << ", Jumlah Stock: " << jumlah_stock[i] << endl;
            isMenuAvailable = true;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada menu yang tersedia." << endl;
        return;
    }

    cout << endl;
    
    bool foundMenu = false;
    string menu;
    while(!foundMenu) {
        cout << "Masukkan Menu yang akan diupdate stoknya: ";
        getline(cin, menu);
        if (menu == "") {
            cout << "Nama Menu tidak boleh kosong." << endl;
        } else {
            foundMenu = foundExistingStockMenu(menu);
            if(!foundMenu) {
                cout << "Menu " << menu << " tidak ditemukan." << endl;
            }
        }
    }

    int jumlah;
    while (true) {
        cout << "Masukkan jumlah stok (tidak boleh 0) yang akan ditambahkan stocknya: ";
        if (cin >> jumlah) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            if (jumlah >= 1) {
                break;
            } else {
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            }
        } else {
            cout << "Input tidak valid, silakan masukkan angka." << endl;
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        }
    }

    bool found = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] == menu)
        {   
            jumlah_stock[i] += jumlah;
            cout << "Stok dengan Menu " << menu << " berhasil ditambahkan menjadi " << jumlah_stock[i] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Gagal melakukan update untuk Menu " << menu << endl;
    }
}

void lihatSisaStokPerMenu() {
    cout << "\nStok Per Menu saat ini:" << endl;

    bool isMenuAvailable = false;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "") {
            cout << "Informasi Stok Menu:" << endl
                << "  Menu: " << nama_menu[i] << endl
                << "  Jumlah Stock: " << jumlah_stock[i] << endl;
            cout << endl;
            isMenuAvailable = true;
        }
    }

    if (!isMenuAvailable) {
        cout << "Tidak ada Menu yang tersedia." << endl;
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
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
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        }
    }
}

void lihatTotalPenjualanPerMenu() {
    cout << "\nTotal penjualan per menu:" << endl;

    string processedMenus[MAX_ITEMS]; // Array untuk menyimpan nama menu yang sudah diproses
    int totalSales[MAX_ITEMS] = {0}; // Array untuk menyimpan total penjualan
    double totalHarga[MAX_ITEMS] = {0};
    int count = 0; // Penghitung untuk jumlah menu unik
    double totalPendapatan = 0;

    bool isMenuAvailable = false;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (nama_menu[i] != "") {
            bool found = false;
            for (int j = 0; j < count; j++) {
                if (processedMenus[j] == nama_menu[i]) {
                    totalSales[j] += menu_terjual[i]; // Tambahkan ke total penjualan yang sudah ada
                    totalHarga[j] += total_harga[i];
                    found = true;
                    break;
                }
            }

            // Jika menu belum diproses, tambahkan ke daftar
            if (!found && count < MAX_ITEMS) {
                processedMenus[count] = nama_menu[i];
                totalSales[count] = menu_terjual[i];
                totalHarga[count] = total_harga[i];
                count++;
            }
            isMenuAvailable = true;
        }
    }

    if (isMenuAvailable) {
        for (int k = 0; k < count; k++) {
            cout << "Detail Penjualan:" << endl
                << "  Menu: " << processedMenus[k] << endl
                << "  Total Penjualan: " << totalSales[k] << endl
                << "Total Harga: " << totalHarga[k] << endl;
            cout << endl;
            totalPendapatan += totalHarga[k];
        }
        cout << "Total keseluruhan pendapatan: " << totalPendapatan << endl;
    } else {
        cout << "Tidak ada data penjualan yang tersedia." << endl;
    }
}

void lihatMenuYangPalingLakuPerHari() {
    cout << "\nMenu yang paling laku per hari:" << endl;

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
        if (!nama_menu[i].empty() && !processed[i] && tanggal_terjual[i] != 0) {
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
                processedDates[processedCount++] = tanggal;
                cout << endl;
            }
        }
    }

    if (processedCount == 0) {
        cout << "Tidak ada data penjualan yang tersedia." << endl;
    }
}