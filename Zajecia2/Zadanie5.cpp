//Zadanie 2.5
//Napisz program, który wczytuje dwa napisy (ciągi znaków) i porównuje je ze sobą.
//Program powinien wykorzystywać dynamiczną alokację pamięci do przechowywania napisów.
//Napisy powinny być wczytywane znak po znaku, aż do napotkania znaku końca linii ('\n').
//Następnie program powinien porównać oba napisy i wyświetlić informację, czy są one identyczne.
//Program powinien również zwolnić pamięć po zakończeniu działania.
//WCY24KY4S1 WDP Stanisław Wieczyński
#include <iostream>

using namespace std;

int main() {
    // Deklaracja zmiennych
    char *napis1 = new char[1000]; // Dynamiczna alokacja pamięci na pierwszy napis
    char *napis2 = new char[1000]; // Dynamiczna alokacja pamięci na drugi napis
    char *pNapis1 = napis1, *pNapis2 = napis2;
    char znak;
    int dlugosc = 0;

    // Wczytywanie napisu znak po znaku
    cout << "Podaj tekst: ";
    while (cin.get(znak) && znak != '\n') {
        *(pNapis1 + dlugosc) = znak;
        dlugosc++;
    }
    *(pNapis1 + dlugosc) = '\0'; // Dodanie znaku końca napisu

    // Kopiowanie napisu1 do napisu2
    for (int i = 0; i <= dlugosc; i++) { // <=, aby skopiować również '\0'
        *(pNapis2 + i) = *(pNapis1 + i);
    }

    // Wyświetlanie wyników
    cout << "Pierwszy napis: " << napis1 << endl;
    cout << "Drugi napis: " << napis2 << endl;

    // Zwolnienie pamięci
    delete[] napis1;
    delete[] napis2;

    return 0;
}