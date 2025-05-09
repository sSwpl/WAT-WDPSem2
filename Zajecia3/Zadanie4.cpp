//Zadanie 3.4
// WCY24KY4S1 WDP Stanisław Wieczyński
#include <iostream>
#include <iomanip> // Dla ustawienia szerokości wyświetlania

using namespace std;

// Funkcja obliczająca iloczyn macierzy T1 x T2 => T3
void parametry(int T1[3], int T2[2], int T3[3][2]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            T3[i][j] = T1[i] * T2[j];
        }
    }
}

int main() {
    // Deklaracja macierzy
    int T1[3], T2[2], T3[3][2];

    // Wczytywanie danych do T1
    cout << "Podaj 3 elementy wektora T1 (kolumnowego):" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "T1[" << i << "]: ";
        cin >> T1[i];
    }

    // Wczytywanie danych do T2
    cout << "Podaj 2 elementy wektora T2 (wierszowego):" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "T2[" << i << "]: ";
        cin >> T2[i];
    }

    // Obliczanie iloczynu macierzy
    parametry(T1, T2, T3);

    // Wyświetlanie macierzy T1
    cout << "\nMacierz T1 (wektor kolumnowy):" << endl;
    for (int i = 0; i < 3; i++) {
        cout << setw(5) << T1[i] << endl;
    }

    // Wyświetlanie macierzy T2
    cout << "\nMacierz T2 (wektor wierszowy):" << endl;
    for (int i = 0; i < 2; i++) {
        cout << setw(5) << T2[i];
    }
    cout << endl;

    // Wyświetlanie macierzy T3
    cout << "\nMacierz T3 (wynik iloczynu T1 x T2):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << setw(5) << T3[i][j];
        }
        cout << endl;
    }

    return 0;
}