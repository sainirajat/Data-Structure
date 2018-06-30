// task is to insert a node at
//1. head
//2. in the given position


#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(){
        data = NULL;
    }
    node(int num){
        data = num;
    }
};

node* insertAtHead(node* head,int data){
    node* newNode = new node(data);
    newNode->next = head;
    return newNode;
}

node* insertNode(node* head,int data,int pos){
    if(pos==1)
        return insertAtHead(head,data);
    node* temp = head;
    node* newNode = new node(data);
    while(pos>2){
        temp = temp->next;
        pos--;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
    
}

void printLinkedList(node* head){
    while(head!=NULL){
        cout<<head->data<<" -->  ";
        head = head->next;
    }
    cout<<endl;
    return;
}

int main(){
    cout<<"Enter the number to be inserted at the head "<<endl;
    int num;
    cin>>num;
    node* head = insertAtHead(NULL,num);
    cout<<"Insert the number to be inserted and the position where to be inserted"<<endl;
    int pos;
    cin>>num>>pos;
    while(num!=-1){
        head = insertNode(head,num,pos);
        cin>>num>>pos;
    }
    printLinkedList(head);
    
    return 0;
}
