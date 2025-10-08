#include <iostream>
#include <limits>
#include "binaryTree.hpp"

using namespace std;

int main() {
    int choice;
    int item;

    binaryTree *T = new binaryTree();

    do {
        cout << "---------------" << endl;
        cout << "1. Search (key)." << endl;
        cout << "2. Traverse (inorder)." << endl;
        cout << "3. Traverse (preorder)." << endl;
        cout << "4. Traverse (postorder)." << endl;
        cout << "5. Insert (key)." << endl;
        cout << "6. Remove (key)." << endl;
        cout << "7. Minimum." << endl;
        cout << "8. Maximum." << endl;
        cout << "9. In-order successor (key)." << endl;
        cout << "10. In-order predecessor (key)" << endl;
        cout << "11. Exit." << endl;
        cout << "---------------" << endl;

        cout << "Please enter your choice: ";
        cin >> choice;

        if (cin.fail())
            {
                cin.clear(); // Reset error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
                cout << "Invalid input. Please enter a number between 1 and 11." << endl;
                continue;
            }

        switch (choice) {
            case 1:
                cout << "Please enter the value you'd like to search for: ";
                cin >> item;
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
                T->insert(item);
                break;
            case 6:
                cout << "Please enter a value to remove: ";
                cin >> item;
                T->remove(item);
                break;
            case 7:
                cout << T->minimum() << " is the minimum value of the tree." << endl;
                break;
            case 8:
                cout << T->maximum() << " is the maximum value of the tree." << endl;
                break;
            case 9:
                cout << "Enter the value you'd like to know the successor of: ";
                cin >> item;
                cout << "The successor of " << item << " is " << T->inorderSuccessor(item) << endl;
                break;
            case 10:
                cout << "Enter the value you'd like to know the predecessor of: ";
                cin >> item;
                cout << "The predecessor of " << item << " is " << T->inorderPredecessor(item) << endl;
                break;
            case 11:
                break;
            default:
                cerr << "Please select a valid choice." << endl;
                break;
       }
    } while (choice != 11);

    delete T;
    return 0;
}
