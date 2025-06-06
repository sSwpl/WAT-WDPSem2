//Zadanie 4.1
//WCY24KY4S1 Stanisław Wieczyński
#include <iostream>
#include <cstdlib>
using namespace std;

// Struktura reprezentująca pojedynczy węzeł listy
struct Node {
    int data;      // Przechowywana wartość
    Node* next;    // Wskaźnik na następny węzeł
};

// Dodaje pojedynczy element do listy w odpowiednim miejscu (priorytetowo)
void addObject(Node*& head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Alokacja pamięci dla nowego węzła
    newNode->data = value;
    newNode->next = nullptr;
    // Jeśli lista jest pusta lub nowy element ma być pierwszy
    if (!head || head->data > value) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        // Szukanie miejsca do wstawienia (rosnąco)
        while (current->next && current->next->data <= value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Dodaje grupę elementów do listy
void addGroup(Node*& head, int values[], int size) {
    for (int i = 0; i < size; ++i) {
        addObject(head, values[i]);
    }
}

// Generator liczb pseudolosowych (LCG)
int myRand(int& seed, int min, int max) {
    seed = (seed * 1103515245 + 12345) & 0x7fffffff;
    return min + (seed % (max - min + 1));
}

// Usuwa element o zadanej wartości z listy i wypisuje odpowiedni komunikat
void removeObject(Node*& head, int value) {
    if (!head) {
        cout << "Brak elementu do usunięcia\n";
        return;
    }
    // Usuwanie pierwszego elementu
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        cout << "Usunięto: " << temp->data << endl;
        free(temp);
        return;
    }
    Node* current = head;
    // Szukanie elementu do usunięcia
    while (current->next && current->next->data != value) {
        current = current->next;
    }
    if (current->next) {
        Node* temp = current->next;
        cout << "Usunięto: " << temp->data << endl;
        current->next = current->next->next;
        free(temp);
    } else {
        cout << "Brak elementu do usunięcia\n";
    }
}

// Sprawdza, czy element o zadanej wartości istnieje w liście
bool findObject(Node* head, int value) {
    Node* current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

// Wypisuje wszystkie elementy listy (po 10 w wierszu)
void listObjects(Node* head) {
    Node* current = head;
    int count = 0;
    while (current) {
        cout << current->data << " ";
        current = current->next;
        if (++count % 10 == 0) cout << endl;
    }
    if (count % 10 != 0) cout << endl;
}

// Usuwa całą listę i zwalnia pamięć
void clearList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = nullptr;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Dodaj obiekt\n";
        cout << "2. Dodaj grupę obiektów (generator)\n";
        cout << "3. Usuń obiekt\n";
        cout << "4. Znajdź obiekt\n";
        cout << "5. Wylistuj zapisane obiekty\n";
        cout << "0. Wyjście\n";
        cout << "Wybierz opcję: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Podaj wartość: ";
                cin >> value;
                addObject(head, value);
                break;
            }
            case 2: {
                int n, min, max, seed;
                cout << "Podaj liczbę elementów: ";
                cin >> n;
                cout << "Podaj zakres (min max): ";
                cin >> min >> max;
                cout << "Podaj ziarno generatora: ";
                cin >> seed;
                int* values = (int*)malloc(n * sizeof(int));
                for (int i = 0; i < n; ++i) {
                    values[i] = myRand(seed, min, max);
                }
                addGroup(head, values, n);
                free(values);
                break;
            }
            case 3: {
                int value;
                cout << "Podaj wartość do usunięcia: ";
                cin >> value;
                removeObject(head, value);
                break;
            }
            case 4: {
                int value;
                cout << "Podaj wartość do znalezienia: ";
                cin >> value;
                if (findObject(head, value)) {
                    cout << "Obiekt znaleziony.\n";
                } else {
                    cout << "Obiekt nie znaleziony.\n";
                }
                break;
            }
            case 5:
                cout << "Zapisane obiekty:\n";
                listObjects(head);
                break;
            case 0:
                cout << "Koniec programu.\n";
                break;
            default:
                cout << "Nieprawidłowa opcja.\n";
        }
    } while (choice != 0);

    clearList(head);
    return 0;
}