#ifndef MENU_DATA_H
#define MENU_DATA_H
using namespace std;
#include <string>

const int MAX_ITEMS = 100;

// Stock menu (Persiapan Menu)
extern string nama_menu[MAX_ITEMS];
extern int harga[MAX_ITEMS];
extern int jumlah_stock[MAX_ITEMS];
extern string status_menu[MAX_ITEMS];
extern int waktu_persiapan[MAX_ITEMS];
extern int menu_terjual[MAX_ITEMS];

// Pesanan pelanggan
extern int nomor_pesanan[MAX_ITEMS];
extern string menu_dipesan[MAX_ITEMS];
extern int jumlah_pesanan[MAX_ITEMS];
extern int periode_istirahat[MAX_ITEMS];

// Menu siap jual
// extern string nama_menu[MAX_ITEMS];
// extern string status_siap[MAX_ITEMS];
// extern int waktu_persiapan[MAX_ITEMS];

// Produksi menu
// extern string nama_menu_produksi[MAX_ITEMS];
// extern int waktu_produksi[MAX_ITEMS];

#endif
