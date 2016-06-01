#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define MAX 1000002
ll n,m;
ll v[MAX];
ll res;
ll uso;
ll cut(ll lvl){
	ll r=0;
	for(int i=0;i<n;i++){
		if(v[i]<=lvl)return r;
		r+=(v[i]-lvl);	
	}
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v,v+n);
		reverse(v,v+n);
		ll in=0,fin=v[0]+100,mid;
		while(in<=fin){
			mid=(in+fin+1)/2;
			uso=cut(mid);
			if(uso<m){
				fin=mid-1;
			}
			else {
				res=max(res,mid);
				in=mid+1;
			}
		}
		cout << res<<"\n";
	}
