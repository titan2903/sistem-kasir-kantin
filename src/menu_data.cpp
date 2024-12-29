#include "../includes/menu_data.h"
using namespace std;

//! Current item count
int currentItemStockCount = 0;
int currentItemPesananCount = 0;

//! Stock menu (Persiapan Menu)
string nama_menu_terdaftar[MAX_ITEMS];
string nama_menu[MAX_ITEMS];
int harga[MAX_ITEMS];
int jumlah_stock[MAX_ITEMS];
int menu_terjual[MAX_ITEMS];
time_t tanggal_dibuat[MAX_ITEMS];
time_t tanggal_terjual[MAX_ITEMS];

//! Pesanan pelanggan
int nomor_pesanan[MAX_ITEMS];
string menu_dipesan[MAX_ITEMS];
int jumlah_pesanan[MAX_ITEMS];
int periode_istirahat[MAX_ITEMS];
string status_menu[MAX_ITEMS];
double total_harga[MAX_ITEMS];
int waktu_produksi[MAX_ITEMS];
time_t waktu_pesan[MAX_ITEMS];
time_t waktu_selesai[MAX_ITEMS];