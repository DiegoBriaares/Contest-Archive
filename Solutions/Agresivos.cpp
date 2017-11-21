#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define MAXN 1000000000
#define ll long long
ll v[MAX];
ll n,p;
bool solve(ll x){
	ll uso=0,uso2=0;
	for(int i=1;i<=n;i++){
		if(v[i]>=uso2){
			uso++;
			uso2=v[i]+x;
		}
	}
	if(uso>=p)return true;
	return false;
}
ll bs(ll in,ll fin){
	if(in==fin)return in;
	ll mid=(in+fin+1)/2;
	if(!solve(mid))return bs(in,mid-1);
	else return bs(mid,fin);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>p;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}	
		sort(v,v+n+1);
		cout << bs(1,MAXN)<<"\n";
	}
