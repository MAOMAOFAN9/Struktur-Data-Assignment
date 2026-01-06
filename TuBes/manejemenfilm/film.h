#ifndef FILM_H
#define FILM_H

#include <string>
using namespace std;

struct Child {
    string namaAktor;
    Child *next;
};

struct Film {
    string judul;     
    int tahun;
    string genre;
    int durasi;
    string aktor[10];
    int jumlahAktor;
};

struct Node {
    Film data;
    Node *left;
    Node *right;
    Child *firstChild;
};


Node* createNode(Film f);
Node* insertFilm(Node *root, Film f);
Node* searchFilm(Node *root, string judul);
Node* deleteFilm(Node *root, string judul);
Node* findMin(Node *root); 

void tambahAktor(Node *filmNode, string namaAktor);
void hapusAktor(Node *filmNode, string namaAktor);
void editFilm(Node* filmNode);
void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);
int countFilm(Node *root);
void cariDurasi(Node *root, Node* &minFilm, Node* &maxFilm);
void insertDummyData(Node* &root);

#endif
