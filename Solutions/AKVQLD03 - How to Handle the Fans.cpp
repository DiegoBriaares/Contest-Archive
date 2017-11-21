#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll long long
ll bit[MAX];
ll n,q;
string v;
ll a,b;
void update(ll i,ll x){
	while(i<=MAX){
		bit[i]+=x;
		i+=(i&-i);
	}
}
ll query(ll i){
	ll r=0;
	while(i>0){
		r+=bit[i];
		i-=(i&-i);
	}
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>q;
		while(q--){
			cin>>v;
			cin>>a>>b;
			if(v=="add")update(a,b);
			else cout <<(query(b)-query(a-1))<<"\n";
		}	
	}
