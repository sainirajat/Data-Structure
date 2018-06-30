//task is to do the following traversal :-
// 1. Preorder
// 2. PostOrder
// 3. Inorder

#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;
	node(int num){
		data=num;
		left = NULL;
		right = NULL;
	}
};

node* build(){
	int d;
	cin>>d;
	if(d==-1)
		return NULL;
	node* n = new node(d);
	n->left = build();
	n->right = build();
	return n;
}

void printIn(node* head){
	if(head==NULL)
		return;
	printIn(head->left);
	cout<<head->data<<" ";
	printIn(head->right);
	return;
}

void printPre(node* head){
	if(head==NULL)
		return;
	cout<<head->data<<" ";
	printPre(head->left);
	printPre(head->right);
	return;
}
void printPost(node* head){
	if(head==NULL)
		return;
	printPost(head->left);
	printPost(head->right);
	cout<<head->data<<" ";
	return;
}

int main(){
	node* head = build()

	cout<<"Inorder sequence :- "<<endl;
	printIn(head);
	cout<<endl<<"PreOrder sequence :- "<<endl;
	printPre(head);
	cout<<endl<<"Postorder sequence :- "<<endl;
	printPost(head);

	return 0;
}