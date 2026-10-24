#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};
struct BinaryTree {
    Node* root = nullptr;

    // Insert a node
    void insert(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
            return;
        }

        if (node->left == nullptr)
            insert(node->left, value);
        else if (node->right == nullptr)
            insert(node->right, value);
        else
            insert(node->left, value);
    }

    // Preorder traversal
    void preorder(Node* node) {
        if (node == nullptr) return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Inorder traversal
    void inorder(Node* node) {
        if (node == nullptr) return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Postorder traversal
    void postorder(Node* node) {
        if (node == nullptr) return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Search for a value
    bool search(Node* node, int value) {
        if (node == nullptr) return false;
        if (node->data == value) return true;

        return search(node->left, value) ||
               search(node->right, value);
    }

    // Count nodes
    int countNodes(Node* node) {
        if (node == nullptr) return 0;

        return 1 + countNodes(node->left)
                 + countNodes(node->right);
    }

    // Calculate height
    int height(Node* node) {
        if (node == nullptr) return 0;

        return 1 + max(height(node->left),
                       height(node->right));
    }
};

int main() {
    BinaryTree tree;

    tree.insert(tree.root, 1);
    tree.insert(tree.root, 2);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 4);
    tree.insert(tree.root, 5);

    cout << "Preorder: ";
    tree.preorder(tree.root);

    cout << "\nInorder: ";
    tree.inorder(tree.root);

    cout << "\nPostorder: ";
    tree.postorder(tree.root);

    cout << "\nSearch 4: "
         << (tree.search(tree.root, 4) ? "Found" : "Not Found");

    cout << "\nTotal nodes: " << tree.countNodes(tree.root);
    cout << "\nHeight: " << tree.height(tree.root);

    return 0;
}