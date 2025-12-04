# <h1 align="center">Laporan Praktikum Modul 10 - Tree(Bagian Pertama)</h1>
<p align="center">Rafhael Januar Turnip - 103112400209</p>

## Dasar Teori
Tree merupakan struktur data non-linier yang tersusun atas node dan edge, di mana satu node berperan sebagai root dan node lainnya membentuk hubungan parent–child.[1]<br>
Berdasarkan definisi tersebut, Struktur tree terdiri dari satu node akar sebagai titik awal, diikuti node-node anak yang membentuk level atau kedalaman tertentu. Setiap bagian tree dapat dipandang sebagai subtree 
yang saling terhubung. Dengan bentuk bertingkat seperti ini, tree cocok untuk mewakili data yang memiliki hierarki. Operasi penelusuran seperti preorder, inorder, dan postorder dapat dilakukan sesuai kebutuhan. 
Selain itu, tree tidak memiliki siklus, sehingga setiap jalur dari root ke node mana pun selalu unik dan mudah diikuti.

Operasi utama dalam queue terdiri dari dua, yaitu:

1. Search<br> 
Proses pencarian pada binary search tree adalah pertama bandingkan terlebih dahulu kunci data yang ingin dicari dengan kunci di akar; jika tidak cocok maka carilah ke subpohon sebelah kiri atau kanan sampai
kunci data yang ingin dicari cocok.[1]<br>
Jadi pencarian dimulai dari root. Jika nilai target sama dengan nilai di root → ketemu. Jika lebih kecil → lanjut ke subtree kiri; jika lebih besar → ke subtree kanan. Proses berlanjut sampai node ditemukan
atau mencapai leaf/bawah pohon (nilai tidak ada).

2. Insert<br>
Proses penambahan (insert) simpul ke dalam pohon adalah proses penempatan atau penempelan simpul baru menjadi subordinat sebuah simpul baik pada simpul kiri atau kanan.[1]<br>
maka saat menambahkan data baru, BST mencari posisi yang sesuai dengan membandingkan dari root ke bawah: jika nilai baru lebih kecil → ke kiri, jika lebih besar → ke kanan — hingga menemukan tempat kosong (leaf),
lalu node baru ditempelkan di situ. Ini menjaga agar aturan BST tetap terpenuhi (semua di kiri ≤ root < semua di kanan).

3. Delete<br>
Pada Binary Search Tree terdapat … operasi dasar … yaitu … penghapusan (delete).[1]<br>
Jika ingin menghapus node, prosedur delete memastikan tree tetap terstruktur dengan benar. Tergantung kasus: jika node adalah daun (leaf) → cukup dihapus; jika punya anak → anak atau subtree menggantikan posisi node;
jika node punya dua anak → biasanya diganti dengan node pengganti (misalnya successor/predecessor), lalu penghapusan dilakukan pada node pengganti agar properti BST tetap terjaga.

4. Most Left
node paling kiri (minimum) mulai dari root dan ikuti pointer left berulang kali sampai left bernilai NULL — node itu adalah nilai minimum. Untuk operasi penghapusan minimum, node tersebut dapat dihapus langsung
(atau digantikan oleh subtree kanan jika ada).[2]<br>

6. Most Right
node paling kanan (maximum) mulai dari root dan ikuti pointer right sampai right bernilai NULL — itu adalah nilai maksimum. Penghapusan maksimum mirip: node tersebut dapat dihapus langsung
(atau digantikan oleh subtree kiri jika ada).[2]<br>

6. Pre-Order
Metode traversal yang dimulai dengan mencetak node saat ini terlebih dahulu, kemudian dilanjutkan dengan mengunjungi node kiri dan akhirnya node kanan.[3]<br>

7. In-Order
Traversal yang dilakukan dengan mengunjungi node kiri terlebih dahulu, lalu mencetak node saat ini, dan terakhir mengunjungi node kanan.[3]<br>

8. Post-Order
Pada traversal ini, proses dimulai dengan mengunjungi node kiri, kemudian node kanan, dan setelah itu barulah mencetak node yang sedang dikunjungi.[3]<br>


## Guided 

### 1. [Guided1]

### a. [Header File]
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node; //alias pointer = node

struct BST{ //nama struct BST
    int angka;
    node left;
    node right;
};

typedef node BinTree; //alias tree = BinTree (merujuk ke node root dari BST)

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```

### b. [Source File]

```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```

### c. [Main Program]

```C++
#include <iostream>
#include "bst.h"
#include "bst.cpp"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```

Dalam program guided ini digunakan untuk membangun struktur Binary Search Tree (BST) melalui beberapa pilihan menu yang tersedia pada main.cpp. Di dalamnya terdapat opsi insert node untuk menambahkan data ke dalam tree, 
delete node untuk menghapus elemen tertentu, serta search tree untuk mengecek apakah suatu nilai ada di dalam tree. Selain itu, program juga mampu menampilkan isi tree menggunakan traversal preorder, inorder, 
dan postorder, menghitung jumlah simpul melalui fitur size tree, menentukan tinggi tree dengan height tree, menampilkan nilai paling kiri (most left) dan paling kanan (most right), serta menyediakan menu untuk 
menghapus seluruh isi tree sekaligus.

## Unguided 

### [Tree]

### a. [Header File]
```C++
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
```
#### Full code Screenshot:
<img width="1917" height="1137" alt="Screenshot 2025-12-04 121501" src="https://github.com/user-attachments/assets/d460d8e6-489e-4f98-9cd4-91bab92c5bc2" />

### b. [Source File]

```C++
#include "bstree.h"

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        } else {
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    }
    if (root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

void printPreOrder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(address root) {
    if (root != Nil) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " - ";
    }
}

int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root, int start) {
    if (root == Nil) {
        return 0; 
    }
    return root->info + hitungTotalInfo(root->left, 0) + hitungTotalInfo(root->right, 0);
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start;
    }
    return max(hitungKedalaman(root->left, start + 1), hitungKedalaman(root->right, start + 1));
}
```
#### Full code Screenshot:
<img width="1919" height="1139" alt="Screenshot 2025-12-04 121527" src="https://github.com/user-attachments/assets/b4f6d91b-0571-4add-8ddf-f36b9d632f23" />


### 3. [Main File]
### a. [Main File - Latihan 1-2]
```C++
#include <iostream>
#include "bstree.h"
#include "bstree.cpp"

using namespace std;

int main() {
    //soal1
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    printInorder(root);
    
    cout << "\n";
    //soal2
    cout << "Kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "Jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "Total : " << hitungTotalInfo(root, 0) << endl;

    return 0;
}
```
#### Full code Screenshot:
<img width="1919" height="1140" alt="Screenshot 2025-12-04 120447" src="https://github.com/user-attachments/assets/8278f383-e318-44fe-b153-c8d7e3d4f43f" />


### b. [Main File - Latihan 3]

```C++
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
    
    cout << "" << endl;
    cout << "PreOrder Traversal: " << endl;
    printPreOrder(root);
    cout << "\n";
    cout << "PostOrder Traversal: " << endl;
    printPostOrder(root);
    cout << "\n";

    return 0;
}
```
#### Full code Screenshot:
<img width="1919" height="1130" alt="Screenshot 2025-12-04 120500" src="https://github.com/user-attachments/assets/71fa59b5-1ec2-4721-8c00-f66e4c8f4943" />

## Pengerjaan Latihan Modul 10 - Tree(Bagian Pertama)

### 1.
<img width="601" height="666" alt="Screenshot 2025-12-04 120517" src="https://github.com/user-attachments/assets/c213a240-e0f3-4931-865a-aad2804317f1" />

#### Output latihan 1:
<img width="258" height="41" alt="Screenshot 2025-12-04 121831" src="https://github.com/user-attachments/assets/4380bb8d-6d4e-43fb-a415-651c7019c2a5" />


### 2. 
<img width="607" height="766" alt="Screenshot 2025-12-04 120535" src="https://github.com/user-attachments/assets/d322d731-0f08-4ae4-87f9-bd4ca6b0611c" />

#### Output latihan 2:
<img width="280" height="107" alt="Screenshot 2025-12-04 121841" src="https://github.com/user-attachments/assets/0c000fb5-031a-47e1-a6cd-b69037f74ea6" />


### 3.
<img width="610" height="284" alt="Screenshot 2025-12-04 120543" src="https://github.com/user-attachments/assets/21af2f83-164c-4cd1-9ae3-f151c52fef9f" />

#### Output latihan 3:
<img width="252" height="109" alt="Screenshot 2025-12-04 121943" src="https://github.com/user-attachments/assets/bd3da1a0-1e3a-48a1-a273-789a1a26b36f" />



<br>
<br>
Program ini berfungsi untuk membuat tree secara BST dengan menggunakan alokasi dan insert sebagai penambahan data/node, dan meng-output kan inputan tadi secara inOrder(yaitu mengunjungi subtree kiri, 
lalu mencetak nilai dari node saat ini, dan mengunjungi subtree kanan).<br>
Uraian berikut menjelaskan rangkaian tugas pada masing-masing bagian unguided:<br>

1. Program ini membuat sebuah Binary Search Tree (BST) dengan memasukkan data menggunakan fungsi insertNode. Setelah seluruh angka dimasukkan ke dalam tree, program menampilkannya menggunakan InOrder.
   Karena InOrder membaca subtree kiri–root–subtree kanan, hasilnya akan muncul dalam urutan yang sudah terurut otomatis.

2. Pada bagian ini, program tetap membangun BST yang sama, tetapi fokusnya bukan hanya menampilkan InOrder. Program juga menghitung berapa banyak node di dalam tree, menjumlahkan seluruh nilai node,
   dan mencari kedalaman tree. Kedalaman di sini menggambarkan seberapa jauh suatu struktur tree dari root ke bagian paling bawah.

3. Untuk latihan ketiga, tree dibuat menggunakan urutan input yang berbeda sehingga bentuknya lebih seimbang. Program kemudian menampilkan isi tree menggunakan dua cara traversal: PreOrder, yang membaca root dulu
   baru ke kiri dan kanan; dan PostOrder, yang membaca kiri dan kanan lebih dulu lalu mencetak root di akhir. Kedua cara ini menghasilkan urutan output yang berbeda sesuai pola penelusurannya.

## Kesimpulan
Pada materi tree kali ini, kita belajar beberapa fungsi penting, mulai dari cara memasukkan data dengan alokasi dan insertNode, sampai menghitung jumlah node lewat fungsi hitungJumlahNode dan hitungTotalInfo. 
Kita juga membahas cara menghitung kedalaman tree menggunakan hitungKedalaman. Walaupun kedalaman dan ketinggian sering terdengar mirip kalau dibayangkan secara konsep, cara kerjanya di tree ternyata berbeda. 
Karena itu, menghitung keduanya dilakukan dengan dua fungsi yang memang punya tugas masing-masing.

## Referensi
[1]PENERAPAN ALGORITHMA POHON UNTUK OPERASI PENGOLAHANDAN PENYIMPANAN DATA DALAM TEKNIK PEMROGRAMAN  Oleh Fitri Latifah &sup1;. diakses pada tanggal 04 Desember 2025 melalui: <br>
https://media.neliti.com/media/publications/227384-penerapan-algorithma-pohon-untuk-operasi-cfabe76a.pdf

[2]Randomized Binary Search Trees Oleh Conrado Mart´InezZ&sup1;, Salvado Roura&sup2;. diakses pada tanggal 04 Desember 2025 melalui: <br>
https://www.cs.upc.edu/~conrado/research/papers/jacm-mr98.pdf?

[3]Find maximum (or minimum) in Binary Tree Oleh kartik&sup2;. diakses pada tanggal 04 Desember 2025 melalui: <br>
https://www.geeksforgeeks.org/dsa/find-maximum-or-minimum-in-binary-tree/





















