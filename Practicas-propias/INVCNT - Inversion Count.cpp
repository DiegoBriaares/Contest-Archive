#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
#define ll long long
ll n;
ll bit[MAX];
pair<ll,ll>v[MAX];
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
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		ll t,r;
		cin>>t;
		while(t--){
			memset(bit,0,sizeof(bit));
			r=0;
			cin>>n;
			for(int i=0;i<n;i++){
				cin>>v[i].first;
				v[i].second=i+1;
			}
			sort(v,v+n);
			for(int i=0;i<n;i++){
				r+=(i-query(v[i].second-1));
				update(v[i].second);
			}
			cout << r<<"\n";
		}
	}
