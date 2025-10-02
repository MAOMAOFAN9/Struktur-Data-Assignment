#include <iostream>
using namespace std;

    void tulis (int x) {
        for (int i = 1; i < x; i++){
            cout << "Baris ke-" << i << endl;
        }
}

int main() {
    int jum;
    cout << "Jumlah Baris kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}