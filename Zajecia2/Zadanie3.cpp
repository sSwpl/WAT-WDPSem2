//Zadanie 2.3
//Napisz program, który wczytuje napis znak po znaku i zapisuje go w tablicy.
//Następnie wyświetla napis w odwrotnej kolejności.
//WCY24KY4S1 WDP Stanisław Wieczyński
#include <iostream>
#include <cstring> // Dla memcpy

using namespace std;

int main() {
    // Początkowy rozmiar bufora
    int rozmiar = 10;
    char *napis = new char[rozmiar];
    char *pNapis = napis;
    char znak;
    int dlugosc = 0;

    // Wczytywanie napisu znak po znaku
    cout << "Podaj napis: ";
    while (cin.get(znak) && znak != '\n') {
        // Sprawdzanie, czy potrzebna jest realokacja
        if (dlugosc >= rozmiar - 1) {
            // Zwiększanie rozmiaru bufora
            rozmiar *= 2;
            char *nowyNapis = new char[rozmiar];
            memcpy(nowyNapis, napis, dlugosc); // Kopiowanie danych
            delete[] napis; // Zwolnienie starej pamięci
            napis = nowyNapis;
            pNapis = napis;
        }
        *(pNapis + dlugosc) = znak;
        dlugosc++;
    }
    *(pNapis + dlugosc) = '\0'; // Dodanie znaku końca napisu

    // Wyświetlanie napisu w odwrotnej kolejności
    cout << "Odwrócony napis: ";
    for (int i = dlugosc - 1; i >= 0; i--) {
        cout << *(pNapis + i);
    }
    cout << endl;

    // Zwolnienie pamięci
    delete[] napis;

    return 0;
}