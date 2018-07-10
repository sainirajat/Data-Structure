#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class node{
public:
	int data;
	node *left;
	node *right;
	node(int data){
		this->data = data;
		left = NULL;
		right= NULL;		
	}
};

node* build(){
	int num;
	cin>>num;
	if(num==-1)
		return NULL;
	node* newNode = new node(num);
	newNode->left = build();
	newNode->right = build();
	return newNode;
}

void print(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* n = q.front();
		if(n==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty())
				q.push(NULL);
		}
		else{
			cout<<n->data<<" ";
			if(n->left)
				q.push(n->left);
			if(n->right)
				q.push(n->right);
			q.pop();
		}
	}
}


int main(){
	cout<<"Enter the nodes data to be inserted"<<endl;
	node* root = build();

	print(root);

	return 0;
}