#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int n,v[MAX][3],memo[MAX][3];
int dp(int i,int j){
	if(i==n-1&&j==1)return v[i][j];
	if(i>=n||j>2)return (1<<20);
	if(memo[i][j])return memo[i][j];
	if(j==0){
		return memo[i][j]=v[i][j]+min(min(dp(i+1,j),dp(i,j+1)),dp(i+1,j+1));
	}
	if(j==1){
		return memo[i][j]=v[i][j]+min(min(dp(i+1,j),dp(i+1,j+1)),min(dp(i,j+1),dp(i+1,j-1)));
	}
	if(j==2){
		return memo[i][j]=v[i][j]+min(dp(i+1,j),dp(i+1,j-1));
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t=1;
			memset(memo,0,sizeof(memo));
			cin>>n;
			if(n==0)return 0;
			for(int i=0;i<n;i++)
			for(int j=0;j<3;j++)
				cin>>v[i][j];
			cout << dp(0,1)<<"\n";
	}
