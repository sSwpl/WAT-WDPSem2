// Zadanie 4: Scalanie czterech posortowanych tablic z plików i zapis do pliku
// WCY24KY4S1 Stanisław Wieczyński
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


// Wczytuje liczby z pliku do tablicy, zwraca ilość liczb przez referencję
int* readNumbersFromFile(const char* filename, int& count) {
    // Pierwsze otwarcie do zliczenia elementów
    ifstream fileCount(filename);
    int temp, n = 0;
    while (fileCount >> temp) ++n;
    fileCount.close();

    // Drugie otwarcie do wczytania danych
    ifstream file(filename);
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
    char file1[100], file2[100], file3[100], file4[100], fileOut[100];
    cout << "Podaj nazwę pierwszego pliku wejściowego (*.txt): ";
    cin >> file1;
    cout << "Podaj nazwę drugiego pliku wejściowego (*.txt): ";
    cin >> file2;
    cout << "Podaj nazwę trzeciego pliku wejściowego (*.txt): ";
    cin >> file3;
    cout << "Podaj nazwę czwartego pliku wejściowego (*.txt): ";
    cin >> file4;
    cout << "Podaj nazwę pliku wyjściowego (*.txt): ";
    cin >> fileOut;

    int n1, n2, n3, n4, nA, nB, nOut;
    //Dane z plików wejściowych
    int* arr1 = readNumbersFromFile(file1, n1);
    int* arr2 = readNumbersFromFile(file2, n2);
    int* arr3 = readNumbersFromFile(file3, n3);
    int* arr4 = readNumbersFromFile(file4, n4);

    cout << "arr1: " << endl; printArray(arr1, n1);
    cout << "arr2: " << endl; printArray(arr2, n2);
    cout << "arr3: " << endl; printArray(arr3, n3);
    cout << "arr4: " << endl; printArray(arr4, n4);

    // Scalenie 1: plik1 + plik2 -> tablica A
    int* mergedA = mergeSortedArrays(arr1, n1, arr2, n2, nA);
    // Scalenie 2: plik3 + plik4 -> tablica B
    int* mergedB = mergeSortedArrays(arr3, n3, arr4, n4, nB);

    free(arr1); free(arr2); free(arr3); free(arr4);

    // Ostateczne scalenie: A + B -> wynik
    int* mergedAll = mergeSortedArrays(mergedA, nA, mergedB, nB, nOut);

    free(mergedA); free(mergedB);

    // Teraz dopiero wypisujemy i zapisujemy do pliku
    cout << "Dane z pliku wyjściowego (scalone i posortowane):" << endl;
    printArray(mergedAll, nOut);
    saveNumbersToFile(fileOut, mergedAll, nOut);

    free(mergedAll);
    return 0;
}