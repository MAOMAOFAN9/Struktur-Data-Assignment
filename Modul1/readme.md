# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Arvinanto Bahtiar</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

1. Perulagan
Perulangan digunakan untuk menyederhanakan program dengan menjalankan bagian yang sama secara berulang. Dan diperlukan intruksi penghenti agar proses bisa berhenti.
dan terdapat beberapa perulangan seperti (for, while, do-while).<br>
untuk for, normal digunakan untuk perulangan yang tahu ingin mengulang berapa kali.<br>
jika while, digunakan untuk hasil yang tidak pasti, bisa lebih dari 2 _output_. dan ada syarat tertentu sebagai _trigger_ untuk mendapat hasil tertentu.<br>
sedangkan untuk do-while sama seperti while, tapi program akan menjalankannya setidaknya sekali walaupun syarat yang diminta salah.

2. Struktur
struktur bisa digunakan untuk mengelompokan variabel dan tipe data.<br>
struktur juga bisa diisi dengan array.<br>
struktur juga bisa menyimpan struktur lain yang menyimpan variabel dan tipe data.<br>

## Guided 

### 1. [Contoh Latihan]

```C++
#include <iostream>
using namespace std;

int main () {
    int a;
    int b;
    
    cout << "Masukan angka1: ";
    cin >> a;
    cout << "Masukan angka2: ";
    cin >> b;

    //operator aritmatika
    cout << "a + b = " << (a+b) << endl;
    cout << "a - b = " << (a-b) << endl;
    cout << "a * b = " << (a*b) << endl;
    cout << "a % b = " << (a%b) << endl;

    //Operator logika
    cout << "a > b = " << (a>b) << endl;
    cout << "a < b = " << (a<b) << endl;
    cout << "a >= b = " << (a>=b) << endl;
    cout << "a <= b = " << (a<=b) << endl;
    cout << "a == b = " << (a==b) << endl;
    cout << "a != b = " << (a!=b) << endl;
    return 0;
}
```
Kode di atas digunakan untuk menerima dua input angka dari pengguna, lalu menampilkan hasil operasi aritmatika dan logika menggunakan function cout untuk mengeksekusinya.

## Unguided 

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main () {
    float a;
    float b;
    
    cout << "Masukan 1: ";
    cin >> a;
    cout << "Masukan 2: ";
    cin >> b;

    cout << "a + b = " << (a+b) << endl;
    cout << "a - b = " << (a-b) << endl;
    cout << "a * b = " << (a*b) << endl;
    cout << "a / b = " << (a/b) << endl;
    return 0;
}
```
#### Output:
<img width="1102" height="180" alt="Image" src="https://github.com/user-attachments/assets/b696477b-896f-441c-a56a-f234e5b59552" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1917" height="1130" alt="image" src="https://github.com/user-attachments/assets/123e5b84-a175-4e64-8b75-3581f99e633f" />

### 2. [Soal 2]

```C++
#include <iostream>
using namespace std;

int main () {

```

### 3. [Soal 3]

```C++
#include <iostream>
using namespace std;

int main () {

```


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
