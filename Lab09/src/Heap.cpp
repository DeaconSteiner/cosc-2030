#include <iostream>
#include <stdexcept>
#include <utility>
#include "Heap.hpp"

// Public methods
Heap::Heap() : heap_size(0) {}

void Heap::display() const {
    for (int i = 0; i < heap_size; i++) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}

void Heap::insert(int key) {
    heap[heap_size] = key;
    heap_size++;

    percolateUp(heap_size - 1);
}

int Heap::getMax() const {
    return heap[0];
}

void Heap::deleteMax() {
    if (heap_size == 0) {
        std::runtime_error("Cannot delete from an empty heap!");
    } else {
        heap[0] = heap[heap_size - 1];
        heap_size--;
        percolateDown(0);
    }
}

// private methods
void Heap::percolateUp(int index) {
    while ( index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            std::swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void Heap::percolateDown(int index) {
    while (2*index + 1 < heap_size) {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int largest = index;

        if (left < heap_size && heap[left] > heap[largest])
            largest = left;
        if (right < heap_size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}
