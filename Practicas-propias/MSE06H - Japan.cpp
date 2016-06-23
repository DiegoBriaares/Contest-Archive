#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
#define MAXN 1000002
#define ll long long int
ll bit[MAX];
ll bit2[MAX];
ll n,m,k;
pair<ll,ll>v[MAXN];
void update(ll i){
	while(i<=MAX){
		bit[i]++;
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
void update2(ll i){
	while(i<=MAX){
		bit2[i]++;
		i+=(i&-i);
	}
}
ll query2(ll i){
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
		ll t;
		cin>>t;
		for(int z=1;z<=t;z++){
			cin>>n>>m>>k;
			ll r=0;
			memset(bit,0,sizeof(bit));
			memset(bit2,0,sizeof(bit2));
			for(int i=0;i<k;i++){
				cin>>v[i].second>>v[i].first;
			}
			sort(v,v+k);
			for(int i=0;i<k;i++){
				r+=(query(v[i].first)-query2(v[i].second));
				update(v[i].first);
				update2(v[i].second);
			}
			cout <<"Test case "<<z<<": "<<r<<"\n";
		}
	}
