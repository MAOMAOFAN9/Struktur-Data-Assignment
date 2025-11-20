#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

float nilaiAkhir(Mahasiswa m){
    return 0.2*m.Tugas + 0.4*m.UTS + 0.4*m.UAS;
}

void createStack(Stack &S){ S.top = -1; }
bool isEmpty(Stack S){ return S.top == -1; }
bool isFull(Stack S){ return S.top == MAX-1; }

void push(Stack &S, Mahasiswa M){
    if(!isFull(S)) S.data[++S.top] = M;
}

void pop(Stack &S, Mahasiswa &M){
    if(!isEmpty(S)) M = S.data[S.top--];
}

void updatePos(Stack &S, int pos, Mahasiswa M){
    int idx = pos-1;
    if(idx >=0 && idx <= S.top) S.data[idx] = M;
}

void view(Stack S){
    if(isEmpty(S)){ cout<<"(kosong)\n"; return; }
    for(int i=0;i<=S.top;i++){
        cout<<i+1<<". "<<S.data[i].Nama
            <<" | NIM:"<<S.data[i].NIM
            <<" | NA:"<<nilaiAkhir(S.data[i])<<"\n";
    }
}

void searchNA(Stack S, float a, float b){
    bool ada=false;
    for(int i=0;i<=S.top;i++){
        float na = nilaiAkhir(S.data[i]);
        if(na>=a && na<=b){
            ada=true;
            cout<<i+1<<". "<<S.data[i].Nama<<" "<<na<<"\n";
        }
    }
    if(!ada) cout<<"Tidak ada\n";
}

void maxNA(Stack S){
    if(isEmpty(S)){ cout<<"(kosong)\n"; return; }
    float mx = nilaiAkhir(S.data[0]);
    for(int i=1;i<=S.top;i++){
        float na = nilaiAkhir(S.data[i]);
        if(na > mx) mx = na;
    }
    cout<<"Nilai Akhir tertinggi: "<<mx<<"\n";
    for(int i=0;i<=S.top;i++)
        if(nilaiAkhir(S.data[i]) == mx)
            cout<<i+1<<". "<<S.data[i].Nama<<"\n";
}