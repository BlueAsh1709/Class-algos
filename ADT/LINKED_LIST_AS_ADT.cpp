#include <iostream>
using namespace std;
//linked list as adt
struct Node{
    int data;
    Node *next;
    Node(int d,Node *n){
        data=d;
        next=n;
    }
    Node(int d){
         data=d;
         next=nullptr;
    }
    
};

struct lst{
    Node* head;
    int no;
    void  createlst(){
        cout<<"Enter number of nodes:";
        cin>>no;
        int temp;
         cout<<"Enter the first element:";
        cin>>temp;
        Node *htemp=new Node(temp);
        head=htemp;
        Node *mover=head;
        for (int i=1;i<no;i++){
            cout<<"Enter "<<i+1<<" th element:";
            cin>>temp;
            Node *tempp=new Node(temp);
            mover->next=tempp;
            mover=tempp;               
        } 
    }
    void display(){
        Node*temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"\t";
            temp=temp-> next;
        }
    }
    void insert(int ele,int index){
        if(index==0){
            Node * temp=new Node(ele);
            temp->next=head;
            head=temp;
        }
        else{
            Node * mover =head;
            Node * temp=new Node (ele);
            for(int i=0;i<index-1;i++){
                mover=mover->next;
            }
            temp->next=mover->next;
            mover->next=temp;
        }
    }
    void del(int index){
        Node*mover=head;
        if (index==0){
            Node * target=head;
            head=head->next;
            delete(target);
        }
        else{
            for (int i=0;i<index-1;i++){
                mover=mover->next;
            }
            Node * target=mover->next;
            mover->next=(mover->next)->next;
            delete(target);
        }

    }
    void search(int ele){
        Node * mover=head;
        int flag=0;
        int i=0;
        while(mover!=nullptr){
            if(mover->data==ele){
                flag=1;
                cout<<"Found Element at index:"<<i<<endl;
                break;
            }
            i++;
            mover=mover->next;
        }
        if(flag==0){
            cout<<"Element not present. "<<endl;

        }
    }
};
int main() {
int key;
lst l;
l.createlst();
 do{
    cout<<"Menu:\nKey=1 for Insertion into list"<<'\n'<<"Key=2 to display list"<<'\n'<<"Key=3 for deletion of element"
    <<'\n'<<"Key=4 for searching of element"<<endl<<"Key=5 exit"<<endl;
  
    cout<<"Enter key for operation:"<<endl;
    cin>>key;
    switch(key){
         case 1:
       int index_1;
        int value_1;
        cout<<"Enter index and value of insertion:";
        cin>>index_1;
        cin>>value_1;
        l.insert(value_1,index_1);
        break;
        case 2:
        l.display();
        break;
        case 3:
        int index;
        cout<<"Enter element index to delete:";
        cin>>index;
        l.del(index);
        break;
        
        case 4:
        int element;
        cout<<"Enter element to search:";
        cin>>element;
        l.search(element);
        break;
        

    
}
}while(key!=5);


return 0; 
}
