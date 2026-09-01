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

  
    void bubbleSort() {

    if (head == nullptr)

        return;

    Node *temp = head;

    while (temp->next != nullptr) {

        Node *mover = head;

        while (mover->next != nullptr) {

            if (mover->data > mover->next->data) {

                int value = mover->data;

                mover->data = mover->next->data;

                mover->next->data = value;

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

    l.bubbleSort();

    cout << "Sorted list: ";
    l.display();

    return 0;
}