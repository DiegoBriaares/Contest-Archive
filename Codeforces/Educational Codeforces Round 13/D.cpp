#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll res;
ll A,B,n,X;
ll power(ll x, ll y) {
    if(y==0)return 1;
    if(y&1)return power(x,y-1)*x%MOD; 
	else {
        ll tmp=power(x,y/2);
        return tmp*tmp%MOD;
    }
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>A>>B>>n>>X;
		A%=MOD;
		B%=MOD;
		X%=MOD;
		ll aux=power(A,n);
		if(A!=1){
			ll div=power(A-1,MOD-2);
			res=((aux-1)*div)%MOD;
		}
		else res=n;
		res%=MOD;
		res=(res*B)%MOD;
		res=(res+((aux*X)%MOD)+MOD)%MOD;
		cout << res<<"\n";
	}
