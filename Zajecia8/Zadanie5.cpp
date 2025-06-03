// Zadanie 5: Wypisywanie zawartości katalogu
// WCY24KY4S1 Stanisław Wieczyński
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

// Funkcja wypisująca zawartość katalogu
void listDirectory(const string& path) {
    try {
        for (const auto& entry : fs::directory_iterator(path)) {
            cout << entry.path().filename().string() << endl;
        }
    } catch (const fs::filesystem_error& e) {
        cerr << "Błąd: " << e.what() << endl;
    }
}

int main() {
    string path;
    cout << "Podaj ścieżkę do katalogu: ";
    getline(cin, path);
    listDirectory(path);
    return 0;
}