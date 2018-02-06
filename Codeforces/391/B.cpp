#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 9999999999999
ll res,n;
map<ll,ll>memo;
void get_div(ll k){
	ll div=2LL;
	while(div*div<=k){
		if(k%div==0){
			memo[div]++;
			res=max(res,memo[div]);
			while(k%div==0)k/=div;
		}
		if(div==2)div++;
		else div+=2;
	}
	if(k>1){
		memo[k]++;
		res=max(res,memo[k]);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			ll x;
			cin>>x;
			get_div(x);
		}
		if(!res)res=1;
		cout << res<<"\n";
	}
