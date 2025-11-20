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