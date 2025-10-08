#include "binaryTree.hpp"
#include <iostream>
#include <stdexcept>

// Exposed methods
binaryTree::binaryTree() : root(nullptr){}

binaryTree::~binaryTree() {
    deleteTree(root);
}

bool binaryTree::search(int value){
   return search(value, root);
}

void binaryTree::insert(int value){
    if (root == nullptr) {
        root = new Node;
        root->data = value;
        root->left = nullptr;
        root->right = nullptr;
    } else {
    insert(value, root);
    }
}

void binaryTree::remove(int value){
    if (root == nullptr) return;
    remove(value, root);
}

// constant methods do not modify the tree
void binaryTree::inorderTraversal() const {
    // left, root, right
    inorderTraversal(root);
}

void binaryTree::preorderTraversal() const {
    // root, left, right
    preorderTraversal(root);
}

void binaryTree::postorderTraversal() const {
    // left, right, root
    postorderTraversal(root);
}

int binaryTree::minimum() const {
    if (root == nullptr) throw std::runtime_error("The tree is empty.");
    return minimum(root);
}

int binaryTree::maximum() const {
    if (root == nullptr) throw std::runtime_error("The tree is empty.");
    return maximum(root);
}

int binaryTree::inorderSuccessor(int value) const {
    if (root == nullptr) throw std::runtime_error("Tree is empty.");
    if ((root->left == nullptr) && (root->right==nullptr)) {
        throw std::runtime_error("Lone node has no successor.");
    } else {
        return inorderSuccessor(value, root);
    }
}

int binaryTree::inorderPredecessor(int value) const {
    if (root == nullptr) throw std::runtime_error("Tree is empty.");
    if ((root->left == nullptr) && (root->right == nullptr)) {
        throw std::runtime_error("Lone node has no predecessor.");
    } else {
        return inorderPredecessor(value, root);
    }
}

// Helper methods

bool binaryTree::search(int value, Node *node) {
    if (node == nullptr) return false;
    if (value == node->data) return true;
    else if (value < node->data) return search(value, node->left);
    else if (value > node->data) return search(value, node->right);
    return false;
}

void binaryTree::insert(int value, Node *&node) {
    if (node == nullptr) {
        node = new Node;
        node->data = value;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if (value < node->data) insert(value, node->left);
    else if (value >= node->data) insert(value, node->right);
}

void binaryTree::remove(int value, Node *&node) {
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
    }
}

// constant methods
void binaryTree::inorderTraversal(Node *node) const {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    std::cout << node->data << std::endl;
    inorderTraversal(node->right);
}

void binaryTree::preorderTraversal(Node *node) const {
    if (node == nullptr) return;
    std::cout << node->data << std::endl;
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void binaryTree::postorderTraversal(Node *node) const {
    if (node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << node->data << std::endl;
}

int binaryTree::minimum(Node *node) const {
    if (node->left == nullptr) return node->data;
    else return minimum(node->left);
}

int binaryTree::maximum(Node *node) const {
    if (node->right == nullptr) return node->data;
    else return maximum(node->right);
}

int binaryTree::inorderPredecessor(int value, Node *node) const {
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

int binaryTree::inorderSuccessor(int value, Node *node) const {
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

Node* binaryTree::findNode(int value, Node *node) const {
    if (node == nullptr) return nullptr;
    if (value == node->data) return node;
    else if (value < node->data) return findNode(value, node->left);
    else if (value > node->data) return findNode(value, node->right);
    return nullptr;
}

Node* binaryTree::findpredecessorCandidate(int value, Node* node) const {
    Node* candidate = nullptr;
    while (!(node == nullptr)) {
        if (node->data < value) {
            candidate = node;
            node = node->right;
        } else {node = node->left;}
    }
    return candidate;
}

Node* binaryTree::findsuccessorCandidate(int value, Node* node) const {
    Node* candidate = nullptr;
    while (!(node == nullptr)) {
        if (node->data > value) {
            candidate = node;
            node = node->left;
        } else {node = node->right;}
    }
    return candidate;
}

void binaryTree::deleteTree(Node *node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
