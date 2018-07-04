#include<iostream>
using namespace std;
#define ll long long int

ll findAlive(ll* people,int p,int x){
	for(int i=2;i<=p;i++){
		if(people[i]==0){
			int alpha=1;
			for(int j=i*i;j<1000000;j=i*i*alpha){
				people[j] = 1;
				alpha++;
			}
		}
	}
	for(int i=p+1;i<1000000;i++){
		
		if(people[i]==0){
			int j=i;
			int alpha=2;
			while(j<1000000){
				people[j] = 1;
				j = alpha*i;
				alpha++;
			}
		}
		
	}

	ll count=0;
	for(int i=0;i<1000000;i++){
		if(people[i]==0){
			count++;
			if(count==x)
				return i;
		}
	}

	return -1;
}

int main(){
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		ll people[1000000] = {0};
		int p,x;
		cin>>p>>x;
		cout<<findAlive(people,p,x)<<endl;
	}

	return 0;
}