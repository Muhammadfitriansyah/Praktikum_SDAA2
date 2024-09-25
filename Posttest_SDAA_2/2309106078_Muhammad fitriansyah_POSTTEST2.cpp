#include <iostream>
#include <string>

using namespace std;

struct Sparepart {
    string kodeSparepart;
    string namaSparepart;
    int stok;
    float harga;
};

const int MAX_SPAREPARTS = 100;
Sparepart* daftarSpareparts[MAX_SPAREPARTS];
int jumlahSparepart = 0;

void tambahSparepart() {
    if (jumlahSparepart < MAX_SPAREPARTS) {
        Sparepart* sparepartBaru = new Sparepart; 
        cout << "Masukkan Kode Sparepart: ";
        cin >> sparepartBaru->kodeSparepart;
        cout << "Masukkan Nama Sparepart: ";
        cin.ignore();
        getline(cin, sparepartBaru->namaSparepart);
        cout << "Masukkan Stok: ";
        cin >> sparepartBaru->stok;
        cout << "Masukkan Harga: ";
        cin >> sparepartBaru->harga;

        daftarSpareparts[jumlahSparepart] = sparepartBaru;
        jumlahSparepart++;
        cout << "Sparepart berhasil ditambahkan!" << endl;
    } else {
        cout << "Kapasitas penuh, tidak bisa menambah sparepart." << endl;
    }
}

void tampilkanSpareparts() {
    if (jumlahSparepart > 0) {
        cout << "Daftar Sparepart Motor: " << endl;
        for (int i = 0; i < jumlahSparepart; i++) {
            cout << "Kode: " << daftarSpareparts[i]->kodeSparepart << ", Nama: " << daftarSpareparts[i]->namaSparepart
                 << ", Stok: " << daftarSpareparts[i]->stok << ", Harga: Rp" << daftarSpareparts[i]->harga << endl;
        }
    } else {
        cout << "Tidak ada sparepart dalam daftar." << endl;
    }
}

void updateSparepart() {
    string kode;
    cout << "Masukkan kode sparepart yang ingin diupdate: ";
    cin >> kode;

    for (int i = 0; i < jumlahSparepart; i++) {
        if (daftarSpareparts[i]->kodeSparepart == kode) {
            cout << "Masukkan Nama Sparepart Baru: ";
            cin.ignore();
            getline(cin, daftarSpareparts[i]->namaSparepart);
            cout << "Masukkan Stok Baru: ";
            cin >> daftarSpareparts[i]->stok;
            cout << "Masukkan Harga Baru: ";
            cin >> daftarSpareparts[i]->harga;
            cout << "Sparepart berhasil diupdate!" << endl;
            return;
        }
    }
    cout << "Sparepart dengan kode tersebut tidak ditemukan." << endl;
}

void hapusSparepart() {
    string kode;
    cout << "Masukkan kode sparepart yang ingin dihapus: ";
    cin >> kode;

    for (int i = 0; i < jumlahSparepart; i++) {
        if (daftarSpareparts[i]->kodeSparepart == kode) {
            delete daftarSpareparts[i]; 
            for (int j = i; j < jumlahSparepart - 1; j++) {
                daftarSpareparts[j] = daftarSpareparts[j + 1];
            }
            jumlahSparepart--;
            cout << "Sparepart berhasil dihapus!" << endl;
            return;
        }
    }
    cout << "Sparepart dengan kode tersebut tidak ditemukan." << endl;
}

void menu() {
    int pilihan;
    do {
        cout << "\nMenu Manajemen Penjualan Sparepart Motor:" << endl;
        cout << "1. Tambah Sparepart" << endl;
        cout << "2. Tampilkan Sparepart" << endl;
        cout << "3. Update Sparepart" << endl;
        cout << "4. Hapus Sparepart" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahSparepart();
                break;
            case 2:
                tampilkanSpareparts();
                break;
            case 3:
                updateSparepart();
                break;
            case 4:
                hapusSparepart();
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 5);
}

int main() {
    menu();
    return 0;
}
