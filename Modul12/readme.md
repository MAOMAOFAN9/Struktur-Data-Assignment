# <h1 align="center">Laporan Praktikum Modul 12 - Multi Linked List</h1>
<p align="center">Rafhael Januar Turnip - 103112400209</p>

## Dasar Teori
Multi linked list merupakan struktur data di mana setiap node dapat memiliki lebih dari satu pointer, memungkinkan hubungan kompleks seperti multiple parent-child atau representasi grid dua dimensi. Struktur ini efisien untuk operasi insertion dan deletion karena fleksibilitas pointer, sering digunakan dalam aplikasi seperti word search puzzle untuk membentuk grid karakter. Berbeda dengan singly linked list, node di multi linked list memiliki beberapa data field dan pointer field untuk navigasi multidimensi.[1]

Berikut beberapa operasi dasarnya:

a. Insert Anak dan Induk.<br>
Pada operasi insert anak (child), node baru dibuat dan pointer child dari parent node diupdate untuk menunjuk ke node tersebut, sementara pointer parent dari node anak diarahkan ke induknya. Insert induk (parent) melibatkan pembuatan node baru yang pointer child-nya menunjuk ke anak yang ada, serta update pointer parent anak ke induk baru. Proses ini memerlukan traversal untuk menemukan posisi tepat, dengan kompleksitas O(1) jika pointer tail/head tersedia, seperti dalam implementasi doubly linked list yang dimodifikasi untuk multi-link.[2]

b. Delete Anak dan Induk.<br>
Delete anak dalam multi linked list mengikuti prinsip serupa dengan insertion, di mana traversal dilakukan untuk menemukan node target, kemudian pointer sibling atau child dari parent diupdate untuk melewati node anak sebelum membebaskan memori. Delete induk memerlukan penyesuaian pointer child yang menunjuk ke node induk, sering dengan reparenting ke induk alternatif atau penghapusan rekursif untuk menjaga integritas struktur. Pendekatan ini memanfaatkan modifikasi doubly linked list untuk efisiensi operasi bidirectional, menghindari traversal linear panjang.[2]

## Guided 

### 1. [Guided]

### a. [Header File]
```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```

### b. [Source File]

```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```

### c. [Main Program]

```C++
#include "mll.h"
#include "mll.cpp"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```

Dalam program guided ini mengelola data instansi dan surat menggunakan multi linked list, di mana setiap instansi dapat memiliki beberapa surat. Program menyediakan fitur untuk menambah, menampilkan, mencari, dan menghapus data. Tujuannya adalah mempermudah pengelolaan relasi antara instansi dan surat secara sederhana dan terstruktur.

## Unguided 

### 2. [Latihan 2]

### a. [Header File]
```C++
#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <iostream>
#define Nil NULL

using namespace std;

typedef int infotypeinduk;
typedef int infotypeanak;

typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

struct listanak {
    address_anak first;
    address_anak last;
};

struct elemen_list_induk {
    infotypeinduk info;
    listanak lanak; 
    address next;
    address prev;
};

struct listinduk {
    address first;
    address last;
};

void createList(listinduk &L);
bool listEmpty(listinduk L);
address alokasi(infotypeinduk X);
void dealokasi(address &P);
void insertFirst(listinduk &L, address P);
void insertLast(listinduk &L, address P);
void insertAfter(listinduk &L, address P, address Prec);
void delFirst(listinduk &L, address &P);
void delLast(listinduk &L, address &P);
void delAfter(listinduk &L, address &P, address Prec);
void delP(listinduk &L, infotypeinduk X);
address findElm(listinduk L, infotypeinduk X);
void printInfo(listinduk L);
void createListAnak(listanak &L);
bool listEmptyAnak(listanak L);
address_anak alokasiAnak(infotypeanak X);
void dealokasiAnak(address_anak &P);
void insertFirstAnak(listanak &L, address_anak P);
void insertLastAnak(listanak &L, address_anak P);
void insertAfterAnak(listanak &L, address_anak P, address_anak Prec);
void delFirstAnak(listanak &L, address_anak &P);
void delLastAnak(listanak &L, address_anak &P);
void delAfterAnak(listanak &L, address_anak &P, address_anak Prec);
void delPAnak(listanak &L, infotypeanak X);
address_anak findElmAnak(listanak L, infotypeanak X);
void printInfoAnak(listanak L);

#endif
```
#### Full code Screenshot:
<img width="1919" height="1138" alt="Screenshot 2025-12-09 192551" src="https://github.com/user-attachments/assets/2abe5e81-35c2-4781-8129-9366c167062e" />


### b. [Source File]

```C++
#include "multilist.h"
#include <iostream>
using namespace std;

//list induk
void createList(listinduk &L) { L.first = L.last = Nil; }
bool listEmpty(listinduk L) { return L.first == Nil; }

address alokasi(infotypeinduk X) {
    address P = new elemen_list_induk;
    P->info = X;
    P->next = P->prev = Nil;
    createListAnak(P->lanak);
    return P;
}

void dealokasi(address &P) {
    address_anak c = P->lanak.first;
    while (c != Nil) {
        address_anak tmp = c;
        c = c->next;
        delete tmp;
    }
    delete P;
    P = Nil;
}

void insertFirst(listinduk &L, address P) {
    if (listEmpty(L)) L.first = L.last = P;
    else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(listinduk &L, address P) {
    if (listEmpty(L)) L.first = L.last = P;
    else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfter(listinduk &L, address P, address Prec) {
    if (!Prec) return;

    P->next = Prec->next;
    P->prev = Prec;

    if (Prec->next) {
        Prec->next->prev = P;
    } else {
        L.last = P;   
    }

    Prec->next = P;
}

void delFirst(listinduk &L, address &P) {
    P = L.first;
    if (!P) return;
    if (L.first == L.last) L.first = L.last = Nil;
    else {
        L.first = P->next;
        L.first->prev = Nil;
    }
    P->next = Nil;
}

void delLast(listinduk &L, address &P) {
    P = L.last;
    if (!P) return;
    if (L.first == L.last) L.first = L.last = Nil;
    else {
        L.last = P->prev;
        L.last->next = Nil;
    }
    P->prev = Nil;
}

void delAfter(listinduk &L, address &P, address Prec) {
    if (!Prec || !Prec->next) return;
    P = Prec->next;
    Prec->next = P->next;
    if (P->next) P->next->prev = Prec;
    else L.last = Prec;
    P->next = P->prev = Nil;
}

void delP(listinduk &L, infotypeinduk X) {
    address P = findElm(L, X), Q;
    if (!P) return;
    if (P == L.first) delFirst(L, Q);
    else if (P == L.last) delLast(L, Q);
    else delAfter(L, Q, P->prev);
    dealokasi(Q);
}

address findElm(listinduk L, infotypeinduk X) {
    for (address P = L.first; P; P = P->next)
        if (P->info == X) return P;
    return Nil;
}

void printInfo(listinduk L) {
    if (listEmpty(L)) {
        cout << "[List Kosong]\n";
        return;
    }
    for (address P = L.first; P; P = P->next) {
        cout << "[Induk " << P->info << "]";
        printInfoAnak(P->lanak);
        cout << endl;
    }
}

//list anak
void createListAnak(listanak &L) { L.first = L.last = Nil; }
bool listEmptyAnak(listanak L) { return L.first == Nil; }

address_anak alokasiAnak(infotypeanak X) {
    address_anak P = new elemen_list_anak;
    P->info = X;
    P->next = P->prev = Nil;
    return P;
}

void dealokasiAnak(address_anak &P) { delete P; P = Nil; }

void insertFirstAnak(listanak &L, address_anak P) {
    if (listEmptyAnak(L)) L.first = L.last = P;
    else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastAnak(listanak &L, address_anak P) {
    if (listEmptyAnak(L)) L.first = L.last = P;
    else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfterAnak(listanak &L, address_anak P, address_anak Prec) {
    if (!Prec) return;
    P->next = Prec->next;
    P->prev = Prec;
    if (Prec->next) Prec->next->prev = P;
    else L.last = P;
    Prec->next = P;
}

void delFirstAnak(listanak &L, address_anak &P) {
    P = L.first;
    if (!P) return;
    if (L.first == L.last) L.first = L.last = Nil;
    else {
        L.first = P->next;
        L.first->prev = Nil;
    }
    P->next = Nil;
}

void delLastAnak(listanak &L, address_anak &P) {
    P = L.last;
    if (!P) return;
    if (L.first == L.last) L.first = L.last = Nil;
    else {
        L.last = P->prev;
        L.last->next = Nil;
    }
    P->prev = Nil;
}

void delAfterAnak(listanak &L, address_anak &P, address_anak Prec) {
    if (!Prec || !Prec->next) return;
    P = Prec->next;
    Prec->next = P->next;
    if (P->next) P->next->prev = Prec;
    else L.last = Prec;
    P->next = P->prev = Nil;
}

void delPAnak(listanak &L, infotypeanak X) {
    address_anak P = findElmAnak(L, X), tmp;
    if (!P) return;
    if (P == L.first) delFirstAnak(L, tmp);
    else if (P == L.last) delLastAnak(L, tmp);
    else delAfterAnak(L, tmp, P->prev);
    dealokasiAnak(tmp);
}

address_anak findElmAnak(listanak L, infotypeanak X) {
    for (address_anak P = L.first; P; P = P->next)
        if (P->info == X) return P;
    return Nil;
}

void printInfoAnak(listanak L) {
    if (listEmptyAnak(L)) { cout << " -> (Tidak ada anak)"; return; }
    cout << " -> Anak: ";
    for (address_anak P = L.first; P; P = P->next)
        cout << P->info << " ";
}
```
#### Full code Screenshot:
<img width="1919" height="1137" alt="Screenshot 2025-12-09 192602" src="https://github.com/user-attachments/assets/d4e3d96b-1a8f-4826-b81f-9a5fe1ba3785" />


### c. [Main File]
```C++
#include <iostream>
#include "multilist.h"
#include "multilist.cpp"
using namespace std;

int main() {
    listinduk L;
    createList(L);

    //Tambah beberapa induk
    insertLast(L, alokasi(101));
    insertLast(L, alokasi(102));
    insertLast(L, alokasi(103));

    cout << "\nSetelah tambah induk:\n";
    printInfo(L);

    //Tambah anak ke induk 101
    address p = findElm(L, 101);
    if (p) {
        insertLastAnak(p->lanak, alokasiAnak(10));
        insertLastAnak(p->lanak, alokasiAnak(20));
    }

    //Tambah anak ke induk 102
    p = findElm(L, 102);
    if (p) insertLastAnak(p->lanak, alokasiAnak(99));

    //Tambah anak ke induk 103
    p = findElm(L, 103);
    if (p) {
        insertFirstAnak(p->lanak, alokasiAnak(5));
        insertLastAnak(p->lanak, alokasiAnak(6));
        insertLastAnak(p->lanak, alokasiAnak(7));
    }

    cout << "\nSetelah tambah anak:\n";
    printInfo(L);

    //Hapus anak 99 dari induk 102
    cout << "\nHapus anak 99 dari induk 102\n";
    p = findElm(L, 102);
    if (p) delPAnak(p->lanak, 99);
    printInfo(L);

    //Hapus induk 101 (beserta anak)
    cout << "\nHapus induk 101\n";
    delP(L, 101);
    printInfo(L);

    return 0;
}
```
#### Full code Screenshot:
<img width="1919" height="1137" alt="Screenshot 2025-12-09 192617" src="https://github.com/user-attachments/assets/5195a74f-2a25-4b5d-ac70-19f0e3a047cc" />


### 3. [Latihan 3]

### a. [Header File]
```C++
#ifndef CIRCULARLIST_H_INCLUDED
#define CIRCULARLIST_H_INCLUDED

#include <iostream>
using namespace std;

struct infotype {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
};

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertFirst(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteLast(List &L, address &P);

address findElm(List L, infotype x);
void printInfo(List L);

address createData(string nama, string nim, char jenis_kelamin, float ipk);

#endif

```
#### Full code Screenshot:
<img width="1919" height="1134" alt="Screenshot 2025-12-09 192728" src="https://github.com/user-attachments/assets/cd12ab3a-ac90-4a47-a721-76435c710558" />

### b. [Source File]

```C++
#include "circularlist.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = P;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address q = L.first;
        while (q->next != L.first) q = q->next;
        q->next = P;
        P->next = L.first;
        L.first = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address q = L.first;
        while (q->next != L.first) q = q->next;
        q->next = P;
        P->next = L.first;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first == NULL) return;

    address last = L.first;
    while (last->next != L.first) last = last->next;

    P = L.first;
    if (P == last) {
        L.first = NULL;
    } else {
        last->next = P->next;
        L.first = P->next;
    }
    P->next = NULL;
}

void deleteAfter(List &L, address Prec, address &P) {
    if (L.first == NULL || Prec == NULL) return;
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}

void deleteLast(List &L, address &P) {
    if (L.first == NULL) return;

    address prev = NULL, q = L.first;
    while (q->next != L.first) {
        prev = q;
        q = q->next;
    }

    if (prev == NULL) {
        L.first = NULL;
    } else {
        prev->next = L.first;
    }
    P = q;
    q->next = NULL;
}

address findElm(List L, infotype x) {
    if (L.first == NULL) return NULL;
    address P = L.first;

    do {
        if (P->info.nim == x.nim)
            return P;
        P = P->next;
    } while (P != L.first);

    return NULL;
}

void printInfo(List L) {
    if (L.first == NULL) {
        cout << "[List kosong]" << endl;
        return;
    }

    address P = L.first;
    do {
        cout << "Nama : " << P->info.nama << endl;
        cout << "NIM  : " << P->info.nim << endl;
        cout << "L/P  : " << P->info.jenis_kelamin << endl;
        cout << "IPK  : " << P->info.ipk << endl << endl;
        P = P->next;
    } while (P != L.first);
}

address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    return alokasi(x);
}

```
#### Full code Screenshot:
<img width="1919" height="1135" alt="Screenshot 2025-12-09 192824" src="https://github.com/user-attachments/assets/c86ef3ca-9bdf-4a78-8e50-45ad28a1f892" />

### c. [Main File]
```C++
#include <iostream>
#include "circularlist.h"
#include "circularlist.cpp"
using namespace std;

int main() {
    List L, A, B, L2;
    address P1 = NULL;
    address P2 = NULL;
    infotype x;

    createList(L);

    cout << "coba insert first, last, dan after" << endl;
    P1 = createData("Danu", "04", 'l', 4.0);
    insertFirst(L, P1);

    P1 = createData("Fahmi", "06", 'l', 3.45);
    insertLast(L, P1);

    P1 = createData("Bobi", "02", 'l', 3.71);
    insertFirst(L, P1);

    P1 = createData("Ali", "01", 'l', 3.3);
    insertFirst(L, P1);

    P1 = createData("Gita", "07", 'p', 3.75);
    insertLast(L, P1);

    x.nim = "07";
    P1 = findElm(L, x);
    P2 = createData("Cindi", "03", 'p', 3.5);
    insertAfter(L, P1, P2);

    x.nim = "02";
    P1 = findElm(L, x);
    P2 = createData("Hilmi", "08", 'p', 3.3);
    insertAfter(L, P1, P2);

    x.nim = "04";
    P1 = findElm(L, x);
    P2 = createData("Eli", "05", 'p', 3.4);
    insertAfter(L, P1, P2);

    printInfo(L);
    return 0;
}

```
#### Full code Screenshot:
<img width="1919" height="1137" alt="Screenshot 2025-12-09 192832" src="https://github.com/user-attachments/assets/494514d0-b6a9-4567-891f-50642d375341" />


## Pengerjaan Latihan Modul 12 - Multi Linked List

### Latihan 2.
<img width="576" height="40" alt="Screenshot 2025-12-09 192113" src="https://github.com/user-attachments/assets/8ab1905d-2c2a-4374-9884-48d54c602d35" />

#### Output latihan 2:
<img width="1285" height="494" alt="Screenshot 2025-12-09 193259" src="https://github.com/user-attachments/assets/489ba5d4-5f25-48fb-b8f7-38d6be10f538" />

### Latihan 3
<img width="572" height="470" alt="Screenshot 2025-12-09 192122" src="https://github.com/user-attachments/assets/6330bc06-3983-4e9a-98ef-2601de2abd53" />
<img width="596" height="868" alt="Screenshot 2025-12-09 192145" src="https://github.com/user-attachments/assets/0bedb09b-c44c-4759-ac4e-99ee1d128b8d" />
<img width="595" height="388" alt="Screenshot 2025-12-09 192153" src="https://github.com/user-attachments/assets/e9d0d9d5-dad2-4346-a3a4-99e1d23e8579" />

#### Output latihan 3:
<img width="1368" height="924" alt="Screenshot 2025-12-09 193325" src="https://github.com/user-attachments/assets/4f761847-91e7-431b-838d-2f9bfd3964ea" />


<br>
<br>
Kedua latihan ini sama-sama membahas cara mengelola data menggunakan struktur linked list, tetapi dengan bentuk yang berbeda. Latihan 2 memakai multilist yang memiliki hubungan induk–anak, sedangkan latihan 3 memakai circular doubly linked list yang menyambungkan node secara melingkar. Tujuan keduanya adalah melatih penggunaan pointer dan cara memasukkan, menghapus, serta menelusuri data.

1. Pada latihan 2 ini, program membangun sebuah multilist, di mana setiap induk bisa memiliki beberapa anak. Program mulai dengan membuat list induk, lalu menambahkan beberapa induk dan mengisi masing-masing dengan anak
   menggunakan fungsi insert. Program juga mencoba menghapus anak tertentu dan menghapus induk beserta seluruh anaknya. Hasil akhirnya ditampilkan sehingga terlihat hubungan antar induk dan anak. Latihan ini membantu
   memahami cara menangani struktur data bertingkat.
   
2. Latihan 3 membuat Circular Doubly Linked List untuk menyimpan data mahasiswa. Node saling terhubung dua arah dan membentuk lingkaran. Program menambahkan beberapa data menggunakan insert di awal, di akhir, dan
   setelah elemen tertentu. Setelah itu, isi list ditampilkan dengan melakukan traversal melingkar dari node pertama. Latihan ini menekankan bagaimana bekerja dengan list yang lebih fleksibel dan dapat ditelusuri ke dua
   arah.

## Kesimpulan
Pada materi ini, kita belajar dua jenis linked list lanjutan. Multilist mengajarkan cara membuat hubungan induk–anak dan mengelola penyisipan serta penghapusan datanya. Circular doubly linked list menunjukkan cara bekerja dengan list yang melingkar dan dapat ditelusuri dua arah. Keduanya menekankan pentingnya pengaturan pointer agar struktur tetap konsisten.

## Referensi
[1]Word Search Puzzle using Multi-Linked Lists Oleh Shivam Hareshkumar Patel &sup1;, A. Jackulin Mahariba &sup2;. diakses pada tanggal 09 Desember 2025 melalui: <br>
https://www.ijeat.org/wp-content/uploads/papers/v8i4s2/D10050484S219.pdf

[2]A New Vista of Performing Insertion and Deletion in Linked Lists Arijeet Banerjee &sup1;, Pijush Kanti Kumar &sup2;. diakses pada tanggal 09 Desember 2025 melalui: <br>
https://ijcsmc.com/docs/papers/July2022/V11I7202208.pdf





















