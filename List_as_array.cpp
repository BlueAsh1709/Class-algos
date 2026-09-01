#include <iostream>
using namespace std;
void add(int *l,int x,int y){
    for(int i=4;i>=x;i--){
        l[i+1]=l[i];
    } 
    l[x]=y;
    }
void del(int *l,int x){
for (int i=x+1;i<5;i++){
    l[i-1]=l[i];
    
}
}

void search(int *l,int x){
    for(int i=0;i<6;i++){
        if(l[i]==x){
            cout<<"The element is at the index:"<<i;
            break;
        }
    }
}
int main() {
    int l[6]={10,20,30,40,50};
    int n;
    cout<<"Enter index to add element";
    cin>>n;
    int e;
    cout<<"Enter the element you want to add";
    cin>>e;
//   add(l,n,e);
//   
//   del(l,n);
//   for(int i=0;i<5;i++){
//      cout<<l[i]<<"\t";
//   }
search(l,n);
    return 0;
}