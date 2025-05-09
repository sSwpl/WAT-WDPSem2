#include <iostream>
#include <string>

using namespace std;

int main() {
    // Deklaracja zmiennych
    int N, W;
    int *pN = &N, *pW = &W;

    // Wczytywanie liczby N z klawiatury
    cout << "Podaj liczbę całkowitą (max 4 cyfry): ";
    cin >> *pN;

    // Konwersja liczby na string
    string strN = to_string(*pN);
    string reversedStrN = string(strN.rbegin(), strN.rend());

    // Sprawdzanie, czy liczba jest lustrzana
    if (strN == reversedStrN) {
        *pW = 1;
    } else {
        *pW = 0;
    }

    // Wyświetlanie wyników
    cout << "Liczba N: " << *pN << endl;
    cout << "Wartość W: " << *pW << endl;

    return 0;
}