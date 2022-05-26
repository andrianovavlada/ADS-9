// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
private: 
    struct Node {
        T value;
        int count;
        Node *left;
        Node *right;
    };

    Node *root;
    Node *addNode(Node *root, const T& data) {
        if (root == nullptr) {
            root = new Node;
            root->value = data;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (data < root->value) {
            root->left = addNode(root->left, data);
        } else if (data > root->value) {
            root->right = addNode(root->right, data);
        } else {
            root->count++;
        }
        return root;
    }

    int searchNode(Node* root, const T& data) {
        if (root == nullptr) {
            return 0;
        } else if (root->value == data) {
            return root->count;
        } else if (root->value > data) {
            return searchNode(root->left, data);
        } else {
            return searchNode(root->right, data);
        }
    }
    int heightTree(Node *root) {
        if (root == nullptr) {
            return 0;
        } else {
           int L = heightTree(root->left);
           int R = heightTree(root->right);
        }
        int L, R;
        if (L > R) {
            return L + 1;
        } else {
            return R + 1;
        }
    }

public: 
    BST() :root(nullptr) {}
    void add(const T& data) {
        root = addNode(root, data);
    }
    int search(const T& data) {
        return searchNode(root, data);
    }
    int height() {
        return heightTree(root) - 1;
    }
};
#endif  // INCLUDE_BST_H_
