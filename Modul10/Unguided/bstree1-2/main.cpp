#include <iostream>
#include "bstree.h"
#include "bstree.cpp"

using namespace std;

int main() {
    //soal1
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    printInorder(root);
    
    cout << "\n";
    //soal2
    cout << "Kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "Jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "Total : " << hitungTotalInfo(root, 0) << endl;

    return 0;
}