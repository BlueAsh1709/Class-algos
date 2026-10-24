//Queue as ADT using linked list
#include <iostream>
using namespace std;
struct Node{                            
    int data;
    Node * next;
    Node(){
        next=nullptr;
    }
    Node(int value){
        data=value;
        next=nullptr;
    }
};
struct Queue{
    Node * front=nullptr;
    Node * rear=nullptr;

    void enqueue(int x){
    Node *temp=new Node(x);
    if(front==nullptr){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
    }
    void dequeue(){
        if (front==nullptr){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        Node * temp=front;
        front=front->next;
        delete temp;
    }
    bool isEmpty(){
        return front==nullptr;
    }
    int peek(){
        if (front==nullptr){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        return front->data;
    }
};

using namespace std;
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.peek() << endl;
    q.dequeue();
    cout << "Front element: " << q.peek() << endl;
    return 0;
}