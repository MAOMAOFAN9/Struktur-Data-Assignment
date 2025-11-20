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