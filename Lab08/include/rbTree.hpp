#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

enum Color {RED, BLACK};

struct Node {
    int data;
    Node *left, *right, *parent;
    Color color;
};

class rbTree {
    private:
        Node* root;
        // private helper methods to keep API clean
        bool search(int value, Node* node);
        void insert(int value, Node*& node, Node* parent);
        // constant methods do not modify the tree
        void inorderTraversal(Node* node) const;
        void preorderTraversal(Node* node) const;
        void postorderTraversal(Node* node) const;
        int minimum(Node* node) const;
        int maximum(Node* node) const;
        int inorderSuccessor(int value, Node* node) const;
        int inorderPredecessor(int value, Node* node) const;
       // this is a completely hidden function, only used for internal node tracking
        Node* findNode(int value, Node* node) const;
        // used for candidate tracking
        Node* findpredecessorCandidate(int value, Node* node) const;
        Node* findsuccessorCandidate(int value, Node* node) const;
        // rb logic - rotations - other cases can just use these too
        Node* rotateLeft(Node* node);
        Node* rotateRight(Node* node);
        Node* fixInsert(Node* node);
       // cleanup, basically destructor logic
        void deleteTree(Node* node);
    public:
        // Exposed methods, simplified for user interaction
        rbTree();
        ~rbTree();
        bool search(int value);
        void insert(int value);
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
