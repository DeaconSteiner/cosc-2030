#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_

#include <iostream>

template <typename T>
class DoubleList {
    protected:
        // For internal use only.
        struct Node {
            T data;
            Node* next;
            Node* prev;
        };

        Node* head;
        Node* tail;

        DoubleList();
        void insertHead(const T& data);
        void insertTail(const T& data);
        void delHead();
        void delTail();
        void traverse() const;
        bool isEmpty() const;
        ~DoubleList();
};

template <typename T>
DoubleList<T>::DoubleList() {
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void DoubleList<T>::insertHead(const T& data) {
    Node* x = new Node{data, nullptr, nullptr};
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
void DoubleList<T>::insertTail(const T& data) {
    Node* x = new Node{data, nullptr, nullptr};
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
        throw std::runtime_error("List is empty.");
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

template <typename T>
void DoubleList<T>::delTail() {
    if (tail == nullptr)
    {
        throw std::runtime_error("List is empty.");
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

template <typename T>
void DoubleList<T>::traverse() const {
    if (head == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    } else {
        Node* curr = head;
        while (curr != nullptr)
        {
            std::cout << "[" << curr->data << "] ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
}

template <typename T>
bool DoubleList<T>::isEmpty() const { return head == nullptr; }

template <typename T>
DoubleList<T>::~DoubleList() {
    Node* curr = head;
    while (curr != nullptr) 
    {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

#endif