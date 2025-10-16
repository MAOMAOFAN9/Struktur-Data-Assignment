#include <iostream>
using namespace std;

void tampil(int a[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void tukarArr(int x[3][3], int y[3][3], int r, int c){
    int tmp = x[r][c];
    x[r][c] = y[r][c];
    y[r][c] = tmp;
}

void tukarPtr(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int A[3][3] = {{3,16,9},{1,12,1},{2,51,8}};
    int B[3][3] = {{21,3,5},{7,9,23},{4,65,8}};
    int *p1, *p2;
    int n1=10, n2=20;

    p1=&n1;
    p2=&n2;

    cout<<"Array A:"<<endl;
    tampil(A);
    cout<<"Array B:"<<endl;
    tampil(B);

    cout<<"\nTukar posisi (1,1)"<<endl;
    tukarArr(A,B,1,1);

    cout<<"Array A sekarang:"<<endl;
    tampil(A);
    cout<<"Array B sekarang:"<<endl;
    tampil(B);

    cout<<"\nNilai sebelum tukar pointer: "<<n1<<" dan "<<n2<<endl;
    tukarPtr(p1,p2);
    cout<<"Nilai sesudah tukar pointer: "<<n1<<" dan "<<n2<<endl;

    return 0;
}
