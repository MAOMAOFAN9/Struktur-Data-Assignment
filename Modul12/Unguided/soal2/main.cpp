#include <iostream>
#include "multilist.h"
#include "multilist.cpp"
using namespace std;

int main() {
    listinduk L;
    createList(L);

    //Tambah beberapa induk
    insertLast(L, alokasi(101));
    insertLast(L, alokasi(102));
    insertLast(L, alokasi(103));

    cout << "\nSetelah tambah induk:\n";
    printInfo(L);

    //Tambah anak ke induk 101
    address p = findElm(L, 101);
    if (p) {
        insertLastAnak(p->lanak, alokasiAnak(10));
        insertLastAnak(p->lanak, alokasiAnak(20));
    }

    //Tambah anak ke induk 102
    p = findElm(L, 102);
    if (p) insertLastAnak(p->lanak, alokasiAnak(99));

    //Tambah anak ke induk 103
    p = findElm(L, 103);
    if (p) {
        insertFirstAnak(p->lanak, alokasiAnak(5));
        insertLastAnak(p->lanak, alokasiAnak(6));
        insertLastAnak(p->lanak, alokasiAnak(7));
    }

    cout << "\nSetelah tambah anak:\n";
    printInfo(L);

    //Hapus anak 99 dari induk 102
    cout << "\nHapus anak 99 dari induk 102\n";
    p = findElm(L, 102);
    if (p) delPAnak(p->lanak, 99);
    printInfo(L);

    //Hapus induk 101 (beserta anak)
    cout << "\nHapus induk 101\n";
    delP(L, 101);
    printInfo(L);

    return 0;
}
