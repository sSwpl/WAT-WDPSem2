// Zadanie 1: Sortowanie bąbelkowe
//WCY24KY4S1 Stanisław Wieczyński
#include <iostream>
#include <fstream>
using namespace std;

// Generator liczb pseudolosowych (LCG)
int myRand(int& seed) {
    seed = (seed * 1103515245 + 12345) & 0x7fffffff;
    return 1 + (seed % 999);
}

// Wypisywanie tablicy (po 10 w wierszu, szerokość 5)
void printArray(int* arr, int n, const char* header) {
    cout << header << endl;
    for (int i = 0; i < n; ++i) {
        cout.width(5);
        cout << arr[i];
        if ((i + 1) % 10 == 0) cout << endl;
    }
    if (n % 10 != 0) cout << endl;
}

// Sortowanie bąbelkowe malejąco
void bubbleSort(int* arr, int n) {
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 0; j <= i - 1; ++j) {
            if (arr[j] > arr[j + 1]) { // zmiana na sortowanie rosnące
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int* arr = nullptr;
    int n = 0;
    int choice;

    cout << "Wybierz źródło danych:\n1. Generator\n2. Plik\nTwój wybór: ";
    cin >> choice;

    if (choice == 1) {
        int seed;
        cout << "Podaj ilość elementów: ";
        cin >> n;
        cout << "Podaj ziarno generatora: ";
        cin >> seed;
        arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; ++i)
            arr[i] = myRand(seed);
    } else if (choice == 2) {
        char filename[100];
        cout << "Podaj nazwę pliku: ";
        cin >> filename;
        ifstream file(filename);
        int temp, count = 0;
        while (file >> temp) ++count;
        file.clear();
        file.seekg(0);
        n = count;
        arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; ++i)
            file >> arr[i];
        file.close();
    } else {
        cout << "Nieprawidłowy wybór.\n";
        return 1;
    }

    printArray(arr, n, "Przed sortowaniem:");
    bubbleSort(arr, n);
    printArray(arr, n, "Po sortowaniu:");

    free(arr);
    return 0;
}