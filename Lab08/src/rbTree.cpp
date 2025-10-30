#include "rbTree.hpp"
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
        root->parent = nullptr;
    } else {
        insert(value, root, nullptr);
    }
}

// constant methods do not modify the tree
void rbTree::inorderTraversal() const {
    // left, root, right
    inorderTraversal(root);
}

void rbTree::preorderTraversal() const {
    // root, left, right
    preorderTraversal(root);
}

void rbTree::postorderTraversal() const {
    // left, right, root
    postorderTraversal(root);
}

int rbTree::minimum() const {
    if (root == nullptr) throw std::runtime_error("The tree is empty.");
    return minimum(root);
}

int rbTree::maximum() const {
    if (root == nullptr) throw std::runtime_error("The tree is empty.");
    return maximum(root);
}

int rbTree::inorderSuccessor(int value) const {
    if (root == nullptr) throw std::runtime_error("Tree is empty.");
    if ((root->left == nullptr) && (root->right==nullptr)) {
        throw std::runtime_error("Lone node has no successor.");
    } else {
        return inorderSuccessor(value, root);
    }
}

int rbTree::inorderPredecessor(int value) const {
    if (root == nullptr) throw std::runtime_error("Tree is empty.");
    if ((root->left == nullptr) && (root->right == nullptr)) {
        throw std::runtime_error("Lone node has no predecessor.");
    } else {
        return inorderPredecessor(value, root);
    }
}

// helper methods
bool rbTree::search(int value, Node* node) {
    if (node == nullptr) return false;
    if(value == node->data) return true;
    else if (value < node->data) return search(value, node->left);
    else if (value > node->data) return search(value, node->right);
    return false;
}

void rbTree::insert(int value, Node*& node, Node* parent) {
    if (node == nullptr) {
        node = new Node;
        node->data = value;
        node->color = RED;
        node->left = nullptr;
        node->right = nullptr;
        node->parent = parent;

        fixInsert(node); // fix newly created nodes
    } else if (value < node->data) {
        insert(value, node->left, node);
    } else if (value >= node->data) {
        insert(value, node->right, node);
    }
}

// constant methods
void rbTree::inorderTraversal(Node* node) const {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    std::cout << node->data << (node->color == RED ? "R" : "B") << std::endl;
    inorderTraversal(node->right);
}

void rbTree::preorderTraversal(Node* node) const {
    if (node == nullptr) return;
    std::cout << node->data << (node->color == RED ? "R" : "B") << std::endl;
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void rbTree::postorderTraversal(Node* node) const {
    if (node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << node->data << (node->color == RED ? "R" : "B") << std::endl;
}

int rbTree::minimum(Node* node) const {
    if (node->left == nullptr) return node->data;
    else return minimum(node->left);
}

int rbTree::maximum(Node *node) const {
    if (node->right == nullptr) return node->data;
    else return maximum(node->right);
}

int rbTree::inorderPredecessor(int value, Node* node) const {
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

int rbTree::inorderSuccessor(int value, Node* node) const {
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

Node* rbTree::findNode(int value, Node* node) const {
    if (node == nullptr) return nullptr;
    if (value == node->data) return node;
    else if (value < node->data) return findNode(value, node->left);
    else if (value > node->data) return findNode(value, node->right);
    return nullptr;
}

Node* rbTree::findpredecessorCandidate(int value, Node* node) const {
    Node* candidate = nullptr;
    while (!(node == nullptr)) {
        if (node->data < value) {
            candidate = node;
            node = node->right;
        } else {node = node->left;}
    }
    return candidate;
}

Node* rbTree::findsuccessorCandidate(int value, Node* node) const {
    Node* candidate = nullptr;
    while (!(node == nullptr)) {
        if (node->data > value) {
            candidate = node;
            node = node->left;
        } else {node = node->right;}
    }
    return candidate;
}

Node* rbTree::rotateLeft(Node* node) {
    Node* x = node->right;
    Node* T2 = x->left;

    // perform rotation
    x->left = node;
    node->right = T2;

    // update parents
    x->parent = node->parent;
    node->parent = x;
    if (T2) { T2->parent = node; }

    if (x->parent) {
        if (x->parent->left == node) x->parent->left = x;
        else x->parent->right = x;
    }

    return x;
}

Node* rbTree::rotateRight(Node* node) {
    Node* x = node->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = node;
    node->left = T2;

    // update parents
    x->parent = node->parent;
    node->parent = x;
    if (T2) { T2->parent = node; }

    if (x->parent) {
        if (x->parent->left == node) x->parent->left = x;
        else x->parent->right = x;
        }

    return x;
}

Node* rbTree::fixInsert(Node* node) {
    Node* parent = nullptr;
    Node* grandparent = nullptr;

    while (node != root && node->parent->color == RED) {
        parent = node->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;

            // case 1
             if (uncle != nullptr && uncle->color == RED) {
                 parent->color = BLACK;
                     uncle->color = BLACK;
                     grandparent->color = RED;
                     node = grandparent; // move up the tree
             } else if ( uncle == nullptr || uncle->color == BLACK) {
                 // case 2
                 if (node == parent->right) {
                     node = parent;
                     grandparent->left = rotateLeft(node);
                     parent = node->parent;
                 }

                 // case 3
                 parent->color = BLACK;
                 grandparent->color = RED;
                 if (grandparent == root)
                     root = rotateRight(grandparent);
                 else
                     rotateRight(grandparent);
             }
        } else {
            Node* uncle = grandparent->left;

            //case 1
             if (uncle != nullptr && uncle->color == RED) {
                 parent->color = BLACK;
                 uncle->color = BLACK;
                 grandparent->color = RED;
                 node = grandparent; // move up the tree
             } else {
                // case 2
                if (node == parent->left) {
                    node = parent;
                    grandparent->right = rotateRight(node);
                    parent = node->parent;
                }

                // case 3
                parent->color = BLACK;
                grandparent->color = RED;
                if (grandparent == root)
                    root = rotateLeft(grandparent);
                else
                    rotateLeft(grandparent);
             }
        }
    }

    root->color = BLACK;
    return root;
}

void rbTree::deleteTree(Node* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
