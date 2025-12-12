
# Health N Mood Tracker

Program konsol sederhana (C++) untuk melacak metrik kesehatan harian dan suasana hati. Cocok sebagai tugas akademik atau demo kecil untuk mencatat asupan air, langkah, durasi tidur, serta mood harian, kemudian menampilkan ringkasan mingguan dan rekomendasi sederhana.

## Fitur

- Input data harian: asupan air (gelas), jumlah langkah, durasi tidur (jam), dan mood singkat.
- Lihat ringkasan mingguan dengan rata-rata tiap metrik.
- Rekomendasi kesehatan dasar (mis. perbandingan dengan target: 8 gelas air/hari, 5000 langkah).
- Reset data untuk memulai pencatatan baru.

## Persyaratan

- Compiler C++ yang mendukung C++17 (mis. `g++`, `clang++`, atau MSVC).
- (Opsional) `make` / `CMake` jika proyek diatur menggunakan build system.

## Kompilasi & Menjalankan (Contoh)

Jika file sumber utama ada di root dengan nama `HealthNMoodTracker.cpp`:

```bash
# Di Windows (MinGW) / WSL / Linux
g++ -std=c++17 -O2 HealthNMoodTracker.cpp -o HealthNMoodTracker

# Jalankan
./HealthNMoodTracker
```

Di Windows (Developer Command Prompt / MSVC):

```powershell
# Menggunakan cl (MSVC)
cl /std:c++17 HealthNMoodTracker.cpp /Fe:HealthNMoodTracker.exe
.
HealthNMoodTracker.exe
```

Jika proyek memiliki sumber di folder `src/`, sesuaikan perintah kompilasi:

```bash
g++ -std=c++17 -O2 src/*.cpp -o build/HealthNMoodTracker
```

## Struktur Projek (contoh)

- HealthNMoodTracker.cpp    — sumber utama (atau `src/` bila terstruktur)
- README.md                 — file ini

## Cara Penggunaan Singkat

1. Jalankan program.
2. Pilih menu untuk memasukkan data harian (masukkan hari 1–7).
3. Pilih menu untuk melihat statistik mingguan atau rekomendasi.
4. Gunakan opsi reset bila ingin mengosongkan data.

Catatan: Menu dan instruksi input bergantung pada implementasi CLI di kode sumber.

## Kontribusi

Perbaikan kecil, perbaikan bug, atau penambahan fitur dipersilakan. Buat branch baru, lakukan perubahan, lalu ajukan pull request atau beri tahu pemilik repo.

## Lisensi

Proyek ini dapat dilisensikan sesuai kebutuhan; jika tidak ada lisensi khusus, anggap menggunakan lisensi MIT untuk kemudahan penggunaan.

## Kontak

Pembuat / Pengirim tugas: Bintang Triadmaja (NIM: 250401010075)

---

Jika Anda ingin saya sesuaikan README ini lebih spesifik dengan nama file sumber, instruksi build, atau contoh output dari program, beri tahu file sumber utama atau contoh keluaran yang diharapkan.