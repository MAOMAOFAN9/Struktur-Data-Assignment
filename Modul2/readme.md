# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Rafhael Januar Turnip</p>

## Dasar Teori

1. Array
Array merupakan suatu struktur data yang terdiri dari sekumpulan data dengan tipe data yang sama dan setiap data yang disimpan kedalam alamat memori disebun elemen array. Ada juga yang disebut array 2 dimensi yaitu perluasan dari konsep array satu dimensi dan array 2 dimensi ini berbentuk matriks dan elemen nya dibentuk dari baris dan kolom sehingga dapat mempresentasikan data yang lebih kompleks lagi.[1]

2. Function
Function adalah sekumpulan perintah yang memiliki nama tertentu dan digunakan untuk menjalankan suatu tugas. Function dapat menerima input (parameter) dan dapat mengembalikan nilai sebagai hasil proses.

3. Procedure
Procedure memiliki konsep serupa dengan function, namun tidak mengembalikan nilai. Biasanya digunakan untuk mengeksekusi serangkaian instruksi tanpa hasil balik.

4. Pointer
pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Pointer tidak menyimpan nilai langsung, tetapi lokasi di mana nilai itu berada. Operator & digunakan untuk mengambil alamat, sedangkan * digunakan untuk mengakses nilai di alamat tersebut. Pointer sering dipakai untuk pass by reference, manipulasi array, dan struct, namun harus digunakan hati-hati agar tidak menyebabkan error.[2]

5. Reference
Reference adalah variabel yang berfungsi sebagai nama lain dari variabel yang telah ada. Dengan reference, kita dapat bekerja langsung pada data aslinya tanpa membuat salinan baru.

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

### 1. [Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3]

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[3][3] = {
        {5, 2, 2},
        {3, 9, 7},
        {6, 1, 8}
    };
    int arrB[3][3] = {
        {2, 3, 1},
        {4, 5, 9},
        {1, 0, 2}
    };
    int arrC[3][3] = {0}; 
    int arrD[3][3] = {0};
    int arrE[3][3] = {0};

    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

 
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
    }

    cout << "Hasil pengurangan : " << endl;
    tampilkanHasil(arrD);

    cout << endl;


    for (int i = 0; i < 3; i++) {            
        for (int j = 0; j < 3; j++) {       
            for (int k = 0; k < 3; k++) {  
                arrE[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrE);

    return 0;
}
```
#### Output:
<img width="1269" height="373" alt="Screenshot 2025-10-09 080558" src="https://github.com/user-attachments/assets/803c1c48-0225-4448-aec1-8fdf791c0aa4" />


Program ini melakukan operasi penjumlahan, pengurangan, dan perkalian pada dua matriks 3x3. Matriks arrA dan arrB berisi data awal, sedangkan arrC, arrD, dan arrE digunakan untuk menyimpan hasil. Penjumlahan dan pengurangan dilakukan dengan dua perulangan, sementara perkalian menggunakan tiga perulangan bersarang untuk menghitung hasil sesuai aturan matriks. Program menampilkan semua hasil dengan fungsi tampilkanHasil.

#### Full code Screenshot:
<img width="1917" height="1136" alt="Screenshot 2025-10-09 080907" src="https://github.com/user-attachments/assets/c6e29257-18f5-45b1-acae-9aeb6ffb6e2c" />


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
[1] Algoritma dan Pemrograman: Konsep Dasar, Logika, dan Implementasi dengan C++ & Phyton Oleh Rozzi Kesuma Dinata, Novia Hasdyna. Diakses pada 9 Oktober 2025 melalui https://books.google.co.id/books?hl=id&lr=&id=6kBlEQAAQBAJ&oi=fnd&pg=PA1&dq=bahasa+pemrograman+c%2B%2B+array+2+dimensi&ots=bk_HFcsTHF&sig=Mu99cJIpT_eMiFE9BXV2aFZko5E&redir_esc=y#v=onepage&q&f=false.

[2] Belajar C++ #14: Memahami Pointer di C++ Oleh Ahmad Muhardian. Diakses pada 9 Oktober 2025 melalului https://www.petanikode.com/cpp-pointer/




