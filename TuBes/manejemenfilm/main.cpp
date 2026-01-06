#include <iostream>
#include "film.h"
#include "film.cpp"
using namespace std;

int main() {
    Node *root = NULL;

    insertDummyData(root);

    int pilihan;
    string judul, aktor;

    do {
        cout << "\n===== MENU MANAJEMEN FILM =====";
        cout << "\n1. Tampilkan Semua Film (Inorder)";
        cout << "\n2. Tambah Film";
        cout << "\n3. Edit Data Film";
        cout << "\n4. Cari Film";
        cout << "\n5. Hitung Total Film";
        cout << "\n6. Film Terlama & Tercepat";
        cout << "\n7. Preorder";
        cout << "\n8. Postorder";
        cout << "\n9. Hapus Film";
        cout << "\n0. Keluar";
        cout << "\nPilih: ";
        cin >> pilihan;
        cin.ignore();

        Film f;

        switch (pilihan) {
        case 1:
            cout << "\nMenampilkan data film dalam database (Inorder):\n";
            inorder(root);
            break;

        case 2:
            cout << "\nMasukkan detail film yang ingin dimasukan kedalam database\n";
            cout << "Judul Film: ";
            getline(cin, f.judul);
            cout << "Tahun Rilis: ";
            cin >> f.tahun;
            cin.ignore();
            cout << "Genre: ";
            getline(cin, f.genre);
            cout << "Durasi: ";
            cin >> f.durasi;
            f.jumlahAktor = 0;
            root = insertFilm(root, f);
            cout << "Film \"" << f.judul << "\" berhasil ditambahkan!\n";

            break;

        case 3:
            cout << "Masukan Judul Film yang ingin dikelola/diedit: ";
            getline(cin, judul);
            {
                Node* target = searchFilm(root, judul);
                if (target != NULL) {
                    editFilm(target);
                } else {
                    cout << "Film dengan judul \"" << judul << "\" tidak ditemukan.\n";
                }
            }
            break;

        case 4:
            cout << "\nMasukkan judul film yang ingin dicari\n";
            cout << "Judul film: ";
            getline(cin, judul);
            if (searchFilm(root, judul))
                cout << "Film ada dalam database\n";
            else
                cout << "Film tidak ada dalam database\n";
            break;

        case 5:
            cout << "Total film yang ada dalam database: " << countFilm(root) << endl;
            break;

        case 6: {
            Node *minFilm = NULL, *maxFilm = NULL;
            cariDurasi(root, minFilm, maxFilm);

            if (minFilm != NULL && maxFilm != NULL) {
                int minjam = minFilm->data.durasi / 60;
                int minSisa = minFilm->data.durasi % 60;

                int maxjam = maxFilm->data.durasi / 60;
                int maxSisa = maxFilm->data.durasi % 60;

                cout << "\nMenampilkan film dengan durasi tercepat dan terlama\n";
                cout << "Film dengan durasi tercepat: " << minFilm->data.judul << " (" << minjam << " jam " << minSisa << " menit)" << endl; 
                cout << "Film dengan durasi terlama : " << maxFilm->data.judul << " (" << maxjam << " jam " << maxSisa << " menit)" << endl;
            
            } else {
                cout << "Tidak ada film dalam database.\n";
            }    
            break;
        }

        case 7:
            cout << "Menampilkan data film berdasarkan Preorder Traversal: " << endl; 
            preorder(root);
            cout << endl;
            break;

        case 8:
            cout << "Menampilkan data film berdasarkan Postorder Traversal: " <<endl;
            postorder(root);
            cout << endl;
            break;

        case 9:
            cout << "\nMasukkan judul film yang ingin dihapus\n";
            cout << "Judul film: ";
            getline(cin, judul);
            if (searchFilm(root, judul)) {
                root = deleteFilm(root, judul);
                cout << "Film \"" << judul << "\" berhasil dihapus dari database\n";
            } else {
                cout << "Film yang ingin dihapus tidak ditemukan";
            }
            break;

        case 0:
            cout << "Program Berakhir" << endl;
        break;
        }
    } while (pilihan != 0);
    return 0;
}