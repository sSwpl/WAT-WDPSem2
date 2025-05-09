//Zadanie 2.1
//Napisz program, który losuje liczby całkowite z przedziału <a, b> i zapisuje je w tablicy.
//WCY24KY4S1 WDP Stanisław Wieczyński
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funkcja losująca liczbę całkowitą z przedziału <a, b>
int losujLiczbe(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main() {
    // Deklaracja zmiennych
    int n, a, b;
    int *pN = &n, *pA = &a, *pB = &b;

    // Inicjalizacja generatora liczb losowych
    srand(time(nullptr));

    // Wczytywanie danych wejściowych
    cout << "Podaj liczbę elementów tablicy (n): ";
    cin >> *pN;
    cout << "Podaj przedział liczb losowych (a, b): ";
    cin >> *pA >> *pB;

    // Dynamiczna alokacja tablicy
    int *Tab = new int[*pN];
    int *pTab = Tab;

    // Wypełnianie tablicy liczbami losowymi
    for (int i = 0; i < *pN; i++) {
        *(pTab + i) = losujLiczbe(*pA, *pB);
    }

    // Wyświetlanie elementów tablicy
    cout << "Elementy tablicy Tab:" << endl;
    for (int i = 0; i < *pN; i++) {
        cout << setw(5) << *(pTab + i); // Liczba zajmuje 5 znaków
        if ((i + 1) % 10 == 0) {
            cout << endl; // Nowy wiersz po 10 liczbach
        }
    }

    // Zwolnienie pamięci
    delete[] Tab;

    return 0;
}