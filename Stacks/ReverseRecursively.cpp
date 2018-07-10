#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q ){
	stack<int> s;
	while(!q.empty()){
		int temp = q.front();
		s.push(temp);
		q.pop();
	}
	while(!s.empty()){
		int temp = s.top();
		q.push(temp);
		s.pop();
	}
}


int main(){
	int n;
	cin>>n;
	queue<int> q;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		q.push(num);
	}
	reverseQueue(q);
	for(int i=0;i<n;i++){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<"END";
	return 0;
}












