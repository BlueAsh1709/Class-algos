//Stack as ADT using array
#include <iostream>
using namespace std;
#define max 10
struct Stack{
    int arr[max];
    int top= -1;
    void push(int x){           //Input the data
        if(top==max-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    int pop(){                  //Deleting topmost element
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        int x = arr[top];
        top--;
        return x;
    }
    int peek(){                //returns topmost element
         if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){            //check if the stack is empty
        return top== -1;
    }    
    bool isFull(){              //check if the stack is full
        return top== max-1;
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