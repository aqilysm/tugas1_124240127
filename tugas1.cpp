#include <iostream>
#include <string>
using namespace std;

struct Lagu {
    string judul;
    string penyanyi;
    string genre;
    int tahun;
};

Lagu arraySong[500];
int count = 0;

void bubleSort() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arraySong[j].judul > arraySong[j + 1].judul) {
                swap(arraySong[j], arraySong[j + 1]);
            }
        }
    }
}

bool cariLagu() {
    if (count == 0) {
        cout << "Playlist masih kosong!\n";
        return false;
    }
    string searchTitle;
    cout << "Masukkan judul lagu yang dicari: ";
    getline(cin, searchTitle);
    for (int i = 0; i < count; i++) {
        if (arraySong[i].judul == searchTitle) {
            cout << "\nLagu ditemukan:\n";
            cout << "Judul Lagu     : " << arraySong[i].judul   << "\n";
            cout << "Penyanyi       : " << arraySong[i].penyanyi<< "\n";
            cout << "Genre          : " << arraySong[i].genre   << "\n";
            cout << "Tahun Terbit   : " << arraySong[i].tahun   << "\n";
            return true;
        }
    }
    cout << "Lagu tidak ditemukan.\n";
    int pilihan;
    do {
        cout << "1. Kembali ke menu utama? (1.Ya/2.Tidak)\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        if (pilihan == 2) {
            cout << "Keluar dari program...\n";
            exit(0);
        }
    } while (pilihan != 1);
    return false;
}

void tmbhLagu() {
    int jumlah;
    cout << "Berapa lagu yang ingin ditambahkan? ";
    cin >> jumlah;
    cin.ignore();
    if (count + jumlah > 500) {
        cout << "Maaf, hanya bisa menambahkan " << 500 - count << " lagu lagi.\n";
        return;
    }
    for (int i = 0; i < jumlah; i++) {
        cout << "\nLagu ke-" << count + 1 << ":\n";
        cout << "Masukkan Judul Lagu    : ";
        getline(cin, arraySong[count].judul);
        cout << "Masukkan Nama Penyanyi : ";
        getline(cin, arraySong[count].penyanyi);
        cout << "Masukkan Genre Lagu    : ";
        getline(cin, arraySong[count].genre);
        cout << "Masukkan Tahun Rilis   : ";
        cin >> arraySong[count].tahun;
        cin.ignore();
        count++;
    }
    bubleSort();
    cout << "\n===== PLAYLIST =====\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << arraySong[i].judul << " - " << arraySong[i].penyanyi << " (" << arraySong[i].genre << ", " << arraySong[i].tahun << ")\n";
    }
    cout << "====================\n";
}

int main() {
    int choice;
    do {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Tambah Lagu\n";
        cout << "2. Cari Lagu\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            tmbhLagu();
        } else if (choice == 2) {
            cariLagu();
        }
    } while (choice != 3);
    cout << "Keluar dari program...\n";
    return 0;
}
