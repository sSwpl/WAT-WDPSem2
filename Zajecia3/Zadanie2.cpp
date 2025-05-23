//Zadanie 3.2
// WCY24KY4S1 WDP Stanisław Wieczyński
#include <iostream>
#include <cstdlib> // Dla rand() i srand()
#include <ctime>   // Dla time()

using namespace std;

// Funkcja wypełniająca tablicę losowymi liczbami z przedziału <a, b>
void parametry(int *Tab, int n, int a, int b) {
    for (int i = 0; i < n; i++) {
        Tab[i] = a + rand() % (b - a + 1); // Losowanie liczby z przedziału <a, b>
    }
}

int main() {
    // Deklaracja zmiennych
    int n, a, b;

    // Wczytywanie danych z klawiatury
    cout << "Podaj rozmiar tablicy (n): ";
    cin >> n;
    cout << "Podaj przedział (a, b): ";
    cin >> a >> b;

    // Dynamiczna alokacja tablicy
    int *Tab = new int[n];

    // Inicjalizacja generatora liczb losowych
    srand(time(0));

    // Wywołanie funkcji wypełniającej tablicę
    parametry(Tab, n, a, b);

    // Wyświetlanie elementów tablicy
    cout << "Elementy tablicy:" << endl;
    for (int i = 0; i < n; i++) {
        cout.width(5); // Ustawienie szerokości pola
        cout << Tab[i];
        if ((i + 1) % 10 == 0) { // Po 10 elementach przejście do nowej linii
            cout << endl;
        }
    }
    if (n % 10 != 0) {
        cout << endl; // Dodanie nowej linii, jeśli ostatni wiersz nie był pełny
    }

    // Zwolnienie pamięci
    delete[] Tab;

    return 0;
}