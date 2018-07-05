#include<iostream>
using namespace std;

class queue
{
	class node{
	public:
		int data;
		node* next;
		node(int num){
			data = num;
			next = NULL;
		}
	};

	node* head;
	node* tail;
	int len;
public:
	void enqueue(int x){
		node* newNode = new node(x);
		if(isEmpty()){
			head = newNode;
			tail = newNode;
			len++;
			return;
		}
		tail->next = newNode;
		tail = tail->next;
		len++;
		return;
	}

	void dequeue(){
		if(len==1){
			delete head;
			head=NULL;
			tail = NULL;
			len=0;
			return;
		}
		node* temp = head;
		head=head->next;
		delete temp;
		len--;
		return;
	}
	int front(){
		if(isEmpty())
			return -1;
		return head->data;
	}
	bool isEmpty(){
		return head==NULL;
	}

	int size(){
		return len;
	}
	queue(){
		head = NULL;
		tail = NULL;
		len = 0;
	}
	~queue(){
		while(head){
			node* ahead = head->next;
			delete head;
			head= ahead;
		}
	}
	
};


int main(){
	queue q;
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.dequeue();
	q.dequeue();
	cout<<q.front();
	q.dequeue();
	q.enqueue(7);
	cout<<q.front();


	return 0;
}