//Zadanie 2.6
//Napisz program, który definiuje strukturę "Osoba" zawierającą pola: imię, nazwisko, PESEL i zainteresowania.
//Program powinien wykorzystywać dynamiczną alokację pamięci do przechowywania danych.
//Następnie program powinien wczytać dane osoby, a następnie je wyświetlić.
//Program powinien również zwolnić pamięć po zakończeniu działania.
//WCY24KY4S1 WDP Stanisław Wieczyński
#include <iostream>

using namespace std;

// Definicja struktury
struct Osoba {
    char imie[50];
    char nazwisko[50];
    char pesel[12];
    char zainteresowania[256];
};

int main() {
    // Dynamiczna alokacja pamięci dla struktury
    Osoba *osoba = new Osoba;
    char *pImie = osoba->imie;
    char *pNazwisko = osoba->nazwisko;
    char *pPesel = osoba->pesel;
    char *pZainteresowania = osoba->zainteresowania;

    // Wczytywanie danych
    cout << "Podaj imię: ";
    cin.getline(pImie, 50);
    cout << "Podaj nazwisko: ";
    cin.getline(pNazwisko, 50);
    cout << "Podaj PESEL: ";
    cin.getline(pPesel, 12);
    cout << "Podaj zainteresowania: ";
    cin.getline(pZainteresowania, 256);

    // Wyświetlanie danych
    cout << "\nWprowadzone dane:" << endl;
    cout << "Imię: " << pImie << endl;
    cout << "Nazwisko: " << pNazwisko << endl;
    cout << "PESEL: " << pPesel << endl;
    cout << "Zainteresowania: " << pZainteresowania << endl;

    // Zwolnienie pamięci
    delete osoba;

    return 0;
}