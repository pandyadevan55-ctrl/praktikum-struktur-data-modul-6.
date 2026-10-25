#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);
    infotype x;
    address P;

    int n = 4;
    string dataNopol[4] = {"D001", "D003", "D001", "D004"};
    string dataWarna[4] = {"hitam", "putih", "merah", "kuning"};
    int dataTahun[4] = {90, 70, 80, 90};

    for (int i = 0; i < n; i++) {
        cout << "masukkan nomor polisi: " << dataNopol[i] << endl;
        cout << "masukkan warna kendaraan: " << dataWarna[i] << endl;
        cout << "masukkan tahun kendaraan: " << dataTahun[i] << endl;

        P = findElm(L, dataNopol[i]);
        if (P != NULL) {
            cout << "nomor polisi sudah terdaftar\n";
        } else {
            x.nopol = dataNopol[i];
            x.warna = dataWarna[i];
            x.thnBuat = dataTahun[i];
            P = alokasi(x);
            insertLast(L, P);
        }
    }

    cout << "\nDATA LIST 1\n\n";
    printInfo(L);

    cout << "\nMasukkan Nomor Polisi yang dicari : D001\n";
    P = findElm(L, "D001");
    if (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    }

    cout << "\nMasukkan Nomor Polisi yang akan dihapus : D003\n";
    address target = findElm(L, "D003");
    if (target != NULL) {
        address delP;
        if (target == L.First) {
            deleteFirst(L, delP);
        } else if (target == L.Last) {
            deleteLast(L, delP);
        } else {
            deleteAfter(L, target->prev, delP);
        }
        dealokasi(delP);
        cout << "Data dengan nomor polisi D003 berhasil dihapus.\n";
    }

    cout << "\nDATA LIST 1\n\n";
    printInfo(L);

    return 0;
}