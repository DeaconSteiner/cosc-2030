#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

struct Node {
    int data;
    Node *left, *right;
};

class binaryTree {
    private:
        Node* root;
        // private helper methods to keep API clean
        bool search(int value, Node *node);
        void insert(int value, Node *&node);
        void remove(int value, Node *&node);
        // constant methods do not modify the tree
        void inorderTraversal(Node *node) const;
        void preorderTraversal(Node *node) const;
        void postorderTraversal(Node *node) const;
        void minimum(Node *node) const;
        void maximum(Node *node) const;
        void inorderSuccessor(Node *node, int value) const;
        void inorderPredecessor(Node *node, int value) const;
        void deleteTree(Node *node);
    public:
        // Exposed methods, simplified for user interaction
        binaryTree();
        ~binaryTree();
        bool search(int value);
        void insert(int value);
        void remove(int value);
        // constant methods do not modify the tree
        void inorderTraversal() const;
        void preorderTraversal() const;
        void postorderTraversal() const;
        void minimum() const;
        void maximum() const;
        void inorderSuccessor(int value) const;
        void inorderPredecessor(int value) const;
};

#endif
