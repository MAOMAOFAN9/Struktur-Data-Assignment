#include <iostream>
#include "StackMahasiswa.h"

using namespace std;

int main() {
    StackMahasiswa SM;

    // 1) Buat stack kosong
    createStack(SM);
    
    cout << "Program Stack Mahasiswa Dimulai..." << endl;

    // 2) Input data mahasiswa (Menggunakan Push parameter agar otomatis terisi)
    // Data 1: Venti
    Push(SM, {"Venti", "11111", 75.7, 82.1, 65.5});
    // Data 2: Xiao
    Push(SM, {"Xiao", "22222", 87.4, 88.9, 81.9});
    // Data 3: Kazuha
    Push(SM, {"Kazuha", "33333", 92.3, 88.8, 82.4});
    // Data 4: Wanderer
    Push(SM, {"Wanderer", "44444", 95.5, 85.5, 90.5});
    // Data 5: Lynette
    Push(SM, {"Lynette", "55555", 77.7, 65.4, 79.9});
    // Data 6: Chasca
    Push(SM, {"Chasca", "66666", 99.9, 93.6, 87.3});

    // 3) Tampilkan stack yang sudah diinputkan
    cout << "\n[Step 3] Menampilkan Data Awal:";
    View(SM);

    // 4) Lakukan pop sebanyak 1x (Chasca akan dihapus)
    cout << "\n[Step 4] Melakukan Pop 1x...";
    Pop(SM);

    // 5) Tampilkan stack setelah pop
    cout << "\n[Step 5] Data Setelah Pop:";
    View(SM);

    // 6) Update data pada posisi ke 3 (Asumsi Indeks 3)
    //    Rincian Data: Heizou, 77777, 99.9, 88.8, 77.7
    //    Catatan: Karena prosedur Update meminta input manual, user harus mengetik data Heizou.
    cout << "\n[Step 6] Melakukan Update Posisi ke-3 (Indeks 3: Wanderer)..." << endl;
    cout << "Silakan masukkan data 'Heizou' sesuai soal:" << endl;
    Update(SM, 3);

    // 7) Tampilkan stack setelah update
    cout << "\n[Step 7] Data Setelah Update:";
    View(SM);

    // 8) Searching Nilai Akhir rentang 85.5 - 95.5
    cout << "\n[Step 8] Searching Data...";
    SearchNilaiAkhir(SM, 85.5, 95.5);

    // Bagian B: Pemanggilan MaxNilaiAkhir
    cout << "\n[Bagian B] Mencari Nilai Maksimum...";
    MaxNilaiAkhir(SM);

    return 0;
}