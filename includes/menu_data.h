#ifndef MENU_DATA_H
#define MENU_DATA_H

#include <string>
#include <ctime>

const int MAX_ITEMS = 100;

// Stock menu (Persiapan Menu)
extern std::string names[MAX_ITEMS];
extern int prices[MAX_ITEMS];
extern int quantities[MAX_ITEMS];

// Menu siap jual
extern std::string nama_menu[MAX_ITEMS];
extern std::string status_siap[MAX_ITEMS];
extern int waktu_persiapan[MAX_ITEMS];

// Produksi menu
extern std::string nama_menu_produksi[MAX_ITEMS];
extern int waktu_produksi[MAX_ITEMS];
extern int porsi_standar[MAX_ITEMS];

// Pesanan pelanggan
extern int nomor_pesanan[MAX_ITEMS];
extern std::string menu_dipesan[MAX_ITEMS];
extern int jumlah_pesanan[MAX_ITEMS];
extern std::time_t created_time[MAX_ITEMS];

#endif
