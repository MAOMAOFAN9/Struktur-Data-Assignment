#include <iostream>
using namespace std;

void tampilArray(int arr[], int n){
    cout << "Isi array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

int cariMIN(int arr[], int ukuran){
    int MIN = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] < MIN){
            MIN = arr[i];
        }
    }
    return MIN;
}

float NilaiRataRata(int arr[], int n){
    int total = 0;
    for(int i = 0; i < n; i++){
        total += arr[i];
    }
    return (float)total / n;
}

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int inputan;

    do {
        cout << "\n-- Menu Program Array --\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Masukkan Inputan: ";
        cin >> inputan;

        switch (inputan){
            case 1:
                tampilArray(arrA, 10); break;
            case 2:
                cout << "Nilai Maksimumnya adalah: " << cariMAX(arrA, 10) << endl; break;
            case 3:
                cout << "Nilai Minimumnya adalah: " << cariMIN(arrA, 10) << endl; break;
            case 4:
                cout << "Nilai rata ratanya adalah: " << NilaiRataRata(arrA, 10) << endl; break;
            case 5:
                cout << "Program selesai\n"; break;
        }
    } while (inputan != 5);

    return 0;
}