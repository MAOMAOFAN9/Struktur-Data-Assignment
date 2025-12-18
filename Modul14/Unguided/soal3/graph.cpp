#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void CreateGraph(graph &G){
    G.first = NULL;
}

void InsertNode(graph &G, infoGraph X){
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = X;
    nodeBaru->visited = 0;
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;

    if(G.first == NULL) {
        G.first = nodeBaru;
    } else {
        adrNode nodeBantu = G.first;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {

        // Buat edge dari N1 -> N2
        adrEdge E1 = new ElmEdge;
        E1->Node = N2;
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        // Buat edge dari N2 -> N1 (undirected)
        adrEdge E2 = new ElmEdge;
        E2->Node = N1;
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(graph &G) {
    adrNode nodeBantu = G.first;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " ";
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

void PrintDFS(graph &G, adrNode N){
    adrNode temp = G.first;
    while (temp != NULL) {
        temp->visited = 0;
        temp = temp->Next;
    }
    if (N == NULL) return;
    stack<adrNode> Stak;
    Stak.push(N);
    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}

void PrintBFS(graph &G, adrNode N){
    adrNode temp = G.first;
    while (temp != NULL) {
        temp->visited = 0;
        temp = temp->Next;
    }
    if (N == NULL ){
        return;
    }
    queue<adrNode> Qyu;
    Qyu.push(N);
    N->visited = 1;
    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}