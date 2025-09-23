#include <iostream>
#include <limits>
#include "../include/TDLList.h"
#include "../include/TDeque.h"

using namespace std;

int main()
{
    try
    {
        int choice;
        TTT item;

        Deque<TTT> *D = new Deque<TTT>();

        do
        {
            cout << "---------------" << endl;
            cout << "1. Queue at Head." << endl;
            cout << "2. Queue at Tail." << endl;
            cout << "3. Delete at Head." << endl;
            cout << "4. Delete at Tail." << endl;
            cout << "5. Show first item (Head)." << endl;
            cout << "6. Show last item (Tail)." << endl;
            cout << "7. Show size of queue." << endl;
            cout << "8. Check if queue is empty." << endl;
            cout << "9. Exit." << endl;
            cout << "---------------" << endl;

            cout << "Enter your choice: ";
            cin >> choice;

            if (cin.fail())
            {
                cin.clear();                                         // Reset error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
                cout << "Invalid input. Please enter a number between 1 and 9." << endl;
                continue;
            }

            switch (choice)
            {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> item;
                D->enqueueHead(item);
                cout << item << " joined queue at head." << endl;
                break;
            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> item;
                D->enqueueTail(item);
                cout << item << " joined queue at tail." << endl;
                break;
            case 3:
                try
                {
                    D->dequeueHead();
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
                break;
            case 4:
                try
                {
                    D->dequeueTail();
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
                break;
            case 5:
                try
                {
                    cout << "Head item: " << D->front() << endl;
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }

                break;
            case 6:
                try
                {
                    cout << "Tail item: " << D->back() << endl;
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
                break;
            case 7:
                cout << "Queue has " << D->getSize() << " items." << endl;
                break;
            case 8:
                if (D->isEmpty())
                {
                    cout << "Queue is empty." << endl;
                }
                else
                {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 9:
                break;

            default:
                throw runtime_error("Please select a valid choice.");
                break;
            }
        } while (choice != 9);

        delete D;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Fatal error: " << e.what() << endl;
        return 1;
    }
}