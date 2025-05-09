//Zadanie 2.7
//Napisz program, który wczytuje napis (ciąg znaków) i zamienia wszystkie małe litery na duże.
//Program powinien wykorzystywać dynamiczną alokację pamięci do przechowywania napisu.
//Napis powinien być wczytywany znak po znaku, aż do napotkania znaku końca linii ('\n').
//Następnie program powinien wyświetlić napis z zamienionymi literami.
//Program powinien również zwolnić pamięć po zakończeniu działania.
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

    // Zamiana na duże litery
    for (int i = 0; i < dlugosc; i++) {
        if (*(pNapis + i) >= 'a' && *(pNapis + i) <= 'z') {
            *(pNapis + i) = *(pNapis + i) - ('a' - 'A');
        }
    }

    // Wyświetlanie wyników
    cout << "Napis dużymi literami: " << napis << endl;

    // Zwolnienie pamięci
    delete[] napis;

    return 0;
}