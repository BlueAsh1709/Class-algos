#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        height = 1;
        left = right = nullptr;
    }
};
struct AVLTree {
    Node* root = nullptr;

    // Get height of a node
    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    // Calculate balance factor
    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* temp = x->right;

        x->right = y;
        y->left = temp;

        y->height = 1 + max(getHeight(y->left),
                            getHeight(y->right));
        x->height = 1 + max(getHeight(x->left),
                            getHeight(x->right));

        return x;
    }

    // Left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* temp = y->left;

        y->left = x;
        x->right = temp;

        x->height = 1 + max(getHeight(x->left),
                            getHeight(x->right));
        y->height = 1 + max(getHeight(y->left),
                            getHeight(y->right));

        return y;
    }

    // Insert a value and balance the tree
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node;  // Ignore duplicates

        node->height = 1 + max(getHeight(node->left),
                               getHeight(node->right));

        int balance = getBalance(node);

        // LL Case
        if (balance > 1 && value < node->left->data)
            return rightRotate(node);

        // RR Case
        if (balance < -1 && value > node->right->data)
            return leftRotate(node);

        // LR Case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL Case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Find the smallest node
    Node* findMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;

        return node;
    }

    // Delete a value and rebalance the tree
    Node* remove(Node* node, int value) {
        if (node == nullptr)
            return nullptr;

        if (value < node->data)
            node->left = remove(node->left, value);
        else if (value > node->data)
            node->right = remove(node->right, value);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ? node->left : node->right;
                delete node;
                node = temp;
            }
            else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }

        if (node == nullptr)
            return nullptr;

        node->height = 1 + max(getHeight(node->left),
                               getHeight(node->right));

        int balance = getBalance(node);

        // LL Case
        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);

        // LR Case
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RR Case
        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);

        // RL Case
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Search for a value
    bool search(Node* node, int value) {
        if (node == nullptr)
            return false;

        if (node->data == value)
            return true;

        if (value < node->data)
            return search(node->left, value);

        return search(node->right, value);
    }

    // Inorder traversal
    void inorder(Node* node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    AVLTree tree;

    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 25);
    tree.root = tree.insert(tree.root, 40);

    cout << "Inorder: ";
    tree.inorder(tree.root);

    cout << "\nSearch 25: "
         << (tree.search(tree.root, 25) ? "Found" : "Not Found");

    tree.root = tree.remove(tree.root, 20);

    cout << "\nAfter deletion: ";
    tree.inorder(tree.root);

    return 0;
}