#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll bit[MAX],bit2[MAX],n,m,k,v[MAX];
pair<pair<int,int>,int>op[MAX];
void update(int i,ll val){
	while(i<=MAX){
		bit[i]+=val;
		i+=(i&-i);
	}
}
void update2(int i,ll val){
	while(i<=MAX){
		bit2[i]+=val;
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
ll query2(int i){
	ll r=0;
	while(i>0){
		r+=bit2[i];
		i-=(i&-i);
	}
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m>>k;
		int i,j,g,h;
		for(i=1;i<=n;i++){
			cin>>v[i];
			if(i>1)v[i]+=v[i-1];
		}
		for(i=1;i<=m;i++){
			cin>>op[i].first.first>>op[i].first.second>>op[i].second;
		}
		for(i=1;i<=k;i++){
			cin>>g>>h;
			update2(g,1);
			update2(h+1,-1);
		}
		for(i=1;i<=m;i++){
			ll uso=op[i].second*(query2(i));
			update(op[i].first.first,uso);
			update(op[i].first.second+1,-uso);
		}
		for(i=1;i<=n;i++){
			cout << (query(i)+v[i]-v[i-1])<<" ";
		}
	}
