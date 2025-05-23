#include <iostream>
using namespace std;

const int N = 4;
int biaya[N][N] = {
    {0, 4, 1, 3},
    {4, 0, 2, 1},
    {1, 2, 0, 5},
    {3, 1, 5, 0}
};

int jalur[N + 1], jalurTerbaik[N + 1];
bool dikunjungi[N];
int biayaTerendah;

void cari(int awal, int posisi, int total, int langkah) {
    if (langkah == N && biaya[posisi][awal] > 0) {
        total += biaya[posisi][awal];
        if (total < biayaTerendah) {
            biayaTerendah = total;
            for (int i = 0; i < N; i++) jalurTerbaik[i] = jalur[i];
            jalurTerbaik[N] = awal;
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!dikunjungi[i] && biaya[posisi][i] > 0) {
            dikunjungi[i] = true;
            jalur[langkah] = i;
            cari(awal, i, total + biaya[posisi][i], langkah + 1);
            dikunjungi[i] = false;
        }
    }
}

int main() {
    int pilihan, awal;

    do {
        cout << "\n===== GRAPH JALUR TERPENDEK =====\n";
        cout << "1. CARI JALUR TERPENDEK\n";
        cout << "2. KELUAR\n";
        cout << "PILIH MENU (1/2): ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "MASUKKAN TITIK AWAL (1-4): ";
            cin >> awal;

            if (awal < 1 || awal > 4) {
                cout << "TITIK TIDAK VALID. MASUKKAN ANTARA 1 - 4.\n";
                continue;
            }

            awal--; // indeks dari 0
            fill(dikunjungi, dikunjungi + N, false);
            biayaTerendah = 9999;

            jalur[0] = awal;
            dikunjungi[awal] = true;

            cari(awal, awal, 0, 1);

            cout << "\nJALUR TERPENDEK : ";
            for (int i = 0; i <= N; i++) {
                cout << jalurTerbaik[i] + 1;
                if (i < N) cout << " -> ";
            }
            cout << "\nBIAYA MINIMUM : " << biayaTerendah << "\n";
        }

    } while (pilihan != 2);

    cout << "PROGRAM SELESAI.\n";
    return 0;
}
