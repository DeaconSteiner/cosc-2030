#include <iostream>
#include "../include/DLList.h"

using namespace std;

int main() {
    int choice;
    int item;

    DoubleList* L = new DoubleList();
    Node* x;

    do
    {
        cout << "---------------" << endl;
        L->traverse();
        cout << "---------------" << endl;
        cout << "1. Insert at Head." << endl;
        cout << "2. Insert at Tail." << endl;
        cout << "3. Delete at Head." << endl;
        cout << "4. Delete at Tail." << endl;
        cout << "5. Traverse the List." << endl;
        cout << "6. Exit." << endl;
        
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at head: ";
            cin >> item;
            x = new Node;
            x->data = item;
            x->next = nullptr;
            x->prev = nullptr;
            L->insertHead(x);
            break;
        case 2:
            cout << "Enter value to insert at the tail: ";
            cin >> item;
            x = new Node;
            x->data = item;
            x->next = nullptr;
            x->prev = nullptr;
            L->insertTail(x);
            break;
        case 3: L->delHead();
            break;
        case 4: L->delTail();
            break;
        case 5: L->traverse();
            break;
        case 6: break;
        default: cout << "Enter a valid choice" << endl;
            break;
        }
    } while (choice != 6);
    
    delete L;
    return 0;
}