#include <iostream>
#include <string>

using namespace std;

int main() {
    // Deklaracja zmiennych
    int N, W, nonZeroCount = 0;
    int *pN = &N, *pW = &W, *pNonZeroCount = &nonZeroCount;

    // Wczytywanie liczby N z klawiatury
    cout << "Podaj liczbę całkowitą (max 4 cyfry): ";
    cin >> *pN;

    // Konwersja liczby na string
    string strN = to_string(*pN);

    // Zliczanie cyfr różnych od zera
    for (char c : strN) {
        if (c != '0') {
            (*pNonZeroCount)++;
        }
    }

    // Sprawdzanie warunku i przypisanie wartości zmiennej W
    if (*pNonZeroCount >= 2) {
        *pW = 1;
    } else {
        *pW = 0;
    }

    // Wyświetlanie wyników
    cout << "Liczba N: " << *pN << endl;
    cout << "Wartość W: " << *pW << endl;
    cout << "Ilość cyfr różnych od zera: " << *pNonZeroCount << endl;

    return 0;
}