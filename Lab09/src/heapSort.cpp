#include "Heap.hpp"
#include "heapSort.hpp"

void heapSort(int arr[], int n) {
    Heap h;

    // Heapify
    for (int i = 0; i < n; i++) {
        h.insert(arr[i]);
    }

    // Sort
    for (int i = n - 1; i >= 0; --i) {
        arr[i] = h.getMax();
        h.deleteMax();
    }
}
