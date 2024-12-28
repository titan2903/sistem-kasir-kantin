#ifndef MENU_DATA_H
#define MENU_DATA_H
using namespace std;
#include <string>

const int MAX_ITEMS = 100;

// Stock menu (Persiapan Menu)
extern string nama_menu_terdaftar[MAX_ITEMS];
extern string nama_menu[MAX_ITEMS];
extern int harga[MAX_ITEMS];
extern int jumlah_stock[MAX_ITEMS];
extern int menu_terjual[MAX_ITEMS];
extern time_t tanggal_dibuat[MAX_ITEMS];
extern time_t tanggal_terjual[MAX_ITEMS];

// Pesanan pelanggan
extern int nomor_pesanan[MAX_ITEMS];
extern string menu_dipesan[MAX_ITEMS];
extern int jumlah_pesanan[MAX_ITEMS];
extern int periode_istirahat[MAX_ITEMS];
extern string status_menu[MAX_ITEMS];
extern int waktu_produksi[MAX_ITEMS];
extern time_t waktu_pesan[MAX_ITEMS];
extern time_t waktu_selesai[MAX_ITEMS];

#endif
