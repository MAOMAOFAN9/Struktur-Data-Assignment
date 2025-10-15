# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Rafhael Januar Turnip</p>

## Dasar Teori

Abstract Data Type (ADT)
ADT atau Abstract Data Type adalah tipe data yang disertai dengan sekumpulan operasi dasar (primitif) yang dapat dilakukan terhadap tipe tersebut. ADT bersifat abstrak karena hanya mendefinisikan apa yang bisa dilakukan, bukan bagaimana caranya dilakukan. Dalam ADT terdapat definisi tipe, invariant (aturan tetap), dan aksioma yang berlaku. Konsep ini membantu pemrogram dalam membangun program yang lebih terstruktur dan mudah dikembangkan karena memisahkan antara spesifikasi dan implementasi. <br>

Struktur data sendiri merupakan komponen fundamental dalam pengembangan perangkat lunak yang efisien. Dalam konteks C++, ADT berperan sebagai model konseptual yang mendefinisikan tipe data beserta operasi-operasi yang dapat dilakukan tanpa mengungkapkan detail implementasinya. Berbagai jenis struktur data seperti array, linked list, stack, queue, hash table, dan tree digunakan untuk membangun dasar kode yang kuat dan efisien[1]. <br>

Komponen utama dalam ADT meliputi:
1. Konstruktor/Kreator, pemebentuk nilai type.Semua objek (variabel) bertype tersebut harus melalui konstruktor. Biasanya namanya diawali Make. <br>
2. Selector, untuk mengakses tipe komponen(biasanya namanya diawali Get). <br>
3. Prosedur pengubah nilai komponen (biasanya namanya diawali Get).
4. Tipe validator komponen, yang dipakai untuk mentest apakah dapat membentuk tipe sesuai dengan batasan.
5. Destruktor/Dealokator yaitu untuk “menghancurkan” nilai objek/variabel (sekaligus memori penyimpanannya).
6. Baca/Tulis, untuk interface dengan input/output device.
7. Operator relasional, terhadap tipe tersebut untuk mendefinisikan lebih besar, lebih kecil, sama dengan dan sebagainya.
8. Aritmatika terhadap tipe tersebut, karena biasanya aritmatika dalam bahasa C hanya terdefinisi untuk bilangan numerik.
9. Konversi dari tipe tersebut ke tipe dasar dan sebaliknya.

Implementasi ADT biasanya dibagi menjadi:
- Header file (.h): berisi definisi tipe data dan deklarasi fungsi/prosedur.
- Source file (.cpp): berisi realisasi (kode) dari fungsi dan prosedur yang dideklarasikan di header.
- Main program (driver): menguji fungsi dan prosedur dari ADT tersebut.

## Guided 

### 1. [Array]

```C++
#include <iostream>

using namespace std;

int main () {

```
Program ini digunakan untuk menampilkan isi array satu, dua, dan tiga dimensi. Pertama, array arrID berisi lima elemen ditampilkan dengan perulangan. Lalu, array dua dimensi arr2D berukuran dua baris dan tiga kolom ditampilkan menggunakan dua loop bersarang. Terakhir, array tiga dimensi arr3D berisi angka 1–12 ditampilkan dengan tiga loop bersarang. Secara keseluruhan, program ini hanya menunjukkan cara mendeklarasikan dan menampilkan array dengan berbagai dimensi menggunakan perulangan.

### 2. [Prosedur dan Fungsi]

```C++
#include <iostream>
using namespace std;

    void tulis (int x) {

```
Program ini meminta pengguna memasukkan jumlah baris, lalu menampilkan teks “Baris ke-” sesuai angka yang dimasukkan. Nilai input disimpan dalam variabel jum dan dikirim ke fungsi tulis, yang menggunakan perulangan for untuk menampilkan baris dari 1 sampai satu kurang dari jumlah yang dimasukkan.

### 3. [Pointer]

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {

```
Program ini menunjukkan penggunaan reference dan pointer. Variabel ref menjadi alias dari a, sehingga perubahan pada ref juga mengubah nilai a. Setelah itu, fungsi tukar digunakan untuk menukar nilai a dan b dengan memanfaatkan pointer.

## Unguided 

### 1. [Buat program yang dapat menyimpan data mahasiswa]

```C++
##include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> n;
    cout << endl;

    if (n > 10) {
        cout << "Jumlah mahasiswa melebihi batas!" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "NIM    : ";
        cin >> mhs[i].nim;
        cout << "UTS    : ";
        cin >> mhs[i].uts;
        cout << "UAS    : ";
        cin >> mhs[i].uas;
        cout << "Tugas  : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);

        cout << endl;
    }

    cout << "\n=== Daftar Nilai Mahasiswa ===" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "No\tNIM\t\tNama\t\tNilai Akhir" << endl;
    cout << "-----------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << mhs[i].nim << "\t\t"
             << mhs[i].nama << "\t\t"
             << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}

```
#### Output:
<img width="1269" height="373" alt="Screenshot 2025-10-09 080558" src="https://github.com/user-attachments/assets/803c1c48-0225-4448-aec1-8fdf791c0aa4" />

Program ini menyimpan data mahasiswa dan menghitung nilai akhirnya dari UTS, UAS, dan tugas, lalu menampilkan hasilnya dalam tabel.

#### Full code Screenshot:
<img width="1917" height="1136" alt="Screenshot 2025-10-09 080907" src="https://github.com/user-attachments/assets/c6e29257-18f5-45b1-acae-9aeb6ffb6e2c" />



### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel.]

```C++
#include <iostream>
using namespace std;


void tukarPointer(int *a, int *b, int *c) {

```
#### Output:
<img width="1261" height="253" alt="oss2" src="https://github.com/user-attachments/assets/b58ffb5a-b0ab-418c-87b1-07a1444cbc34" />

Program ini menukar nilai tiga variabel menggunakan pointer dan reference. Nilai awal x, y, dan z ditukar melalui fungsi tukarPointer dengan mengirim alamat variabel, lalu ditukar lagi dengan tukarReference menggunakan referensi langsung. Hasil sebelum dan sesudah pertukaran ditampilkan untuk menunjukkan perubahan nilai pada ketiga variabel.

#### Full code Screenshot:
<img width="1919" height="1136" alt="fss2" src="https://github.com/user-attachments/assets/9850fd52-6a2a-45fd-a689-24e60b30bda9" />



### 3. [Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari arrayA {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}]

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[], int n){

```
#### Output:
<img width="1259" height="422" alt="Screenshot 2025-10-09 083042" src="https://github.com/user-attachments/assets/7e7c632d-1276-49e7-a13e-2954fcf5bedb" />

Program ini menampilkan menu untuk mengolah data array. Pengguna dapat melihat isi array, mencari nilai maksimum, minimum, dan menghitung rata-rata dengan memilih opsi yang tersedia. Setiap fitur dibuat dalam fungsi terpisah, dan program akan terus berjalan sampai pengguna memilih keluar.

#### Full code Screenshot:
<img width="1915" height="1135" alt="Screenshot 2025-10-09 083100" src="https://github.com/user-attachments/assets/816b7a8c-3d8a-44b8-8ef4-09351009cb59" />


## Kesimpulan
Secara umum dari Modul 3 tentang Abstract Data Type (ADT), intinya kita belajar cara membuat tipe data sendiri beserta operasinya. Tujuannya supaya program lebih teratur dan mudah diatur. Dalam C++, ADT biasanya dipisah jadi file .h, .cpp, dan main. Secara keseluruhan, konsep ini membantu bikin kode lebih rapi dan efisien, meskipun menurut saya sendiri lebih ribet.

## Referensi
[1] Exploring the Code Foundation: A Literature Review of Data Structures in C++ Oleh RAgung Yuliyanto Nugroho, Nur Hamid Sutanto. Diakses pada 15 Oktober 2025 melalui https://international.aritekin.or.id/index.php/IJMICSE/article/view/47/73

[2] Belajar C++ #14: Memahami Pointer di C++ Oleh Ahmad Muhardian. Diakses pada 9 Oktober 2025 melalului https://www.petanikode.com/cpp-pointer/















