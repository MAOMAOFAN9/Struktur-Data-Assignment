#include <iostream>
#include "singlylist.h"
using namespace std;

int main(){
    list L;
    buatList(L);

    node *a=buatNode(5);
    node *b=buatNode(7);
    node *c=buatNode(9);
    node *d=buatNode(2);
    node *e=buatNode(8);
    node *f=buatNode(12);

    insertAwal(L,a);
    insertAkhir(L,b);
    insertAkhir(L,c);
    insertAwal(L,d);
    insertAfter(b,e);
    insertAkhir(L,f);

    cout<<"Isi list : ";
    tampil(L);
}
