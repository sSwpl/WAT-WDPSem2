//Zadanie 5.2
//WCY24KY4S1 Stanisław Wieczyński
#include <iostream>
#include <cstdlib>
using namespace std;

// Struktura węzła stosu
struct Node {
    int data;
    Node* next;
};

// Struktura stosu
struct Stack {
    Node* top;
};

// Inicjalizacja stosu
void InitStack(Stack& s) {
    s.top = nullptr;
}

// Sprawdza, czy stos jest pusty
bool IsEmpty(Stack& s) {
    return s.top == nullptr;
}

// Odkłada element na szczyt stosu
void Push(Stack& s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s.top;
    s.top = newNode;
}

// Generator liczb pseudolosowych (LCG)
int MyRand(int& seed, int min, int max) {
    seed = (seed * 1103515245 + 12345) & 0x7fffffff;
    return min + (seed % (max - min + 1));
}

// Odkłada grupę elementów na szczyt stosu (generator)
void PushG(Stack& s, int count, int min, int max, int seed) {
    for (int i = 0; i < count; ++i) {
        int val = MyRand(seed, min, max);
        Push(s, val);
    }
}

// Zdejmuje element ze szczytu stosu
void Pop(Stack& s) {
    if (IsEmpty(s)) {
        cout << "Stos jest pusty\n";
        return;
    }
    Node* temp = s.top;
    cout << "Usunięto: " << temp->data << endl;
    s.top = s.top->next;
    free(temp);
}

// Zwraca element ze szczytu stosu
int Top(Stack& s) {
    if (IsEmpty(s)) {
        cout << "Stos jest pusty\n";
        return -1;
    }
    return s.top->data;
}

// Usuwa cały stos
void Clear(Stack& s) {
    while (!IsEmpty(s)) {
        Pop(s);
    }
}

// Wypisuje elementy stosu
void ListStack(Stack& s) {
    Node* current = s.top;
    int lp = 1;
    while (current) {
        cout << lp << ". " << current->data
             << " | adres: " << current
             << " | next: " << current->next << endl;
        current = current->next;
        ++lp;
    }
    if (lp == 1) cout << "Stos jest pusty\n";
}

int main() {
    Stack s;
    InitStack(s);
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Odkładaj element (Push)\n";
        cout << "2. Odkładaj grupę elementów (PushG)\n";
        cout << "3. Zdejmij element (Pop)\n";
        cout << "4. Odczytaj ze szczytu (Top)\n";
        cout << "5. Czy pusty? (IsEmpty)\n";
        cout << "6. Wyczyść stos (Clear)\n";
        cout << "7. Wylistuj stos\n";
        cout << "0. Wyjście\n";
        cout << "Wybierz opcję: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int val;
                cout << "Podaj wartość: ";
                cin >> val;
                Push(s, val);
                break;
            }
            case 2: {
                int n, min, max, seed;
                cout << "Ile liczb wygenerować? "; cin >> n;
                cout << "Podaj zakres (min max): "; cin >> min >> max;
                cout << "Podaj ziarno generatora: "; cin >> seed;
                PushG(s, n, min, max, seed);
                break;
            }
            case 3:
                Pop(s);
                break;
            case 4:
                cout << "Element ze szczytu: " << Top(s) << endl;
                break;
            case 5:
                cout << (IsEmpty(s) ? "Stos jest pusty\n" : "Stos nie jest pusty\n");
                break;
            case 6:
                Clear(s);
                cout << "Stos wyczyszczony\n";
                break;
            case 7:
                ListStack(s);
                break;
            case 0:
                break;
            default:
                cout << "Nieprawidłowa opcja\n";
        }
    } while (choice != 0);
    Clear(s);
    return 0;
}