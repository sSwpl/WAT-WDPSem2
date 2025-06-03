// Zadanie 3: Scalanie dwóch posortowanych tablic z plików
// WCY24KY4S1 Stanisław Wieczyński
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// Wczytuje liczby z pliku do tablicy, zwraca ilość liczb przez referencję
int* readNumbersFromFile(const char* filename, int& count) {
    ifstream file(filename);
    int temp, n = 0;
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

// Scala dwie posortowane tablice w jedną posortowaną
int* mergeSortedArrays(int* arr1, int n1, int* arr2, int n2, int& nOut) {
    int* merged = (int*)malloc((n1 + n2) * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }
    while (i < n1) merged[k++] = arr1[i++];
    while (j < n2) merged[k++] = arr2[j++];
    nOut = n1 + n2;
    return merged;
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
    char file1[100], file2[100], fileOut[100];
    cout << "Podaj nazwę pierwszego pliku wejściowego (*.txt): ";
    cin >> file1;
    cout << "Podaj nazwę drugiego pliku wejściowego (*.txt): ";
    cin >> file2;
    cout << "Podaj nazwę pliku wyjściowego (*.txt): ";
    cin >> fileOut;

    int n1, n2, nOut;
    int* arr1 = readNumbersFromFile(file1, n1);
    int* arr2 = readNumbersFromFile(file2, n2);

    cout << "Dane z pliku " << file1 << ":" << endl;
    printArray(arr1, n1);
    cout << "Dane z pliku " << file2 << ":" << endl;
    printArray(arr2, n2);

    int* merged = mergeSortedArrays(arr1, n1, arr2, n2, nOut);

    saveNumbersToFile(fileOut, merged, nOut);

    cout << "Dane z pliku wyjściowego (scalone i posortowane):" << endl;
    printArray(merged, nOut);

    free(arr1);
    free(arr2);
    free(merged);
    return 0;
}