//Zadanie 1 Utworzenie programu, który tworzy 24 rekordy typu Destynacja, zapisuje je do 4 plików binarnych, a następnie odczytuje i wypisuje ich zawartość z nagłówkiem i numerami porządkowymi.
//WCY24KY4S1 Stanisław Wieczyński
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

struct Dest {
    char nazwa[20];
    char n_ang[40];
    int nr_t;
};

const int N = 24;
const char* tabN[N] = { "Akizuki", "Teruzuki", "Suzutsuki", "Hatsutsuki", "Niizuki", "Wakatsuki", "Shimotsuki", "Fuyutsuki", "Harutsuki", "Yoizuki", "Hanatsuki", "Natsuzuki",
    "Satsuki", "Kisarigi", "Yayoi", "Mutsuki", "Uzuki", "Fumizuki", "Kikuzuki", "Minazuki", "Mikazuki", "Nagatsuki", "Yuzuki", "Mochizuki" };
const char* tabT[N] = { "Autumn Moon", "Pale or Lighter Moon, Shining Moon", "Colder Moon", "New Moon", "New Moon", "Moon in First Quarter", "11th Month (Month of Frost, Frost Moon)","Winter Moon",
    "Spring Moon", "Moon Visible as Day Joins Evening", "Blooming Moon", "Summer Moon", "Month of First Buds", "Second Month", "Month of Growing Plants", "Month (moon) of First Rice-Sowing",
    "Month of Blooming Makinos", "Month of Rice Ears", "Month of Chrysanthemum Blooms", "Sixth Month", "Sickle Moon", "Month of Long Moonlight", "Evening Moon", "Full Moon" };
const int tabNrT[N] = { 109, 110, 112, 114, 113, 120, 115, 118, 111, 119, 117, 116, 121, 127, 123, 130, 132, 126, 122, 128, 125, 124, 131, 129 };

int main() {
    std::vector<Dest> tab(N);
    int part = N / 4;
    std::vector<std::string> pliki(4);

    // Tworzenie rekordów
    for (int i = 0; i < N; i++) {
        strncpy(tab[i].nazwa, tabN[i], 19);
        tab[i].nazwa[19] = '\0';
        strncpy(tab[i].n_ang, tabT[i], 39);
        tab[i].n_ang[39] = '\0';
        tab[i].nr_t = tabNrT[i];
    }

    // Wczytanie nazw plików
    for (int i = 0; i < 4; i++) {
        std::cout << "Podaj nazwę pliku binarnego nr " << (i + 1) << ": ";
        std::cin >> pliki[i];
    }

    // Zapis do plików binarnych
    for (int i = 0; i < 4; i++) {
        std::ofstream f(pliki[i], std::ios::binary);
        if (!f) {
            std::cout << "Błąd otwarcia pliku " << pliki[i] << std::endl;
            return 1;
        }
        f.write(reinterpret_cast<char*>(&tab[i * part]), part * sizeof(Dest));
        f.close();
    }

    // Odczyt i wypisanie z nagłówkiem i numerami porządkowymi
    for (int i = 0; i < 4; i++) {
        std::ifstream f(pliki[i], std::ios::binary);
        if (!f) {
            std::cout << "Błąd otwarcia pliku " << pliki[i] << std::endl;
            return 1;
        }
        std::vector<Dest> temp(part);
        f.read(reinterpret_cast<char*>(temp.data()), part * sizeof(Dest));
        f.close();

        std::cout << "\nPlik: " << pliki[i] << std::endl;
        std::cout << "Lp. | " << std::setw(18) << std::left << "Nazwa"
                  << " | " << std::setw(38) << std::left << "Nazwa angielska"
                  << " | Nr_t" << std::endl;
        std::cout << "---------------------------------------------------------------" << std::endl;
        for (int j = 0; j < part; j++) {
            std::cout << std::setw(2) << (j + 1 + i * part) << ". | "
                      << std::setw(18) << std::left << temp[j].nazwa << " | "
                      << std::setw(38) << std::left << temp[j].n_ang << " | "
                      << std::setw(3) << temp[j].nr_t << std::endl;
        }
    }
    return 0;
}