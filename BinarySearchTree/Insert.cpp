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

node* insert(node* root,int num){
	if(root->left==NULL && num<root->data){
		node* newNode = new node(num);
		root->left = newNode;
		return root;
	}
	if(root->right==NULL && num>root->data){
		node* newNode = new node(num);
		root->right = newNode;
		return root;
	}
	if(num<root->data){
		root->left = insert(root->left,num);
	}
	else
		root->right = insert(root->right,num);
	return root;
}

node* build(){
	int num;
	cin>>num;
	node* root = new node(num);
	cin>>num;
	while(num!=-1){
		insert(root,num);
		cin>>num;
	}
	return root;

}

void print(node* root){
	if(root==NULL)
		return;
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* temp = q.front();
		if(temp==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			q.pop();
		}
	}
	return;
}

int main(){

	cout<<"insert the numbers"<<endl;
	node* root = build();

	cout<<"inserted"<<endl;
	print(root);

	return 0;
}