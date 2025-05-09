#include <iostream>

using namespace std;

int main() {
    // Deklaracja zmiennych
    int a, b, num, sum = 0, count = 0, negativeCount = 0;
    int *pA = &a, *pB = &b, *pNum = &num, *pSum = &sum, *pCount = &count, *pNegativeCount = &negativeCount;

    // Wczytywanie wartości a i b z klawiatury
    cout << "Podaj dwie liczby całkowite (a, b): ";
    cin >> *pA >> *pB;

    // Wczytywanie kolejnych liczb i sprawdzanie warunków zakończenia
    while (true) {
        cout << "Podaj liczbę: ";
        cin >> *pNum;

        // Aktualizacja sumy i liczników
        (*pSum) += *pNum;
        (*pCount)++;
        if (*pNum < 0) {
            (*pNegativeCount)++;
        }

        // Sprawdzanie warunków zakończenia
        if (*pSum > *pA || *pNegativeCount > *pB) {
            break;
        }
    }

    // Wyświetlanie wyników
    cout << "Suma wczytanych liczb: " << *pSum << endl;
    cout << "Ilość wczytanych liczb: " << *pCount << endl;

    return 0;
}