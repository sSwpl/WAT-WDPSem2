//Zadanie 2 Wczytanie i zapis do plików binarnych, sortowanie i scalanie rekordów
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

void printRecords(Dest tab[], int n, const string& naglowek) {
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

void selectionSort(Dest tab[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (tab[j].nr_t < tab[minIdx].nr_t)
                minIdx = j;
        }
        if (minIdx != i) {
            Dest tmp = tab[i];
            tab[i] = tab[minIdx];
            tab[minIdx] = tmp;
        }
    }
}

int main() {
    const int MAX = 100;
    char pliki[4][100];

    for (int i = 0; i < 4; ++i) {
        cout << "Podaj nazwę pliku binarnego nr " << (i + 1) << ": ";
        cin >> pliki[i];
    }

    for (int i = 0; i < 4; ++i) {
        ifstream fin(pliki[i], ios::binary);
        if (!fin) {
            cout << "Błąd otwarcia pliku " << pliki[i] << endl;
            continue;
        }
        // Ustalenie liczby rekordów
        fin.seekg(0, ios::end);
        int size = fin.tellg();
        fin.seekg(0, ios::beg);
        int n = size / sizeof(Dest);
        if (n > MAX) n = MAX;
        Dest tab[MAX];
        fin.read(reinterpret_cast<char*>(tab), n * sizeof(Dest));
        fin.close();

        printRecords(tab, n, "Dane z pliku " + string(pliki[i]) + " (przed sortowaniem):");

        selectionSort(tab, n);

        ofstream fout(pliki[i], ios::binary | ios::trunc);
        if (!fout) {
            cout << "Błąd zapisu do pliku " << pliki[i] << endl;
            continue;
        }
        fout.write(reinterpret_cast<const char*>(tab), n * sizeof(Dest));
        fout.close();

        printRecords(tab, n, "Dane z pliku " + string(pliki[i]) + " (po sortowaniu):");
    }
    return 0;
}