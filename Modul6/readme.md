# <h1 align="center">Laporan Praktikum Modul 6 - Double Linked List (Bagian Kedua) (ADT)</h1>
<p align="center">Rafhael Januar Turnip - 103112400209</p>

## Dasar Teori

Doubly Linked List (DLL)<br>
Salah satu struktur data yang setiap simpulnya memiliki dua pointer — satu menunjuk ke simpul berikutnya dan satu lagi ke simpul sebelumnya — disebut **Doubly Linked List**. Struktur ini memungkinkan proses *traversal* dilakukan ke dua arah, yaitu maju dan mundur, sehingga lebih fleksibel dalam pengelolaan data dibandingkan Singly Linked List.<br>

Doubly Linked List Daftar tertaut ganda adalah struktur data tertaut yang terdiri dari sekumpulan rekaman yang terhubung secara berurutan yang disebut node. Setiap node berisi tiga bidang: dua bidang tautan dan satu bidang data. Tautan sebelumnya dan berikutnya dari simpul awal dan akhir, masing-masing, mengarah ke semacam terminator, biasanya simpul sentinel atau null, untuk memudahkan penelusuran daftar.[1]. <br>

Operasi Dasar. <br>
Beberapa operasi dasar pada Doubly Linked List meliputi: <br>
- Insert: menambah elemen baru ke dalam list, bisa di awal (insert first), di akhir (insert last), setelah elemen tertentu (insert after), atau sebelum elemen tertentu (insert before).<br>
- Delete: menghapus elemen dari list, baik dari awal, akhir, atau di posisi tertentu (delete first, delete last, delete after, delete before).<br>
- Update, View, dan Search: digunakan untuk memperbarui, menampilkan, dan mencari data, mirip dengan operasi pada Singly Linked List namun lebih fleksibel karena akses bisa dua arah.<br>

Dalam implementasi, DLL mempunyai beberapa elemen utama: first/head menunjuk simpul pertama, last/tail menunjuk simpul terakhir, dan setiap node memiliki data, next, dan prev. Misalnya: apabila ingin menyisipkan setelah suatu node, maka cukup mengubah next dan prev dari simpul yang relevan. Begitu juga untuk penghapusan — lebih sederhana dibanding daftar satu arah karena pointer sebelumnya sudah tersedia.<br>

Dalam penerapannya, DLL memberikan kemudahan dalam penyisipan dan penghapusan data karena dapat dilakukan dari dua arah tanpa perlu menelusuri list dari awal. Konsep dua arah ini juga membantu dalam efisiensi proses pengelolaan memori dan mempercepat akses ke elemen tertentu. Dalam konteks sistem yang lebih kompleks, struktur ini bahkan bisa dikembangkan menjadi non-blocking doubly linked list, di mana beberapa proses dapat mengakses dan memodifikasi data secara bersamaan tanpa saling mengganggu.<br>

Menurut Shafiei (2015) dalam penelitiannya berjudul Non-Blocking Doubly-Linked Lists with Good Amortized Complexity,<br>
Implementasi daftar tertaut ganda non-pemblokiran untuk sistem memori bersama asinkron. Ini adalah implementasi pertama yang batas atas kompleksitas waktu amortisasinya telah dibuktikan. Dalam implementasi kami, operasi mengakses daftar melalui kursor. Kursor dapat digunakan untuk melintasi dan memperbarui daftar, bahkan ketika operasi konkuren memodifikasi daftar. Implementasi ini mendukung dua operasi pembaruan, insertBefore dan delete, serta dua operasi pemindahan, moveRight dan moveLeft. Operasi pembaruan menggunakan instruksi Compare&Swap satu kata. Operasi pemindahan hanya membaca memori bersama dan tidak pernah mengubah status struktur data. Jika semua operasi pembaruan memodifikasi bagian daftar yang berbeda, operasi tersebut berjalan sepenuhnya secara konkuren. Kompleksitas langkah amortisasi adalah O(c˙(op)) untuk setiap operasi pembaruan dan O(1) untuk setiap pemindahan[2].<br>

Pernyataan ini menunjukkan bahwa struktur DLL dapat dioptimalkan agar tetap efisien meskipun digunakan dalam lingkungan konkuren atau paralel. Setiap operasi penyisipan, penghapusan, dan pergerakan elemen tetap memiliki performa yang stabil serta mempertahankan konsistensi data antar proses yang berjalan bersamaan.<br>




## Guided 

### 1. [List Makanan]

### a. [Header File]
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

### b. [Source File]

```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

### c. [Main Program]

```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```

Program ini berfungsi untuk menginputkan beberapa buah dengan fungsi insert dan mengubah urutannya dengan fungsi updatefirst, updatelast, dan update before


### 2. [List Makanan Lanjutan]

### a. [Header File]
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```

### b. [Source File]

```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nama == nama){
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.jenis == jenis){
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.rating >= minRating){
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(nodeNext == Nil || nodeNext->prev == Nil){
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if(nodeNext->prev == List.first){
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target){
    if(isEmpty(List) == true || target == Nil){
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if(target == List.first){
        deleteFirst(List);
    } else if(target == List.last){
        deleteLast(List);
    } else {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nama != nama){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```

### c. [Main Program]

```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```
Program ini berfungsi untuk menampilkan hasil update, setelah itu mencari data dengan fungsi searchbyname dan menghapus data dengan data, menghapus data berdasarkan data yang pertama dan menghapus dataBefore.

## Unguided 

### [ADT Doubly Linked List / Data Kendaraan]

### a. [Header File / "doublylist.h"]
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

using namespace std;

#define Nil NULL

struct infotype {
    string nopol;
    string warna;
    int thnBuat;
};

typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
bool isEmpty(List L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);

void printInfo(List L);
address findElm(List L, string nopol);

void searchAndPrintAll(List L, string nopol);

int deleteAllMatches(List &L, string nopol);

#endif
```
#### Full code Screenshot:
<img width="1917" height="1134" alt="Screenshot 2025-11-13 193108" src="https://github.com/user-attachments/assets/e24fede4-fd33-4a08-82d0-111593ec4d61" />


### b. [Source File / "doublylist.cpp"]

```C++
#include "doublylist.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

bool isEmpty(List L) {
    return (L.First == Nil && L.Last == Nil);
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    if (isEmpty(L)) {
        cout << "DATA LIST KOSONG" << endl;
        return;
    }
    
    address P = L.Last;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

address findElm(List L, string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void searchAndPrintAll(List L, string nopol) {
    address P = L.First;
    bool found = false;
    
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            cout << "Nomor Polisi : " << P->info.nopol << endl;
            cout << "Warna        : " << P->info.warna << endl;
            cout << "Tahun        : " << P->info.thnBuat << endl;
            cout << "-----------------" << endl;
            found = true;
        }
        P = P->next;
    }
    
    if (!found) {
        cout << "Data dengan nomor polisi " << nopol << " tidak ditemukan." << endl;
    }
}

int deleteAllMatches(List &L, string nopol) {
    int count = 0;
    address P = L.First;
    
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            address Pdel = P;
            P = P->next;
            
            if (Pdel == L.First) {
                deleteFirst(L, Pdel);
            } else if (Pdel == L.Last) {
                deleteLast(L, Pdel);
            } else {
                address Prec = Pdel->prev;
                deleteAfter(L, Prec, Pdel);
            }
            dealokasi(Pdel);
            count++;
            
        } else {
            P = P->next;
        }
    }
    return count;
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;
        L.First->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    P = Prec->next;
    if (P == L.Last) {
        deleteLast(L, P);
    } else {
        Prec->next = P->next;
        P->next->prev = Prec;
        P->next = Nil;
        P->prev = Nil;
    }
}
```
#### Full code Screenshot:
<img width="1919" height="1140" alt="Screenshot 2025-11-13 193128" src="https://github.com/user-attachments/assets/ddc924ca-477f-4753-9a82-2ea5f3f93710" />

### c. [Main Program / "main.cpp"]

```C++
#include <iostream>
#include "doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    
    address P;
    infotype data;
    string nopolCari, nopolHapus;

    cout << "Program Input Data Kendaraan" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> data.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> data.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> data.thnBuat;

        P = alokasi(data);
        insertLast(L, P);
        
        cout << "-------------------------------" << endl;
    }

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);
    cout << endl;

    cout << "Program Pencarian Data" << endl;
    cout << "Masukkan Nomor Polisi yang dicari: ";
    cin >> nopolCari;

    searchAndPrintAll(L, nopolCari);
    
    cout << endl;

    cout << "Program Hapus Data" << endl;
    cout << "Masukkan Nomor Polisi yang akan dihapus: ";
    cin >> nopolHapus;
    
    int deleteCount = deleteAllMatches(L, nopolHapus);
    
    if (deleteCount > 0) {
        cout << "Sebanyak " << deleteCount << " data dengan nomor polisi " 
             << nopolHapus << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan nomor polisi " << nopolHapus << " tidak ditemukan." << endl;
    }
    cout << endl;

    cout << "DATA LIST 1 (Setelah Dihapus)" << endl;
    printInfo(L);
    
    return 0;
}
```
#### Full code Screenshot:
<img width="1919" height="1137" alt="Screenshot 2025-11-13 193049" src="https://github.com/user-attachments/assets/751bb7a5-2693-4cc8-9949-98d2b8d7f881" />

<br>
<br>

### LATIHAN <br>

### 1. [Buatlah implementasi ADT Doubly Linked list pada file “Doublylist.cpp” dan coba hasil implementasi ADT pada file “main.cpp”.]
#### Output:
<img width="991" height="728" alt="Screenshot 2025-11-13 192554" src="https://github.com/user-attachments/assets/dcf160fb-191b-4da7-8771-58ebc7dd78f5" />


### 2. [Buat fungsi findElm(L, x) untuk mencari elemen dengan info = 8 dan mengembalikan alamat node tersebut]
#### Output:
<img width="360" height="227" alt="Screenshot 2025-11-13 192605" src="https://github.com/user-attachments/assets/c837cb07-410f-42fe-bc62-78f9e49dbf14" />


### 3. [Hapus elemen dengan nomor polisi D003 dengan procedure delete]
#### Output:
<img width="662" height="341" alt="Screenshot 2025-11-13 192614" src="https://github.com/user-attachments/assets/283415a8-b7ee-4adc-b045-81a7c9a3c099" />


#### Full code Screenshot:
### a. ["doublylist.h"]
#### Output:
<img width="1917" height="1134" alt="Screenshot 2025-11-13 193108" src="https://github.com/user-attachments/assets/e24fede4-fd33-4a08-82d0-111593ec4d61" />

### b. ["doublylist.cpp"]
#### Output:
<img width="1919" height="1140" alt="Screenshot 2025-11-13 193128" src="https://github.com/user-attachments/assets/ddc924ca-477f-4753-9a82-2ea5f3f93710" />

### c. ["main.cpp"]
#### Output:
<img width="1919" height="1137" alt="Screenshot 2025-11-13 193049" src="https://github.com/user-attachments/assets/751bb7a5-2693-4cc8-9949-98d2b8d7f881" />


Sistem Manajemen Data Kendaraan yang menggunakan struktur data Doubly Linked List (Daftar Berantai Dua Arah) untuk menyimpan dan mengelola informasi Nomor Polisi, Warna, dan Tahun Pembuatan secara dinamis. Inti dari program ini adalah mengizinkan data yang duplikat (Nomor Polisi yang sama boleh dimasukkan lebih dari satu kali) dan menyediakan fungsionalitas lanjutan (searchAndPrintAll dan deleteAllMatches) untuk mencari serta menghapus semua data kendaraan yang cocok dengan kriteria yang diberikan, bukan hanya data pertama.

## Kesimpulan
pengaplikasian Doubly Linked List (DLL), sebuah struktur data yang efisien karena setiap simpulnya memiliki dua penunjuk (next dan prev), memungkinkan traversal dua arah (maju dan mundur), seperti yang dijelaskan dalam teori. Sementara operasi dasar DLL secara alami mendukung pencarian dan penghapusan data, modifikasi pada program latihan Anda untuk mengizinkan dan mengelola duplikat (Nomor Polisi ganda) melalui fungsi khusus (searchAndPrintAll dan deleteAllMatches) menunjukkan kemampuan fleksibel DLL dalam menangani kompleksitas data, sejalan dengan konsep teori bahwa DLL mudah dioptimalkan untuk penyisipan dan penghapusan data di posisi manapun.

## Referensi
[1] Doubly linked list oleh: Wikipedia. Diakses pada 28 Oktober 2025 melalui: <br>
https://en.wikipedia.org/wiki/Doubly_linked_list <br>
[2] Non-Blocking Doubly-Linked Lists with Good Amortized Complexity oleh: Niloufar Shafiei. Diakses pada 13 November 2025 melalui: <br>
https://drops.dagstuhl.de/storage/00lipics/lipics-vol046-opodis2015/LIPIcs.OPODIS.2015.35/LIPIcs.OPODIS.2015.35.pdf <br>




















