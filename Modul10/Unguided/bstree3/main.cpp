#include <iostream>
#include "bstree.h"
#include "bstree.cpp"

using namespace std;

int main() {
    //soal3
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root, 6);   
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 3);

    cout << "PreOrder Traversal: " << endl;
    printPreOrder(root);
    cout << "\n";
    cout << "PostOrder Traversal: " << endl;
    printPostOrder(root);
    cout << "\n";

    return 0;
}