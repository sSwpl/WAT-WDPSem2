//Zadanie 3.7
// WCY24KY4S1 WDP Stanisław Wieczyński
#include <iostream>
#include <string>

using namespace std;

// Definicja struktury
struct Osoba {
    string imie;
    string nazwisko;
    string pesel;
    string zainteresowania;
};

// Funkcja wczytująca dane do struktury
Osoba wczytajDane() {
    Osoba a;
    cout << "Podaj imię: ";
    getline(cin, a.imie);
    cout << "Podaj nazwisko: ";
    getline(cin, a.nazwisko);
    cout << "Podaj PESEL: ";
    getline(cin, a.pesel);
    cout << "Podaj zainteresowania (maks. 256 znaków): ";
    getline(cin, a.zainteresowania);
    return a;
}

// Funkcja wyświetlająca dane ze struktury
void wyswietlDane(const Osoba &a) {
    cout << "\nDane osoby:" << endl;
    cout << "Imię: " << a.imie << endl;
    cout << "Nazwisko: " << a.nazwisko << endl;
    cout << "PESEL: " << a.pesel << endl;
    cout << "Zainteresowania: " << a.zainteresowania << endl;
}

int main() {
    // Wczytanie danych do struktury
    Osoba osoba = wczytajDane();

    // Wyświetlenie danych
    wyswietlDane(osoba);

    return 0;
}