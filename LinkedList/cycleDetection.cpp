#include<iostream>

using namespace std;

class node{
public:
	int data;
	node* next;
	node(int data){
		this->data = data;
		next= NULL;
	}
};
node* build(){
	cout<<"enter the numbers for the linked list please"<<endl;
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
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
	return;
}

bool checkCycle(node* head){
	if(head==NULL)
		return false;

	node* slow = head;
	node* fast = head;

	while(fast->next!=NULL && fast!=NULL && slow){
		slow=slow->next;
		fast=fast->next->next;
		
		if(fast->next==NULL){
			return true;
		}
	}
	
	return false;
}

int main(){
	node* head = build();
	print(head);

	bool cycleHaiKya = checkCycle(head);
	if(cycleHaiKya)
		cout<<"cycle present";
	else
		cout<<"NO cycle "<<endl;


	head->next->next->next->next = head->next;
	bool cycleCheck = checkCycle(head);
	if(cycleCheck)
		cout<<"cycle present";
	else
		cout<<"NO cycle "<<endl;
	return 0;
}






