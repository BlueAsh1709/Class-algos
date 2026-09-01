#include <iostream>
using namespace std;
struct arrlst{
    int arr[10];
    int size;
    
    void create(int x){
        int i;
        size=x;
        for (i=0;i<x;i++){
            cout<<"Enter elements:"<<endl;
            cin>>arr[i];
        }
    }
    void insert(int index,int value){
        int i;
        for (i=size;i>=index;i--){
            arr[i+1]=arr[i];
        }
        arr[index]=value;
        size++;
    }
      void display(){
        int i;
        for (i=0;i<size;i++){
            cout<<arr[i]<<'\t';
            
        }
        cout<<endl;
    }
    void deletee(int index){
        for (int i=index;i<=size;i++){
            arr[i]=arr[i+1];
        }
        size--;

    }
    void search(int ele){
        int flag=0;
        for(int i=0;i<size;i++){
            if(arr[i]==ele){
                flag=1;
                cout<<"Found element at index="<<i-1<<endl;
                break;
            }
            
        }
        if(flag==0){
            cout<<"Not found"<<endl;
        }

    }
};
int main() {
    int key;
    arrlst a;
    int x;
        cout<<"Enter size of list till 9:";
        cin>>x;
        a.create(x); 
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
        a.insert(index_1,value_1);
        break;
        case 2:
        a.display();
        case 3:
        int i;
        cout<<"Enter index to delete:";
        cin>>i;
        a.deletee(i);
        break;
        case 4:
        cout<<"Enter element to find:"<<endl;
        int ele;
        cin>>ele;
        a.search(ele);
        break;
    }}while (key!=5);
    return 0;
}