#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
long long v[MAX],memo[MAX],n;
long long dp(long long i){
	if(i>=n)return 0;
	if(memo[i])return memo[i];
	return memo[i]=min(min(v[i+1]+dp(i+2),v[i+2]+v[i+3]+dp(i+4)),v[i+3]+v[i+4]+v[i+5]+dp(i+6));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		long long t,i,j,k,g,h;
		cin>>t;
		while(t--){
			memset(memo,0,sizeof(memo));
			memset(v,0,sizeof(v));
			k=0;
			cin>>n;
			for(i=0;i<n;i++){
				cin>>v[i];
				k+=v[i];
			}
			cout << k-dp(0)<<"\n";
		}
	}
