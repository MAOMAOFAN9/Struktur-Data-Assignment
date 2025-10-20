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
