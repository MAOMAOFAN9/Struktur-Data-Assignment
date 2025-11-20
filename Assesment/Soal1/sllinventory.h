#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H
#include <string>
using namespace std;

struct Product{ string Nama,SKU; int Jumlah; float HargaSatuan,DiskonPersen; };
struct Node{ Product info; Node* next; };
struct List{ Node* head; };

void createList(List& L);
bool isEmpty(List L);
Node* allocate(Product P);
void deallocate(Node* p);
void insertFirst(List& L, Product P);
void insertLast(List& L, Product P);
void insertAfter(List& L, Node* Q, Product P);
void deleteFirst(List& L, Product& P);
void deleteLast(List& L, Product& P);
void deleteAfter(List& L, Node* Q, Product& P);
void updateAtPosition(List& L, int pos);
void viewList(List L);
void searchByFinalPriceRange(List L, float a, float b);
void MaxHargaAkhir(List L);

#endif