#include<iostream>
#include<climits>
using namespace std;
#define ll long long int

pair<ll,int> findMaxSum(ll* arr,int i){
	if(i<0)
		return make_pair(0,0);

	pair<ll,int> p = findMaxSum(arr,i-1);
	ll p1,p2;
	p1 = arr[i] + p.first;
	p2 = p.first;


	if(p1>=p2)
		return make_pair(p1,p.second+1);
	else
		return make_pair(p2,p.second);

}

ll findMin(ll* arr,int n){
	ll ans = INT_MIN;
	for(int i=0;i<n;i++){
		if(arr[i]>ans)
			ans=arr[i];
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	pair<ll,int> p,p2;
	p = findMaxSum(arr,n-1);
	if(p.first!=0)
		cout<<p.first<<" "<<p.second;
	else
		cout<<findMin(arr,n)<<" 1";
	return 0;
}
