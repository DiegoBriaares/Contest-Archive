#include <bits/stdc++.h>
using namespace std;
#define MAX 1008
#define M 1000007
#define ll long long

ll N,Q,K,res,dp[MAX][MAX],p[MAX];

int main () {
  	ios_base::sync_with_stdio(0);
  	cin.tie(0);
	cout.tie(0);
	
	p[0]=1;
	for (int i=1; i<MAX; i++) p[i]=(2*p[i-1])%M;
	
	while(cin>>N){
		cin>>Q;
		dp[1][1]=1;
		for (ll i=2; i<=N; i++){
			for (ll j=i; j>0; j--){
				dp[i][j]=(p[i-j]*dp[i-1][j-1]+j*dp[i-1][j])%M;
			}
		}
		for (ll i=0; i<Q; i++){
			cin>>K;
			res=0;
			for (ll j=1; j <= min(N,K); j++){
				res=(res+dp[N][j])%M;
			}
			cout<<res<<' ';
		}
		memset(dp,0,sizeof(dp));
		cout<<'\n';
	}	
}
