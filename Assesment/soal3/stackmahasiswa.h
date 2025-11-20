#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H
#include <string>
using namespace std;

struct Mahasiswa {
    string Nama, NIM;
    float Tugas, UTS, UAS;
};

const int MAX = 6;

struct Stack {
    Mahasiswa data[MAX];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);

void push(Stack &S, Mahasiswa M);
void pop(Stack &S, Mahasiswa &M);

void updatePos(Stack &S, int pos, Mahasiswa M);
void view(Stack S);

void searchNA(Stack S, float a, float b);
void maxNA(Stack S);

#endif