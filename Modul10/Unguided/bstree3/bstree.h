#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include <algorithm> 
#define Nil NULL
using namespace std;
typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);
void printPreOrder(address root);
void printPostOrder(address root);

#endif