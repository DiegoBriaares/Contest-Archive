#include <bits/stdc++.h>
using namespace std;
#define MAX 1102
#define ll long long
#define INF 99999999999999999
ll n,k;
ll v[MAX];
ll memo[MAX][MAX][3];
ll dp(int i,int j,int p){
	if(i==0&&j==n-1)return 0;
	if(memo[i][j][p]!=-1)return memo[i][j][p];
	ll a,b;
	a=b=INF;
	if(!p){
		if(i)a=dp(i-1,j,0)+(n-j+i-1)*abs(v[i]-v[i-1]);
		if(j+1<n)b=dp(i,j+1,1)+(n-j+i-1)*abs(v[i]-v[j+1]);
		memo[i][j][p]=min(a,b);
	}
	else {
		if(i)a=dp(i-1,j,0)+(n-j+i-1)*abs(v[j]-v[i-1]);
		if(j+1<n)b=dp(i,j+1,1)+(n-j+i-1)*abs(v[j]-v[j+1]);
		memo[i][j][p]=min(a,b);
	}
	return memo[i][j][p];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		memset(memo,-1,sizeof(memo));
		for(int i=0;i<n;i++){
			cin>>v[i];	
		}	
		sort(v,v+n);
		int in=0;
		for(int i=0;i<n;i++){
			if(v[i]<=k){
				in=i;
			}
		}
		ll res=min(dp(in,in,0)+n*abs(k-v[in]),dp(in+1,in+1,0)+n*abs(k-v[in+1]));
		cout << res<<"\n";
	}
