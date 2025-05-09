//Zadanie 3.1
// WCY24KY4S1 WDP Stanisław Wieczyński
#include <iostream>

using namespace std;

// Funkcja do obliczania największego wspólnego dzielnika (NWD)
int nwd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Funkcja do obliczania najmniejszej wspólnej wielokrotności (NWW)
int nww(int a, int b) {
    return (a * b) / nwd(a, b);
}

// Funkcja parametry obliczająca NWD i NWW
void parametry(int a, int b, int &c, int &d) {
    c = nwd(a, b);
    d = nww(a, b);
}

int main() {
    // Deklaracja zmiennych
    int a, b, c, d;

    // Wczytywanie danych z klawiatury
    cout << "Podaj dwie liczby naturalne (a, b): ";
    cin >> a >> b;

    // Wywołanie funkcji parametry
    parametry(a, b, c, d);

    // Wyświetlanie wyników
    cout << "Liczba a: " << a << endl;
    cout << "Liczba b: " << b << endl;
    cout << "Największy wspólny dzielnik (NWD): " << c << endl;
    cout << "Najmniejsza wspólna wielokrotność (NWW): " << d << endl;

    return 0;
}