//Zadanie 4 Scalanie 4 plików binarnych
//WCY24KY4S1 Stanisław Wieczyński
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

struct Dest {
    char nazwa[20];
    char n_ang[40];
    int nr_t;
};

void printRecords(Dest tab[], int n, const char* naglowek) {
    cout << "\n" << naglowek << endl;
    cout << "Lp. | " << setw(18) << left << "Nazwa"
         << " | " << setw(38) << left << "Nazwa angielska"
         << " | Nr_T" << endl;
    cout << "---------------------------------------------------------------" << endl;
    for (int i = 0; i < n; ++i) {
        cout << setw(2) << (i + 1) << ". | "
             << setw(18) << left << tab[i].nazwa << " | "
             << setw(38) << left << tab[i].n_ang << " | "
             << setw(3) << tab[i].nr_t << endl;
    }
}

int main() {
    const int MAX = 100;
    char pliki[5][100];
    Dest tab[4][MAX];
    int n[4] = {0, 0, 0, 0};

    // Wczytaj nazwy plików
    for (int i = 0; i < 4; ++i) {
        cout << "Podaj nazwę pliku wejściowego nr " << (i + 1) << ": ";
        cin >> pliki[i];
    }
    cout << "Podaj nazwę pliku wyjściowego: ";
    cin >> pliki[4];

    // Wczytaj dane z plików wejściowych
    for (int i = 0; i < 4; ++i) {
        ifstream fin(pliki[i], ios::binary);
        if (!fin) {
            cout << "Błąd otwarcia pliku " << pliki[i] << endl;
            return 1;
        }
        fin.seekg(0, ios::end);
        int size = fin.tellg();
        fin.seekg(0, ios::beg);
        n[i] = size / sizeof(Dest);
        if (n[i] > MAX) n[i] = MAX;
        fin.read(reinterpret_cast<char*>(tab[i]), n[i] * sizeof(Dest));
        fin.close();
        printRecords(tab[i], n[i], ("Dane z pliku " + string(pliki[i]) + ":").c_str());
    }

    // Merge 4 posortowanych tablic
    Dest tabOut[4 * MAX];
    int idx[4] = {0, 0, 0, 0};
    int total = n[0] + n[1] + n[2] + n[3];
    for (int k = 0; k < total; ++k) {
        int minIdx = -1;
        for (int i = 0; i < 4; ++i) {
            if (idx[i] < n[i]) {
                if (minIdx == -1 || tab[i][idx[i]].nr_t < tab[minIdx][idx[minIdx]].nr_t)
                    minIdx = i;
            }
        }
        if (minIdx != -1) {
            tabOut[k] = tab[minIdx][idx[minIdx]];
            idx[minIdx]++;
        }
    }

    // Zapisz i wyświetl wynik
    ofstream fout(pliki[4], ios::binary | ios::trunc);
    if (!fout) {
        cout << "Błąd zapisu do pliku " << pliki[4] << endl;
        return 1;
    }
    fout.write(reinterpret_cast<const char*>(tabOut), total * sizeof(Dest));
    fout.close();

    printRecords(tabOut, total, ("Dane z pliku " + string(pliki[4]) + ":").c_str());

    return 0;
}