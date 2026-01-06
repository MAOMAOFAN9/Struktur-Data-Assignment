#include "film.h"
#include <iostream>
using namespace std;

Node* createNode(Film f) {
    Node *newNode = new Node;
    newNode->data = f;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->firstChild = NULL;
    return newNode;
}

Node* insertFilm(Node *root, Film f) {
    if (root == NULL) 
        return createNode(f);

    if (f.judul < root->data.judul)
        root->left = insertFilm(root->left, f);
    else if (f.judul > root->data.judul)
        root->right = insertFilm(root->right, f);
    else
        cout << "Film sudah terdaftar!\n";

    return root;
}

Node* searchFilm(Node *root, string judul) {
    if (root == NULL || root->data.judul == judul)
        return root;

    if (judul < root->data.judul)
        return searchFilm(root->left, judul);

    return searchFilm(root->right, judul);
}

void tambahAktor(Node *filmNode, string namaAktor) {
    if (filmNode == NULL) return;

    Child *newChild = new Child;
    newChild->namaAktor = namaAktor;
    newChild->next = NULL;

    if (filmNode->firstChild == NULL) {
        filmNode->firstChild = newChild;
    } else {
        Child *temp = filmNode->firstChild;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newChild;
    }
}

void hapusAktor(Node *filmNode, string namaAktor) {
    if (filmNode == NULL || filmNode->firstChild == NULL) return;

    Child *temp = filmNode->firstChild;
    Child *prev = NULL;
    
    if (temp != NULL && temp->namaAktor == namaAktor) {
        filmNode->firstChild = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->namaAktor != namaAktor) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    delete temp;
}

void editFilm(Node* filmNode) {
    if (filmNode == NULL) return;

    int subPilihan;
    do {
        cout << "\nMenu Edit Detail Film: " << filmNode->data.judul << " ---";
        cout << "\n1. Ubah Tahun Terbit (Sekarang: " << filmNode->data.tahun << ")";
        cout << "\n2. Ubah Genre (Sekarang: " << filmNode->data.genre << ")";
        cout << "\n3. Ubah Durasi (Sekarang: " << filmNode->data.durasi << " menit)";
        cout << "\n4. Tambah Aktor/Aktris";
        cout << "\n5. Hapus Aktor/Aktris";
        cout << "\n0. Selesai & Kembali ke Menu Utama";
        cout << "\nPilih: ";
        cin >> subPilihan;
        cin.ignore();

        switch (subPilihan) {
            case 1:
                cout << "Masukkan Tahun Baru: ";
                cin >> filmNode->data.tahun;
                cin.ignore();
                cout << "Tahun berhasil diperbarui!\n";
                cout << endl;
                break;
            case 2:
                cout << "Masukkan Genre Baru: ";
                getline(cin, filmNode->data.genre);
                cout << "Genre berhasil diperbarui!\n";
                cout << endl;
                break;
            case 3:
                cout << "Masukkan Durasi Baru (menit): ";
                cin >> filmNode->data.durasi;
                cin.ignore();
                cout << "Durasi berhasil diperbarui!\n";
                cout << endl;
                break;
            case 4: {
                int jml;
                cout << "Berapa banyak aktor yang ingin ditambahkan? ";
                cin >> jml;
                cin.ignore();
                for (int i = 1; i <= jml; i++) {
                    string namaAktor;
                    cout << "Nama Aktor ke-" << i << ": ";
                    getline(cin, namaAktor);
                    tambahAktor(filmNode, namaAktor);
                }
                cout << "Aktor berhasil ditambahkan ke dalam film";
                cout << endl;
                break;
            }
            case 5: {
                cout << "Aktor/Aktris dalam film:" << endl;
                Child* current = filmNode->firstChild;
                if (current == NULL) {
                    cout << " Tidak ada aktor/aktris yang terdaftar.\n";
                } else {
                    while (current != NULL) {
                        cout << " - " << current->namaAktor << endl;
                        current = current->next;
                    }
                cout << "Masukkan nama aktor/aktris yang ingin dihapus: ";
                string namaAktor;
                getline(cin, namaAktor);
                hapusAktor(filmNode, namaAktor);
                cout << endl;
            }
                break;
            }
            case 0:
                break;
            default:
                cout << "Pilihan tidak tersedia.\n";
        }
    } while (subPilihan != 0);
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);

        int jam = root->data.durasi / 60;
        int sisaMenit = root->data.durasi % 60; 

        cout << "\nJudul        : " << root->data.judul;
        cout << "\nTahun        : " << root->data.tahun;
        cout << "\nGenre        : " << root->data.genre;
        cout << "\nDurasi       : " << root->data.durasi << " menit (" << jam << " jam " << sisaMenit << " menit)";
        cout << "\nAktor/Aktris : ";

        Child *c = root->firstChild;
        if (c == NULL) {
            cout << "-";
        } else {
            while (c != NULL) {
                cout << c->namaAktor;
                
                if (c ->next != NULL) {
                    cout << ", ";
                }
                c = c->next;
            }
        }
        while (c != NULL) {
            cout << c->namaAktor << ", ";
            c = c->next;
        }
        cout << "\n----------------------------";

        inorder(root->right);
    }
}

void preorder(Node *root) {
    if (root != NULL) {
        cout << root->data.judul << " | ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data.judul << " | ";
    }
}

int countFilm(Node *root) {
    if (root == NULL)
        return 0;
    return 1 + countFilm(root->left) + countFilm(root->right);
}

void cariDurasi(Node *root, Node* &minFilm, Node* &maxFilm) {
    if (root != NULL) {
        if (minFilm == NULL || root->data.durasi < minFilm->data.durasi)
            minFilm = root;
        if (maxFilm == NULL || root->data.durasi > maxFilm->data.durasi)
            maxFilm = root;

        cariDurasi(root->left, minFilm, maxFilm);
        cariDurasi(root->right, minFilm, maxFilm);
    }
}

Node* findMin(Node *root) {
    while (root->left != NULL) root = root->left;
    return root;
}

Node* deleteFilm(Node *root, string judul) {
    if (root == NULL) return root;

    if (judul < root->data.judul) {
        root->left = deleteFilm(root->left, judul);
    } else if (judul > root->data.judul) {
        root->right = deleteFilm(root->right, judul);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteFilm(root->right, temp->data.judul);
    }
    return root;
}

void insertDummyData(Node* &root) {
    Film f;

    f = {"Inception", 2010, "Sci-Fi", 148, {}, 0};
    root = insertFilm(root, f);
    tambahAktor(searchFilm(root, f.judul), "Leonardo DiCaprio");
    tambahAktor(searchFilm(root, f.judul), "Joseph Gordon-Levitt");

    f = {"Interstellar", 2014, "Sci-Fi", 169, {}, 0};
    root = insertFilm(root, f);
    tambahAktor(searchFilm(root, f.judul), "Matthew McConaughey");
    tambahAktor(searchFilm(root, f.judul), "Anne Hathaway");

    f = {"The Dark Knight", 2008, "Action", 152, {}, 0};
    root = insertFilm(root, f);
    tambahAktor(searchFilm(root, f.judul), "Christian Bale");
    tambahAktor(searchFilm(root, f.judul), "Heath Ledger");

    f = {"Forrest Gump", 1994, "Drama", 142, {}, 0};
    root = insertFilm(root, f);
    tambahAktor(searchFilm(root, f.judul), "Tom Hanks");

    f = {"Parasite", 2019, "Thriller", 132, {}, 0};
    root = insertFilm(root, f);
    tambahAktor(searchFilm(root, f.judul), "Song Kang-ho");

    f = {"Avengers Endgame", 2019, "Action", 181, {}, 0};
    root = insertFilm(root, f);
    tambahAktor(searchFilm(root, f.judul), "Robert Downey Jr.");
    tambahAktor(searchFilm(root, f.judul), "Chris Evans");
}
