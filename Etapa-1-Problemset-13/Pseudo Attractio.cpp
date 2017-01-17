#include <bits/stdc++.h>
using namespace std;
#define MAX 5002
#define ll long long
ll v[MAX],n,chico=(1<<30);
map<pair<ll,int>,ll>memo;
ll dp(ll p,int i){
	if(i==n)return 0;
	pair<ll,int>aux=make_pair(p,i);
	if(memo[aux])return memo[aux];
	ll mi=(1<<30),r=0;
	if(i==0){
		if(v[i]>=v[i+1]){
			mi=(v[i]-v[i+1])+dp(v[i+1],i+1);
		}
		else mi=dp(v[i],i+1);
	}
	else if(v[i]==p)mi=dp(p,i+1);
	else if(v[i]>=p){
		for(ll j=v[i];j>=p;r++,j--){
			mi=min(mi,dp(j,i+1)+r);
		}
	}
	else {
		mi=(p-v[i])+dp(p,i+1);
	}
	return memo[aux]=mi;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
			if(v[i]<chico)chico=v[i];
		}
		cout << dp(-(1<<30),0)<<"\n";
	}
