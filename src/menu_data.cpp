#include "../includes/menu_data.h"

// Stock menu (Persiapan Menu)
std::string names[MAX_ITEMS];
int prices[MAX_ITEMS];
int quantities[MAX_ITEMS];

// Menu siap jual
std::string nama_menu[MAX_ITEMS];
std::string status_siap[MAX_ITEMS];
int waktu_persiapan[MAX_ITEMS];

// Produksi menu
std::string nama_menu_produksi[MAX_ITEMS];
int waktu_produksi[MAX_ITEMS];
int porsi_standar[MAX_ITEMS];

// Pesanan pelanggan
int nomor_pesanan[MAX_ITEMS];
std::string menu_dipesan[MAX_ITEMS];
int jumlah_pesanan[MAX_ITEMS];
std::time_t created_time[MAX_ITEMS];