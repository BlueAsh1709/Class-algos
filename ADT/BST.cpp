#include <iostream>
using namespace std;
// Structure representing a BST node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};
// Binary Search Tree ADT
struct BST {
    Node* root = nullptr;

    // Insert a value into the BST
    Node* insert(Node* node, int value) {
        // Create a new node if the position is empty
        if (node == nullptr)
            return new Node(value);

        // Smaller values go to the left
        if (value < node->data)
            node->left = insert(node->left, value);

        // Greater values go to the right
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    // Search for a value in the BST
    bool search(Node* node, int value) {
        if (node == nullptr)
            return false;

        if (node->data == value)
            return true;

        // Search the appropriate subtree
        if (value < node->data)
            return search(node->left, value);

        return search(node->right, value);
    }

    // Find the minimum value in a subtree
    Node* findMin(Node* node) {
        while (node != nullptr && node->left != nullptr)
            node = node->left;

        return node;
    }

    // Delete a value from the BST
    Node* remove(Node* node, int value) {
        if (node == nullptr)
            return nullptr;

        // Search in the left subtree
        if (value < node->data)
            node->left = remove(node->left, value);

        // Search in the right subtree
        else if (value > node->data)
            node->right = remove(node->right, value);

        else {
            // Case 1: No left child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            // Case 2: No right child
            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            // Replace with the minimum value in the right subtree
            Node* temp = findMin(node->right);
            node->data = temp->data;

            // Delete the duplicate successor node
            node->right = remove(node->right, temp->data);
        }

        return node;
    }

    // Inorder traversal: Left -> Root -> Right
    void inorder(Node* node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    //preorder traversal:Root ->Left-> Right
    void preorder(Node * node){
        if (node == nullptr)
        return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    //postorder traversal:Left->Right->Root
    void postorder(Node * node){
        if (node == nullptr)
        return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};

int main() {
    BST tree;

    // Insert values
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 70);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 60);
    tree.root = tree.insert(tree.root, 80);

    cout << "Inorder: ";
    tree.inorder(tree.root);
    cout << endl;
    tree.preorder(tree.root);
    cout << endl;
    tree.postorder(tree.root);
    cout << endl;

    // Search for a value
    int value = 40;

    if (tree.search(tree.root, value))
        cout << value << " found." << endl;
    else
        cout << value << " not found." << endl;

    // Delete a value
    tree.root = tree.remove(tree.root, 30);

    cout << "After deletion: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}