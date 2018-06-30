#include <iostream>

using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;
	node(){
		left=NULL;
		right=NULL;
	}
	node(int num){
		data = num;
		left = NULL;
		right=NULL;
	}
};



node* build(){
	

	int num;
	cin>>num;
	if(num==-1)
		return NULL;
	node* head = new node(num);
	head->left = build();
	head->right = build();
	
	return head;
}

void printIn(node* head){
	if(head==NULL)
		return;

	printIn(head->left);
	cout<<head->data<<" ";
	printIn(head->right);

	return;
}


int main(){
	cout<<"Enter numbers to be inserted in the tree"<<endl;
	node* head = build();
	printIn(head);
	

	return 0;
}
