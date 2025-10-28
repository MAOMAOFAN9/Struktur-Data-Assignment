# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua) (ADT)</h1>
<p align="center">Rafhael Januar Turnip</p>

## Dasar Teori

Singly Linked List <br>
Singly Linked List adalah struktur data dinamis yang tersusun dari sekumpulan node yang saling terhubung lewat pointer. Setiap node berisi data dan alamat node berikutnya. Tidak seperti array, elemen-elemen pada linked list tidak tersimpan berurutan di memori, tapi dihubungkan menggunakan pointer next. <br>

Linked list juga merupakan struktur data list yang diimplementasikan sebagai node dengan dua entitas: data dan pointer.[1]. <br>

Dalam linked list, jumlah elemen tidak perlu ditentukan sebelumnya, dan memorinya dapat dialokasikan atau dilepaskan selama pemrosesan sesuai kebutuhan, sehingga proses penyisipan dan penghapusan menjadi lebih mudah dan sederhana[2]. <br>

Beberapa operasi dasar yang digunakan :
- createList() untuk membuat list kosong.
- alokasi() untuk membuat node baru.
- insertFirst(), insertAfter(), dan insertLast() untuk menambah node di posisi berbeda.
- delFirst(), delAfter(), dan delLast() untuk menghapus node dari list.
- printList() untuk menampilkan isi list.
- nbList() untuk menghitung jumlah node.
- deleteList() untuk menghapus seluruh isi list.

## Guided 

### 1. [ADT ListBuah]

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

Program ini 

## Unguided 

### 1. [ADT Singly Linked]

### a. [Header File]
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

struct list{
    node *first;
};

void buatList(list &L);
node* buatNode(int x);
void insertAwal(list &L,node *n);
void insertAkhir(list &L,node *n);
void insertAfter(node *prev,node *n);
void tampil(list L);

#endif
```


### b. [Source File]

```C++
#include "singlylist.h"
#include <iostream>
using namespace std;

void buatList(list &L){
    L.first=NULL;
}

node* buatNode(int x){
    node *n = new node;
    n->data=x;
    n->next=NULL;
    return n;
}

void insertAwal(list &L,node *n){
    if(L.first==NULL){
        L.first=n;
    }else{
        n->next=L.first;
        L.first=n;
    }
}

void insertAkhir(list &L,node *n){
    if(L.first==NULL){
        L.first=n;
    }else{
        node *p=L.first;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=n;
    }
}

void insertAfter(node *prev,node *n){
    if(prev!=NULL){
        n->next=prev->next;
        prev->next=n;
    }
}

void tampil(list L){
    node *p=L.first;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
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

    node *a=buatNode(5);
    node *b=buatNode(7);
    node *c=buatNode(9);
    node *d=buatNode(2);
    node *e=buatNode(8);
    node *f=buatNode(12);

    insertAwal(L,a);
    insertAkhir(L,b);
    insertAkhir(L,c);
    insertAwal(L,d);
    insertAfter(b,e);
    insertAkhir(L,f);

    cout<<"Isi list : ";
    tampil(L);
}
```


#### Output:
<img width="869" height="96" alt="1 ss" src="https://github.com/user-attachments/assets/ec657173-0334-4f61-8f47-f5e60902b4a3" />

Program ini menerapkan ADT Singly Linked List untuk menyimpan data secara dinamis. Struktur node berisi data dan pointer ke node berikutnya. Melalui fungsi insertAwal, insertAkhir, dan insertAfter, data dimasukkan ke dalam list, kemudian seluruh isi list ditampilkan ke layar.

#### Full code Screenshot:
<img width="1917" height="1137" alt="1 fss" src="https://github.com/user-attachments/assets/ff19e29d-bbb8-4504-804b-95a2751f50a0" />


### 2. [ADT Singly Linked++]

### a. [Header File]
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

struct list{
    node *first;
};

void buatList(list &L);
node* buatNode(int x);
void insertAwal(list &L,node *n);
void insertAkhir(list &L,node *n);
void insertAfter(node *prev,node *n);
void tampil(list L);

void deleteFirst(list &L);
void deleteLast(list &L);
void deleteAfter(node *prev);
int nbList(list L);
void deleteList(list &L);

#endif
```


### b. [Source File]

```C++
#include "singlylist.h"
#include <iostream>
using namespace std;

void buatList(list &L){
    L.first=NULL;
}

node* buatNode(int x){
    node *n=new node;
    n->data=x;
    n->next=NULL;
    return n;
}

void insertAwal(list &L,node *n){
    if(L.first==NULL) L.first=n;
    else{
        n->next=L.first;
        L.first=n;
    }
}

void insertAkhir(list &L,node *n){
    if(L.first==NULL) L.first=n;
    else{
        node *p=L.first;
        while(p->next!=NULL) p=p->next;
        p->next=n;
    }
}

void insertAfter(node *prev,node *n){
    if(prev!=NULL){
        n->next=prev->next;
        prev->next=n;
    }
}

void tampil(list L){
    node *p=L.first;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void deleteFirst(list &L){
    if(L.first!=NULL){
        node *p=L.first;
        L.first=p->next;
        delete p;
    }
}

void deleteLast(list &L){
    if(L.first!=NULL){
        node *p=L.first;
        node *q=NULL;
        while(p->next!=NULL){
            q=p;
            p=p->next;
        }
        if(q==NULL) L.first=NULL;
        else q->next=NULL;
        delete p;
    }
}

void deleteAfter(node *prev){
    if(prev!=NULL && prev->next!=NULL){
        node *p=prev->next;
        prev->next=p->next;
        delete p;
    }
}

int nbList(list L){
    int n=0;
    node *p=L.first;
    while(p!=NULL){
        n++;
        p=p->next;
    }
    return n;
}

void deleteList(list &L){
    node *p=L.first;
    while(p!=NULL){
        node *tmp=p;
        p=p->next;
        delete tmp;
    }
    L.first=NULL;
}
```


### c. [Main Program]

```C++
#include <iostream>
#include "Singlylist.h"
using namespace std;

int main(){
    list L;
    buatList(L);

    node *a=buatNode(5);
    node *b=buatNode(7);
    node *c=buatNode(9);
    node *d=buatNode(2);
    node *e=buatNode(8);
    node *f=buatNode(12);

    insertAwal(L,a);
    insertAkhir(L,b);
    insertAkhir(L,c);
    insertAwal(L,d);
    insertAfter(b,e);
    insertAkhir(L,f);

    tampil(L);

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(b);

    tampil(L);
    cout<<"Jumlah node: "<<nbList(L)<<endl;

    deleteList(L);
    cout<<"List berhasil terhapus\n";
    cout<<"Jumlah node: "<<nbList(L)<<endl;
}

```


#### Output:
<img width="884" height="198" alt="2 ss" src="https://github.com/user-attachments/assets/d15f8a96-7586-4d50-a415-528ade21775f" />

Program ini merupakan pengembangan dari ADT Single Linked sebelumnya, tapi ada tambahan beberapa fungsi untuk hapus data dan hitung jumlah node. Strukturnya masih pakai node dengan data dan pointer next. Bedanya, sekarang ada fungsi deleteFirst, deleteLast, deleteAfter, nbList, dan deleteList. Jadi selain bisa nambah data lewat insertAwal, insertAkhir, dan insertAfter, program ini juga bisa hapus dan bersihin list.

#### Full code Screenshot:
<img width="1919" height="1137" alt="2 fss" src="https://github.com/user-attachments/assets/a9c0357f-1f49-4c36-8cc1-5c492ae8c39b" />


## Kesimpulan
Secara keseluruhan, modul dan praktikum Singly Linked List membahas cara mengelola data secara dinamis menggunakan node yang saling terhubung. Materi mencakup proses penambahan, penghapusan, hingga perhitungan data dalam list.

## Referensi
[1] Analysis of Arraylist dan Linked List oleh: K. Renuka Devi. Diakses pada 20 Oktober 2025 melalui: <br>
https://www.scribd.com/document/756597574/263-IJCSE-07046-23?utm <br>
[2] Review Paper On Dynamic Implementation Using Linked List oleh: Manish saini, Ankush Sharma. Diakses pada 20 Oktober 2025 melalui: <br>
https://www.researchgate.net/publication/329609389_Review_Paper_On_Dynamic_Implementation_Using_Linked_List_Chandigarh_universty





















