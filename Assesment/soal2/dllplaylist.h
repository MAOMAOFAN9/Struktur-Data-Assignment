#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#include <string>
using namespace std;

struct Song {
    string Title, Artist;
    int DurationSec, PlayCount;
    float Rating;
};

struct Node {
    Song info;
    Node *prev, *next;
};

struct List {
    Node *head, *tail;
};

void createList(List &L);
Node* newNode(Song S);
bool isEmpty(List L);

void insertLast(List &L, Song S);
void insertBefore(List &L, Node* Q, Song S);

void deleteLast(List &L, Song &S);
void deleteBefore(List &L, Node* Q, Song &S);

void updateAtPosition(List &L, int pos, Song S);
void updateBefore(Node* Q, Song S);

void viewList(List L);
void searchByPopularityRange(List L, float a, float b);

#endif