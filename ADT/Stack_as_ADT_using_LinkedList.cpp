//Stack as adt using linked list
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
struct Stack{
    Node * top=nullptr;
    
    void push(int x) {
    Node* temp = new Node(x);
    temp->next = top;
    top = temp;
}
    void pop(){
    Node * temp=top;
    if(top==nullptr){
        cout<<"Stack Underflow"<<endl;
        return ;
    }
    top=top->next;
    delete temp;
    }
    int peek(){
        if(top==nullptr){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    return top->data;
    }
    bool isEmpty(){
        return top==nullptr;
    }

};
int main() {
    Stack s;
    s.push(17);
    s.push(29);
    s.push(3);
    s.push(8);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.isEmpty();

    return 0;
}