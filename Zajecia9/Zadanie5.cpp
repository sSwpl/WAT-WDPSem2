//Zadanie 5 Wypisanie ścieżki do katalogu roboczego i utworzenie podkatalogu o nazwie podanej przez użytkownika
//WCY24KY4S1 Stanisław Wieczyński
#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstring>

using namespace std;

int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        cout << "Bieżący katalog: " << cwd << endl;
    } else {
        cout << "Błąd pobierania ścieżki." << endl;
        return 1;
    }

    char nazwa[256];
    cout << "Podaj nazwę podkatalogu do utworzenia: ";
    cin >> nazwa;

    // Tworzenie ścieżki do nowego katalogu
    char sciezka[1280];
    strcpy(sciezka, cwd);
    strcat(sciezka, "/");
    strcat(sciezka, nazwa);

    // Tworzenie katalogu
    if (mkdir(sciezka, 0755) == 0) {
        cout << "Utworzono podkatalog: " << sciezka << endl;
    } else {
        cout << "Błąd tworzenia podkatalogu lub już istnieje." << endl;
    }

    return 0;
}