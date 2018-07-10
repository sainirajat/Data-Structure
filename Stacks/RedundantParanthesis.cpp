#include<iostream>
using namespace std;

class stack{
	class node{
	public:
		char data;
		node* next;
		node(char num){
			data = num;
			next = NULL;
		}
	};
	node* head;
	// int flag;
public:
	void push(char num){
		node* newNode = new node(num);
		newNode->next = head;
		head=newNode;
	}
	void pop(){
		if(empty())
			return;
		node* temp = head;
		head = head->next;
		delete temp;
	}
	char top(){
		if(empty())
			return -1;
		return head->data;
	}
	bool empty(){
		if(head==NULL)
			return true;
		return false;
	}
	stack(){
		head=NULL;
		// flag=0;
	}
};

void findDuplicasy(char *ch ){
	stack s;
	int i=0;
	while(ch[i]!='\0'){
		if(ch[i]==')'){

			if(s.top()=='('){
				cout<<"Duplicate"<<endl;
				return;
			}
			else{
				while(s.top()!='(')
					s.pop();
				s.pop();
			}
		}
		else{
			s.push(ch[i]);
		}
		i++;
	}
	cout<<"Not Duplicate"<<endl;
	return;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		char ch[101];
		cin>>ch;
		findDuplicasy(ch);
	}
	return 0;
}








