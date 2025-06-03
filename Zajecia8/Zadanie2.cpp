// Zadanie 2: Sortowanie liczb z pliku
// WCY24KY4S1 Stanisław Wieczyński
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// Wczytuje liczby z pliku do tablicy, zwraca ilość liczb przez referencję
int* readNumbersFromFile(const char* filename, int& count) {
    ifstream file(filename);
    int temp, n = 0;
    // Liczenie liczb
    while (file >> temp) ++n;
    file.clear();
    file.seekg(0);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        file >> arr[i];
    file.close();
    count = n;
    return arr;
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

// Sortowanie przez wybieranie
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[k])
                k = j;
        int tmp = arr[k];
        arr[k] = arr[i];
        arr[i] = tmp;
    }
}

// Zapisuje liczby do pliku po 10 w wierszu, szerokość 5
void saveNumbersToFile(const char* filename, int* arr, int n) {
    ofstream file(filename);
    for (int i = 0; i < n; ++i) {
        file.width(5);
        file << arr[i];
        if ((i + 1) % 10 == 0) file << endl;
    }
    if (n % 10 != 0) file << endl;
    file.close();
}

int main() {
    char inputFile[100], outputFile[100];
    cout << "Podaj nazwę pliku wejściowego (*.txt): ";
    cin >> inputFile;
    cout << "Podaj nazwę pliku wyjściowego (*.txt): ";
    cin >> outputFile;

    int n;
    int* arr = readNumbersFromFile(inputFile, n);

    cout << "Dane z pliku wejściowego:" << endl;
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Dane po sortowaniu:" << endl;
    printArray(arr, n);

    saveNumbersToFile(outputFile, arr, n);

    free(arr);
    return 0;
}