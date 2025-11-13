#include "doublylist.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

bool isEmpty(List L) {
    return (L.First == Nil && L.Last == Nil);
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    if (isEmpty(L)) {
        cout << "DATA LIST KOSONG" << endl;
        return;
    }
    
    address P = L.Last;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

address findElm(List L, string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void searchAndPrintAll(List L, string nopol) {
    address P = L.First;
    bool found = false;
    
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            cout << "Nomor Polisi : " << P->info.nopol << endl;
            cout << "Warna        : " << P->info.warna << endl;
            cout << "Tahun        : " << P->info.thnBuat << endl;
            cout << "-----------------" << endl;
            found = true;
        }
        P = P->next;
    }
    
    if (!found) {
        cout << "Data dengan nomor polisi " << nopol << " tidak ditemukan." << endl;
    }
}

int deleteAllMatches(List &L, string nopol) {
    int count = 0;
    address P = L.First;
    
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            address Pdel = P;
            P = P->next;
            
            if (Pdel == L.First) {
                deleteFirst(L, Pdel);
            } else if (Pdel == L.Last) {
                deleteLast(L, Pdel);
            } else {
                address Prec = Pdel->prev;
                deleteAfter(L, Prec, Pdel);
            }
            dealokasi(Pdel);
            count++;
            
        } else {
            P = P->next;
        }
    }
    return count;
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;
        L.First->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    P = Prec->next;
    if (P == L.Last) {
        deleteLast(L, P);
    } else {
        Prec->next = P->next;
        P->next->prev = Prec;
        P->next = Nil;
        P->prev = Nil;
    }
}