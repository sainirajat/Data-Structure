#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

void print(node* head){
	while(head->next!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	return;
}

node* merge(node* head1,node* head2){
	//recurssive 
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;

	node* head;
	if(head1->data < head2->data){
		head=head1;
		head->next = merge(head1->next,head2);
	}
	else{
		head=head2;
		head->next = merge(head1,head2->next);
	}

	return head;
}

int main(){
	int arr[] = {2,4,6,8,10,12};

	node* head1 = new node(arr[0]);
	node* temp = head1;

	for(int i=1;i<=6;i++){
		node* newNode = new node(arr[i]);
		temp->next = newNode;
		temp=temp->next;
	}
	print(head1);
	cout<<endl;

	int arr2[] = {1,3,5,7,9,11};
	node* head2 = new node(arr2[0]);
	node* temp2 = head2;

	for(int i=1;i<=6;i++){
		node* newNode = new node(arr2[i]);
		temp2->next = newNode;
		temp2=temp2->next;
	}
	print(head2);
	cout<<endl;


	node* head = merge(head1,head2);
	print(head);

	return 0;
}




