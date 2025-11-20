
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

