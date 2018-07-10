#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

bool check(char* arr,int n){

	stack<char> s;
	int i=0;
	while(i<n){
		char bracket = arr[i];
		if(bracket=='('){
			s.push(bracket);
		}
		else{
			if(s.empty())
				return false;

			char temp = s.top();
			if(temp==')')
				return false;
			s.pop();
		}
		i++;
	}
	if(!s.empty())
		return false;
	return true;
}


int main(){
	char s[100000];
	cin>>s;
	bool isBalanced = check(s,strlen(s));
	if(isBalanced)
		cout<<"Yes";
	else
		cout<<"No";

	return 0;
}