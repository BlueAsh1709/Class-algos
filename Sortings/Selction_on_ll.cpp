#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

struct lst {
    Node *head;

    lst() {
        head = nullptr;
    }

    void createList() {
        int no;
        cout << "Enter number of nodes: ";
        cin >> no;

        if (no <= 0)
            return;

        int temp;

        cout << "Enter element 1: ";
        cin >> temp;

        head = new Node(temp);
        Node *mover = head;

        for (int i = 1; i < no; i++) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> temp;

            Node *tempp = new Node(temp);
            mover->next = tempp;
            mover = tempp;
        }
    }

    void display() {
        Node *temp = head;

        while (temp != nullptr) {
            cout << temp->data << "\t";
            temp = temp->next;
        }

        cout << endl;
    }

   void selectionSort() {
    Node *temp = head;
    while (temp != nullptr) {
        Node *mover = temp->next;
        while (mover != nullptr) {
            if (temp->data > mover->data) {
                int swap = temp->data;
                temp->data = mover->data;
                mover->data = swap;
            }
            mover = mover->next;
        }
        temp = temp->next;
    }

}
};

int main() {

    lst l;

    l.createList();

    cout << "Original list: ";
    l.display();

    l.selectionSort();

    cout << "Sorted list: ";
    l.display();

    return 0;
}