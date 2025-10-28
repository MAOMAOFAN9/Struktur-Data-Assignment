# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua) (ADT)</h1>
<p align="center">Rafhael Januar Turnip</p>

## Dasar Teori

Searching <br>
Searching merupakan operasi dasar pada list untuk mencari node tertentu dengan menelusuri setiap node hingga ditemukan. Proses ini memudahkan operasi-operasi seperti insert after, delete after, dan update. Semua fungsi dasar tersebut merupakan bagian dari ADT pada singly linked list dan diimplementasikan dalam file .c dan .h.<br>

Dalam Linked List, proses pencarian berjalan lambat karena harus dilakukan secara berurutan (sequential search). Namun, kecepatan pencarian dapat ditingkatkan dengan menambahkan indeks pada list.[1]<br>
Teknik seperti menambahkan lane linked list sebagai indeks dapat membantu melewati beberapa node sehingga proses pencarian menjadi lebih cepat: <br>
Kami menggunakan lane untuk mengunjungi dan memeriksa jumlah node seminimal mungkin. Saat menggunakan lane, beberapa node yang berada di antara node lane saat ini dan node lane sebelumnya akan dilewati sesuai dengan pembagian yang telah ditentukan. Dengan melewati beberapa node ini, waktu yang dibutuhkan untuk memeriksa node-node di antara dua node lane tersebut juga dapat dihemat.[1]<br>
Dengan begitu, meskipun ADT singly linked list sangat berguna untuk operasi dinamis, aspek pencarian memerlukan perhatian khusus dan optimasi agar kinerjanya lebih baik.

## Guided 

### [ADT ListBuah]

### a. [Header File]
```C++
//header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct buah
struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias dataBuah untuk struct buah

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata; //disamakan dengan di list.cpp
    address next;
};

struct linkedList { 
    address first;
};

//Semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);

address alokasi(string nama, int jumlah, float harga);

void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);
void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedList List);
void updateLast(linkedList List);
void updateAfter(linkedList List, address Prev);
void FindNodeByData(linkedList list, string data);
void FindNodeByAddress(linkedList list, address node);
void FindNodeByRange(linkedList list, float hargaAwal, float HargaAkhir);

#endif
```

### b. [Source File]

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
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

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedList List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedList List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedList List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedList list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedList list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedList list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

### c. [Main Program]

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List; // nama struct disamakan (linkedList)
    address nodeA = Nil, nodeB = Nil, nodeC = Nil, nodeD = Nil, nodeE = Nil; // semua diinisialisasi Nil
    createList(List);

    // Pembuatan node baru (alokasi data buah)
    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 11450);

    // Proses insert node ke dalam list
    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "Kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << nbList(List) << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl; 

    return 0;
}
```

Program ini mengimplementasikan ADT Singly Linked List dalam C++ untuk mengelola data buah. Konsep yang digunakan meliputi node, pointer, dan manajemen memori dinamis guna melakukan operasi penyimpanan, penambahan, penghapusan, pembaruan, serta pencarian data.

## Unguided 

### [Updated ADT singlylist]

### a. [Header File]
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

struct list {
    node *first;
};

void buatList(list &L);
node* buatNode(int x);
void insertAwal(list &L, node *n);
void insertAkhir(list &L, node *n);
void insertAfter(node *prev, node *n);
void tampil(list L);

void deleteFirst(list &L);
void deleteLast(list &L);
void deleteAfter(node *prev);
int nbList(list L);
void deleteList(list &L);

//update singlylist modul 5
node* findElm(list L, int x);
int totalInfo(list L);

#endif
```


### b. [Source File]

```C++
#include "singlylist.h"
#include <iostream>
using namespace std;

void buatList(list &L){
    L.first = NULL;
}

node* buatNode(int x){
    node *n = new node;
    n->data = x;
    n->next = NULL;
    return n;
}

void insertAwal(list &L, node *n){
    if(L.first == NULL) L.first = n;
    else {
        n->next = L.first;
        L.first = n;
    }
}

void insertAkhir(list &L, node *n){
    if(L.first == NULL) L.first = n;
    else {
        node *p = L.first;
        while(p->next != NULL) p = p->next;
        p->next = n;
    }
}

void insertAfter(node *prev, node *n){
    if(prev != NULL){
        n->next = prev->next;
        prev->next = n;
    }
}

void tampil(list L){
    node *p = L.first;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void deleteFirst(list &L){
    if(L.first != NULL){
        node *p = L.first;
        L.first = p->next;
        delete p;
    }
}

void deleteLast(list &L){
    if(L.first != NULL){
        node *p = L.first;
        node *q = NULL;
        while(p->next != NULL){
            q = p;
            p = p->next;
        }
        if(q == NULL) L.first = NULL;
        else q->next = NULL;
        delete p;
    }
}

void deleteAfter(node *prev){
    if(prev != NULL && prev->next != NULL){
        node *p = prev->next;
        prev->next = p->next;
        delete p;
    }
}

int nbList(list L){
    int n = 0;
    node *p = L.first;
    while(p != NULL){
        n++;
        p = p->next;
    }
    return n;
}

void deleteList(list &L){
    node *p = L.first;
    while(p != NULL){
        node *tmp = p;
        p = p->next;
        delete tmp;
    }
    L.first = NULL;
}

//update singlylist modul 5
node* findElm(list L, int x){
    node *p = L.first;
    while(p != NULL && p->data != x){
        p = p->next;
    }
    return p;
}


int totalInfo(list L){
    int total = 0;
    node *p = L.first;
    while(p != NULL){
        total += p->data;
        p = p->next;
    }
    return total;
}
```


### c. [Main Program]

```C++
#include <iostream>
#include "singlylist.h"
using namespace std;

int main(){
    list L;
    buatList(L);

    //update singlylist dari modul 4 dan ganti sesuai modul 5
    node *P1 = buatNode(2);
    node *P2 = buatNode(0);
    node *P3 = buatNode(8);
    node *P4 = buatNode(12);
    node *P5 = buatNode(9);

    insertAwal(L, P1); 
    insertAwal(L, P2); 
    insertAwal(L, P3); 
    insertAwal(L, P4);
    insertAwal(L, P5); 

    cout << endl;
    cout << "Isi kelima elemen: ";
    tampil(L);
    cout << endl;

    node *found = findElm(L, 8);
    if (found != NULL)
        cout << "Elemen dengan nilai 8 ditemukan di alamat: " << found << endl;
    else
        cout << "Elemen dengan nilai 8 tidak ditemukan." << endl;
    cout << endl;

    
    cout << "Total info dari kelima elemen adalah : " << totalInfo(L) << endl;
    cout << endl;

    return 0;
}
```
<br>

### 2. [Hasil Implementasi ADT Singly Linked List]
#### Output:
<img width="300" height="29" alt="Screenshot 2025-10-28 130758" src="https://github.com/user-attachments/assets/e5881b5b-b1dc-4065-97b6-ab03aaeda646" />


### 3. [Buat fungsi findElm(L, x) untuk mencari elemen dengan info = 8 dan mengembalikan alamat node tersebut]
#### Output:
<img width="520" height="29" alt="Screenshot 2025-10-28 130806" src="https://github.com/user-attachments/assets/ddf352ab-d3e9-4940-9a76-36a6db1483f0" />


### 4. [Buat fungsi untuk menghitung total nilai dari seluruh list elemen (9 + 12 + 8 + 0 + 2 = 31)]
#### Output:
<img width="379" height="28" alt="Screenshot 2025-10-28 130813" src="https://github.com/user-attachments/assets/3d2b31aa-df84-468f-934e-50916299e5c0" />


Program ini merupakan lanjutan dari modul sebelumnya, dengan fokus pada penambahan dua fungsi baru yaitu findElm() dan totalInfo(). Struktur list masih sama, di mana setiap node berisi data dan pointer yang menunjuk ke node berikutnya. Pada program ini, list diisi dengan nilai 2, 0, 8, 12, dan 9.<br>
Program kemudian menjalankan tiga bagian utama, yaitu:<br>
- menampilkan seluruh elemen dalam list
- mencari alamat node yang memiliki nilai 8 menggunakan fungsi findElm()
- serta menghitung total nilai dari semua elemen list menggunakan fungsi totalInfo()

#### Full code Screenshot:
<img width="1919" height="1138" alt="Screenshot 2025-10-28 132821" src="https://github.com/user-attachments/assets/f697a076-85fa-49be-a30b-d63f924d9356" />


## Kesimpulan
Ssingly linked list dapat digunakan untuk menampilkan data, mencari elemen tertentu, dan menghitung total nilai elemen dengan bantuan fungsi findElm() dan totalInfo().

## Referensi
[1] Analysis of Arraylist dan Linked List oleh: Sarvesh Rakesh Bhatnagar. Diakses pada 28 Oktober 2025 melalui: <br>
[https://www.scribd.com/document/756597574/263-IJCSE-07046-23?utm](https://www.ijcaonline.org/archives/volume182/number18/29977-2018917892/?utm_source) <br>
[2]





















