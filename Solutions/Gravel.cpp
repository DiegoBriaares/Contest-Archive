#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll long long
ll bit[MAX],n,m,c;
void add(ll i,ll v){
	while(i<=MAX){
		bit[i]+=v;
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
		ll i,j,k,g,h;
		char uso;
		cin>>n>>m>>c;
		add(1,c);
		for(i=0;i<m;i++){
			cin>>uso;
			if(uso=='Q'){
				cin>>k;
				cout << query(k)<<"\n";
			}
			if(uso=='S'){
				cin>>g>>h>>k;
				add(g,k);
				add(h+1,-k);
			}
		}
	}
