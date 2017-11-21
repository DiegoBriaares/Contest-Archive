#include <bits/stdc++.h>
using namespace std;
#define MAX 1000012
#define ll long long 
ll n;
ll bit[MAX];
ll r;
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
		int t;
		cin>>t;
		while(t--){
			r=0;
			memset(bit,0,sizeof(bit));
			ll x;
			cin>>n;
			for(int i=0;i<n;i++){
				cin>>x;
				x+=2;
				r+=query(x-1);
				update(x,(x-2));
			}
			cout << r<<"\n";
		}
	}
