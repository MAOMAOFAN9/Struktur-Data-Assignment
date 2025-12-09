# <h1 align="center">Laporan Praktikum Modul 12 - Multi Linked List</h1>
<p align="center">Rafhael Januar Turnip - 103112400209</p>

## Dasar Teori
Multi linked list merupakan struktur data di mana setiap node dapat memiliki lebih dari satu pointer, memungkinkan hubungan kompleks seperti multiple parent-child atau representasi grid dua dimensi. Struktur ini efisien untuk operasi insertion dan deletion karena fleksibilitas pointer, sering digunakan dalam aplikasi seperti word search puzzle untuk membentuk grid karakter. Berbeda dengan singly linked list, node di multi linked list memiliki beberapa data field dan pointer field untuk navigasi multidimensi.[1]

Berikut beberapa operasi dasarnya:

a. Insert Anak dan Induk.<br>
Pada operasi insert anak (child), node baru dibuat dan pointer child dari parent node diupdate untuk menunjuk ke node tersebut, sementara pointer parent dari node anak diarahkan ke induknya. Insert induk (parent) melibatkan pembuatan node baru yang pointer child-nya menunjuk ke anak yang ada, serta update pointer parent anak ke induk baru. Proses ini memerlukan traversal untuk menemukan posisi tepat, dengan kompleksitas O(1) jika pointer tail/head tersedia, seperti dalam implementasi doubly linked list yang dimodifikasi untuk multi-link.[2]

b. Delete Anak dan Induk.<br>
Delete anak dalam multi linked list mengikuti prinsip serupa dengan insertion, di mana traversal dilakukan untuk menemukan node target, kemudian pointer sibling atau child dari parent diupdate untuk melewati node anak sebelum membebaskan memori. Delete induk memerlukan penyesuaian pointer child yang menunjuk ke node induk, sering dengan reparenting ke induk alternatif atau penghapusan rekursif untuk menjaga integritas struktur. Pendekatan ini memanfaatkan modifikasi doubly linked list untuk efisiensi operasi bidirectional, menghindari traversal linear panjang.[2]

## Guided 

### 1. [Guided]

### a. [Header File]
```C++

```

### b. [Source File]

```C++

```

### c. [Main Program]

```C++

```

Dalam program guided ini

## Unguided 

### 2. [Latihan 2]

### a. [Header File]
```C++
#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <iostream>
#define Nil NULL

using namespace std;

typedef int infotypeinduk;
typedef int infotypeanak;

typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

struct listanak {
    address_anak first;
    address_anak last;
};

struct elemen_list_induk {
    infotypeinduk info;
    listanak lanak; 
    address next;
    address prev;
};

struct listinduk {
    address first;
    address last;
};

void createList(listinduk &L);
bool listEmpty(listinduk L);
address alokasi(infotypeinduk X);
void dealokasi(address &P);
void insertFirst(listinduk &L, address P);
void insertLast(listinduk &L, address P);
void insertAfter(listinduk &L, address P, address Prec);
void delFirst(listinduk &L, address &P);
void delLast(listinduk &L, address &P);
void delAfter(listinduk &L, address &P, address Prec);
void delP(listinduk &L, infotypeinduk X);
address findElm(listinduk L, infotypeinduk X);
void printInfo(listinduk L);
void createListAnak(listanak &L);
bool listEmptyAnak(listanak L);
address_anak alokasiAnak(infotypeanak X);
void dealokasiAnak(address_anak &P);
void insertFirstAnak(listanak &L, address_anak P);
void insertLastAnak(listanak &L, address_anak P);
void insertAfterAnak(listanak &L, address_anak P, address_anak Prec);
void delFirstAnak(listanak &L, address_anak &P);
void delLastAnak(listanak &L, address_anak &P);
void delAfterAnak(listanak &L, address_anak &P, address_anak Prec);
void delPAnak(listanak &L, infotypeanak X);
address_anak findElmAnak(listanak L, infotypeanak X);
void printInfoAnak(listanak L);

#endif
```
#### Full code Screenshot:
<img width="1919" height="1138" alt="Screenshot 2025-12-09 192551" src="https://github.com/user-attachments/assets/2abe5e81-35c2-4781-8129-9366c167062e" />


### b. [Source File]

```C++
#include "multilist.h"
#include <iostream>
using namespace std;

//list induk
void createList(listinduk &L) { L.first = L.last = Nil; }
bool listEmpty(listinduk L) { return L.first == Nil; }

address alokasi(infotypeinduk X) {
    address P = new elemen_list_induk;
    P->info = X;
    P->next = P->prev = Nil;
    createListAnak(P->lanak);
    return P;
}

void dealokasi(address &P) {
    address_anak c = P->lanak.first;
    while (c != Nil) {
        address_anak tmp = c;
        c = c->next;
        delete tmp;
    }
    delete P;
    P = Nil;
}

void insertFirst(listinduk &L, address P) {
    if (listEmpty(L)) L.first = L.last = P;
    else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(listinduk &L, address P) {
    if (listEmpty(L)) L.first = L.last = P;
    else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfter(listinduk &L, address P, address Prec) {
    if (!Prec) return;

    P->next = Prec->next;
    P->prev = Prec;

    if (Prec->next) {
        Prec->next->prev = P;
    } else {
        L.last = P;   
    }

    Prec->next = P;
}

void delFirst(listinduk &L, address &P) {
    P = L.first;
    if (!P) return;
    if (L.first == L.last) L.first = L.last = Nil;
    else {
        L.first = P->next;
        L.first->prev = Nil;
    }
    P->next = Nil;
}

void delLast(listinduk &L, address &P) {
    P = L.last;
    if (!P) return;
    if (L.first == L.last) L.first = L.last = Nil;
    else {
        L.last = P->prev;
        L.last->next = Nil;
    }
    P->prev = Nil;
}

void delAfter(listinduk &L, address &P, address Prec) {
    if (!Prec || !Prec->next) return;
    P = Prec->next;
    Prec->next = P->next;
    if (P->next) P->next->prev = Prec;
    else L.last = Prec;
    P->next = P->prev = Nil;
}

void delP(listinduk &L, infotypeinduk X) {
    address P = findElm(L, X), Q;
    if (!P) return;
    if (P == L.first) delFirst(L, Q);
    else if (P == L.last) delLast(L, Q);
    else delAfter(L, Q, P->prev);
    dealokasi(Q);
}

address findElm(listinduk L, infotypeinduk X) {
    for (address P = L.first; P; P = P->next)
        if (P->info == X) return P;
    return Nil;
}

void printInfo(listinduk L) {
    if (listEmpty(L)) {
        cout << "[List Kosong]\n";
        return;
    }
    for (address P = L.first; P; P = P->next) {
        cout << "[Induk " << P->info << "]";
        printInfoAnak(P->lanak);
        cout << endl;
    }
}

//list anak
void createListAnak(listanak &L) { L.first = L.last = Nil; }
bool listEmptyAnak(listanak L) { return L.first == Nil; }

address_anak alokasiAnak(infotypeanak X) {
    address_anak P = new elemen_list_anak;
    P->info = X;
    P->next = P->prev = Nil;
    return P;
}

void dealokasiAnak(address_anak &P) { delete P; P = Nil; }

void insertFirstAnak(listanak &L, address_anak P) {
    if (listEmptyAnak(L)) L.first = L.last = P;
    else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastAnak(listanak &L, address_anak P) {
    if (listEmptyAnak(L)) L.first = L.last = P;
    else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfterAnak(listanak &L, address_anak P, address_anak Prec) {
    if (!Prec) return;
    P->next = Prec->next;
    P->prev = Prec;
    if (Prec->next) Prec->next->prev = P;
    else L.last = P;
    Prec->next = P;
}

void delFirstAnak(listanak &L, address_anak &P) {
    P = L.first;
    if (!P) return;
    if (L.first == L.last) L.first = L.last = Nil;
    else {
        L.first = P->next;
        L.first->prev = Nil;
    }
    P->next = Nil;
}

void delLastAnak(listanak &L, address_anak &P) {
    P = L.last;
    if (!P) return;
    if (L.first == L.last) L.first = L.last = Nil;
    else {
        L.last = P->prev;
        L.last->next = Nil;
    }
    P->prev = Nil;
}

void delAfterAnak(listanak &L, address_anak &P, address_anak Prec) {
    if (!Prec || !Prec->next) return;
    P = Prec->next;
    Prec->next = P->next;
    if (P->next) P->next->prev = Prec;
    else L.last = Prec;
    P->next = P->prev = Nil;
}

void delPAnak(listanak &L, infotypeanak X) {
    address_anak P = findElmAnak(L, X), tmp;
    if (!P) return;
    if (P == L.first) delFirstAnak(L, tmp);
    else if (P == L.last) delLastAnak(L, tmp);
    else delAfterAnak(L, tmp, P->prev);
    dealokasiAnak(tmp);
}

address_anak findElmAnak(listanak L, infotypeanak X) {
    for (address_anak P = L.first; P; P = P->next)
        if (P->info == X) return P;
    return Nil;
}

void printInfoAnak(listanak L) {
    if (listEmptyAnak(L)) { cout << " -> (Tidak ada anak)"; return; }
    cout << " -> Anak: ";
    for (address_anak P = L.first; P; P = P->next)
        cout << P->info << " ";
}
```
#### Full code Screenshot:
<img width="1919" height="1137" alt="Screenshot 2025-12-09 192602" src="https://github.com/user-attachments/assets/d4e3d96b-1a8f-4826-b81f-9a5fe1ba3785" />


### c. [Main File]
```C++
#include <iostream>
#include "multilist.h"
#include "multilist.cpp"
using namespace std;

int main() {
    listinduk L;
    createList(L);

    //Tambah beberapa induk
    insertLast(L, alokasi(101));
    insertLast(L, alokasi(102));
    insertLast(L, alokasi(103));

    cout << "\nSetelah tambah induk:\n";
    printInfo(L);

    //Tambah anak ke induk 101
    address p = findElm(L, 101);
    if (p) {
        insertLastAnak(p->lanak, alokasiAnak(10));
        insertLastAnak(p->lanak, alokasiAnak(20));
    }

    //Tambah anak ke induk 102
    p = findElm(L, 102);
    if (p) insertLastAnak(p->lanak, alokasiAnak(99));

    //Tambah anak ke induk 103
    p = findElm(L, 103);
    if (p) {
        insertFirstAnak(p->lanak, alokasiAnak(5));
        insertLastAnak(p->lanak, alokasiAnak(6));
        insertLastAnak(p->lanak, alokasiAnak(7));
    }

    cout << "\nSetelah tambah anak:\n";
    printInfo(L);

    //Hapus anak 99 dari induk 102
    cout << "\nHapus anak 99 dari induk 102\n";
    p = findElm(L, 102);
    if (p) delPAnak(p->lanak, 99);
    printInfo(L);

    //Hapus induk 101 (beserta anak)
    cout << "\nHapus induk 101\n";
    delP(L, 101);
    printInfo(L);

    return 0;
}
```
#### Full code Screenshot:
<img width="1919" height="1137" alt="Screenshot 2025-12-09 192617" src="https://github.com/user-attachments/assets/5195a74f-2a25-4b5d-ac70-19f0e3a047cc" />


### 3. [Latihan 3]

### a. [Header File]
```C++
#ifndef CIRCULARLIST_H_INCLUDED
#define CIRCULARLIST_H_INCLUDED

#include <iostream>
using namespace std;

struct infotype {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
};

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertFirst(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteLast(List &L, address &P);

address findElm(List L, infotype x);
void printInfo(List L);

address createData(string nama, string nim, char jenis_kelamin, float ipk);

#endif

```
#### Full code Screenshot:
<img width="1919" height="1134" alt="Screenshot 2025-12-09 192728" src="https://github.com/user-attachments/assets/cd12ab3a-ac90-4a47-a721-76435c710558" />

### b. [Source File]

```C++
#include "circularlist.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = P;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address q = L.first;
        while (q->next != L.first) q = q->next;
        q->next = P;
        P->next = L.first;
        L.first = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address q = L.first;
        while (q->next != L.first) q = q->next;
        q->next = P;
        P->next = L.first;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first == NULL) return;

    address last = L.first;
    while (last->next != L.first) last = last->next;

    P = L.first;
    if (P == last) {
        L.first = NULL;
    } else {
        last->next = P->next;
        L.first = P->next;
    }
    P->next = NULL;
}

void deleteAfter(List &L, address Prec, address &P) {
    if (L.first == NULL || Prec == NULL) return;
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}

void deleteLast(List &L, address &P) {
    if (L.first == NULL) return;

    address prev = NULL, q = L.first;
    while (q->next != L.first) {
        prev = q;
        q = q->next;
    }

    if (prev == NULL) {
        L.first = NULL;
    } else {
        prev->next = L.first;
    }
    P = q;
    q->next = NULL;
}

address findElm(List L, infotype x) {
    if (L.first == NULL) return NULL;
    address P = L.first;

    do {
        if (P->info.nim == x.nim)
            return P;
        P = P->next;
    } while (P != L.first);

    return NULL;
}

void printInfo(List L) {
    if (L.first == NULL) {
        cout << "[List kosong]" << endl;
        return;
    }

    address P = L.first;
    do {
        cout << "Nama : " << P->info.nama << endl;
        cout << "NIM  : " << P->info.nim << endl;
        cout << "L/P  : " << P->info.jenis_kelamin << endl;
        cout << "IPK  : " << P->info.ipk << endl << endl;
        P = P->next;
    } while (P != L.first);
}

address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    return alokasi(x);
}

```
#### Full code Screenshot:
<img width="1919" height="1135" alt="Screenshot 2025-12-09 192824" src="https://github.com/user-attachments/assets/c86ef3ca-9bdf-4a78-8e50-45ad28a1f892" />

### c. [Main File]
```C++
#include <iostream>
#include "circularlist.h"
#include "circularlist.cpp"
using namespace std;

int main() {
    List L, A, B, L2;
    address P1 = NULL;
    address P2 = NULL;
    infotype x;

    createList(L);

    cout << "coba insert first, last, dan after" << endl;
    P1 = createData("Danu", "04", 'l', 4.0);
    insertFirst(L, P1);

    P1 = createData("Fahmi", "06", 'l', 3.45);
    insertLast(L, P1);

    P1 = createData("Bobi", "02", 'l', 3.71);
    insertFirst(L, P1);

    P1 = createData("Ali", "01", 'l', 3.3);
    insertFirst(L, P1);

    P1 = createData("Gita", "07", 'p', 3.75);
    insertLast(L, P1);

    x.nim = "07";
    P1 = findElm(L, x);
    P2 = createData("Cindi", "03", 'p', 3.5);
    insertAfter(L, P1, P2);

    x.nim = "02";
    P1 = findElm(L, x);
    P2 = createData("Hilmi", "08", 'p', 3.3);
    insertAfter(L, P1, P2);

    x.nim = "04";
    P1 = findElm(L, x);
    P2 = createData("Eli", "05", 'p', 3.4);
    insertAfter(L, P1, P2);

    printInfo(L);
    return 0;
}

```
#### Full code Screenshot:
<img width="1919" height="1137" alt="Screenshot 2025-12-09 192832" src="https://github.com/user-attachments/assets/494514d0-b6a9-4567-891f-50642d375341" />


## Pengerjaan Latihan Modul 12 - Multi Linked List

### Latihan 2.
<img width="576" height="40" alt="Screenshot 2025-12-09 192113" src="https://github.com/user-attachments/assets/8ab1905d-2c2a-4374-9884-48d54c602d35" />

#### Output latihan 2:
<img width="1285" height="494" alt="Screenshot 2025-12-09 193259" src="https://github.com/user-attachments/assets/489ba5d4-5f25-48fb-b8f7-38d6be10f538" />

### Latihan 3
<img width="572" height="470" alt="Screenshot 2025-12-09 192122" src="https://github.com/user-attachments/assets/6330bc06-3983-4e9a-98ef-2601de2abd53" />
<img width="596" height="868" alt="Screenshot 2025-12-09 192145" src="https://github.com/user-attachments/assets/0bedb09b-c44c-4759-ac4e-99ee1d128b8d" />
<img width="595" height="388" alt="Screenshot 2025-12-09 192153" src="https://github.com/user-attachments/assets/e9d0d9d5-dad2-4346-a3a4-99e1d23e8579" />

#### Output latihan 3:
<img width="1368" height="924" alt="Screenshot 2025-12-09 193325" src="https://github.com/user-attachments/assets/4f761847-91e7-431b-838d-2f9bfd3964ea" />


<br>
<br>
Kedua latihan ini sama-sama membahas cara mengelola data menggunakan struktur linked list, tetapi dengan bentuk yang berbeda. Latihan 2 memakai multilist yang memiliki hubungan induk–anak, sedangkan latihan 3 memakai circular doubly linked list yang menyambungkan node secara melingkar. Tujuan keduanya adalah melatih penggunaan pointer dan cara memasukkan, menghapus, serta menelusuri data.

1. Pada latihan 2 ini, program membangun sebuah multilist, di mana setiap induk bisa memiliki beberapa anak. Program mulai dengan membuat list induk, lalu menambahkan beberapa induk dan mengisi masing-masing dengan anak
   menggunakan fungsi insert. Program juga mencoba menghapus anak tertentu dan menghapus induk beserta seluruh anaknya. Hasil akhirnya ditampilkan sehingga terlihat hubungan antar induk dan anak. Latihan ini membantu
   memahami cara menangani struktur data bertingkat.
   
2. Latihan 3 membuat Circular Doubly Linked List untuk menyimpan data mahasiswa. Node saling terhubung dua arah dan membentuk lingkaran. Program menambahkan beberapa data menggunakan insert di awal, di akhir, dan
   setelah elemen tertentu. Setelah itu, isi list ditampilkan dengan melakukan traversal melingkar dari node pertama. Latihan ini menekankan bagaimana bekerja dengan list yang lebih fleksibel dan dapat ditelusuri ke dua
   arah.

## Kesimpulan
Pada materi ini, kita belajar dua jenis linked list lanjutan. Multilist mengajarkan cara membuat hubungan induk–anak dan mengelola penyisipan serta penghapusan datanya. Circular doubly linked list menunjukkan cara bekerja dengan list yang melingkar dan dapat ditelusuri dua arah. Keduanya menekankan pentingnya pengaturan pointer agar struktur tetap konsisten.

## Referensi
[1]Word Search Puzzle using Multi-Linked Lists Oleh Shivam Hareshkumar Patel &sup1;, A. Jackulin Mahariba &sup2;. diakses pada tanggal 09 Desember 2025 melalui: <br>
https://www.ijeat.org/wp-content/uploads/papers/v8i4s2/D10050484S219.pdf

[2]A New Vista of Performing Insertion and Deletion in Linked Lists Arijeet Banerjee &sup1;, Pijush Kanti Kumar &sup2;. diakses pada tanggal 09 Desember 2025 melalui: <br>
https://ijcsmc.com/docs/papers/July2022/V11I7202208.pdf





















