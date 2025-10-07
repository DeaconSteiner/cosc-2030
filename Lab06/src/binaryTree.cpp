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

// Helper methods

bool binaryTree::search(int value, Node *node) {
    if (node == nullptr) return false;
    if (value == node->data) return true;
    else if (value < node->data) return search(value, node->left);
    else if (value > node->data) return search(value, node->right);
    return false;
}

void binaryTree::insert(int value, Node *node) {
    
}

void binaryTree::deleteTree(Node *node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
