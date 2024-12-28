#include "../includes/menu_data.h"
using namespace std;

//! Stock menu (Persiapan Menu)
// string nama_menu_terdaftar[MAX_ITEMS];
// string nama_menu[MAX_ITEMS];
// int harga[MAX_ITEMS];
// int jumlah_stock[MAX_ITEMS];
// int menu_terjual[MAX_ITEMS];
// time_t tanggal_dibuat[MAX_ITEMS];

string nama_menu_terdaftar[MAX_ITEMS] = {
    "Pizza", "Burger", "Pasta", "Salad", "Soup",
    "Steak", "Fish & Chips", "Chicken Wings", "Sushi", "Mie Ayam"
};
string nama_menu[MAX_ITEMS] = {
    "Pizza", "Burger", "Pasta", "Salad", "Soup",
    "Steak", "Fish & Chips", "Chicken Wings", "Sushi", "Mie Ayam"
};
int harga[MAX_ITEMS] = {
    30000, 10000, 9000, 7500, 16000,
    50000, 30000, 25000, 20000, 12000
};
int jumlah_stock[MAX_ITEMS] = {
    50, 40, 60, 70, 80,
    30, 35, 45, 20, 50
};
int menu_terjual[MAX_ITEMS] = {
    200, 150, 300, 90, 120,
    300, 250, 230, 210, 200
};
time_t tanggal_dibuat[MAX_ITEMS];

//! Pesanan pelanggan
int nomor_pesanan[MAX_ITEMS] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
string menu_dipesan[MAX_ITEMS] = {
    "Pizza", "Burger", "Pasta", "Salad", "Soup",
    "Steak", "Fish & Chips", "Chicken Wings", "Sushi", "Pizza"
};
int jumlah_pesanan[MAX_ITEMS] = {50, 20, 15, 5, 10, 25, 30, 5, 15, 10};  // Existing sample data
int periode_istirahat[MAX_ITEMS] = {1, 2, 1, 3, 2, 1, 3, 2, 3, 1};  // Existing sample data
string status_menu[MAX_ITEMS] = {
    "siap", "siap", "tidak siap", "siap", "siap",
    "siap", "siap", "siap", "tidak siap", "siap"
};
int waktu_produksi[MAX_ITEMS] = {
    15, 10, 20, 5, 7,
    25, 20, 15, 30
};
time_t waktu_pesan[MAX_ITEMS];
time_t waktu_selesai[MAX_ITEMS];

//! Pesanan pelanggan
// string nomor_pesanan[MAX_ITEMS];
// string menu_dipesan[MAX_ITEMS];
// int jumlah_pesanan[MAX_ITEMS];
// int periode_istirahat[MAX_ITEMS];
// string status_menu[MAX_ITEMS];
// int waktu_produksi[MAX_ITEMS];
// time_t waktu_pesan[MAX_ITEMS];
// time_t waktu_selesai[MAX_ITEMS];