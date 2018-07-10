#include<iostream>
#include<stack>
using namespace std;

int main(){
	int n;
	cin>>n;
	stack<int> s;

	for(int i=0;i<n;i++){
		int query;
		cin>>query;
		if(query==1){
			if(s.empty())
				cout<<"No Code"<<endl;
			else{
				cout<<s.top()<<endl;
				s.pop();
			}
		}
		else{
			int cost;
			cin>>cost;
			s.push(cost);
		}
	}

	return 0;
}