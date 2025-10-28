#ifndef LOWONGAN_H
#define LOWONGAN_H

#include <iostream>
#include <string>
using namespace std;

struct lowongan {
    string ID_Lowongan;
    string Nama_Jabatan;
    float Gaji_Ditawarkan;
};

typedef lowongan infotype;
typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

// Deklarasi fungsi primitive
void createList(List &L);
address newElm(string id, string jabatan, float gaji);
void insertFirst(List &L, address P);
void insertAfter(List &L, address P, address Prec);
void insertLast(List &L, address P);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec, address &P);
void show(List L);

#endif
