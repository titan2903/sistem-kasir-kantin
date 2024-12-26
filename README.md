# README.md

## Kelompok 13

1. Titanio Yudista
2. Fairuz Fajri
3. Muhammad Haikal
4. Muhammad Taqi Dzakwan

## Software Requirements

### Sistem Kasir untuk Kantin

#### Sebagai Owner

- **Rush Hour Management:**
  - **Pengelolaan Jam Sibuk:**
    1. Saya ingin lihat total pesanan per periode istirahat.
    2. Saya ingin lihat stok makanan menjelang istirahat.
  - **Kapasitas Layanan:**
    1. Saya ingin lihat rata-rata waktu layanan per hari.
    2. Saya ingin lihat jumlah pesanan per jenis makanan.

- **Food Management:**
  - **Kontrol Stok:**
    1. Saya ingin update stok makanan tersedia.
    2. Saya ingin lihat sisa stok per menu.
  - **Analisis Menu:**
    1. Saya ingin lihat total penjualan per menu.
    2. Saya ingin lihat menu yang paling laku per hari.

#### Sebagai Staff

- **Service Operation:**
  - **Proses Penjualan:**
    1. Saya ingin input pesanan pelanggan:
       - Nomor pesanan.
       - Menu yang dipesan.
       - Jumlah pesanan.
    2. Saya ingin lihat status stok saat ini.
  - **Persiapan Menu:**
    1. Saya ingin input stok awal per menu.
    2. Saya ingin update pengurangan stok otomatis.

- **Kitchen Operation:**
  - **Produksi Menu:**
    1. Saya ingin catat waktu produksi menu.
    2. Saya ingin input porsi standar per menu.
  - **Kontrol Kualitas:**
    1. Saya ingin checklist menu siap jual:
       - Nama menu.
       - Status siap.
       - Waktu persiapan.

## Flow Navigasi Sistem Kasir untuk Kantin

![Gambar Flow Navigasi Sistem Kasir untuk Kantin](assets/navigasi%20aplikasi.drawio.png)

## Prerequisites

Sebelum Anda memulai, pastikan Anda telah memenuhi kebutuhan berikut:

### Sistem Operasi

- **Windows**: Windows 10 atau lebih baru.
- **macOS**: macOS 10.15 Catalina atau lebih baru.
- **Linux**: Distro Linux berbasis Debian (seperti Ubuntu), Fedora, atau CentOS.

### Perangkat Lunak

- **Compiler C++**: GCC, Clang, atau MSVC.
- **CMake**: Versi 3.15 atau lebih baru (opsional, jika proyek Anda menggunakan CMake).

### Instalasi Compiler C++

#### Windows

1. **Menggunakan Visual Studio:**
   - Unduh dan instal [Visual Studio](https://visualstudio.microsoft.com/downloads/).
   - Selama instalasi, pilih workload "Desktop development with C++" untuk menginstal MSVC.

2. **Menggunakan MinGW:**
   - Unduh MinGW dari [MinGW-w64](https://www.mingw-w64.org/downloads/).
   - Ikuti instruksi instalasi dan pastikan `g++.exe` terdapat dalam PATH sistem Anda.

#### macOS

1. **Menggunakan Xcode:**
   - Instal Xcode dari Mac App Store.
   - Buka Xcode dan instal alat baris perintah melalui `Preferences > Downloads`.

2. **Menggunakan Homebrew:**
   - Instal Homebrew dengan menjalankan:

     ```bash
     /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
     ```

   - Instal GCC dengan Homebrew:

     ```bash
     brew install gcc
     ```

#### Linux (Ubuntu)

1. **Menggunakan apt:**
   - Buka terminal dan jalankan perintah berikut:

     ```bash
     sudo apt update
     sudo apt install build-essential
     ```

   - Perintah ini akan menginstal GCC, G++ dan make.

### Verifikasi Instalasi

Untuk memverifikasi bahwa compiler C++ telah terinstal dengan benar, buka terminal atau command prompt dan ketik:

```bash
g++ --version
```

## Run

1. **Clone Repository:**

   ```bash
   https://github.com/titan2903/sistem-kasir-kantin.git
   ```

2. **Run System Application:**

  ```bash
  g++ -I../include src/main.cpp src/role.cpp src/owner_menu.cpp src/staff_menu.cpp src/menu_data.cpp -o src/output && ./src/output
  ```
