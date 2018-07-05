#include<iostream>
using namespace std;

class Stack{
	class node{
	public:
		int data;
		node* next;
		node(){
			next=NULL;
		}
		node(int num){
			data=num;
			next=NULL;
		}
	};
	node* head;
	int size;
public:
	void push(int num){
		node* newNode = new node(num);
		newNode->next = head;
		head = newNode;
		size++;
		return;
	}
	void pop(){
		if(isEmpty(head))
			return;
		node* temp = head;
		head = head->next;
		delete(temp);
		size--;
		return;
	}
	int atTop(){
		if(isEmpty(head))
			return -1;
		return head->data;
	}

	bool isEmpty(){
		return head==NULL;
	}

	int findSize(){
		return size;
	}
	Stack(){
		head = NULL;
		size=0;
	}

	~Stack(){
		while(head){
			node* ahead = head->next;
			delete head;
			head = ahead;
		}
	}

};


int main(){
	Stack Stack1;
	Stack1.push(1);
	cout<<Stack1.atTop();
	Stack1.push(2);
	cout<<Stack1.atTop();
	Stack1.push(3);
	cout<<Stack1.atTop();
	Stack1.push(4);
	cout<<Stack1.atTop();
	Stack1.push(5);
	cout<<Stack1.atTop();
	Stack1.pop();
	Stack1.pop();
	cout<<Stack1.atTop();
	Stack1.pop();
	Stack1.pop();
	cout<<Stack1.atTop();


	return 0;
}