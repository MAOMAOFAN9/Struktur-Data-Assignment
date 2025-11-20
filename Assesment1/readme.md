
## Assesment 1 

### [soal 1]

### a. [Header File]
```C++
#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H
#include <string>
using namespace std;

struct Product{ string Nama,SKU; int Jumlah; float HargaSatuan,DiskonPersen; };
struct Node{ Product info; Node* next; };
struct List{ Node* head; };

void createList(List& L);
bool isEmpty(List L);
Node* allocate(Product P);
void deallocate(Node* p);
void insertFirst(List& L, Product P);
void insertLast(List& L, Product P);
void insertAfter(List& L, Node* Q, Product P);
void deleteFirst(List& L, Product& P);
void deleteLast(List& L, Product& P);
void deleteAfter(List& L, Node* Q, Product& P);
void updateAtPosition(List& L, int pos);
void viewList(List L);
void searchByFinalPriceRange(List L, float a, float b);
void MaxHargaAkhir(List L);

#endif
```


### b. [Source File]

```C++
#include "sllinventory.h"
#include <iostream>
using namespace std;

float F(Product p){ return p.HargaSatuan*(1-p.DiskonPersen/100); }
void createList(List& L){ L.head=NULL; }
bool isEmpty(List L){ return !L.head; }
Node* allocate(Product P){ Node* n=new Node; n->info=P; n->next=NULL; return n; }
void deallocate(Node* p){ delete p; }

void insertFirst(List& L, Product P){
    Node* n=allocate(P); n->next=L.head; L.head=n;
}
void insertLast(List& L, Product P){
    Node* n=allocate(P);
    if(isEmpty(L)) L.head=n;
    else{ Node* p=L.head; while(p->next) p=p->next; p->next=n; }
}
void insertAfter(List& L, Node* Q, Product P){
    if(!Q) return; Node* n=allocate(P); n->next=Q->next; Q->next=n;
}

void deleteFirst(List& L, Product& P){
    if(isEmpty(L)) return; Node* d=L.head; P=d->info; L.head=d->next; deallocate(d);
}
void deleteLast(List& L, Product& P){
    if(isEmpty(L)) return;
    Node *p=L.head,*b=NULL; while(p->next){ b=p; p=p->next; }
    P=p->info; if(!b) L.head=NULL; else b->next=NULL; deallocate(p);
}
void deleteAfter(List& L, Node* Q, Product& P){
    if(!Q||!Q->next) return; Node* d=Q->next; P=d->info; Q->next=d->next; deallocate(d);
}

void updateAtPosition(List& L, int pos){
    Node* p=L.head; int i=1; while(p&&i<pos){ p=p->next; i++; }
    if(p){
        cin>>p->info.Nama>>p->info.SKU>>p->info.Jumlah
           >>p->info.HargaSatuan>>p->info.DiskonPersen;
    }
}

void viewList(List L){
    Node* p=L.head; int i=1;
    while(p){
        cout<<i++<<". "<<p->info.Nama<<" "<<p->info.SKU<<" "
            <<p->info.Jumlah<<" "<<p->info.HargaSatuan<<" "
            <<p->info.DiskonPersen<<" Final:"<<F(p->info)<<"\n";
        p=p->next;
    }
}

void searchByFinalPriceRange(List L, float a,float b){
    Node* p=L.head; int i=1,ok=0;
    while(p){
        float f=F(p->info);
        if(f>=a&&f<=b){ cout<<i<<". "<<p->info.Nama<<" "<<f<<"\n"; ok=1; }
        p=p->next; i++;
    }
    if(!ok) cout<<"Tidak ada\n";
}

void MaxHargaAkhir(List L){
    if(isEmpty(L)){ cout<<"List kosong\n"; return; }
    Node* p=L.head; float mx=F(p->info); p=p->next;
    while(p){ float f=F(p->info); if(f>mx) mx=f; p=p->next; }
    cout<<"Max="<<mx<<"\n";
    p=L.head; int i=1;
    while(p){ if(F(p->info)==mx) cout<<i<<". "<<p->info.Nama<<"\n"; p=p->next; i++; }
}
```


### c. [Main Program]

```C++
#include <iostream>
#include "sllinventory.h"
using namespace std;

int main(){
    List L; createList(L);

    insertLast(L,{"Pulpen","A001",20,2500,0});
    insertLast(L,{"Buku_Tulis","A002",15,5000,10});
    insertLast(L,{"Penghapus","A003",30,1500,0});

    cout<<"Awal:\n"; viewList(L);

    Product x; deleteFirst(L,x);
    cout<<"\nSetelah deleteFirst:\n"; viewList(L);

    cout<<"\nUpdate pos 2 (input langsung):\n";
    updateAtPosition(L,2);

    cout<<"\nSetelah update:\n"; viewList(L);

    cout<<"\nSearch 2000-7000:\n";
    searchByFinalPriceRange(L,2000,7000);

    cout<<"\nMax harga akhir:\n";
    MaxHargaAkhir(L);
}
```
#### Output Soal 1:
<img width="1545" height="668" alt="Screenshot 2025-11-20 091033" src="https://github.com/user-attachments/assets/b18bd035-71c4-477e-92dc-ed0f4f883aca" />


### [soal 2]

### a. [Header File]
```C++
#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#include <string>
using namespace std;

struct Song {
    string Title, Artist;
    int DurationSec, PlayCount;
    float Rating;
};

struct Node {
    Song info;
    Node *prev, *next;
};

struct List {
    Node *head, *tail;
};

void createList(List &L);
Node* newNode(Song S);
bool isEmpty(List L);

void insertLast(List &L, Song S);
void insertBefore(List &L, Node* Q, Song S);

void deleteLast(List &L, Song &S);
void deleteBefore(List &L, Node* Q, Song &S);

void updateAtPosition(List &L, int pos, Song S);
void updateBefore(Node* Q, Song S);

void viewList(List L);
void searchByPopularityRange(List L, float a, float b);

#endif
```


### b. [Source File]

```C++
#include "DLLPlaylist.h"
#include <iostream>
using namespace std;

float popu(Song s){ return 0.8*s.PlayCount + 20*s.Rating; }

void createList(List &L){ L.head=L.tail=NULL; }
bool isEmpty(List L){ return L.head==NULL; }

Node* newNode(Song S){
    Node* n=new Node; n->info=S; n->prev=n->next=NULL; return n;
}

void insertLast(List &L, Song S){
    Node* n=newNode(S);
    if(isEmpty(L)) L.head=L.tail=n;
    else { L.tail->next=n; n->prev=L.tail; L.tail=n; }
}

void insertBefore(List &L, Node* Q, Song S){
    if(!Q) return;
    Node* n=newNode(S);
    n->next=Q; n->prev=Q->prev;
    if(Q->prev) Q->prev->next=n; else L.head=n;
    Q->prev=n;
}

void deleteLast(List &L, Song &S){
    if(isEmpty(L)) return;
    Node* d=L.tail; S=d->info;
    if(L.head==L.tail) L.head=L.tail=NULL;
    else { L.tail=d->prev; L.tail->next=NULL; }
    delete d;
}

void deleteBefore(List &L, Node* Q, Song &S){
    if(!Q||!Q->prev) return;
    Node* d=Q->prev; S=d->info;
    Q->prev=d->prev;
    if(d->prev) d->prev->next=Q; else L.head=Q;
    delete d;
}

void updateAtPosition(List &L, int pos, Song S){
    Node* p=L.head; int i=1;
    while(p && i<pos){ p=p->next; i++; }
    if(p) p->info=S;
}

void updateBefore(Node* Q, Song S){
    if(Q && Q->prev) Q->prev->info=S;
}

void viewList(List L){
    Node* p=L.head; int i=1;
    while(p){
        cout<<i++<<". "<<p->info.Title<<" ("<<popu(p->info)<<")\n";
        p=p->next;
    }
}

void searchByPopularityRange(List L, float a, float b){
    Node* p=L.head; int i=1; bool ada=false;
    while(p){
        float h=popu(p->info);
        if(h>=a && h<=b){
            cout<<i<<". "<<p->info.Title<<" "<<h<<"\n";
            ada=true;
        }
        p=p->next; i++;
    }
    if(!ada) cout<<"Tidak ada\n";
}
```


### c. [Main Program]

```C++
#include <iostream>
#include "DLLPlaylist.h"
using namespace std;

int main(){
    List L; createList(L);

    insertLast(L, {"Senja di Kota","Nona Band",210,150,4.2});
    insertLast(L, {"Langkahmu","Delta",185,320,4.8});
    insertLast(L, {"Hujan Minggu","Arka",240,90,3.9});

    cout<<"Awal:\n"; viewList(L);

    Song x;
    deleteLast(L,x);
    cout<<"\nHapus belakang:\n"; viewList(L);

    updateAtPosition(L,2,{"Pelita","Luna",200,260,4.5});
    cout<<"\nUpdate pos 2:\n"; viewList(L);

    Node* pos2=L.head->next;
    insertBefore(L,pos2,{"Senandung","Mira",175,120,4.0});
    cout<<"\nInsertBefore pos 2:\n"; viewList(L);

    updateBefore(pos2,{"UpdateBefore","ArtX",180,200,4.3});
    cout<<"\nUpdateBefore pos 2:\n"; viewList(L);

    Node* pos3=L.head->next->next;
    deleteBefore(L,pos3,x);
    cout<<"\nDeleteBefore pos 3:\n"; viewList(L);

    cout<<"\nSearch 150-300:\n";
    searchByPopularityRange(L,150,300);

    return 0;
}
```

#### Output Soal 2:
<img width="1545" height="893" alt="Screenshot 2025-11-20 090710" src="https://github.com/user-attachments/assets/71d8a5d2-a3c8-40a5-a2d3-f5e1283d300b" />

### [soal 3]

### a. [Header File]
```C++
#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H
#include <string>
using namespace std;

struct Mahasiswa {
    string Nama, NIM;
    float Tugas, UTS, UAS;
};

const int MAX = 6;

struct Stack {
    Mahasiswa data[MAX];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);

void push(Stack &S, Mahasiswa M);
void pop(Stack &S, Mahasiswa &M);

void updatePos(Stack &S, int pos, Mahasiswa M);
void view(Stack S);

void searchNA(Stack S, float a, float b);
void maxNA(Stack S);

#endif
```


### b. [Source File]

```C++
#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

float nilaiAkhir(Mahasiswa m){
    return 0.2*m.Tugas + 0.4*m.UTS + 0.4*m.UAS;
}

void createStack(Stack &S){ S.top = -1; }
bool isEmpty(Stack S){ return S.top == -1; }
bool isFull(Stack S){ return S.top == MAX-1; }

void push(Stack &S, Mahasiswa M){
    if(!isFull(S)) S.data[++S.top] = M;
}

void pop(Stack &S, Mahasiswa &M){
    if(!isEmpty(S)) M = S.data[S.top--];
}

void updatePos(Stack &S, int pos, Mahasiswa M){
    int idx = pos-1;
    if(idx >=0 && idx <= S.top) S.data[idx] = M;
}

void view(Stack S){
    if(isEmpty(S)){ cout<<"(kosong)\n"; return; }
    for(int i=0;i<=S.top;i++){
        cout<<i+1<<". "<<S.data[i].Nama
            <<" | NIM:"<<S.data[i].NIM
            <<" | NA:"<<nilaiAkhir(S.data[i])<<"\n";
    }
}

void searchNA(Stack S, float a, float b){
    bool ada=false;
    for(int i=0;i<=S.top;i++){
        float na = nilaiAkhir(S.data[i]);
        if(na>=a && na<=b){
            ada=true;
            cout<<i+1<<". "<<S.data[i].Nama<<" "<<na<<"\n";
        }
    }
    if(!ada) cout<<"Tidak ada\n";
}

void maxNA(Stack S){
    if(isEmpty(S)){ cout<<"(kosong)\n"; return; }
    float mx = nilaiAkhir(S.data[0]);
    for(int i=1;i<=S.top;i++){
        float na = nilaiAkhir(S.data[i]);
        if(na > mx) mx = na;
    }
    cout<<"Nilai Akhir tertinggi: "<<mx<<"\n";
    for(int i=0;i<=S.top;i++)
        if(nilaiAkhir(S.data[i]) == mx)
            cout<<i+1<<". "<<S.data[i].Nama<<"\n";
}
```


### c. [Main Program]

```C++
#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

int main(){
    Stack S; createStack(S);
    Mahasiswa m;

    push(S, {"Venti","11111",75.7,82.1,65.5});
    push(S, {"Xiao","22222",87.4,88.9,81.9});
    push(S, {"Kazuha","33333",92.3,88.8,82.4});
    push(S, {"Wanderer","44444",95.5,85.5,90.5});
    push(S, {"Lynette","55555",77.7,65.4,79.9});
    push(S, {"Chasca","66666",99.9,93.6,87.3});

    cout<<"Stack awal:\n"; view(S);

    pop(S,m);
    cout<<"\nSetelah pop:\n"; view(S);

    updatePos(S,3,{"Heizou","77777",99.9,88.8,77.7});
    cout<<"\nSetelah update pos 3:\n"; view(S);

    cout<<"\nCari NA 85.5 - 95.5:\n";
    searchNA(S,85.5,95.5);

    cout<<"\nNilai akhir maksimum:\n";
    maxNA(S);

    return 0;
}
```

#### Output Soal 3:
<img width="1545" height="858" alt="Screenshot 2025-11-20 090811" src="https://github.com/user-attachments/assets/9223756e-9c76-45e4-9ae9-4a3af33a32b5" />



### [soal 4]

### a. [Header File]
```C++
#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H
#include <string>
using namespace std;

struct Paket {
    string Resi, Pengirim, Tujuan;
    int Berat;
};

const int MAX = 5;

struct Queue {
    Paket data[MAX];
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);

void enQueue(Queue &Q, Paket P);
void deQueue(Queue &Q, Paket &P);
void viewQueue(Queue Q);

long long totalBiaya(Queue Q);

#endif
```


### b. [Source File]

```C++
#include "QueuePengiriman.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q){ Q.head = Q.tail = -1; }
bool isEmpty(Queue Q){ return Q.head == -1; }
bool isFull(Queue Q){ return Q.tail == MAX-1; }

void enQueue(Queue &Q, Paket P){
    if(isFull(Q)) return;
    if(isEmpty(Q)){
        Q.head = Q.tail = 0;
        Q.data[0] = P;
    } else {
        Q.data[++Q.tail] = P;
    }
}

void deQueue(Queue &Q, Paket &P){
    if(isEmpty(Q)) return;
    P = Q.data[Q.head];
    for(int i=Q.head;i<Q.tail;i++)
        Q.data[i] = Q.data[i+1];
    Q.tail--;
    if(Q.tail < 0) Q.head = Q.tail = -1;
}

void viewQueue(Queue Q){
    if(isEmpty(Q)){ cout<<"(kosong)\n"; return; }
    for(int i=Q.head;i<=Q.tail;i++){
        cout<<i+1<<". "<<Q.data[i].Resi<<" | "
            <<Q.data[i].Pengirim<<" | "
            <<Q.data[i].Berat<<"kg | "
            <<Q.data[i].Tujuan<<"\n";
    }
}

long long totalBiaya(Queue Q){
    long long t = 0;
    for(int i=Q.head;i<=Q.tail;i++)
        t += Q.data[i].Berat * 8250LL;
    return t;
}
```


### c. [Main Program]

```C++
#include <iostream>
#include "QueuePengiriman.h"
using namespace std;

int main(){
    Queue Q; createQueue(Q);
    Paket p;

    enQueue(Q, {"123456","Hutao","Sumeru",14});
    enQueue(Q, {"234567","Ayaka","Fontaine",10});
    enQueue(Q, {"345678","Bennet","Natlan",7});
    enQueue(Q, {"456789","Furina","Liyue",16});
    enQueue(Q, {"567890","Nefer","Inazuma",6});

    cout<<"Awal:\n"; viewQueue(Q);

    deQueue(Q,p);
    cout<<"\nSetelah deQueue:\n"; viewQueue(Q);

    cout<<"\nTotal Biaya: Rp "<<totalBiaya(Q)<<"\n";
}
}
```
#### Output Soal 4:
<img width="1544" height="615" alt="Screenshot 2025-11-20 092320" src="https://github.com/user-attachments/assets/7c1b49d7-c22b-4266-84d4-fde5700c3e67" />

