#include <bits/stdc++.h>
using namespace std;
#define MAX 42
#define ll long long
ll res;
ll n,mod;
ll v[MAX];
vector<ll>arr,ma,me;
set<ll>S;
ll solve(ll k){
	set<ll>::iterator it = S.upper_bound(k);
	it--;
	return (*it);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>mod;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=1;i<(1<<(n/2));i++){
			ll s=0;
			for(int j=0;j<(n/2);j++){
				if((i&(1<<j))){
					s+=v[j];
				}
			}
			s%=mod;
			res=max(res,s);
			arr.push_back(s);
		}
		for(int i=1;i<(1<<((n-n/2)));i++){
			ll s=0;
			for(int j=0;j<(((n-n/2)));j++){
				if((i&(1<<j))){
					s+=v[j+(n/2)];
				}
			}
			s%=mod;	
			res=max(res,s);
			S.insert(s);
		}
		for(int i=0;i<arr.size();i++){
			int pos=solve(mod-arr[i]-1);
			res=max(res,(arr[i]+pos)%mod);
		}
		cout << res<<"\n";
	}
