#include <iostream>
#include "doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    
    address P;
    infotype data;
    string nopolCari, nopolHapus;

    cout << "Program Input Data Kendaraan" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> data.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> data.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> data.thnBuat;

        P = alokasi(data);
        insertLast(L, P);
        
        cout << "-------------------------------" << endl;
    }

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);
    cout << endl;

    cout << "Program Pencarian Data" << endl;
    cout << "Masukkan Nomor Polisi yang dicari: ";
    cin >> nopolCari;

    searchAndPrintAll(L, nopolCari);
    
    cout << endl;

    cout << "Program Hapus Data" << endl;
    cout << "Masukkan Nomor Polisi yang akan dihapus: ";
    cin >> nopolHapus;
    
    int deleteCount = deleteAllMatches(L, nopolHapus);
    
    if (deleteCount > 0) {
        cout << "Sebanyak " << deleteCount << " data dengan nomor polisi " 
             << nopolHapus << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan nomor polisi " << nopolHapus << " tidak ditemukan." << endl;
    }
    cout << endl;

    cout << "DATA LIST 1 (Setelah Dihapus)" << endl;
    printInfo(L);
    
    return 0;
}