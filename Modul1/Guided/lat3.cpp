#include <iostream>
using namespace std;

int main () {
    int angka1 = 10;
    int angka2 = 20;

    if (angka1 > angka2) {
        cout << "angka-1 lebih besar dari angka-2" << endl;
    } else if (angka1 < angka2) {
        cout << "angka-1 lebih kecil dari angka-2" << endl;
    } else {
        cout << "angka-1 sama dengan angka-2" << endl;
    }

    return 0;
}