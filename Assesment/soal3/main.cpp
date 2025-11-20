#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

int main(){
    Stack S; createStack(S);
    Mahasiswa m;

    push(S, {"Venti","11111",75.7,82.1,65.5});
    push(S, {"Xiao","22222",87.4,88.9,81.9});
    push(S, {"Kazuha","33333",92.3,88.8,82.4});
    push(S, {"Wanderer","44444",95.5,85.5,90.5});
    push(S, {"Lynette","55555",77.7,65.4,79.9});
    push(S, {"Chasca","66666",99.9,93.6,87.3});

    cout<<"Stack awal:\n"; view(S);

    pop(S,m);
    cout<<"\nSetelah pop:\n"; view(S);

    updatePos(S,3,{"Heizou","77777",99.9,88.8,77.7});
    cout<<"\nSetelah update pos 3:\n"; view(S);

    cout<<"\nCari NA 85.5 - 95.5:\n";
    searchNA(S,85.5,95.5);

    cout<<"\nNilai akhir maksimum:\n";
    maxNA(S);

    return 0;
}