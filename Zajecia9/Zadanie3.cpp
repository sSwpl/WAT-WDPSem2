//Zadanie 3 Scalanie 2 plików binarnych
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
    char plik1[100], plik2[100], plik3[100];

    cout << "Podaj nazwę pierwszego pliku wejściowego: ";
    cin >> plik1;
    cout << "Podaj nazwę drugiego pliku wejściowego: ";
    cin >> plik2;
    cout << "Podaj nazwę pliku wyjściowego: ";
    cin >> plik3;

    // Wczytaj pierwszy plik
    ifstream fin1(plik1, ios::binary);
    if (!fin1) {
        cout << "Błąd otwarcia pliku " << plik1 << endl;
        return 1;
    }
    fin1.seekg(0, ios::end);
    int size1 = fin1.tellg();
    fin1.seekg(0, ios::beg);
    int n1 = size1 / sizeof(Dest);
    if (n1 > MAX) n1 = MAX;
    Dest tab1[MAX];
    fin1.read(reinterpret_cast<char*>(tab1), n1 * sizeof(Dest));
    fin1.close();

    // Wczytaj drugi plik
    ifstream fin2(plik2, ios::binary);
    if (!fin2) {
        cout << "Błąd otwarcia pliku " << plik2 << endl;
        return 1;
    }
    fin2.seekg(0, ios::end);
    int size2 = fin2.tellg();
    fin2.seekg(0, ios::beg);
    int n2 = size2 / sizeof(Dest);
    if (n2 > MAX) n2 = MAX;
    Dest tab2[MAX];
    fin2.read(reinterpret_cast<char*>(tab2), n2 * sizeof(Dest));
    fin2.close();

    printRecords(tab1, n1, ("Dane z pliku " + string(plik1) + ":").c_str());
    printRecords(tab2, n2, ("Dane z pliku " + string(plik2) + ":").c_str());

    // Scalanie dwóch posortowanych tablic
    Dest tab3[2 * MAX];
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (tab1[i].nr_t < tab2[j].nr_t) {
            tab3[k++] = tab1[i++];
        } else {
            tab3[k++] = tab2[j++];
        }
    }
    while (i < n1) tab3[k++] = tab1[i++];
    while (j < n2) tab3[k++] = tab2[j++];

    // Zapis do pliku wyjściowego
    ofstream fout(plik3, ios::binary | ios::trunc);
    if (!fout) {
        cout << "Błąd zapisu do pliku " << plik3 << endl;
        return 1;
    }
    fout.write(reinterpret_cast<const char*>(tab3), k * sizeof(Dest));
    fout.close();

    printRecords(tab3, k, ("Dane z pliku " + string(plik3) + ":").c_str());

    return 0;
}