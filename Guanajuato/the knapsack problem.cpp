#include <bits/stdc++.h>
#define MAX 10002
int dp[MAX][MAX],p[MAX],u[MAX],d,n;
using namespace std;
int solve(int i,int m){
	if(m<0||i==n)return 0;
	if(dp[i][m])return dp[i][m];
	if(m-p[i]>=0)dp[i][m]=max(solve(i+1,m-p[i])+u[i],solve(i+1,m));
	return dp[i][m];
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i,k=0;
	cin>>d>>n;
	for(i=0;i<n;i++){
		cin>>p[i]>>u[i];
	}
	for(i=0;i<n;i++){
		k=max(k,solve(i,d));
	}
	cout << k<<"\n";
}
