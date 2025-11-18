# <h1 align="center">Laporan Praktikum Modul 6 - Stack (ADT)</h1>
<p align="center">Rafhael Januar Turnip - 103112400209</p>

## Dasar Teori
Stack adalah struktur data linier yang bekerja dengan prinsip LIFO (Last In, First Out), di mana elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan. 
Struktur ini dapat diimplementasikan menggunakan array maupun linked list, dengan pemilihan metode bergantung pada kebutuhan fleksibilitas dan efisiensi memori dalam pengembangan aplikasi[1].<br>

Stack menyediakan dua operasi inti:

1. Push<br>
Menambahkan elemen baru ke posisi paling atas dari stack. Operasi ini hanya bisa dilakukan jika stack belum mencapai kapasitas maksimum. Jika penuh, terjadi kondisi stack overflow[1].<br>

2. Pop<br>
Mengambil dan menghapus elemen paling atas dari stack. Operasi hanya dapat dilakukan jika stack berisi data. Jika kosong, muncul kondisi stack underflow[1].<br>

Kedua operasi ini bekerja mengikuti prinsip LIFO (Last In, First Out), sehingga elemen terakhir yang masuk adalah elemen pertama yang keluar. 
Struktur dan perilaku push/pop menjadikan stack efektif digunakan pada berbagai proses seperti navigasi aplikasi, undo–redo, hingga pemrosesan ekspresi.<br>

## Guided 

### 1. [Guided1]

### a. [Header File]
```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

### b. [Source File]

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

### c. [Main Program]

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

Program ini berfungsi untuk membuat stack dengan menggunakan single linked list agar penyimpanan data dapat dilakukan secara dinamis dengan menggunakan beberapa fungsi 
yaitu pop sebagai menghapus node yang paling atas dan push sebagai membuat node baru dan menaruhnya di paling atas. Program ini juga dapat mengupdate/mengubah nilai di 
posisi tertentu dan menampilkan isi stack dari atas ke bawah serta mencari apakah data tersebut ada di dalam stack atau tidak.


### 2. [Guided 2]

### a. [Header File]
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

//ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong

};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```

### b. [Source File]

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s) {
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX -1;
}

void createStack(stackTable &s) {
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack Penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " Berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    //index = top - (posisi -1)
    int idx = s.top - (posisi -1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " Tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka: ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
        return;
    }
    cout << "Mencari data" << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}
```

### c. [Main Program]

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    //Posisi dihitung dari TOP(1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```
Program ini berfungsi untuk membuat stack dengan menggunakan fungsi array dengan menginisiasi nilai max yaitu sebanyak 10 data pada array dan posisi atas pada stack diperiksa oleh top dan 
jika top == -1 maka stack tersebut kosong. Berbeda dengan stack linked list, pada pengecekan kondisi stack pada array dilakukan dengan menngunakan 2 fungsi yaitu isEmpty dan isFull. 
fungsi selanjutnya yaitu pop untuk menambah data di paling atas dan pop untuk menghapus data yang berada di posisi paling atas. Lalu program ini juga dapat mengubah data pada posisi tertentu 
dan mencari data tertentu pada stack dan menampilkan isi stack dari atas ke bawah.

## Unguided 

### [Stack]

### a. [Header File / stack.h]
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#define MAX 20

typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
int pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
```
#### Full code Screenshot:
<img width="1919" height="1140" alt="Screenshot 2025-11-18 111833" src="https://github.com/user-attachments/assets/e89af71c-a50f-4e71-90e4-f5fb56d69554" />


### b. [Source File / stack.cpp]

```C++
#include "stack.h"

void createStack(Stack &S) {
    S.top = 0;
}

bool isEmpty(Stack S) {
    return S.top == 0;
}

bool isFull(Stack S) {
    return S.top == MAX;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh" << endl;
    }
}

int pop(Stack &S) {
    if (!isEmpty(S)) {
        int x = S.info[S.top];
        S.top--;
        return x;
    }
    return 0;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    if (isEmpty(S)) {
        cout << "Kosong";
    } else {
        for (int i = S.top; i >= 1; i--) {
            cout << S.info[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    for (int i = 1; i <= S.top / 2; i++) {
        int t = S.info[i];
        S.info[i] = S.info[S.top - i + 1];
        S.info[S.top - i + 1] = t;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (isEmpty(S) || x >= S.info[S.top]) {
        push(S, x);
    } else {
        int t = pop(S);
        pushAscending(S, x);
        push(S, t);
    }
}

void getInputStream(Stack &S) {
    char c;
    while (cin.get(c) && c != '\n') {
        if (c >= '0' && c <= '9') {
            int n = c - '0';
            push(S, n);
        }
    }
}
```
#### Full code Screenshot:
<img width="1919" height="1138" alt="Screenshot 2025-11-18 111911" src="https://github.com/user-attachments/assets/4d0a3a42-d521-48ad-a98b-569cafd2dd1d" />


### c. [Main Program / main.cpp]

```C++
#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack S;

    // latihan 1
    cout << "Hello world!" << endl;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout << endl;

    // latihan 2
    cout << "Hello world!" << endl;
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout << endl;

    // latihan 3
    cout << "Hello world!" << endl;
    createStack(S);
    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
#### Full code Screenshot:
<img width="1919" height="1139" alt="Screenshot 2025-11-18 111925" src="https://github.com/user-attachments/assets/471a9b24-b0a3-49db-965a-39930df8736f" />

## Pengerjaan Latihan Modul 7 - Stack

### 1.
<img width="677" height="670" alt="Screenshot 2025-11-18 110727" src="https://github.com/user-attachments/assets/813a1b72-5efd-49b8-af6a-e35cedb2c298" />

#### Output latihan 1:
<img width="745" height="135" alt="Screenshot 2025-11-18 112310" src="https://github.com/user-attachments/assets/34eb35c2-111c-4a7f-ab32-0973763a86f9" />

### 2. 
<img width="682" height="607" alt="Screenshot 2025-11-18 110742" src="https://github.com/user-attachments/assets/dd106319-c7c2-4081-8993-5db7ce849834" />

#### Output latihan 2:
<img width="748" height="94" alt="Screenshot 2025-11-18 112319" src="https://github.com/user-attachments/assets/e638b8ae-5fcf-4272-85af-f90dc1a282cf" />

### 3.
<img width="694" height="323" alt="Screenshot 2025-11-18 110748" src="https://github.com/user-attachments/assets/31316a1c-b43d-4b02-bbb2-ee0de656b609" />

#### Output latihan 3:
<img width="756" height="130" alt="Screenshot 2025-11-18 112330" src="https://github.com/user-attachments/assets/07fbaf2c-8d24-433d-8760-9248de38ce8e" />

<br>
<br>
Program ini mengimplementasikan struktur data Stack dengan media array dan memperlihatkan tiga cara pengolahan data dalam satu rangkaian percobaan.<br>

1. Pada bagian pertama, program menjalankan operasi dasar stack dengan prinsip LIFO. Data dimasukkan menggunakan push dan diambil dengan pop, sehingga terlihat bagaimana elemen yang terakhir masuk menjadi yang pertama keluar. Beberapa nilai juga dihapus untuk menunjukkan perubahan susunan elemen pada stack.

2. Di bagian berikutnya, program menggunakan pushAscending. Berbeda dari push biasa, fungsi ini tidak hanya menambah data, tetapi juga memastikan posisi data tetap terurut dari nilai kecil ke besar. Dengan demikian, isi stack selalu tersusun otomatis tanpa perlu pengurutan tambahan.

3. Percobaan terakhir memakai fungsi getInputStream, di mana program menerima input angka dari pengguna secara langsung. Setiap karakter angka yang diketik akan langsung dimasukkan ke stack sampai pengguna menekan Enter. Cara ini membuat proses pengisian lebih fleksibel tanpa harus memanggil push berkali-kali secara manual.

Di akhir setiap skenario di atas, program selalu menampilkan status terkini stack menggunakan fungsi printInfo , kemudian membalik urutan seluruh elemen stack menggunakan fungsi balikStack, dan menampilkan kembali hasil pembalikan tersebut untuk memperlihatkan urutan data yang berlawanan.<br>

## Kesimpulan
Pada praktikum kali ini, kita diberikan beberapa fungsi tambahan pada stack yaitu pushAscending yaitu bukan hanya sekedar menginput dan menaruh data di dalam stack, 
tetapi juga mengurutkannya dengan secara ascending yaitu dari terbesar [top] hingga terkecil. Setelah itu kita juga dapat menginput data secara manual dengan menggunakan fungsi 
getStreamInput selama data masih dibawah nilai MAX (pada fungsi ini nilai MAX yaitu 20). Program ini juga dapat membalik isi pada stack dengan fungsi balikStack. Output pada program ini 
akan ditampilkan dengan fungsi printInfo.

## Referensi
[1] Application of Stack Data Structure oleh: S. Amaylia dkk. Diakses pada 18 November 2025 melalui: <br>
file:///D:/Main%20Storage/Download/Documents/Application+of+Stack+Data+Structure+in+Application+Development.pdf <br>





















