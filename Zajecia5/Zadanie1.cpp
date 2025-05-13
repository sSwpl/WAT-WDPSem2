//Zadanie 5.1
//WCY24KY4S1 Stanisław Wieczyński
#include <iostream>
#include <cstdlib>
using namespace std;

// Struktura węzła kolejki
struct Node {
    int data;
    Node* next;
};

// Struktura kolejki
struct Queue {
    Node* front;
    Node* rear;
};

// Inicjalizacja kolejki
void InitQueue(Queue& q) {
    q.front = nullptr;
    q.rear = nullptr;
}

// Sprawdza, czy kolejka jest pusta
bool IsEmpty(Queue& q) {
    return q.front == nullptr;
}

// Dodaje element na koniec kolejki
void Enqueue(Queue& q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = nullptr;
    if (q.rear) {
        q.rear->next = newNode;
    } else {
        q.front = newNode;
    }
    q.rear = newNode;
}

// Generator liczb pseudolosowych (prosty LCG)
int MyRand(int& seed, int min, int max) {
    seed = (seed * 1103515245 + 12345) & 0x7fffffff;
    return min + (seed % (max - min + 1));
}

// Dodaje grupę elementów na koniec kolejki (generator)
void EnqueueG(Queue& q, int count, int min, int max, int seed) {
    for (int i = 0; i < count; ++i) {
        int val = MyRand(seed, min, max);
        Enqueue(q, val);
    }
}

// Usuwa element z początku kolejki
void Dequeue(Queue& q) {
    if (IsEmpty(q)) {
        cout << "Kolejka jest pusta\n";
        return;
    }
    Node* temp = q.front;
    cout << "Usunięto: " << temp->data << endl;
    q.front = q.front->next;
    if (!q.front) q.rear = nullptr;
    free(temp);
}

// Zwraca element z początku kolejki
int Front(Queue& q) {
    if (IsEmpty(q)) {
        cout << "Kolejka jest pusta\n";
        return -1;
    }
    return q.front->data;
}

// Usuwa całą kolejkę
void Clear(Queue& q) {
    while (!IsEmpty(q)) {
        Dequeue(q);
    }
}

// Wypisuje elementy kolejki
void ListQueue(Queue& q) {
    Node* current = q.front;
    int lp = 1;
    while (current) {
        cout << lp << ". " << current->data
             << " | adres: " << current
             << " | next: " << current->next << endl;
        current = current->next;
        ++lp;
    }
    if (lp == 1) cout << "Kolejka jest pusta\n";
}

int main() {
    Queue q;
    InitQueue(q);
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Dodaj element (Enqueue)\n";
        cout << "2. Dodaj grupę elementów (EnqueueG)\n";
        cout << "3. Usuń element (Dequeue)\n";
        cout << "4. Odczytaj z przodu (Front)\n";
        cout << "5. Czy pusta? (IsEmpty)\n";
        cout << "6. Wyczyść kolejkę (Clear)\n";
        cout << "7. Wylistuj kolejkę\n";
        cout << "0. Wyjście\n";
        cout << "Wybierz opcję: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int val;
                cout << "Podaj wartość: ";
                cin >> val;
                Enqueue(q, val);
                break;
            }
            case 2: {
                int n, min, max, seed;
                cout << "Ile liczb wygenerować? "; cin >> n;
                cout << "Podaj zakres (min max): "; cin >> min >> max;
                cout << "Podaj ziarno generatora: "; cin >> seed;
                EnqueueG(q, n, min, max, seed);
                break;
            }
            case 3:
                Dequeue(q);
                break;
            case 4:
                cout << "Element z przodu: " << Front(q) << endl;
                break;
            case 5:
                cout << (IsEmpty(q) ? "Kolejka jest pusta\n" : "Kolejka nie jest pusta\n");
                break;
            case 6:
                Clear(q);
                cout << "Kolejka wyczyszczona\n";
                break;
            case 7:
                ListQueue(q);
                break;
            case 0:
                break;
            default:
                cout << "Nieprawidłowa opcja\n";
        }
    } while (choice != 0);
    Clear(q);
    return 0;
}