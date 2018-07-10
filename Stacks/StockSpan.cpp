// problem statement at >> https://hack.codingblocks.com/contests/c/471/404
#include<iostream>
using namespace std;

class queue{
	class node{
	public:
		int data;
		node* next;
		node(int data){
			this->data = data;
			next = NULL;
		}
	};
	node* head;
	int count;
public:
	void push(int num){
		node* newNode = new node(num);
		newNode->next = head;
		head = newNode;
		if(head->next!=NULL){
			if(num>=(head->next->data))
				count++;
			else
				count=1;
		}
		else{
			count = 1;
		}
		return;
	}
	int findCount(){
		return count;
	}
	queue(){
		head = NULL;
		count=0;
	}
};


int main(){
	int n;
	cin>>n;
	queue q;
	int arr[n];
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		q.push(num);
		arr[i] = q.findCount();
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"END";

	return 0;
}