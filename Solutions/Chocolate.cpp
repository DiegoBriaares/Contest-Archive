#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
#define ll long long
ll n,m;
ll x[MAX];
ll y[MAX];
ll dp[MAX][MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		n--,m--;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=m;i++){
			cin>>y[i];
		}
		sort(x+1,x+n+1);
		sort(y+1,y+m+1);
		reverse(x+1,x+n+1);
		reverse(y+1,y+m+1);
		for(int i=1;i<=n;i++)dp[i][0]=dp[i-1][0]+x[i];
		for(int i=1;i<=m;i++)dp[0][i]=dp[0][i-1]+y[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ll a,b;
				a=dp[i-1][j]+x[i]*(j+1);
				b=dp[i][j-1]+y[j]*(i+1);
				dp[i][j]=min(a,b);
			}
		}
		cout << dp[n][m]<<"\n";
	}
