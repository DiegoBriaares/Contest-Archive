#include <bits/stdc++.h>
using namespace std;
#define MAX 502
#define MAXN 10002
int u[MAX],p[MAX],memo[MAX][MAXN],n;
int dp(int i,int m){
	if(i==n||m==0)return 0;
	if(m<0)return -(1<<30);
	if(memo[i][m])return memo[i][m];
	memo[i][m]=max(dp(i+1,m-p[i])+u[i],dp(i+1,m));
	return memo[i][m];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int d,i,j,k=0;
		cin>>d>>n;
		for(i=0;i<n;i++){
			cin>>p[i]>>u[i];
		}
		cout <<dp(0,d)<<"\n";
	}
