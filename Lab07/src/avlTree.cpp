#include "avlTree.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>

// Exposed methods
avlTree::avlTree() : root(nullptr){}

avlTree::~avlTree() {
    deleteTree(root);
}

bool avlTree::search(int value){
   return search(value, root);
}

void avlTree::insert(int value){
    if (root == nullptr) {
        root = new Node;
        root->data = value;
        root->height = 0;
        root->left = nullptr;
        root->right = nullptr;
    } else {
    insert(value, root);
    }
}

void avlTree::remove(int value){
    if (root == nullptr) return;
    remove(value, root);
}

// constant methods do not modify the tree
void avlTree::inorderTraversal() const {
    // left, root, right
    inorderTraversal(root);
}

void avlTree::preorderTraversal() const {
    // root, left, right
    preorderTraversal(root);
}

void avlTree::postorderTraversal() const {
    // left, right, root
    postorderTraversal(root);
}

int avlTree::minimum() const {
    if (root == nullptr) throw std::runtime_error("The tree is empty.");
    return minimum(root);
}

int avlTree::maximum() const {
    if (root == nullptr) throw std::runtime_error("The tree is empty.");
    return maximum(root);
}

int avlTree::inorderSuccessor(int value) const {
    if (root == nullptr) throw std::runtime_error("Tree is empty.");
    if ((root->left == nullptr) && (root->right==nullptr)) {
        throw std::runtime_error("Lone node has no successor.");
    } else {
        return inorderSuccessor(value, root);
    }
}

int avlTree::inorderPredecessor(int value) const {
    if (root == nullptr) throw std::runtime_error("Tree is empty.");
    if ((root->left == nullptr) && (root->right == nullptr)) {
        throw std::runtime_error("Lone node has no predecessor.");
    } else {
        return inorderPredecessor(value, root);
    }
}

// Helper methods

bool avlTree::search(int value, Node *node) {
    if (node == nullptr) return false;
    if (value == node->data) return true;
    else if (value < node->data) return search(value, node->left);
    else if (value > node->data) return search(value, node->right);
    return false;
}

void avlTree::insert(int value, Node *&node) {
    if (node == nullptr) {
        node = new Node;
        node->data = value;
        node->height = 0;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if (value < node->data) {
        insert(value, node->left);
    }
    else if (value >= node->data) {
        insert(value, node->right);
    }

    // update height
    node->height = computeHeight(node);

    // Perform rotations
    node = rebalance(node);
}

void avlTree::remove(int value, Node *&node) {
    if (node == nullptr) return;
    if (value < node->data) remove(value, node->left);
    else if (value > node->data) remove(value, node->right);
    else if (value == node->data) {
        if ((node->left == nullptr) && (node->right == nullptr)) {
            delete node;
            node = nullptr;
        } else if ((node->left == nullptr) ^ (node->right == nullptr)) {
            if (node->left == nullptr) {
                Node* old = node;
                node = node->right;
                delete old;
            }
            else {
             Node* old = node;
             node = node->left;
             delete old;
            }
        } else {
            int successorval = inorderSuccessor(value, root);
            node->data = successorval;
            remove(successorval, node->right);
        }
        // Make sure youre not dereferencing nullptr
        if (node != nullptr) {
            node->height = computeHeight(node);
            node = rebalance(node);
        }
    }
}

// constant methods
void avlTree::inorderTraversal(Node *node) const {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    std::cout << node->data << std::endl;
    inorderTraversal(node->right);
}

void avlTree::preorderTraversal(Node *node) const {
    if (node == nullptr) return;
    std::cout << node->data << std::endl;
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void avlTree::postorderTraversal(Node *node) const {
    if (node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << node->data << std::endl;
}

int avlTree::minimum(Node *node) const {
    if (node->left == nullptr) return node->data;
    else return minimum(node->left);
}

int avlTree::maximum(Node *node) const {
    if (node->right == nullptr) return node->data;
    else return maximum(node->right);
}

int avlTree::inorderPredecessor(int value, Node *node) const {
    if (node == nullptr) throw std::runtime_error("Value not found.");
    Node* target = findNode(value, node);
    if (target == nullptr) throw std::runtime_error("Value not found.");
    if (target->left != nullptr) return maximum(target->left);
    else {
        Node* candidate = findpredecessorCandidate(value, root);
        if (candidate == nullptr) throw std::runtime_error("No predecessor found.");
        return candidate->data;
    }
}

int avlTree::inorderSuccessor(int value, Node *node) const {
    if (node == nullptr) throw std::runtime_error("Value not found.");
    Node* target = findNode(value, node);
    if (target == nullptr) throw std::runtime_error("Value not found.");
    if (target->right != nullptr) return minimum(target->right);
    else {
        Node* candidate = findsuccessorCandidate(value, root);
        if (candidate == nullptr) throw std::runtime_error("No successor found.");
        return candidate->data;
    }
}

Node* avlTree::findNode(int value, Node *node) const {
    if (node == nullptr) return nullptr;
    if (value == node->data) return node;
    else if (value < node->data) return findNode(value, node->left);
    else if (value > node->data) return findNode(value, node->right);
    return nullptr;
}

Node* avlTree::findpredecessorCandidate(int value, Node* node) const {
    Node* candidate = nullptr;
    while (!(node == nullptr)) {
        if (node->data < value) {
            candidate = node;
            node = node->right;
        } else {node = node->left;}
    }
    return candidate;
}

Node* avlTree::findsuccessorCandidate(int value, Node* node) const {
    Node* candidate = nullptr;
    while (!(node == nullptr)) {
        if (node->data > value) {
            candidate = node;
            node = node->left;
        } else {node = node->right;}
    }
    return candidate;
}

Node* avlTree::rotateLeft(Node* node) {
    Node* x = node->right;
    Node* T2 = x->left;

    // Perform rotation
    x->left = node;
    node->right = T2;

    // Update heights
    node->height = computeHeight(node);
    x->height = computeHeight(x);

    return x;
}

Node* avlTree::rotateRight(Node* node) {
    Node* x = node->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = node;
    node->left = T2;

    // Update heights
    node->height = computeHeight(node);
    x->height = computeHeight(x);

    return x;
}

Node* avlTree::rebalance(Node* node) {
    int balance = balanceFactor(node);

    if (balance > 1) {
        if (balanceFactor(node->left) >= 1)
            return rotateRight(node); // Left-Left
        else {
            node->left = rotateLeft(node->left);
            return rotateRight(node); // Left-Right
        }
    } else if (balance < -1) {
        if (balanceFactor(node->right) <=0)
            return rotateLeft(node); // Right-Right
        else {
            node->right = rotateRight(node->right);
            return rotateLeft(node); // Right-Left
        }
    }
    return node; // Already balanced - Mostly just so the editor doesn't yell about return paths
}

int avlTree::height(Node* node) { return node ? node->height : -1; }

int avlTree::computeHeight(Node* node) { return 1 + std::max(height(node->left), height(node->right)); }

int avlTree::balanceFactor(Node* node) {
    return (height(node->left) - height(node->right));
}

void avlTree::deleteTree(Node *node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
