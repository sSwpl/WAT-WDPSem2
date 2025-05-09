//Zadanie 3.5
// WCY24KY4S1 WDP Stanisław Wieczyński
#include <iostream>
#include <string>

using namespace std;

// Funkcja szyfrująca (Szyfr Cezara)
void SCr(int n, const string &a, string &b) {
    b = ""; // Wyczyszczenie tekstu wyjściowego
    for (char c : a) {
        if (isalpha(c)) { // Sprawdzenie, czy znak jest literą
            char base = islower(c) ? 'a' : 'A';
            b += (c - base + n) % 26 + base; // Przesunięcie w alfabecie
        } else {
            b += c; // Pozostawienie innych znaków (np. spacji) bez zmian
        }
    }
}

// Funkcja deszyfrująca (Szyfr Cezara)
void DSCr(int n, const string &a, string &b) {
    b = ""; // Wyczyszczenie tekstu wyjściowego
    for (char c : a) {
        if (isalpha(c)) { // Sprawdzenie, czy znak jest literą
            char base = islower(c) ? 'a' : 'A';
            b += (c - base - n + 26) % 26 + base; // Przesunięcie w alfabecie
        } else {
            b += c; // Pozostawienie innych znaków (np. spacji) bez zmian
        }
    }
}

int main() {
    // Deklaracja zmiennych
    int n;
    string a, b;

    // Wczytywanie danych wejściowych
    cout << "Podaj liczbę szyfru (n): ";
    cin >> n;
    cin.ignore(); // Ignorowanie znaku nowej linii po liczbie
    cout << "Podaj tekst do zaszyfrowania (a): ";
    getline(cin, a);

    // Szyfrowanie
    SCr(n, a, b);
    cout << "\nZaszyfrowany tekst (b): " << b << endl;

    // Deszyfrowanie
    string decrypted;
    DSCr(n, b, decrypted);
    cout << "Odszyfrowany tekst: " << decrypted << endl;

    return 0;
}