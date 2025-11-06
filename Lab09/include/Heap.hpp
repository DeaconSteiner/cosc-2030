#ifndef HEAP_HPP
#define HEAP_HPP

#define MAX_SIZE 50 // Project description specifies static array size 50

struct Heap {
    // Structure methods
    Heap();
    void display() const;
    void insert(int key);
    int getMax() const;
    void deleteMax();

    private:
        int heap[MAX_SIZE];
        int heap_size;
        void percolateUp(int index);
        void percolateDown(int index);
};

#endif
