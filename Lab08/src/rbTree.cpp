#include "rbTree.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>

// Exposed methods
rbTree::rbTree() : root(nullptr) {}

rbTree::~rbTree() {
    deleteTree(root);
}

bool rbTree::search(int value) {
    return search(value, root);
}

void rbTree::insert(int value) {
    if (root == nullptr) {
        root = new Node;
        root->data = value;
        root->color = BLACK;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        insert(value, root);
    }
}

void rbTree::remove(int value) {
    if (root == nullptr) return;
    remove(value, root);
}

// constant methods do not modify the tree