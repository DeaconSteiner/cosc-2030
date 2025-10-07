#include <iostream>
#include "DLList.h"

using namespace std;

DoubleList::DoubleList() {
    head = nullptr;
    tail = nullptr;
}

void DoubleList::insertHead(Node* x) {
    if (head == nullptr && tail == nullptr)
    {
        // List is empty.
        head = tail = x;
        x->next = nullptr;
        x->prev = nullptr;
    } else {
        // List is not empty.
        x->next = head;
        x->prev = nullptr;
        head->prev = x;
        head = x;
    }
}

void DoubleList::insertTail(Node* x) {
    if (head == nullptr && tail == nullptr)
    {
        // List is empty.
        head = tail = x;
        x->next = nullptr;
        x->prev = nullptr;
    } else {
        // List is not empty.
        x->next = nullptr;
        x->prev = tail;
        tail->next = x;
        tail = x;

    }
}

void DoubleList::delHead() {
    if (head == nullptr)
    {
        cout << "The list is empty." << endl;
        return;
    } else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
}

void DoubleList::delTail() {
    if (tail == nullptr)
    {
        cout << "The list is empty." << endl;
        return;
    } else if (head == tail) {
        delete tail;
        head = nullptr;
        tail = nullptr;
    } else {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
}

void DoubleList::traverse() const {
    if (head == nullptr)
    {
        cout << "The list is empty." << endl;
    } else {
        Node* curr = head;
        while (curr != nullptr)
        {
            cout << "[" << curr->data << "] ";
            curr = curr->next;
        }
        cout << endl;
    }
}

DoubleList::~DoubleList() {
    Node* curr = head;
    while (curr != nullptr)
    {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}
