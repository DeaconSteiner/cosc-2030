#include <exception>
#include <ios>
#include <iostream>
#include <limits>
#include "Heap.hpp"

using namespace std;

int main() {
    int choice;
    int item;

    Heap h;

    do {
        cout << "---------------" << endl;
        h.display();
        cout << "---------------" << endl;
        cout << " 1. Insert (key)." << endl;
        cout << "2. Show max entry." << endl;
        cout << "3. Delete max entry." << endl;
        cout << "4. Exit." << endl;
        cout << "---------------" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // Reset error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cerr << "Invalid input. Please enter a number between 1 and 4." << endl; // Warn user of input error
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> item;
            h.insert(item);
            cout << item << " added to heap." << endl;
            break;
        case 2:
            cout << "The largest entry is: " << h.getMax() << "." << endl;
            break;
        case 3:
            try {
                h.deleteMax();
            } catch (const exception &e) {
                cerr << e.what() << '\n';
            }
            break;
        case 4:
            break;
        default:
            cerr << "Please select a valid option." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
