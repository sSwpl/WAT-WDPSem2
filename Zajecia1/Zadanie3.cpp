#include <iostream>

using namespace std;

int main() {
    // Deklaracja zmiennych
    int a, b, k, count = 0;
    int *pA = &a, *pB = &b, *pK = &k, *pCount = &count;

    // Wczytywanie danych z klawiatury
    cout << "Podaj trzy liczby całkowite (a, b, k): ";
    cin >> *pA >> *pB >> *pK;

    // Obliczanie ilości liczb podzielnych przez k w przedziale <a, b>
    for (int i = *pA; i <= *pB; i++) {
        if (i % *pK == 0) {
            (*pCount)++;
        }
    }

    // Wyświetlanie wyniku
    cout << "Ilość liczb podzielnych przez " << *pK << " w przedziale <" << *pA << ", " << *pB << ">: " << *pCount << endl;

    return 0;
}