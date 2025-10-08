#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

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
        int minimum(Node *node) const;
        int maximum(Node *node) const;
        int inorderSuccessor(int value, Node *node) const;
        int inorderPredecessor(int value, Node *node) const;
       // this is a completely hidden function, only used for internal node tracking
        Node* findNode(int value, Node* node) const;
        // used for candidate tracking
        Node* findpredecessorCandidate(int value, Node* node) const;
        Node* findsuccessorCandidate(int value, Node* node) const;
       // cleanup, basically destructor logic
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
        int minimum() const;
        int maximum() const;
        int inorderSuccessor(int value) const;
        int inorderPredecessor(int value) const;
};

#endif
