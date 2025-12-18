# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Rafhael Januar Turnip - 103112400209</p>

## Dasar Teori
Teori graph merupakan cabang dari matematika diskrit yang mempelajari struktur graf dan karakteristiknya. Graf didefinisikan sebagai struktur yang terdiri dari sekumpulan simpul (vertex) dan sekumpulan sisi (edge) yang merepresentasikan hubungan antar simpul. Representasi graf banyak digunakan untuk memodelkan relasi dan konektivitas pada berbagai bidang seperti ilmu komputer, jaringan, dan sistem informasi. Sebuah graf secara formal dinyatakan sebagai pasangan terurut 𝐺 = (𝑉,𝐸) G = (V,E), di mana 𝑉 merupakan himpunan simpul dan 𝐸 adalah himpunan sisi yang menghubungkan pasangan simpul tersebut.[1]

1. Depth First Search (DFS)
Depth First Search (DFS) merupakan algoritma penelusuran graf yang bekerja dengan cara mengeksplorasi simpul sedalam mungkin pada satu jalur sebelum melakukan penelusuran ke jalur lainnya. Proses DFS dimulai dari sebuah simpul awal, kemudian berpindah ke simpul tetangga yang belum dikunjungi dan terus berlanjut hingga mencapai simpul terdalam. Setelah tidak ditemukan simpul yang dapat dikunjungi, algoritma akan melakukan proses backtracking untuk melanjutkan penelusuran pada simpul lain yang belum dikunjungi. DFS banyak digunakan untuk eksplorasi struktur graf secara menyeluruh dan mendalam.[2]

2. Breadth First Search (BFS)
Breadth First Search (BFS) adalah algoritma penelusuran graf yang mengunjungi simpul berdasarkan tingkat atau level. Penelusuran dimulai dari simpul awal pada level nol, kemudian dilanjutkan dengan mengunjungi seluruh simpul yang bertetangga langsung pada level berikutnya sebelum berpindah ke level yang lebih dalam. Proses ini dilakukan secara berulang hingga seluruh simpul dalam graf berhasil dikunjungi. BFS sangat efektif digunakan untuk menemukan jalur terpendek pada graf tak berbobot dan untuk analisis keterhubungan antar simpul.[2]

## Guided 

### 1. [Guided]

### a. [Header File]
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;      //menyimpan data node (misal: char/int)
    int visited;        //Penanda untuk traversal (0/1) (penanda apakah node sudah dikunjungi)
    adrEdge firstEdge; //Pointer ke edge pertama yang terhubung
    adrNode Next;     //Pointer ke node berikutnya dalam graph
};

struct ElmEdge {
    adrNode Node;  //Pointer yang menunjuk ke lokasi node tujuan
    adrEdge Next;  //Pointer ke edge berikutnya (jika satu node memiliki banyak cabang)
};

struct Graph {
    adrNode First;  //Pointer ke node pertama dalam list graph
};

void CreateGraph(Graph &G);  //prosedur untuk mengeset fitur dari graph sebagai NULL
adrNode AlokasiNode(infoGraph data);  //alokasi node baru
adrEdge AlokasiEdge(adrNode nodeTujuan);  //alokasi Edge baru

void InsertNode(Graph &G, infoGraph data);  //menambahkan node ke dalam graph
adrNode FindNode(Graph G, infoGraph data);  //function untuk mencari alamat node berdasarkan nilai info yang diberikan
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2); //prosedur untuk menghubungkan dua node (membuat edge dari info1 ke info2)
void DisconnectNode(adrNode node1, adrNode node2);  //prosedur untuk memutuskan hubungan dua node (menghapus edge dari node1 ke node2)
void DeleteNode(Graph &G, infoGraph X);  //prosedur untuk menghapus node X beserta semua Edge yang terhubung

void PrintInfoGraph(Graph G);  //Menampilkan isi graph(Adjency list)
void ResetVisited(Graph &G);  //Reset status visited sebelum traversal
void PrintBFS(Graph G, infoGraph StartInfo);  //traversal Breadth Search / BFS (Menggunakan queue untuk menelusuri node berdasarkan tingkat)
void PrintDFS(Graph G, infoGraph StartInfo);  //traversal Depth First Search / DFS (menggunakan stack untuk menelusuri node secara mendalam)

#endif
```

### b. [Source File]

```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
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

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

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
```

### c. [Main Program]

```C++
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    
    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');  //BFS
    PrintDFS(G, 'A');  //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL) {
        cout << "node E berhasil dihapus" << endl;
    } else {
        cout << "Node E tidak berhasil dihapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');  //BFS
    PrintDFS(G, 'A');  //DFS

    return 0;
}
```

Dalam program guided ini berfungsi untuk membuat graph dengan menambahkan node menggunakan fungsi insertnode dan menghubungkan dua node atau membuat edge dengan node yang sudah ditambahkan tadi menggunakan fungsi connectnode. Pada program ini, juga dapat menampilkan hasil 2 search / menelusuri node dengan metode BFS yaitu menelusuri node dengan menggunakan queue dengan berdasarkan tingkat, serta menelusuri node dengan metode DFS yaitu penelusuran node dengan menggunakan stack dengan mendalam. Pada proses penghapusan node, program ini menggunakan 2 fungsi yaitu findnode untuk mencari node mana yang ingin dihapus dan fungsi Deletenode untuk penghapusannya.

## Unguided 

### 1. [Latihan 1]

### a. [Header File]
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct graph {
    adrNode first;
};

void CreateGraph(graph &G);
void InsertNode(graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(graph &G);

#endif
```
#### Full code Screenshot:
<img width="1919" height="1137" alt="Screenshot 2025-12-18 180916" src="https://github.com/user-attachments/assets/93231b1d-d1bf-45b9-a17e-e5c13060f505" />


### b. [Source File]

```C++
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
```
#### Full code Screenshot:
<img width="1919" height="1138" alt="Screenshot 2025-12-18 180956" src="https://github.com/user-attachments/assets/007d9706-b2bc-46b9-8931-3ed5f3044183" />


### c. [Main File]
```C++
#include "graph.h"
#include "graph.cpp"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    graph G;
    CreateGraph(G);

    InsertNode(G, 'A'); adrNode A = G.first;
    InsertNode(G, 'B'); adrNode B = A->Next;
    InsertNode(G, 'C'); adrNode C = B->Next;
    InsertNode(G, 'D'); adrNode D = C->Next;
    InsertNode(G, 'E'); adrNode E = D->Next;
    InsertNode(G, 'F'); adrNode F = E->Next;
    InsertNode(G, 'G'); adrNode Gn = F->Next;
    InsertNode(G, 'H'); adrNode H = Gn->Next;
    
    //hubungkan antar node
    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gn);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gn, H);

    cout << "=== LIST GRAPH ===" << endl;
    PrintInfoGraph(G);
    cout << endl;   
}
```
#### Full code Screenshot:
<img width="1919" height="1135" alt="Screenshot 2025-12-18 181006" src="https://github.com/user-attachments/assets/f29d9254-4869-44f3-896d-100f7ca81ebd" />


### 2. [Latihan 2]

### a. [Header File]
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct graph {
    adrNode first;
};

void CreateGraph(graph &G);
void InsertNode(graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(graph &G);
void PrintDFS(graph &G, adrNode N);

#endif
```
#### Full code Screenshot:
<img width="1919" height="1142" alt="Screenshot 2025-12-18 181159" src="https://github.com/user-attachments/assets/fa346e94-a3a6-4a22-98d0-229fd0e711cc" />


### b. [Source File]

```C++
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
```
#### Full code Screenshot:
<img width="1919" height="1138" alt="Screenshot 2025-12-18 181211" src="https://github.com/user-attachments/assets/07037f64-015d-4ef4-ba0f-6276c564db4c" />


### c. [Main File]
```C++
#include "graph.h"
#include "graph.cpp"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    graph G;
    CreateGraph(G);

    InsertNode(G, 'A'); adrNode A = G.first;
    InsertNode(G, 'B'); adrNode B = A->Next;
    InsertNode(G, 'C'); adrNode C = B->Next;
    InsertNode(G, 'D'); adrNode D = C->Next;
    InsertNode(G, 'E'); adrNode E = D->Next;
    InsertNode(G, 'F'); adrNode F = E->Next;
    InsertNode(G, 'G'); adrNode Gn = F->Next;
    InsertNode(G, 'H'); adrNode H = Gn->Next;
    
    //hubungkan antar node
    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gn);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gn, H);

    cout << "=== LIST GRAPH ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== Hasil Penelusuran DFS ===" << endl;
    PrintDFS(G, A);
    cout << endl;
}
```
#### Full code Screenshot:
<img width="1919" height="1139" alt="Screenshot 2025-12-18 181221" src="https://github.com/user-attachments/assets/6c6698b5-33f9-4a19-a0d2-160e07917bf0" />


### 3. [Latihan 3]

### a. [Header File]
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct graph {
    adrNode first;
};

void CreateGraph(graph &G);
void InsertNode(graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(graph &G);
void PrintDFS(graph &G, adrNode N);
void PrintBFS(graph &G, adrNode N);

#endif
```
#### Full code Screenshot:
<img width="1919" height="1138" alt="Screenshot 2025-12-18 181409" src="https://github.com/user-attachments/assets/09571f2b-0af5-4607-be13-100648195f2b" />


### b. [Source File]

```C++
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
```
#### Full code Screenshot:
<img width="1919" height="1134" alt="Screenshot 2025-12-18 181421" src="https://github.com/user-attachments/assets/5852712b-ccb8-47cc-9ae7-9871e46d2570" />


### c. [Main File]
```C++
#include "graph.h"
#include "graph.cpp"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    graph G;
    CreateGraph(G);

    InsertNode(G, 'A'); adrNode A = G.first;
    InsertNode(G, 'B'); adrNode B = A->Next;
    InsertNode(G, 'C'); adrNode C = B->Next;
    InsertNode(G, 'D'); adrNode D = C->Next;
    InsertNode(G, 'E'); adrNode E = D->Next;
    InsertNode(G, 'F'); adrNode F = E->Next;
    InsertNode(G, 'G'); adrNode Gn = F->Next;
    InsertNode(G, 'H'); adrNode H = Gn->Next;
    
    //hubungkan antar node
    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gn);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gn, H);

    cout << "=== LIST GRAPH ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== Hasil Penelusuran DFS ===" << endl;
    PrintDFS(G, A);
    cout << endl;

    cout << "=== Hasil Penelusuran BFS ===" << endl;
    PrintBFS(G, A);
    cout << endl;
}
```
#### Full code Screenshot:
<img width="1919" height="1136" alt="Screenshot 2025-12-18 181432" src="https://github.com/user-attachments/assets/cf9e98ba-dbdc-402f-afd6-0dd68d1d6cb2" />



## Pengerjaan Latihan Modul 14 - Graph

### Latihan 1.
<img width="734" height="706" alt="Screenshot 2025-12-18 181555" src="https://github.com/user-attachments/assets/b7fcb93f-83f4-4a39-9dac-be8c68e44072" />

#### Output latihan 1:
<img width="1343" height="288" alt="Screenshot 2025-12-18 181921" src="https://github.com/user-attachments/assets/3cd84347-983d-47b0-81c2-534aaa81dffe" />


### Latihan 2.
<img width="644" height="28" alt="Screenshot 2025-12-18 181605" src="https://github.com/user-attachments/assets/3cbdd111-75f2-4bba-8df3-e1c60c545b72" />
<img width="602" height="36" alt="Screenshot 2025-12-18 181614" src="https://github.com/user-attachments/assets/934ff16a-37c3-4540-a92e-ac812e063624" />

#### Output latihan 2:
<img width="1340" height="354" alt="Screenshot 2025-12-18 181941" src="https://github.com/user-attachments/assets/5c59bf8b-7082-487f-aed3-853fc4791584" />


### Latihan 3.
<img width="601" height="63" alt="Screenshot 2025-12-18 181620" src="https://github.com/user-attachments/assets/c6f418c2-cf77-4959-88c1-c946c4233317" />

#### Output latihan 3:
<img width="1341" height="415" alt="Screenshot 2025-12-18 182007" src="https://github.com/user-attachments/assets/3007f992-c935-4de6-8f70-6981d31eb668" />

<br>
<br>
Ketiga latihan pada Modul 14 berfokus pada pengelolaan data menggunakan struktur graph yang direpresentasikan dengan pointer dan multilist. Tujuan utama latihan-latihan ini adalah melatih pemahaman konsep node (vertex), edge, serta cara menghubungkan, menyimpan, dan menelusuri hubungan antar data secara dinamis dalam bentuk graph

1. Program ini membuat graph tak berarah menggunakan adjacency list dengan node berupa karakter. Penambahan node dilakukan hanya dengan satu fungsi, yaitu insertNode. Graph diawali dengan G.first = NULL, dan hubungan
   antar node ditampilkan menggunakan fungsi PrintInfoGraph.
   
2. Program ini membangun graph tak berarah berbasis adjacency list dan melakukan penelusuran DFS menggunakan stack. Karena tidak ada fungsi resetVisited, seluruh node diinisialisasi dengan visited = 0. Hasil DFS
   ditampilkan melalui pemanggilan fungsi PrintDFS dengan node awal A.
   
3. Program ini mengimplementasikan graph tak berarah dengan adjacency list serta mendukung penelusuran DFS (stack) dan BFS (queue). Status visited diinisialisasi bernilai 0 pada awal program. Hasil penelusuran BFS
   ditampilkan dengan memanggil fungsi PrintBFS dari main dengan node awal A.

## Kesimpulan
Pada materi ini, membahas beberapa fungsi pada graph seperti insertNode, connectNode, serta penelusuran graph menggunakan DFS dan BFS. DFS melakukan penelusuran dengan bantuan stack, sedangkan BFS menggunakan queue. Meskipun tanpa fungsi alokasi, findNode, dan resetVisited, proses tetap dapat berjalan dengan memodifikasi fungsi insertNode dan menginisialisasi nilai visited = 0 pada awal proses DFS dan BFS.

## Referensi
[1]MENGIDENTIFIKASI POLA KONSUMSI ENERGI RUMAH TANGGA MENGGUNAKAN ALGORITMA GRAFBERBASIS C++ Oleh Alvin Hafiz&sup1;, Fadilla Amanah&sup2;, Revi Damurti&sup3;, Putri Harliana&sup4;. diakses pada tanggal 18 Desember 2025 melalui: <br>
https://www.ejournal.itn.ac.id/jati/article/view/11788/6637.

[2]Struktur Data Dan Algoritma Dengan C++ (Vol. 1). CV. AA. RIZKY. Oleh Anita Sindar&sup1;. diakses pada tanggal 18 Desember 2025 melalui: <br>
https://www.researchgate.net/publication/337657500_STRUKTUR_DATA_DAN_ALGORITMA_DENGAN_C#page=19.26





















