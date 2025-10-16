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

### 1. ADT Struct]

### a. [Header File]
```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2 (mahasiswa m);
#endif // MAHASISWA_H_INCLUDED
```
Bagian ini berisi deklarasi struct mahasiswa yang menyimpan data NIM serta dua nilai. Selain itu, terdapat deklarasi fungsi inputMhs() untuk memasukkan data mahasiswa dan rata2() untuk menghitung nilai rata-rata.

### b. [Source File]

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m){
cout << "input nama : ";
cin >> (m).nim;
cout << "input nilai : ";
cin >> (m).nilai1;
cout << "input nilai2 : ";
cin >> (m).nilai2;

}
float rata2(mahasiswa m){
 return float(m.nilai1+m.nilai2)/2;
}
```
Bagian ini berisi definisi fungsi dari file header. <br>
Fungsi inputMhs() digunakan untuk menerima input data mahasiswa dari pengguna, sedangkan fungsi rata2() digunakan untuk menghitung dan mengembalikan nilai rata-rata dari dua nilai yang dimasukkan.

### c. [Main Program]

```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main(){
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata = " << rata2(mhs);
    return 0;
}
```
Bagian utama program yang menjalankan proses utama. Program akan memanggil inputMhs() untuk mengisi data mahasiswa, kemudian memanggil rata2() untuk menghitung rata-rata dan menampilkan hasilnya ke layar.

Deskripsi Program: <br>
Program ini menggunakan struct sebagai ADT untuk menyimpan data mahasiswa. Data diinput melalui fungsi inputMhs(), kemudian rata-rata dari dua nilai dihitung dengan fungsi rata2() dan ditampilkan ke layar.

## Unguided 

### 1. [Data Mahasiswa]

```C++
#include <iostream>
using namespace std;

struct mhs{
    string nama,nim;
    float uts,uas,tugas,nilaiAkhir;
};

float hitung(float u,float a,float t){
    return (0.3*u)+(0.4*a)+(0.3*t);
}

int main(){
    mhs M[10];
    int n;
    cout<<"Masukkan jumlah mahasiswa (max 10): ";
    cin>>n;
    if(n>10){
        cout<<"Kebanyakan, max 10 aja\n";
        return 0;
    }
    for(int i=0;i<n;i++){
        cout<<"\nMahasiswa ke-"<<i+1<<endl;
        cout<<"Nama : ";
        cin.ignore();
        getline(cin,M[i].nama);
        cout<<"NIM  : ";
        cin>>M[i].nim;
        cout<<"UTS  : ";
        cin>>M[i].uts;
        cout<<"UAS  : ";
        cin>>M[i].uas;
        cout<<"Tugas: ";
        cin>>M[i].tugas;
        M[i].nilaiAkhir=hitung(M[i].uts,M[i].uas,M[i].tugas);
    }
    cout<<"\nDaftar Nilai Mahasiswa\n";
    cout<<"-----------------------------\n";
    cout<<"No\tNIM\t\tNama\t\tNilAkhir\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<"\t"<<M[i].nim<<"\t\t"<<M[i].nama<<"\t\t"<<M[i].nilaiAkhir<<endl;
    }
    return 0;
}
```
#### Output:
<img width="1262" height="532" alt="s1 ss" src="https://github.com/user-attachments/assets/c1a7feae-0dab-489a-931a-c637c1e2ac4e" />

Program ini pakai struct buat menyimpan data mahasiswa. Nilai akhir dihitung dari UTS, UAS, dan tugas lewat fungsi hitungNilaiAkhir, lalu hasilnya ditampilin dalam bentuk tabel.

#### Full code Screenshot:
<img width="1919" height="1141" alt="s1 fss" src="https://github.com/user-attachments/assets/27a28b6c-b253-4bc9-b74a-25f8c06c84b5" />


### 2. [ADT Pelajaran]

### a. [Header File]
```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```
Berisi struct pelajaran untuk menyimpan nama dan kode mata pelajaran, serta deklarasi fungsi terkait.

### b. [Source File]

```C++
#include "pelajaran.h"
#include <iostream>
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "=== Data Pelajaran ===" << endl;
    cout << "Nama Mata Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode Mata Pelajaran : " << pel.kodeMapel << endl;
}
```
Berisi fungsi create_pelajaran() untuk membuat data pelajaran dan tampil_pelajaran() untuk menampilkannya.

### c. [Main Program]

```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    return 0;
}
```
Membuat objek pelajaran baru lalu menampilkan datanya ke layar.

#### Output:
<img width="873" height="146" alt="s2 ss" src="https://github.com/user-attachments/assets/610f6af3-7092-45ad-b676-65224e6a804b" />

Program ini pakai struct sebagai ADT buat nyimpen nama dan kode pelajaran. Data dibuat lewat fungsi create_pelajaran, lalu ditampilin ke layar pakai tampil_pelajaran biar pengguna bisa lihat hasilnya.

#### Full code Screenshot:
<img width="1917" height="1139" alt="s2 fss" src="https://github.com/user-attachments/assets/87104152-690f-48b1-bd40-dfb0b754a33a" />


### 3. [Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari arrayA {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}]

```C++
#include <iostream>
using namespace std;

void tampil(int a[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void tukarArr(int x[3][3], int y[3][3], int r, int c){
    int tmp = x[r][c];
    x[r][c] = y[r][c];
    y[r][c] = tmp;
}

void tukarPtr(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int A[3][3] = {{3,16,9},{1,12,1},{2,51,8}};
    int B[3][3] = {{21,3,5},{7,9,23},{4,65,8}};
    int *p1, *p2;
    int n1=10, n2=20;

    p1=&n1;
    p2=&n2;

    cout<<"Array A:"<<endl;
    tampil(A);
    cout<<"Array B:"<<endl;
    tampil(B);

    cout<<"\nTukar posisi (1,1)"<<endl;
    tukarArr(A,B,1,1);

    cout<<"Array A sekarang:"<<endl;
    tampil(A);
    cout<<"Array B sekarang:"<<endl;
    tampil(B);

    cout<<"\nNilai sebelum tukar pointer: "<<n1<<" dan "<<n2<<endl;
    tukarPtr(p1,p2);
    cout<<"Nilai sesudah tukar pointer: "<<n1<<" dan "<<n2<<endl;

    return 0;
}
```
#### Output:
<img width="1259" height="531" alt="s3 ss" src="https://github.com/user-attachments/assets/95ef3d82-f84d-43b5-be3b-476294fed2bc" />

Program ini menampilkan dua array 3x3, menukar elemen tertentu antar array, dan menukar nilai dua variabel menggunakan pointer. Hasil perubahan ditampilkan agar terlihat efek tukarnya.

#### Full code Screenshot:
<img width="1919" height="1137" alt="s3 fss" src="https://github.com/user-attachments/assets/7d40f181-906d-4685-b349-2b5b6f6025cc" />


## Kesimpulan
Secara umum dari Modul 3 tentang Abstract Data Type (ADT), intinya kita belajar cara membuat tipe data sendiri beserta operasinya. Tujuannya supaya program lebih teratur dan mudah diatur. Dalam C++, ADT biasanya dipisah jadi file .h, .cpp, dan main. Secara keseluruhan, konsep ini membantu bikin kode lebih rapi dan efisien, meskipun menurut saya sendiri lebih ribet.

## Referensi
[1] Exploring the Code Foundation: A Literature Review of Data Structures in C++ Oleh RAgung Yuliyanto Nugroho, Nur Hamid Sutanto. Diakses pada 15 Oktober 2025 melalui https://international.aritekin.or.id/index.php/IJMICSE/article/view/47/73



















