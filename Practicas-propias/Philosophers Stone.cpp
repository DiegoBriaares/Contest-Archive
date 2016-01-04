#include <bits/stdc++.h>
using namespace std;
#define MAX 102
int m[MAX][MAX],memo[MAX][MAX],n,c;
int dp(int i,int j){
	if(i==n||i<0||j==c||j<0)return 0;
	if(memo[i][j])return memo[i][j];
	return memo[i][j]=max(m[i][j]+dp(i+1,j),max(m[i][j]+dp(i+1,j+1),m[i][j]+dp(i+1,j-1)));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			memset(memo,0,sizeof(memo));
			cin>>n>>c;
			for(int i=0;i<n;i++){
				for(int j=0;j<c;j++)cin>>m[i][j];
			}
			int r=0;
			for(int i=0;i<c;i++){
				r=max(r,dp(0,i));
			}
			cout << r<<"\n";
		}
	}
