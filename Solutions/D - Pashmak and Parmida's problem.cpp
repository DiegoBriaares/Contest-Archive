#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll long long
int n;
ll res;
ll v[MAX];
ll bit[2*MAX];
void update(int i,ll x){
	while(i<MAX){
		bit[i]+=x;
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
map<ll,int>memo,ap;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<n;i++){
			memo[v[i]]++;
			update(memo[v[i]],1);
		}
		for(int i=0;i<n;i++){
			update(memo[v[i]],-1);
			memo[v[i]]--;
			res+=query(ap[v[i]]);
			ap[v[i]]++;
		}
		cout << res<<"\n";
	}
