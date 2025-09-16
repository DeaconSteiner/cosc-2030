#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoubleList {
    private:
        Node* head;
        Node* tail;

    public:
        DoubleList();
        void insertHead(Node*);
        void insertTail(Node*);
        void delHead();
        void delTail();
        void traverse() const;
        ~DoubleList();
};

#endif