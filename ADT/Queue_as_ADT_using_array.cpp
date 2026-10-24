//Queue As ADT using array
#include <iostream>
using namespace std;

const int MAX = 10;

struct Queue {
    int arr[MAX];
    int front = 0;
    int rear = -1;

    bool isEmpty() {
        return rear < front;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }

        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        return arr[front++];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return arr[front];
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.peek() << endl;
    cout << "Removed: " << q.dequeue() << endl;
    cout << "Front element: " << q.peek() << endl;
    return 0;
}