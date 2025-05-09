//Zadanie 3.6
// WCY24KY4S1 WDP Stanisław Wieczyński
#include <iostream>
#include <string>

using namespace std;

// Funkcja zamieniająca wszystkie znaki w napisie na duże litery
void toUpperCase(const string &a, string &result) {
    result = ""; // Wyczyszczenie napisu wynikowego
    for (char c : a) {
        if (c >= 'a' && c <= 'z') { // Sprawdzenie, czy znak jest małą literą
            result += c - ('a' - 'A'); // Zamiana na dużą literę
        } else {
            result += c; // Pozostawienie innych znaków bez zmian
        }
    }
}

int main() {
    // Deklaracja zmiennych
    string a, result;

    // Wczytanie danych wejściowych
    cout << "Podaj napis: ";
    getline(cin, a);

    // Zamiana na duże litery
    toUpperCase(a, result);

    // Wyświetlenie wyników
    cout << "Napis oryginalny: " << a << endl;
    cout << "Napis po zamianie na duże litery: " << result << endl;

    return 0;
}