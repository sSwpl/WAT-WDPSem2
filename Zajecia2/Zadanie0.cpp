//Zadanie 2.0
//Napisz program, który losuje liczby całkowite z przedziału <a, b> i wypisuje je na ekranie.
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
    int a, b, liczbaLosowan;

    // Inicjalizacja generatora liczb losowych
    srand(time(nullptr));

    // Wczytywanie danych wejściowych
    cout << "Podaj dwie liczby całkowite (a, b): ";
    cin >> a >> b;

    cout << "Podaj ilość liczb do wylosowania: ";
    cin >> liczbaLosowan;

    // Wyświetlanie wylosowanych liczb
    cout << "Wylosowane liczby:" << endl;
    for (int i = 1; i <= liczbaLosowan; i++) {
        cout << setw(5) << losujLiczbe(a, b); // Liczba zajmuje 5 znaków
        if (i % 10 == 0) {
            cout << endl; // Nowy wiersz po 10 liczbach
        }
    }

    return 0;
}