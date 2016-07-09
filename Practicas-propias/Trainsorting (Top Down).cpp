#include <bits/stdc++.h>
using namespace std;
#define MAX 2502
int n,r;
int v[MAX];
map<pair<int,int>,int>memo,memo2;
int dp(int i,int x){
	if(i==n)return 0;
	pair<int,int> uso=make_pair(i,x);
	if(memo[uso])return memo[uso];
	if(v[i]>x){
		return memo[uso]=max(dp(i+1,x),1+dp(i+1,v[i]));
	}
	else return memo[uso]=dp(i+1,x);
}
int dp2(int i,int x){
	if(i==n)return 0;
	pair<int,int> uso=make_pair(i,x);
	if(memo2[uso])return memo2[uso];
	if(v[i]<x){
		return memo2[uso]=max(dp2(i+1,x),1+dp2(i+1,v[i]));
	}
	else return memo2[uso]=dp2(i+1,x);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			memo.clear();
			memo2.clear();
			cin>>n;
			r=0;
			for(int i=0;i<n;i++){
				cin>>v[i];
			}
			int uso=dp(0,0);
			uso=dp2(0,(1<<30)); 
			for(int i=1;i<=n;i++){
				pair<int,int>uso=make_pair(i,v[i-1]);
				r=max(memo[uso]+memo2[uso]+1,r);
			}
			cout << r<<"\n";
		}
	}
