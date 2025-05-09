#include <iostream>

using namespace std;

int main() {
    // Deklaracja zmiennych
    int a, b, c, W;
    int *pA = &a, *pB = &b, *pC = &c, *pW = &W;

    // Wczytywanie danych z klawiatury
    cout << "Podaj trzy liczby całkowite (a, b, c): ";
    cin >> *pA >> *pB >> *pC;

    // Sprawdzanie warunku i przypisanie wartości zmiennej W
    if (*pA == *pB || *pA == *pC || *pB == *pC) {
        *pW = 1;
    } else {
        *pW = 0;
    }

    // Wyświetlanie wartości zmiennej W i równych liczb
    cout << "Wartość W: " << *pW << endl;
    if (*pW == 1) {
        cout << "Równe liczby: ";
        if (*pA == *pB) cout << *pA << " i " << *pB << endl;
        if (*pA == *pC) cout << *pA << " i " << *pC << endl;
        if (*pB == *pC) cout << *pB << " i " << *pC << endl;
    }

    return 0;
}