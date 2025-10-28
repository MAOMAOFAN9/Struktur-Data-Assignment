#include <iostream>
#include "singlylist.h"
using namespace std;

int main(){
    list L;
    buatList(L);

    //update singlylist dari modul 4 dan ganti sesuai modul 5
    node *P1 = buatNode(2);
    node *P2 = buatNode(0);
    node *P3 = buatNode(8);
    node *P4 = buatNode(12);
    node *P5 = buatNode(9);

    insertAwal(L, P1); 
    insertAwal(L, P2); 
    insertAwal(L, P3); 
    insertAwal(L, P4);
    insertAwal(L, P5); 

    cout << endl;
    cout << "Nilai kelima elemen: ";
    tampil(L);
    cout << endl;

    node *found = findElm(L, 8);
    if (found != NULL)
        cout << "Elemen dengan nilai 8 ditemukan di alamat: " << found << endl;
    else
        cout << "Elemen dengan nilai 8 tidak ditemukan." << endl;
    cout << endl;

    
    cout << "Total info dari kelima elemen adalah : " << totalInfo(L) << endl;
    cout << endl;

    return 0;
}
