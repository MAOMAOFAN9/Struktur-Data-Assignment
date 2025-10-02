#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main () {
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a : " << a << endl;
    cout << "Alamat a (&a) : " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat red (&ref): " << &ref << endl;


    //mengubah nilai a lewar refrence
    ref = 50;
    cout << "\nSetelah ref = 50: " << endl;
    cout << "Nilai a :" << a << endl;
    cout << "Nilai ref :" << ref << endl;

tukar(&a, &b);
cout << "After swapping, value of a : " << a << " and b=" << b << endl;

return 0;
}