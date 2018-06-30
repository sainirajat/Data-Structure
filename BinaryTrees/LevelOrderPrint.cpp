//task is to print in level order way

#include<iostream>
#include <queue>
#include <algorithm>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;
	node(int num){
		data=num;
		left=NULL;
		right=NULL;
	}
};

node* build(){
	int d;
	cin>>d;
	if(d==-1)
		return NULL;
	node* n= new node(d);
	n->left = build();
	n->right = build();
	return n;
}

void print(node* head){
	if(head==NULL)
		return;
	print(head->left);
	cout<<head->data<<" ";
	print(head->right);
	return;
}

int height(node*head){
	if(head->left==NULL&&head->right==NULL)
		return 1;

	if(head->left==NULL)
		return 1 + height(head->right);
	else if(head->right==NULL)
		return 1 + height(head->left);
	else
		return max(height(head->left),height(head->right)) + 1;
}

void printNodeAtHeight(node* head,int hgt){
	if(head==NULL||hgt<1)
		return;
	
	if(hgt==1){
		cout<<head->data<<" ";
		return;
	}
	
	printNodeAtHeight(head->left,hgt-1);
	printNodeAtHeight(head->right,hgt-1);
	return;
}





void levelOrdeOne(node* head,int hgt){
	if(head==NULL)
		return;

	while(hgt>=1){
		printNodeAtHeight(head,hgt);
		hgt--;
		cout<<endl;
	}
	return;

}

int main(){
	cout<<"Enter the numbers in the tree"<<endl;
	node* head = build();

	// print(head);

	cout<<"Level order traversal :- "<<endl;
	
	//recursive method
	int hgt = height(head);
	levelOrdeOne(head,hgt);


	return 0;
}