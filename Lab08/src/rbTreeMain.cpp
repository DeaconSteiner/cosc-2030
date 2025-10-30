#include <ios>
#include <iostream>
#include <limits>
#include "rbTree.hpp"

using namespace std;

int main() {
    int choice;
    int item;

    rbTree *T = new rbTree();

    do {
        cout << "---------------" << endl;
        cout << "1. Search (key)." << endl;
        cout << "2. Traverse (inorder)." << endl;
        cout << "3. Traverse (preorder)." << endl;
        cout << "4. Traverse (postorder)." << endl;
        cout << "5. Insert (key)." << endl;
        cout << "6. Exit." << endl;
        cout << "---------------" << endl;

        cout << "Please enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Please enter the value you'd like to search for: ";
                cin >> item;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid value entered." << endl;
                    continue;
                }
                if (T->search(item)) {
                    cout << item << " is in the tree." << endl;
                } else { cout << item << " is not in the tree." << endl; }
                break;
            case 2:
                T->inorderTraversal();
                break;
            case 3:
                T->preorderTraversal();
                break;
            case 4:
                T->postorderTraversal();
                break;
            case 5:
                cout << "Please enter a value to insert: ";
                cin >> item;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid value entered." << endl;
                    continue;
                }
                T->insert(item);
                break;
            case 6:
                break;
            default:
                cerr << "Please select a valid choice." << endl;
                break;
        }
    } while (choice != 6);

    delete T;
    return 0;
}
