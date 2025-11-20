#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H
#include <string>
using namespace std;

struct Paket {
    string Resi, Pengirim, Tujuan;
    int Berat;
};

const int MAX = 5;

struct Queue {
    Paket data[MAX];
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);

void enQueue(Queue &Q, Paket P);
void deQueue(Queue &Q, Paket &P);
void viewQueue(Queue Q);

long long totalBiaya(Queue Q);

#endif