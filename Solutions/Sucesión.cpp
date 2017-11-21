#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,n;
map<ll, ll>memo;
ll f(int i,ll p1,ll p2){
	if(i==n){
		if(p1%2==0)return -(1<<30);
		return p1;
	}
	if(memo[p1+p2])return memo[p1+p2];
	return memo[p1+p2]=max(f(i+1,p1+p2,p1),f(i+1,2*p1,p1));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>a>>b>>n;
		cout << f(2,b,a)<<"\n";
	}
