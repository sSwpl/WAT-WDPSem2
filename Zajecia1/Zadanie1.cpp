#include <iostream>

using namespace std;

int main() {
    // Deklaracja zmiennych
    int in1, in2;
    float fl1, fl2;
    long int loin1, loin2;
    double doub1, doub2;
    char znak1, znak2;

    // Deklaracja wskaźników
    int *pIn1 = &in1, *pIn2 = &in2;
    float *pFl1 = &fl1, *pFl2 = &fl2;
    long int *pLoin1 = &loin1, *pLoin2 = &loin2;
    double *pDoub1 = &doub1, *pDoub2 = &doub2;
    char *pZnak1 = &znak1, *pZnak2 = &znak2;

    // Wczytywanie danych z klawiatury
    cout << "Podaj dwie liczby całkowite (int): ";
    cin >> in1 >> in2;
    cout << "Podaj dwie liczby zmiennoprzecinkowe (float): ";
    cin >> fl1 >> fl2;
    cout << "Podaj dwie liczby całkowite długie (long int): ";
    cin >> loin1 >> loin2;
    cout << "Podaj dwie liczby zmiennoprzecinkowe podwójnej precyzji (double): ";
    cin >> doub1 >> doub2;
    cout << "Podaj dwa znaki (char): ";
    cin >> znak1 >> znak2;

    // Wyświetlanie wartości zmiennych i wskaźników
    cout << "Wartości zmiennych i wskaźników:\n";
    cout << "int: " << in1 << " (adres: " << pIn1 << "), " << in2 << " (adres: " << pIn2 << ")\n";
    cout << "float: " << fl1 << " (adres: " << pFl1 << "), " << fl2 << " (adres: " << pFl2 << ")\n";
    cout << "long int: " << loin1 << " (adres: " << pLoin1 << "), " << loin2 << " (adres: " << pLoin2 << ")\n";
    cout << "double: " << doub1 << " (adres: " << pDoub1 << "), " << doub2 << " (adres: " << pDoub2 << ")\n";
    cout << "char: " << znak1 << " (adres: " << static_cast<void*>(pZnak1) << "), " << znak2 << " (adres: " << static_cast<void*>(pZnak2) << ")\n";

    // Arytmetyka wskaźników
    cout << "\nArytmetyka wskaźników:\n";
    cout << "Adres pIn1: " << pIn1 << ", pIn1 + 1: " << (pIn1 + 1) << "\n";
    cout << "Adres pFl1: " << pFl1 << ", pFl1 + 1: " << (pFl1 + 1) << "\n";
    cout << "Adres pLoin1: " << pLoin1 << ", pLoin1 + 1: " << (pLoin1 + 1) << "\n";
    cout << "Adres pDoub1: " << pDoub1 << ", pDoub1 + 1: " << (pDoub1 + 1) << "\n";
    cout << "Adres pZnak1: " << static_cast<void*>(pZnak1) << ", pZnak1 + 1: " << static_cast<void*>(pZnak1 + 1) << "\n";

    return 0;
}