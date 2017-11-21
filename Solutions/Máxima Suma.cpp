#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll long long
ll v[2*MAX],bit[2*MAX],v2[2*MAX],n,q,res=0;
void update(int i,ll val){
	while(i<=MAX){
		bit[i]+=val;
		i+=(i&-i);
	}
}
ll query(int i){
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
		int i,j,g,h;
		for(i=1;i<=n;i++){
			cin>>v[i];
		}
		sort(v,v+n+1);
		for(i=1;i<=q;i++){
			cin>>g>>h;
			update(g,1);
			update(h+1,-1);
		}
		for(i=1;i<=n;i++){
			v2[i]=query(i);
		}
		sort(v2,v2+n+1);
		for(i=n;i>=1;i--){
			res+=(v[i]*v2[i]);
		}
		cout << res<<"\n";
	}
