#include <iostream>
using namespace std;


string bilangan (int angka) {
    
    string satuan[] = {"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan"};
 
    if (angka == 0) return "nol";
    if (angka == 10) return "sepuluh";
    if (angka == 11) return "sebelas";
    if (angka < 10) return satuan[angka];                
    if (angka < 20) return satuan[angka % 10] + " belas";  

     
    if (angka < 100) {
        int puluhan = angka / 10;   
        int sisa = angka % 10;      
        string kataPuluhan[] = {"","", "dua puluh","tiga puluh","empat puluh","lima puluh","enam puluh","tujuh puluh","delapan puluh","sembilan puluh"};
        if (sisa == 0) return kataPuluhan[puluhan];        
        return kataPuluhan[puluhan] + " " + satuan[sisa];  
    }

    if (angka == 100) return "seratus";  
    return ""; 
}

int main() {
    int angka;

    cout << "Angka: ";
    cin >> angka;
 
    if (angka < 0 || angka > 100) {
        cout << "Hanya angka 0-100" << endl;
    } else { 
        cout << "Hasil: " << bilangan(angka) << endl;
    }

    return 0;
}