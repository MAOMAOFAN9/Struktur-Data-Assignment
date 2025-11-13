#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

using namespace std;

#define Nil NULL

struct infotype {
    string nopol;
    string warna;
    int thnBuat;
};

typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
bool isEmpty(List L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);

void printInfo(List L);
address findElm(List L, string nopol);

void searchAndPrintAll(List L, string nopol);

int deleteAllMatches(List &L, string nopol);

#endif