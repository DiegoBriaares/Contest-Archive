#include <bits/stdc++.h>
using namespace std;
#define MAX 152
int n,c;
int m[MAX][MAX];
int memo[MAX][MAX];
int dp(int i,int j){
	if(i>=n||j>=c||i<0||j<0)return (1<<30);
	if(i==n-1&&j==c-1)return m[n-1][c-1];
	if(memo[i][j])return memo[i][j];
	return memo[i][j]=m[i][j]+min(dp(i+1,j),dp(i,j+1));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c;
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++){
				cin>>m[i][j];
			}
		}
		cout << dp(0,0)<<"\n";
	}
