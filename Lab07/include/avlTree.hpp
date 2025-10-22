#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

struct Node {
    int data;
    int height;
    Node *left, *right;
};

class avlTree {
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
        // avl logic - rotations - other cases can just use these too
        Node* rotateLeft(Node* node);
        Node* rotateRight(Node* node);
        Node* rebalance(Node* node);
        // other avl stuff
        int height(Node* node);
        int computeHeight(Node* node);
        int balanceFactor(Node* node);
       // cleanup, basically destructor logic
        void deleteTree(Node *node);
    public:
        // Exposed methods, simplified for user interaction
        avlTree();
        ~avlTree();
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
