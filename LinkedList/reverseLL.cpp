//task is to reverse a linked list using following approaches:
//1. recursive
//2. iterative

#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(){
        data = NULL;
        next = NULL;
    }
    node(int n){
        data = n;
        next = NULL;
    }
};

node* build(){
    int num;
    cin>>num;
    node* head = new node(num);
    node* temp = head;
    while(num!=-1){
        cin>>num;
        if(num!=-1){
            node* newNode = new node(num);
            temp->next = newNode;
            temp=temp->next;
        }
    }
    return head;
}

void printLL(node* head){
    while(head!=NULL){
        cout<<head->data<<" ==> ";
        head=head->next;
    }
    cout<<endl;
}

node* ReverseLLRecursive(node* head){
    if(head->next==NULL)
        return head;
    node* smallHead = ReverseLLRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}

node* iterativeReverse(node* head){
    node* temp = head->next;
    head->next = NULL;
    node* prev = head;
    head = temp;
    while(head!=NULL){
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
    
}

int main(){
    cout<<"enter the number to be inserted in the linked list"<<endl;
    node* head = build();
    printLL(head);
    
    //recursive
    head = ReverseLLRecursive(head);
    printLL(head);
    
    //iterative
    head = iterativeReverse(head);
    printLL(head);
    
    return 0;
}
