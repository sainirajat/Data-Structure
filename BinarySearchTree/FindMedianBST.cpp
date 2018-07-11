#include<iostream>
using namespace std;
int a=0;
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

void print(node* root){
	if(root==NULL){
		return;
	}
	if(root->left)
		print(root->left);
	cout<<root->data<<" ";
	if(root->right)
		print(root->right);
	return;
}

void find(node* root,int i){
	if(i==0){
		a=root->data;
		return;
	}
	if(root->left)
		find(root->left,i);
	i--;
	if(root->right)
		find(root->right,i);
	return;
}

int main(){
	int n;
	cin>>n;

	int num;
	cin>>num;
	node* root = new node(num);
	for(int i=0;i<n-1;i++){
		cin>>num;
		root = insert(root,num);
	}

	// print(root);
	// cout<<endl;

	if((n&1)==1){
		find(root,n/2);
		cout<<a; 
	}
	else{
		find(root,n/2-1);
		int b = a;
		a=0;
		find(root,n/2);
		cout<<(a+b)/2;
	}

	return 0;
}







