//task is to find number Kth from the last node. we will use two approach for it as well:
//1. in this one we will first find the length of the list by one iteration then in other loop we will find ans
//2. we will use fast and slow pointer

#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(){
        data=NULL;
        next=NULL;
    }
    node(int num){
        data = num;
        next = NULL;
    }
};

node* build(){
    cout<<"enter number to be inserted in the linked list"<<endl;
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

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ==> ";
        head=head->next;
    }
    cout<<endl;
    return;
}

int findKthFromLast(node* head,int k){
    int length = 0;
    node* temp = head;
    while(temp!=NULL){
        length++;
        temp = temp->next;
    }
    length = length-k;
    temp = head;
    while (length>0) {
        length--;
        temp=temp->next;
    }
    return temp->data;
}

int findKthFromLastSecond(node* head,int k){
    node* fast = head;
    node* slow = head;
    while(k>0){
        k--;
        fast = fast->next;
    }
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    return slow->data;
}

int main(){
    node* head = build();
    print(head);
    int k;
    
    //first approach
    cout<<"enter the value of k"<<endl;
    cin>>k;
    cout<<findKthFromLast(head,k)<<endl;
    
    //second approach
    cout<<findKthFromLastSecond(head,k)<<endl;
    
    return 0;
}
