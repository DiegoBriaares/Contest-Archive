#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int n,q;
int p,k;
int v[MAX];
map<pair<int,int>,int>memo;
int dp(int i){
	if(i>n)return 0;
	pair<int,int>aux=make_pair(i,k);
	if(memo[aux])return memo[aux];
	return memo[aux]=1+dp(i+k+v[i]);
}
int solve(int i){
	if(i>n)return 0;
	return 1+solve(i+k+v[i]);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		cin>>q;
		while(q--){
			cin>>p>>k;
			if(k<333){
				cout << dp(p)<<"\n";	
			}
			else {
				cout << solve(p)<<"\n";
			}
		}
	}
