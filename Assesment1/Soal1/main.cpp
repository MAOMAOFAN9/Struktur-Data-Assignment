#include <iostream>
#include "sllinventory.h"
using namespace std;

int main(){
    List L; createList(L);

    insertLast(L,{"Pulpen","A001",20,2500,0});
    insertLast(L,{"Buku_Tulis","A002",15,5000,10});
    insertLast(L,{"Penghapus","A003",30,1500,0});

    cout<<"Awal:\n"; viewList(L);

    Product x; deleteFirst(L,x);
    cout<<"\nSetelah deleteFirst:\n"; viewList(L);

    cout<<"\nUpdate pos 2 (input langsung):\n";
    updateAtPosition(L,2);

    cout<<"\nSetelah update:\n"; viewList(L);

    cout<<"\nSearch 2000-7000:\n";
    searchByFinalPriceRange(L,2000,7000);

    cout<<"\nMax harga akhir:\n";
    MaxHargaAkhir(L);
}