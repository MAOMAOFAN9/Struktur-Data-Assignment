#include <iostream>
#include "DLLPlaylist.h"
using namespace std;

int main(){
    List L; createList(L);

    insertLast(L, {"Senja di Kota","Nona Band",210,150,4.2});
    insertLast(L, {"Langkahmu","Delta",185,320,4.8});
    insertLast(L, {"Hujan Minggu","Arka",240,90,3.9});

    cout<<"Awal:\n"; viewList(L);

    Song x;
    deleteLast(L,x);
    cout<<"\nHapus belakang:\n"; viewList(L);

    updateAtPosition(L,2,{"Pelita","Luna",200,260,4.5});
    cout<<"\nUpdate pos 2:\n"; viewList(L);

    Node* pos2=L.head->next;
    insertBefore(L,pos2,{"Senandung","Mira",175,120,4.0});
    cout<<"\nInsertBefore pos 2:\n"; viewList(L);

    updateBefore(pos2,{"UpdateBefore","ArtX",180,200,4.3});
    cout<<"\nUpdateBefore pos 2:\n"; viewList(L);

    Node* pos3=L.head->next->next;
    deleteBefore(L,pos3,x);
    cout<<"\nDeleteBefore pos 3:\n"; viewList(L);

    cout<<"\nSearch 150-300:\n";
    searchByPopularityRange(L,150,300);

    return 0;
}