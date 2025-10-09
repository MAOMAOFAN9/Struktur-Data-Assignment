#include <iostream>
using namespace std;


void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;   
    *a = *b;         
    *b = *c;         
    *c = temp;     
}
void tukarReference(int &a, int &b, int &c) {
    int temp = a;   
    a = b;          
    b = c;           
    c = temp;       
}
int main() {
    int x = 10, y = 20, z = 30;

    cout << "Sebelum ditukar:" << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    tukarPointer(&x, &y, &z);
    cout << "\nSetelah ditukar dengan Pointer:" << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    tukarReference(x, y, z);
    cout << "\nSetelah ditukar dengan Reference:" << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    return 0;
}