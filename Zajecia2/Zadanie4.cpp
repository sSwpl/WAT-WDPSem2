//Zadanie 2.4
//Napisz program, który wczytuje dwa napisy znak po znaku i zapisuje je w tablicach.
//Następnie porównuje napisy i wyświetla komunikat, czy są identyczne.
//WCY24KY4S1 WDP Stanisław Wieczyński
#include <iostream>

using namespace std;

int main() {
    // Deklaracja zmiennych
    char *napis1 = new char[1000]; // Dynamiczna alokacja pamięci na pierwszy napis
    char *napis2 = new char[1000]; // Dynamiczna alokacja pamięci na drugi napis
    char *pNapis1 = napis1, *pNapis2 = napis2;
    char znak;
    int dlugosc1 = 0, dlugosc2 = 0;

    // Wczytywanie pierwszego napisu znak po znaku
    cout << "Podaj pierwszy napis: ";
    while (cin.get(znak) && znak != '\n') {
        *(pNapis1 + dlugosc1) = znak;
        dlugosc1++;
    }
    *(pNapis1 + dlugosc1) = '\0'; // Dodanie znaku końca napisu

    // Wczytywanie drugiego napisu znak po znaku
    cout << "Podaj drugi napis: ";
    while (cin.get(znak) && znak != '\n') {
        *(pNapis2 + dlugosc2) = znak;
        dlugosc2++;
    }
    *(pNapis2 + dlugosc2) = '\0'; // Dodanie znaku końca napisu

    // Porównywanie napisów
    bool identyczne = true;
    if (dlugosc1 != dlugosc2) {
        identyczne = false; // Jeśli długości są różne, napisy nie są identyczne
    } else {
        for (int i = 0; i < dlugosc1; i++) {
            if (*(pNapis1 + i) != *(pNapis2 + i)) {
                identyczne = false;
                break;
            }
        }
    }

    // Wyświetlanie wyników
    cout << "Pierwszy napis: " << napis1 << endl;
    cout << "Drugi napis: " << napis2 << endl;
    if (identyczne) {
        cout << "Napisy są identyczne." << endl;
    } else {
        cout << "Napisy nie są identyczne." << endl;
    }

    // Zwolnienie pamięci
    delete[] napis1;
    delete[] napis2;

    return 0;
}