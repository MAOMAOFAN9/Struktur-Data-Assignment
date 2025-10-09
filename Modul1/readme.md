# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Rafhael Januar Turnip</p>

## Dasar Teori

1. Percabangan <br>
Pernyataan seleksi kondisi (percabangan) yaitu melakukan pengujian untuk memilih satu dari beberapa alternatif yang tersedia. Seleksi kondisi, haruslah dapat menghasilkan nilai benar (true) atau nilai salah (false). Jika hasil seleksi kondisi bernilai benar, maka suatu pernyataan baru akan dikerjakan.

2. Perulagan. <br> 
Perulangan digunakan untuk menyederhanakan program dengan menjalankan bagian yang sama secara berulang. Dan diperlukan intruksi penghenti agar proses bisa berhenti.
dan terdapat beberapa perulangan seperti (for, while, do-while).<br>
untuk for, normal digunakan untuk perulangan yang tahu ingin mengulang berapa kali.<br>
jika while, digunakan untuk hasil yang tidak pasti, bisa lebih dari 2 _output_. dan ada syarat tertentu sebagai _trigger_ untuk mendapat hasil tertentu.<br>
sedangkan untuk do-while sama seperti while, tapi program akan menjalankannya setidaknya sekali walaupun syarat yang diminta salah.

3. Struktur. <br>
struktur bisa digunakan untuk mengelompokan variabel dan tipe data.<br>
struktur juga bisa diisi dengan array.<br>
struktur juga bisa menyimpan struktur lain yang menyimpan variabel dan tipe data.<br>

## Guided 

### 1. [Contoh Latihan]

```C++
#include <iostream>
using namespace std;

int main () {
    int a;
    int b;
    
    cout << "Masukan angka1: ";
    cin >> a;
    cout << "Masukan angka2: ";
    cin >> b;

    //operator aritmatika
    cout << "a + b = " << (a+b) << endl;
    cout << "a - b = " << (a-b) << endl;
    cout << "a * b = " << (a*b) << endl;
    cout << "a % b = " << (a%b) << endl;

    //Operator logika
    cout << "a > b = " << (a>b) << endl;
    cout << "a < b = " << (a<b) << endl;
    cout << "a >= b = " << (a>=b) << endl;
    cout << "a <= b = " << (a<=b) << endl;
    cout << "a == b = " << (a==b) << endl;
    cout << "a != b = " << (a!=b) << endl;
    return 0;
}
```
Kode di atas digunakan untuk menerima dua input angka dari pengguna, lalu menampilkan hasil operasi aritmatika dan logika menggunakan function cout untuk mengeksekusinya.

## Unguided 

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main () {
    float a;
    float b;
    
    cout << "Masukan 1: ";
    cin >> a;
    cout << "Masukan 2: ";
    cin >> b;

    cout << "a + b = " << (a+b) << endl;
    cout << "a - b = " << (a-b) << endl;
    cout << "a * b = " << (a*b) << endl;
    cout << "a / b = " << (a/b) << endl;
    return 0;
}
```
#### Output:
<img width="1102" height="180" alt="Image" src="https://github.com/user-attachments/assets/b696477b-896f-441c-a56a-f234e5b59552" />

Program ini dipakai untuk menerima dua angka dari pengguna lalu menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagiannya. Input dibaca lewat cin, kemudian hasil operasi ditampilkan ke layar dengan cout.

#### Full code Screenshot:
<img width="1917" height="1130" alt="image" src="https://github.com/user-attachments/assets/123e5b84-a175-4e64-8b75-3581f99e633f" />

### 2. [Soal 2]

```C++
#include <iostream>
using namespace std;


string bilangan (int angka) {
    
    string satuan[] = {"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan"};
 
    if (angka == 0) return "nol";
    if (angka == 10) return "sepuluh";
    if (angka == 11) return "sebelas";
    if (angka < 10) return satuan[angka];                
    if (angka < 20) return satuan[angka % 10] + " belas";  

     
    if (angka < 100) {
        int puluhan = angka / 10;   
        int sisa = angka % 10;      
        string kataPuluhan[] = {"","", "dua puluh","tiga puluh","empat puluh","lima puluh","enam puluh","tujuh puluh","delapan puluh","sembilan puluh"};
        if (sisa == 0) return kataPuluhan[puluhan];        
        return kataPuluhan[puluhan] + " " + satuan[sisa];  
    }

    if (angka == 100) return "seratus";  
    return ""; 
}

int main() {
    int angka;

    cout << "Angka: ";
    cin >> angka;
 
    if (angka < 0 || angka > 100) {
        cout << "Hanya angka 0-100" << endl;
    } else { 
        cout << "Hasil: " << bilangan(angka) << endl;
    }

    return 0;
}
```
#### Output:
<img width="1434" height="149" alt="2ops" src="https://github.com/user-attachments/assets/b8124050-2b7d-4c0f-92ec-9888ed044308" />

Program ini dipakai untuk mengubah angka 0 sampai 100 jadi tulisan. Aturannya ada di fungsi bilangan(), misalnya 1 jadi “satu”, 15 jadi “lima belas”, atau 100 jadi “seratus”. Di main(), program minta input angka, dicek apakah masih dalam 0–100, lalu hasil tulisannya ditampilkan.

#### Full code Screenshot:
<img width="1918" height="1131" alt="2fss" src="https://github.com/user-attachments/assets/d9e89e3f-1000-44cb-b9f0-9f7886b0cc9a" />


### 3. [Soal 3]

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n; i >= 1; i--) {
        for (int s = 0; s < n - i; s++) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }
    
    for (int s = 0; s < n; s++) cout << "  ";
    cout << "*" << endl;

    return 0;
}
```
#### Output:
<img width="1273" height="155" alt="3ops" src="https://github.com/user-attachments/assets/3fc7c11b-247f-40e9-aea0-6c2fdbacc4f2" />

Program ini menampilkan pola segitiga angka dengan simbol * di tengah. Angka di sisi kiri ditampilkan menurun, lalu di sisi kanan ditampilkan menaik. Spasi digunakan di awal baris agar pola terlihat rata, dan pada bagian akhir ditambahkan simbol * di tengah bawah sebagai penutup pola.

#### Full code Screenshot:
<img width="1919" height="1131" alt="3fss" src="https://github.com/user-attachments/assets/39943a9f-4e80-479e-80e8-b47f8fd19482" />


## Kesimpulan
Dari kode _guided_ dan _unguided_ yang dibuat, praktikum kali ini hanya belajar dasar-dasar C++ saja. Kode pertama buat operasi hitung sederhana, kode kedua mengubah angka jadi tulisan sampai 100, dan kode ketiga bikin pola angka dengan tanda * di tengah. Jadi kesimpulannya praktikum ini lebih ke latihan input-output, percabangan, sama perulangan supaya terbiasa pakai dasar pemrograman.

## Referensi
[1]  Konsep Dasar Algoritma dan Pemograman Menggunakan C++ Chapter#1. Diakses pada 02 Oktober 2025 melalui https://repository.unpkediri.ac.id/2466/1/55201_0701107802.pdf.
