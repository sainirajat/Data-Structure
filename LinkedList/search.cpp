//task is to search for a numbe in the linked list so we have to
//1. write a build function to make a linked list then
//2. search for the given number in the linked list

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
    node(int num){
        data = num;
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
            temp = temp->next;
        }
    }
    return head;
}

void printLL(node* head){
    while(head!=NULL){
        cout<<head->data<<" ==> ";
        head = head->next;
    }
    cout<<endl;
}

int search(node* head,int num){
    if(head==NULL)
        return -1;
    int count = 1;
    while(head!=NULL){
        if(head->data==num)
            return count;
        else{
            count++;
            head=head->next;
        }
    }
    return -1;
}


int main(){
    cout<<"give the numbers to be inserted in the linked list"<<endl;
    node* head = build();
    printLL(head);
    cout<<"Enter the number to be searched"<<endl;
    int n;
    cin>>n;
    cout<<search(head,n);
    
    return 0;
}
