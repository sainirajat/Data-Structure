#include<iostream>
#include<queue>
using namespace std;

int main(){
	int n;
	cin>>n;

	queue<int> q1;
	queue<int> q2;

	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		q1.push(num);
	}
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		q2.push(num);
	}

	int cost=0;
	while(!q2.empty()){
		if(q1.front()==q2.front()){
			q1.pop();
			q2.pop();
			cost++;
		}
		else{
			int temp = q1.front();
			q1.pop();
			q1.push(temp);
			cost++;
		}
	}
	cout<<cost;

	return 0;
}