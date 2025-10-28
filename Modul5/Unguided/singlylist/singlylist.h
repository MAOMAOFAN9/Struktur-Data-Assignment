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
