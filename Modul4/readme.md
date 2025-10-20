# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama) (ADT)</h1>
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

### 1. [Guided 1]

### a. [Header File]
```C++
//header guard digunakan untuk mencegah file  header yang sama
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adaalah data & pointer next
    dataMahasiswa isidata; //disamakan dengan di list.cpp
    address next;
};

struct linkedList { //Ini linked listnya
    address first;
};

//Semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev); //
void insertLast(linkedList &List, address nodeBaru);

#endif
```
Bagian ini berisi deklarasi struct mahasiswa, node, dan linked list, serta daftar fungsi yang digunakan untuk mengelola data pada list.

### b. [Source File]

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
Bagian ini berisi implementasi fungsi-fungsi dari header, seperti membuat list, menambah node, menghapus node, dan menampilkan isi list.

### c. [Main Program]

```C++
#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List; //nama struct disamakan (linkedList)
    address nodeA = Nil, nodeB = Nil, nodeC = Nil, nodeD = Nil, nodeE = Nil; //semua diinisialisasi Nil
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}

```
Bagian ini menjalankan proses utama program, yaitu membuat list, menambahkan data mahasiswa, dan menampilkan hasilnya ke layar.

Deskripsi Program: <br>
Program ini intinya buat menyimpen data mahasiswa pakai konsep linked list. Tiap data disimpan dalam node yang bisa disambung-sambung. Fungsinya cuma buat nambah, hapus, sama nampilin isi list biar keliatan datanya nyambung satu sama lain.

### 1. [Guided 1]

### a. [Header File]
```C++
//header guard digunakan untuk mencegah file  header yang sama
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adaalah data & pointer next
    dataMahasiswa isidata; //disamakan dengan di list.cpp
    address next;
};

struct linkedList { //Ini linked listnya
    address first;
};

//Semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev); //
void insertLast(linkedList &List, address nodeBaru);

#endif
```
Bagian ini berisi deklarasi struct mahasiswa, node, dan linked list, serta daftar fungsi yang digunakan untuk mengelola data pada list.

### b. [Source File]

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
Bagian ini berisi implementasi fungsi-fungsi dari header, seperti membuat list, menambah node, menghapus node, dan menampilkan isi list.

### c. [Main Program]

```C++
#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List; //nama struct disamakan (linkedList)
    address nodeA = Nil, nodeB = Nil, nodeC = Nil, nodeD = Nil, nodeE = Nil; //semua diinisialisasi Nil
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}

```
Bagian ini menjalankan proses utama program, yaitu membuat list, menambahkan data mahasiswa, dan menampilkan hasilnya ke layar.

Deskripsi Program: <br>
Program ini intinya buat menyimpen data mahasiswa pakai konsep linked list. Tiap data disimpan dalam node yang bisa disambung-sambung. Fungsinya cuma buat nambah, hapus, sama nampilin isi list biar keliatan datanya nyambung satu sama lain.

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


### 3. [Tukar Array dan Pointer]

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





















