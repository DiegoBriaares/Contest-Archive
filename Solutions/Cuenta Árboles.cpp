#include <bits/stdc++.h>
#define MOD 1000000
#define ll long long
using namespace std;
ll memo[1002];
ll dp(int x){
	if(x==1)return 1;
	if(memo[x])return memo[x];
	ll s=0;
	for(int i=1;i<x;i++){
		s+=((dp(i)%MOD)*dp(x-i)%MOD)%MOD;
	}
	return memo[x]=s%MOD;
}
int main(){
	  ios_base::sync_with_stdio(0);
	  cin.tie(0);
	  int n;
      cin>>n;
	  cout << dp(n+1)<<"\n";
}
