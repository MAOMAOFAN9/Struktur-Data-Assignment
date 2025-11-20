#include <iostream>
#include "QueuePengiriman.h"
using namespace std;

int main(){
    Queue Q; createQueue(Q);
    Paket p;

    enQueue(Q, {"123456","Hutao","Sumeru",14});
    enQueue(Q, {"234567","Ayaka","Fontaine",10});
    enQueue(Q, {"345678","Bennet","Natlan",7});
    enQueue(Q, {"456789","Furina","Liyue",16});
    enQueue(Q, {"567890","Nefer","Inazuma",6});

    cout<<"Awal:\n"; viewQueue(Q);

    deQueue(Q,p);
    cout<<"\nSetelah deQueue:\n"; viewQueue(Q);

    cout<<"\nTotal Biaya: Rp "<<totalBiaya(Q)<<"\n";
}