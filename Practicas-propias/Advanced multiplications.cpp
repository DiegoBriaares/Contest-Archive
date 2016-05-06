#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
#define MOD 10000000000
ll go(ll x, ll y){
	ll r=0;
	for (;y;y/=2){
		if ((y&1))
			r=(r+x)%MOD;
		x=(x+x)%MOD;
	}
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		while(cin>>n){
			if(n==0)return 0;
			ll uso=(n*(n+1))/2;
			cout << go(uso,uso)<<"\n";
		}
	}
