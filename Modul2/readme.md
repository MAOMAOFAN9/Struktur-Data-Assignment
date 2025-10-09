# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
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

### 1. [Array]

```C++
#include <iostream>

using namespace std;

int main () {
    // array 1 dimensi
    int arrID[5] = {10,20,30,40,50};
    cout << "Array 1 Dimensi" << endl;
    for (int i=0; i<5; i++) {
        cout << "arrID" << i << " = " << arrID[i] << endl; 
        
    }
    cout << endl;

    // array 2 dimensi baris & kolom
    int arr2D[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    cout << "Array 2 Dimensi" << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            cout << "arr2D[" << i << "}[" << j << "] = " << arr2D[i][j]
            << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    //array multi dimensi (3D)
    int arr3D[2][2][3] = {
    { { 1, 2, 3 }, {4, 5, 6} },
    { { 7, 8, 9} , {10, 11, 12} }   
    };
    cout << "array 3 dimensi" << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<3; k++) {
                cout << "arr3D[" << i << "][" << j << "]["
                << k << "] = " << arr3D[i][j][k] << endl;
            }
        }
    }

    return 0;
}
```
Program ini digunakan untuk menampilkan isi array satu, dua, dan tiga dimensi. Pertama, array arrID berisi lima elemen ditampilkan dengan perulangan. Lalu, array dua dimensi arr2D berukuran dua baris dan tiga kolom ditampilkan menggunakan dua loop bersarang. Terakhir, array tiga dimensi arr3D berisi angka 1–12 ditampilkan dengan tiga loop bersarang. Secara keseluruhan, program ini hanya menunjukkan cara mendeklarasikan dan menampilkan array dengan berbagai dimensi menggunakan perulangan.

### 2. [Prosedur dan Fungsi]

```C++
#include <iostream>
using namespace std;

    void tulis (int x) {
        for (int i = 1; i < x; i++){
            cout << "Baris ke-" << i << endl;
        }
}

int main() {
    int jum;
    cout << "Jumlah Baris kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}
```
Program ini meminta pengguna memasukkan jumlah baris, lalu menampilkan teks “Baris ke-” sesuai angka yang dimasukkan. Nilai input disimpan dalam variabel jum dan dikirim ke fungsi tulis, yang menggunakan perulangan for untuk menampilkan baris dari 1 sampai satu kurang dari jumlah yang dimasukkan.

### 3. [Pointer]

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main () {
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a : " << a << endl;
    cout << "Alamat a (&a) : " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat red (&ref): " << &ref << endl;


    //mengubah nilai a lewar refrence
    ref = 50;
    cout << "\nSetelah ref = 50: " << endl;
    cout << "Nilai a :" << a << endl;
    cout << "Nilai ref :" << ref << endl;

tukar(&a, &b);
cout << "After swapping, value of a : " << a << " and b=" << b << endl;

return 0;
}
```
Program ini menunjukkan penggunaan reference dan pointer. Variabel ref menjadi alias dari a, sehingga perubahan pada ref juga mengubah nilai a. Setelah itu, fungsi tukar digunakan untuk menukar nilai a dan b dengan memanfaatkan pointer.

## Unguided 

### 1. [prosedur dan fungsi]

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

