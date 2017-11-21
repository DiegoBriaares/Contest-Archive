#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll bit[2*MAX],v[MAX];
ll n,k;
ll res=0,res2=0;
void update(ll i){
	i+=MAX;
	while(i<=2*MAX){
		bit[i]++;
		i+=(i&-i);
	}
}
ll query(ll i){
	ll r=0;
	i+=MAX;
	while(i>0){
		r+=bit[i];
		i-=(i&-i);
	}
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>v[i];
			if(v[i]>=k)v[i]=1;
			else v[i]=-1;
		}	
		update(0);
		for(int i=0;i<n;i++){
			res2+=v[i];
			res+=query(res2);
			update(res2);
		}
		cout << res<<"\n";
	}
