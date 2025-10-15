# <h1 align="center">Laporan Praktikum Modul 2 Pengenalan Bahasa C++ (Bagian Kedua) (2)</h1>
<p align="center">Rafhael Januar Turnip</p>

## Dasar Teori

1. Array <br>
Array merupakan suatu struktur data yang terdiri dari sekumpulan data dengan tipe data yang sama dan setiap data yang disimpan kedalam alamat memori disebun elemen array. Ada juga yang disebut array 2 dimensi yaitu perluasan dari konsep array satu dimensi dan array 2 dimensi ini berbentuk matriks dan elemen nya dibentuk dari baris dan kolom sehingga dapat mempresentasikan data yang lebih kompleks lagi.[1]

2. Function <br>
Function adalah sekumpulan perintah yang memiliki nama tertentu dan digunakan untuk menjalankan suatu tugas. Function dapat menerima input (parameter) dan dapat mengembalikan nilai sebagai hasil proses.

3. Procedure <br>
Procedure memiliki konsep serupa dengan function, namun tidak mengembalikan nilai. Biasanya digunakan untuk mengeksekusi serangkaian instruksi tanpa hasil balik.

4. Pointer <br>
pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Pointer tidak menyimpan nilai langsung, tetapi lokasi di mana nilai itu berada. Operator & digunakan untuk mengambil alamat, sedangkan * digunakan untuk mengakses nilai di alamat tersebut. Pointer sering dipakai untuk pass by reference, manipulasi array, dan struct, namun harus digunakan hati-hati agar tidak menyebabkan error.[2]

5. Reference <br>
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



### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel.]

```C++
#include <iostream>
using namespace std;


void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;   
    *a = *b;         
    *b = *c;         
    *c = temp;     
}
void tukarReference(int &a, int &b, int &c) {
    int temp = a;   
    a = b;          
    b = c;           
    c = temp;       
}
int main() {
    int x = 10, y = 20, z = 30;

    cout << "Sebelum ditukar:" << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    tukarPointer(&x, &y, &z);
    cout << "\nSetelah ditukar dengan Pointer:" << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    tukarReference(x, y, z);
    cout << "\nSetelah ditukar dengan Reference:" << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    return 0;
}
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
    cout << "Isi array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

int cariMIN(int arr[], int ukuran){
    int MIN = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] < MIN){
            MIN = arr[i];
        }
    }
    return MIN;
}

float NilaiRataRata(int arr[], int n){
    int total = 0;
    for(int i = 0; i < n; i++){
        total += arr[i];
    }
    return (float)total / n;
}

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int inputan;

    do {
        cout << "\n-- Menu Program Array --\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Masukkan Inputan: ";
        cin >> inputan;

        switch (inputan){
            case 1:
                tampilArray(arrA, 10); break;
            case 2:
                cout << "Nilai Maksimumnya adalah: " << cariMAX(arrA, 10) << endl; break;
            case 3:
                cout << "Nilai Minimumnya adalah: " << cariMIN(arrA, 10) << endl; break;
            case 4:
                cout << "Nilai rata ratanya adalah: " << NilaiRataRata(arrA, 10) << endl; break;
            case 5:
                cout << "Program selesai\n"; break;
        }
    } while (inputan != 5);

    return 0;
}

```
#### Output:
<img width="1259" height="422" alt="Screenshot 2025-10-09 083042" src="https://github.com/user-attachments/assets/7e7c632d-1276-49e7-a13e-2954fcf5bedb" />

Program ini menampilkan menu untuk mengolah data array. Pengguna dapat melihat isi array, mencari nilai maksimum, minimum, dan menghitung rata-rata dengan memilih opsi yang tersedia. Setiap fitur dibuat dalam fungsi terpisah, dan program akan terus berjalan sampai pengguna memilih keluar.

#### Full code Screenshot:
<img width="1915" height="1135" alt="Screenshot 2025-10-09 083100" src="https://github.com/user-attachments/assets/816b7a8c-3d8a-44b8-8ef4-09351009cb59" />


## Kesimpulan
Pada pertemuan ini, mahasiswa mempelajari cara membuat menu sederhana yang berisi beberapa fungsi dan prosedur, serta bagaimana mengubah nilai variabel menggunakan dua metode berbeda, yaitu melalui pointer dan reference.

## Referensi
[1] Algoritma dan Pemrograman: Konsep Dasar, Logika, dan Implementasi dengan C++ & Phyton Oleh Rozzi Kesuma Dinata, Novia Hasdyna. Diakses pada 9 Oktober 2025 melalui https://books.google.co.id/books?hl=id&lr=&id=6kBlEQAAQBAJ&oi=fnd&pg=PA1&dq=bahasa+pemrograman+c%2B%2B+array+2+dimensi&ots=bk_HFcsTHF&sig=Mu99cJIpT_eMiFE9BXV2aFZko5E&redir_esc=y#v=onepage&q&f=false.

[2] Belajar C++ #14: Memahami Pointer di C++ Oleh Ahmad Muhardian. Diakses pada 9 Oktober 2025 melalului https://www.petanikode.com/cpp-pointer/













