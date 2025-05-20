//Zadanie 6
//WCY24KY4S1 Stanisław Wieczyński
#include <iostream>
using namespace std;

// Struktura węzła drzewa
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Funkcja tworząca nowy węzeł
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Dodawanie węzła do drzewa
void addNode(Node*& root, int value) {
    if (root == nullptr) {
        root = createNode(value);
    } else if (value < root->data) {
        addNode(root->left, value);
    } else {
        addNode(root->right, value);
    }
}

// Generator liczb pseudolosowych (LCG)
int myRand(int& seed, int min, int max) {
    seed = (seed * 1103515245 + 12345) & 0x7fffffff;
    return min + (seed % (max - min + 1));
}

// Dodawanie grupy węzłów
void addGroup(Node*& root, int count, int min, int max, int seed) {
    for (int i = 0; i < count; ++i) {
        int value = myRand(seed, min, max);
        addNode(root, value);
    }
}

// Wyszukiwanie węzła i wypisywanie przodków
bool findNode(Node* root, int value) {
    if (root == nullptr) return false;
    cout << root->data << " ";
    if (root->data == value) return true;
    if (value < root->data) return findNode(root->left, value);
    return findNode(root->right, value);
}

// Przechodzenie drzewa in-order (LVR)
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

// Zobrazowanie drzewa (pseudograficzne)
void printTree(Node* root, int space = 0, int level = 5) {
    if (root == nullptr) return;
    space += level;
    printTree(root->right, space);
    for (int i = level; i < space; ++i) cout << " ";
    cout << root->data << "\n";
    printTree(root->left, space);
}

int main() {
    Node* root = nullptr;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Dodaj węzeł\n";
        cout << "2. Dodaj grupę węzłów (generator)\n";
        cout << "3. Wyszukaj węzeł\n";
        cout << "4. Wypisz węzły (in-order)\n";
        cout << "5. Zobrazuj drzewo\n";
        cout << "0. Wyjście\n";
        cout << "Wybierz opcję: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Podaj wartość: ";
                cin >> value;
                addNode(root, value);
                break;
            }
            case 2: {
                int n, min, max, seed;
                cout << "Podaj liczbę węzłów: ";
                cin >> n;
                cout << "Podaj zakres (min max): ";
                cin >> min >> max;
                cout << "Podaj ziarno generatora: ";
                cin >> seed;
                addGroup(root, n, min, max, seed);
                break;
            }
            case 3: {
                int value;
                cout << "Podaj wartość do wyszukania: ";
                cin >> value;
                cout << "Przodkowie: ";
                if (!findNode(root, value)) {
                    cout << "Węzeł nie znaleziony.\n";
                } else {
                    cout << "\n";
                }
                break;
            }
            case 4:
                cout << "Węzły drzewa (in-order): ";
                inOrderTraversal(root);
                cout << "\n";
                break;
            case 5:
                cout << "Drzewo BST:\n";
                printTree(root);
                break;
            case 0:
                cout << "Koniec programu.\n";
                break;
            default:
                cout << "Nieprawidłowa opcja.\n";
        }
    } while (choice != 0);

    return 0;
}