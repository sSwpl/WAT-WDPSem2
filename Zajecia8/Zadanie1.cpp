// Zadanie 1: Generator liczb pseudolosowych i zapis do pliku
// WCY24KY4S1 Stanisław Wieczyński
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// Generator liczb pseudolosowych (LCG) z przedziału 1–999
int myRand(int& seed) {
    seed = (seed * 1103515245 + 12345) & 0x7fffffff;
    return 1 + (seed % 999);
}

// Zapisuje liczby do pliku i do tablicy (po 10 w wierszu, szerokość 5)
void generateAndSaveNumbers(const char* filename, int count, int* arr, int seed) {
    ofstream file(filename);
    for (int i = 0; i < count; ++i) {
        arr[i] = myRand(seed);
        file.width(5);
        file << arr[i];
        if ((i + 1) % 10 == 0)
            file << endl;
    }
    if (count % 10 != 0)
        file << endl;
    file.close();
}

// Wypisuje liczby po 10 w wierszu, szerokość 5
void printArray(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout.width(5);
        cout << arr[i];
        if ((i + 1) % 10 == 0) cout << endl;
    }
    if (n % 10 != 0) cout << endl;
}

int main() {
    char filename[100];
    int count, seed;

    cout << "Podaj nazwę pliku (*.txt): ";
    cin >> filename;
    cout << "Podaj ilość liczb: ";
    cin >> count;
    cout << "Podaj ziarno generatora: ";
    cin >> seed;

    int* arr = (int*)malloc(count * sizeof(int));
    generateAndSaveNumbers(filename, count, arr, seed);

    cout << "Wygenerowane liczby:" << endl;
    printArray(arr, count);

    free(arr);
    return 0;
}