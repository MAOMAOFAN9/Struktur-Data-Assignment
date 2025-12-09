#include "multilist.h"
#include <iostream>
using namespace std;

//list induk
void createList(listinduk &L) { L.first = L.last = Nil; }
bool listEmpty(listinduk L) { return L.first == Nil; }

address alokasi(infotypeinduk X) {
    address P = new elemen_list_induk;
    P->info = X;
    P->next = P->prev = Nil;
    createListAnak(P->lanak);
    return P;
}

void dealokasi(address &P) {
    address_anak c = P->lanak.first;
    while (c != Nil) {
        address_anak tmp = c;
        c = c->next;
        delete tmp;
    }
    delete P;
    P = Nil;
}

void insertFirst(listinduk &L, address P) {
    if (listEmpty(L)) L.first = L.last = P;
    else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(listinduk &L, address P) {
    if (listEmpty(L)) L.first = L.last = P;
    else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfter(listinduk &L, address P, address Prec) {
    if (!Prec) return;

    P->next = Prec->next;
    P->prev = Prec;

    if (Prec->next) {
        Prec->next->prev = P;
    } else {
        L.last = P;   
    }

    Prec->next = P;
}

void delFirst(listinduk &L, address &P) {
    P = L.first;
    if (!P) return;
    if (L.first == L.last) L.first = L.last = Nil;
    else {
        L.first = P->next;
        L.first->prev = Nil;
    }
    P->next = Nil;
}

void delLast(listinduk &L, address &P) {
    P = L.last;
    if (!P) return;
    if (L.first == L.last) L.first = L.last = Nil;
    else {
        L.last = P->prev;
        L.last->next = Nil;
    }
    P->prev = Nil;
}

void delAfter(listinduk &L, address &P, address Prec) {
    if (!Prec || !Prec->next) return;
    P = Prec->next;
    Prec->next = P->next;
    if (P->next) P->next->prev = Prec;
    else L.last = Prec;
    P->next = P->prev = Nil;
}

void delP(listinduk &L, infotypeinduk X) {
    address P = findElm(L, X), Q;
    if (!P) return;
    if (P == L.first) delFirst(L, Q);
    else if (P == L.last) delLast(L, Q);
    else delAfter(L, Q, P->prev);
    dealokasi(Q);
}

address findElm(listinduk L, infotypeinduk X) {
    for (address P = L.first; P; P = P->next)
        if (P->info == X) return P;
    return Nil;
}

void printInfo(listinduk L) {
    if (listEmpty(L)) {
        cout << "[List Kosong]\n";
        return;
    }
    for (address P = L.first; P; P = P->next) {
        cout << "[Induk " << P->info << "]";
        printInfoAnak(P->lanak);
        cout << endl;
    }
}

//list anak
void createListAnak(listanak &L) { L.first = L.last = Nil; }
bool listEmptyAnak(listanak L) { return L.first == Nil; }

address_anak alokasiAnak(infotypeanak X) {
    address_anak P = new elemen_list_anak;
    P->info = X;
    P->next = P->prev = Nil;
    return P;
}

void dealokasiAnak(address_anak &P) { delete P; P = Nil; }

void insertFirstAnak(listanak &L, address_anak P) {
    if (listEmptyAnak(L)) L.first = L.last = P;
    else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastAnak(listanak &L, address_anak P) {
    if (listEmptyAnak(L)) L.first = L.last = P;
    else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfterAnak(listanak &L, address_anak P, address_anak Prec) {
    if (!Prec) return;
    P->next = Prec->next;
    P->prev = Prec;
    if (Prec->next) Prec->next->prev = P;
    else L.last = P;
    Prec->next = P;
}

void delFirstAnak(listanak &L, address_anak &P) {
    P = L.first;
    if (!P) return;
    if (L.first == L.last) L.first = L.last = Nil;
    else {
        L.first = P->next;
        L.first->prev = Nil;
    }
    P->next = Nil;
}

void delLastAnak(listanak &L, address_anak &P) {
    P = L.last;
    if (!P) return;
    if (L.first == L.last) L.first = L.last = Nil;
    else {
        L.last = P->prev;
        L.last->next = Nil;
    }
    P->prev = Nil;
}

void delAfterAnak(listanak &L, address_anak &P, address_anak Prec) {
    if (!Prec || !Prec->next) return;
    P = Prec->next;
    Prec->next = P->next;
    if (P->next) P->next->prev = Prec;
    else L.last = Prec;
    P->next = P->prev = Nil;
}

void delPAnak(listanak &L, infotypeanak X) {
    address_anak P = findElmAnak(L, X), tmp;
    if (!P) return;
    if (P == L.first) delFirstAnak(L, tmp);
    else if (P == L.last) delLastAnak(L, tmp);
    else delAfterAnak(L, tmp, P->prev);
    dealokasiAnak(tmp);
}

address_anak findElmAnak(listanak L, infotypeanak X) {
    for (address_anak P = L.first; P; P = P->next)
        if (P->info == X) return P;
    return Nil;
}

void printInfoAnak(listanak L) {
    if (listEmptyAnak(L)) { cout << " -> (Tidak ada anak)"; return; }
    cout << " -> Anak: ";
    for (address_anak P = L.first; P; P = P->next)
        cout << P->info << " ";
}
