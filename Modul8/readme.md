# <h1 align="center">Laporan Praktikum Modul 7 - Queue</h1>
<p align="center">Rafhael Januar Turnip - 103112400209</p>

## Dasar Teori
Queue adalah struktur data yang bekerja berdasarkan prinsip FIFO (First In First Out). Queue berfungsi untuk mengatur urutan eksekusi proses secara efisien dan adil, dimana data yang pertama kali masuk akan menjadi 
yang pertama keluar. Struktur queue terdiri dari dua pointer utama, yaitu front dan rear. Pointer front menunjuk ke elemen pertama dalam antrian, sedangkan rear menunjuk ke elemen terakhir yang dimasukkan. 
Elemen-elemen antara front dan rear merupakan bagian dari queue yang masih aktif. Dengan prinsip ini, queue memungkinkan pengelolaan data secara terstruktur dan sistematis terutama dalam proses antrian di sistem 
operasi dan pemrograman. Circular queue adalah variasi dari queue linear, yang memungkinkan pointer rear kembali ke awal array saat ada ruang kosong, sehingga penggunaan memori menjadi lebih efisien. Jenis lain dari 
queue adalah priority queue yang mengelola elemen berdasarkan prioritas dan double-ended queue (deque) yang dapat menambah dan menghapus elemen di kedua ujung antrian.[1]<br>

Operasi utama dalam queue terdiri dari dua, yaitu:

1. Enqueue<br> 
Didefinisikan sebagai proses penambahan elemen baru ke ujung belakang antrean (rear). Saat melakukan enqueue, sistem memeriksa apakah antrean penuh; jika tidak penuh, elemen baru dimasukkan pada posisi rear,
kemudian pointer rear diperbarui ke posisi berikutnya agar siap menerima elemen selanjutnya. Hal ini memastikan elemen baru selalu ditambahkan di akhir antrean sesuai dengan prinsip FIFO.[2]

2. Dequeue<br>
Adalah operasi pengambilan atau penghapusan elemen dari ujung depan antrean (front). Ketika dequeue dilakukan, sistem memeriksa apakah antrean kosong; jika tidak kosong, elemen pada posisi front diambil dan pointer
front diperbarui ke posisi berikutnya. Dengan demikian, elemen yang paling lama berada di antrean akan diakses dan dikeluarkan lebih dulu, menjamin mekanisme FIFO tetap berjalan.[2]


## Guided 

### 1. [Guided1]

### a. [Header File]
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include<string>

using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

### b. [Source File]

```C++
#include "queue.h"
using namespace std;

void createQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```

### c. [Main Program]

```C++
#include "queue.h"
#include "queue.cpp"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    createQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```

Dalam program guided 1 ini berfungsi untuk membuat antrian dengan menggunakan queue dengan linked list dan bekerja dengan proses FIFO yaitu First In First Out. Program ini juga berfungsi menambah data ke antrian, 
menghapus data yang paling depan, dan menghapus seluruh isi queue dan menampilkan outputnya dengan fungsi viewQueue.


### 2. [Guided 2]

### a. [Header File]
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void createQueue(queue &Q); //terbentuk queue dengan head = -1 dan tail = -1
void enQueue(queue &Q, string nama); 
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

### b. [Source File]

```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void createQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```

### c. [Main Program]

```C++
#include "queue.h"
#include "queue.cpp"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    createQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
} 
```
Dalam program guided 2 ini berfungsi untuk mengelola antrian dengan menggunakan queue dengan array dan menerapkan fungsi FIFO yaitu First In First Out. Program ini sama dengan program sebelumnya tetapi di program 
ini ada beberapa implementasi yaitu implementasi 1 (head diam, tail bergerak), implementasi 2 (head bergerak, tail bergerak), dan implementasi 3 (head dan tail berputar).

## Unguided 

### [Queue]

### 1. [Source File - Alternatif 1]
```C++
#include "queue1.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

bool isFull(queue Q){
    if(Q.tail == MAX - 1 ){
        return true;
    } else {
        return false;
    }
}


void createQueue(queue &Q){ 
    Q.head = -1;
    Q.tail = -1;
}
 


int enqueue(queue &Q, infotype X){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = X;
    }
    return 0;
}

void dequeue(queue &Q){
    if(isEmpty(Q)){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i < Q.tail; i++){
            Q.info[i] = Q.info[i+1];
        }
        Q.tail--;
        if(Q.tail < Q.head){ 
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

void printInfo(queue Q){
      cout << Q.head << " - " << Q.tail << " | ";
    if(isEmpty(Q) == true){
        cout << "Empty Queue";
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```
#### Full code Screenshot:
<img width="1917" height="1137" alt="Screenshot 2025-11-23 184248" src="https://github.com/user-attachments/assets/9bc5f6cb-e1e8-43a2-a1d7-0314d9afc07c" />

### b. [Source File - Alternatif 2]

```C++
#include "queue2.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

bool isFull(queue Q){
    if(Q.tail == MAX - 1 ){
        return true;
    } else {
        return false;
    }
}


void createQueue(queue &Q){ 
    Q.head = -1;
    Q.tail = -1;
}

int enqueue(queue &Q, infotype X){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = X;
    }
    return 0;
}


void dequeue(queue &Q){
     if(isEmpty(Q) == true){
         cout << "Queue kosong!" << endl;
     } else {
         Q.head++;
         if(Q.head > Q.tail){
             Q.head = -1;
             Q.tail = -1;
         }
     }
 }

void printInfo(queue Q){
      cout << Q.head << " - " << Q.tail << " | ";
    if(isEmpty(Q) == true){
        cout << "Empty Queue";
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```
#### Full code Screenshot:
<img width="1914" height="1137" alt="Screenshot 2025-11-23 184306" src="https://github.com/user-attachments/assets/849bf1b9-b8b5-48b4-b60b-309035d845d9" />

### c. [Source File - Alternatif 3]

```C++
#include "queue3.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q)
{
    if (Q.head == -1 && Q.tail == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(queue Q)
{
    if ((Q.tail + 1) % MAX == Q.head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createQueue(queue &Q)
{
    Q.head = -1;
    Q.tail = -1;
}

int enqueue(queue &Q, infotype X)
{
    if (isFull(Q) == true)
    {
        cout << "Queue sudah penuh!" << endl;
    }
    else
    {
        if (isEmpty(Q) == true)
        {
            Q.head = Q.tail = 0;
        }
        else
        {
            Q.tail = (Q.tail + 1) % MAX;
        }
        Q.info[Q.tail] = X;
    }
    return 0;
}

void dequeue(queue &Q)
{
    if (isEmpty(Q) == true)
    {
        cout << "Queue kosong!" << endl;
    }
    else
    {
        if (Q.head == Q.tail)
        {
            Q.head = -1;
            Q.tail = -1;
        }
        else
        {
            Q.head = (Q.head + 1) % MAX;
        }
    }
}

void printInfo(queue Q)
{
    if (isEmpty(Q) == true)
    {
    cout << Q.head << " - " << Q.tail << " | Empty Queue" << endl;
    return;
    }
    else
    {
        cout << Q.head << " - " << Q.tail << " | ";
        int i = Q.head;
        int count = 1;
        while (true)
        {
            cout << Q.info[i] << " ";

            if (i == Q.tail)
                break;

            cout << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}
```
#### Full code Screenshot:
<img width="1919" height="1137" alt="Screenshot 2025-11-23 184320" src="https://github.com/user-attachments/assets/cd9f4313-7cb5-40fa-9711-cc433b621007" />

## Pengerjaan Latihan Modul 7 - Stack

### 1.
<img width="588" height="537" alt="Screenshot 2025-11-23 172857" src="https://github.com/user-attachments/assets/8c6f2afc-0025-4a8d-b37c-03362795b2a1" />

#### Output latihan 1:
<img width="1368" height="358" alt="Screenshot 2025-11-23 184623" src="https://github.com/user-attachments/assets/d2f5d1ed-cbcd-47a7-8b4f-a11922528947" />


### 2. 
<img width="580" height="38" alt="Screenshot 2025-11-23 172911" src="https://github.com/user-attachments/assets/d7eb710d-db34-4a77-b5a7-bcfd0ab83139" />

#### Output latihan 2:
<img width="1366" height="357" alt="Screenshot 2025-11-23 184647" src="https://github.com/user-attachments/assets/fd02f3c2-0573-46f2-8312-24b86a73e1af" />


### 3.
<img width="570" height="39" alt="Screenshot 2025-11-23 172918" src="https://github.com/user-attachments/assets/921251b6-0b41-4b7d-9d70-ca6c561a5377" />

#### Output latihan 3:
<img width="1365" height="351" alt="Screenshot 2025-11-23 184707" src="https://github.com/user-attachments/assets/6f6ef5eb-e390-438d-b563-1a2fb6de72ad" />


<br>
<br>
Program ini memperlihatkan bagaimana struktur data Queue bekerja melalui tiga pendekatan berbeda. Ketiganya sama-sama menggunakan array, namun cara pengolahan datanya berbeda sehingga hasil dan perilakunya juga 
terlihat berbeda.

1. Pada alternatif pertama, setiap kali ada penghapusan elemen, program akan menggeser seluruh isi queue satu langkah ke kiri. Metode ini mudah dipahami karena elemen belakang tampak “maju” menggantikan posisi 
yang hilang, meskipun proses geser ini membuat operasinya kurang efisien jika data cukup banyak.

2. Alternatif kedua sudah lebih baik karena tidak lagi memakai sistem geser. Ketika elemen depan dihapus, program cukup memindahkan posisi head ke indeks berikutnya. Dengan cara ini, operasi dequeue menjadi 
jauh lebih ringan. Namun ada kekurangan: ruang kosong yang muncul di bagian depan array tidak bisa digunakan kembali, sehingga kapasitas queue bisa cepat habis meskipun masih ada ruang kosong.

3. Pada alternatif ketiga, program menggunakan konsep circular queue. Di sini, posisi head dan tail tidak berhenti di ujung array, tetapi bisa kembali ke awal menggunakan operasi modulo. Pendekatan ini membuat 
pemanfaatan array jauh lebih optimal karena ruang yang sebelumnya tidak terpakai dapat digunakan kembali.

## Kesimpulan
Pada modul kali ini, kita mempelajari queue yaitu sebuah antrian yang menerapkan sistem FIFO yaitu First In First Out berbeda dengan stack kemarin yang menerapkan sistem LIFO Last In First Out. Pada pembuatannya juga ada beberapa implementasi yaitu ada 3 implementasi.

## Referensi
[1]Implementasi Struktur Data Antrian Queue dalam Sistem Penjadwalan Proses pada Sistem Operasi Oleh Azura Trijayanti&sup1;, Intan Aulia&sup2;, Nazwa Khairunisa&sup3;, Farhan Asyrof Hamadi Purba&sup4;, Indra Gunawan&sup5;. diakses pada tanggal 23 November 2025 melalui: <br>
[](https://journalcenter.org/index.php/jupti)<br>
[2]RESEARCH PAPER ON QUEUES Oleh A. Jain&sup1;, U. Kumar&sup2;. diakses pada tanggal 23 November 2025 melalui: <br>
[](https://ijirt.org/publishedpaper/IJIRT100828_PAPER.pdf)





















