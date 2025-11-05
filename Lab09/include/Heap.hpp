#ifndef HEAP_HPP
#define HEAP_HPP

#define MAX_SIZE 50 // Project discription specifies static array size 50

struct Heap {
    // Initial values
    int heap[MAX_SIZE]; // Project discription specifies static array size 50
    int heap_size;

    // Structure methods
    Heap();
    void display() const;
    void insert(int key);
    int getMax() const;
    void deleteMax();

    private:
        void percolateUp(int index);
        void percolateDown(int index);
};

#endif
