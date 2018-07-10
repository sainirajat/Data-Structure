#include<iostream>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;
	node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

node* build(){
	int num;
	cin>>num;
	if(num==-1)
		return NULL;
	node* n = new node(num);
	n->left = build();
	n->right = build();
	return n;
}

void printLevelOrder(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* temp = q.front();
		if(temp==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty())
				q.push(NULL);
		}
		else{
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			
		}
	}
}

node* reverse(node* root){
	if(root == NULL)
		return NULL;
	node* NewNode = new node(root->data);
	if(root->right)
		NewNode->left = reverse(root->right);
	if(root->left)
		NewNode->right = reverse(root->left);
	return NewNode;
}

int main(){
	cout<<"Enter the numbers to be inserted"<<endl;
	node* root = build();
	printLevelOrder(root);

	cout<<endl;
	node* newRoot = reverse(root);
	printLevelOrder(newRoot);

	return 0;
}