#include <bits/stdc++.h>
using namespace std;
#define MAX 152
#define ll long long
ll n;
string s;
int v[MAX];
int memo[MAX][MAX][MAX];
int dp(int i,int j,int t){
	if(i>j)return v[t];
	if(memo[i][j][t]!=-1)return memo[i][j][t];
	if(t)memo[i][j][t]=dp(i,j,0)+v[t];
	int add=2;
	if(i==j)add=1;
	if(s[i]==s[j])memo[i][j][t]=max(memo[i][j][t],dp(i+1,j-1,t+add));
	for(int a=i;a<j;a++){
		memo[i][j][t]=max(memo[i][j][t],dp(i,a,t)+dp(a+1,j,0));
		memo[i][j][t]=max(memo[i][j][t],dp(i,a,0)+dp(a+1,j,t));
	}
	return memo[i][j][t];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		memset(memo,-1,sizeof(memo));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		for(int i=1;i<=n;i++){
			if(v[i]==-1)v[i]=-(1<<30);
		}
		cin>>s;
		if(dp(0,n-1,0)>0)cout << memo[0][n-1][0]<<"\n";
		else cout << "0\n";
	}
