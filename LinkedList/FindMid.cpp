// task is to find out the mid point of the linked list. we will do it with 2 techniques:-
//1. simple calculate length by 1 iteration and then go till half of it
//2. two pointer approach --fast and slow one

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
    cout<<"enter the numbers to be inserted in the linked list";
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

//first approach having 2 iteration over the array
int findMidFirst(node* head){
    if(head==NULL)
        return 0;
    int length=0;
    node* temp = head;
    while(temp!=NULL){
        length++;
        temp = temp->next;
    }
    temp = head;
    int counter = length/2;
    while(counter>0){
        temp=temp->next;
        counter--;
    }
    
    return temp->data;
}

//using second approach only 1 iteration needed
int findMidSecond(node* head){
    node* slow = head;
    node* fast = head;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}


int main(){
    
    node* head = build();
    print(head);
    
    //using first approach (slower one)
    cout<<endl<<findMidFirst(head)<<endl;
    
    //using second approach (faster one)
    cout<<findMidSecond(head)<<endl;
    return 0;
}
















