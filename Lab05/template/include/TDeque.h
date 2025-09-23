#ifndef _DOUBLE_ENDED_QUEUE_
#define _DOUBLE_ENDED_QUEUE_

#include <iostream>
#include "TDLList.h"

template <typename T>
class Deque : protected DoubleList<T>{
    private:
        int size = 0;
    public:
        Deque();
        void enqueueHead(const T& data);
        void enqueueTail(const T& data);
        void dequeueHead();
        void dequeueTail();
        bool isEmpty() const;
        const T& front() const;
        const T& back() const;
        int getSize() const;
        ~Deque();
};

template<typename T>
Deque<T>::Deque() : size(0) {}

template<typename T>
void Deque<T>::enqueueHead(const T& data) {
    this->insertHead(data);
    size++;
}

template<typename T> 
void Deque<T>::enqueueTail(const T& data) {
    this->insertTail(data);
    size++;
}

template<typename T>
void Deque<T>::dequeueHead() {
    if (!isEmpty()) {
        this->delHead();
        size--;
    } else {
        throw std::runtime_error("Queue is empty.");
    }
}

template<typename T>
void Deque<T>::dequeueTail() {
    if (!isEmpty()) {
        this->delTail();
        size--;
    } else {
        throw std::runtime_error("Queue is empty.");
    }
}

template <typename T>
bool Deque<T>::isEmpty() const { return this->DoubleList<T>::isEmpty(); }

template <typename T>
const T& Deque<T>::front() const {
    if (this->head == nullptr)
    {
        throw std::runtime_error("Queue is empty.");
    } else {
        return this->head->data;
    }
}

template <typename T>
const T& Deque<T>::back() const {
    if (this->tail == nullptr)
    {
        throw std::runtime_error("Queue is empty.");
    } else {
        return this->tail->data;
    }
    
}

template <typename T>
int Deque<T>::getSize() const { return size; }

template<typename T>
Deque<T>::~Deque() = default;

#endif