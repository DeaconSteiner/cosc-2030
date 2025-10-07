#include "binaryTree.hpp"

// Exposed methods

binaryTree::binaryTree() : root(nullptr) {}

binaryTree::~binaryTree() {
    deleteTree(root);
}

bool binaryTree::search(int value){
    // Search function implementation
    if (value == root->data) return true;
    if (value < root->data) return search(value, root->left);
    if (value > root->data) return search(value, root->right);

    return false;
}

void binaryTree::insert(int value){}

void binaryTree::remove(int value){}

// constant methods do not modify the tree
void binaryTree::inorderTraversal() const {}

void binaryTree::preorderTraversal() const {}

void binaryTree::postorderTraversal() const {}

void binaryTree::minimum() const {}

void binaryTree::maximum() const {}

void binaryTree::inorderSuccessor(int value) const {}

void binaryTree::inorderPredecessor(int value) const {}

// Helper methods

bool binaryTree::search(int value, Node *node) {
    if (node == nullptr) return false;
    if (value == node->data) return true;
    else if (value < node->data) return search(value, node->left);
    else if (value > node->data) return search(value, node->right);
    return false;
}

void binaryTree::insert(int value, Node *&node) {}

void binaryTree::remove(int val, Node *&node) {}

// constant
void binaryTree::inorderTraversal(Node *node) const {}

void binaryTree::preorderTraversal(Node *node) const {}

void binaryTree::postorderTraversal(Node *node) const {}

void binaryTree::minimum(Node *node) const {}

void binaryTree::maximum(Node *node) const {}

void binaryTree::inorderSuccessor(Node *node, int value) const {}

void binaryTree::inorderPredecessor(Node *node, int value) const {}

void binaryTree::deleteTree(Node *node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
