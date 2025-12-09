#include "circularlist.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = P;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address q = L.first;
        while (q->next != L.first) q = q->next;
        q->next = P;
        P->next = L.first;
        L.first = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address q = L.first;
        while (q->next != L.first) q = q->next;
        q->next = P;
        P->next = L.first;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first == NULL) return;

    address last = L.first;
    while (last->next != L.first) last = last->next;

    P = L.first;
    if (P == last) {
        L.first = NULL;
    } else {
        last->next = P->next;
        L.first = P->next;
    }
    P->next = NULL;
}

void deleteAfter(List &L, address Prec, address &P) {
    if (L.first == NULL || Prec == NULL) return;
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}

void deleteLast(List &L, address &P) {
    if (L.first == NULL) return;

    address prev = NULL, q = L.first;
    while (q->next != L.first) {
        prev = q;
        q = q->next;
    }

    if (prev == NULL) {
        L.first = NULL;
    } else {
        prev->next = L.first;
    }
    P = q;
    q->next = NULL;
}

address findElm(List L, infotype x) {
    if (L.first == NULL) return NULL;
    address P = L.first;

    do {
        if (P->info.nim == x.nim)
            return P;
        P = P->next;
    } while (P != L.first);

    return NULL;
}

void printInfo(List L) {
    if (L.first == NULL) {
        cout << "[List kosong]" << endl;
        return;
    }

    address P = L.first;
    do {
        cout << "Nama : " << P->info.nama << endl;
        cout << "NIM  : " << P->info.nim << endl;
        cout << "L/P  : " << P->info.jenis_kelamin << endl;
        cout << "IPK  : " << P->info.ipk << endl << endl;
        P = P->next;
    } while (P != L.first);
}

address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    return alokasi(x);
}
