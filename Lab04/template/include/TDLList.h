#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class DoubleList {
    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        DoubleList();
        void insertHead(Node<T>*);
        void insertTail(Node<T>*);
        void delHead();
        void delTail();
        void traverse() const;
        ~DoubleList();
};

template <typename T>
DoubleList<T>::DoubleList() {
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void DoubleList<T>::insertHead(Node<T>* x) {
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

template <typename T>
void DoubleList<T>::insertTail(Node<T>* x) {
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

template <typename T>
void DoubleList<T>::delHead() {
    if (head == nullptr) 
    {
        cout << "The list is empty." << endl;
        return;
    } else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node<T>* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
}

template <typename T>
void DoubleList<T>::delTail() {
    if (tail == nullptr)
    {
        cout << "The list is empty." << endl;
        return;
    } else if (head == tail) {
        delete tail;
        head = nullptr;
        tail = nullptr;
    } else {
        Node<T>* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
}

template <typename T>
void DoubleList<T>::traverse() const {
    if (head == nullptr)
    {
        cout << "The list is empty." << endl;
    } else {
        Node<T>* curr = head;
        while (curr != nullptr)
        {
            cout << "[" << curr->data << "] ";
            curr = curr->next;
        }
        cout << endl;
    }
}

template <typename T>
DoubleList<T>::~DoubleList() {
    Node<T>* curr = head;
    while (curr != nullptr) 
    {
        Node<T>* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

#endif