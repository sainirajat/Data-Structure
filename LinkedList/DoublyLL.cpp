//to build a doubly linked list and do the following operations :-
//1. insert
//2. delete

#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;
    node(){
        data= NULL;
        next= NULL;
        prev =NULL;
    }
    node(int num){
        data= num;
        next = NULL;
        prev = NULL;
    }
};

node* build(){
    cout<<"enter the numbers to be inserted in the linked list"<<endl;
    int num;
    cin>>num;
    
}

int main(){
    node* head = build();
    
    
    
    
    return 0;
}
