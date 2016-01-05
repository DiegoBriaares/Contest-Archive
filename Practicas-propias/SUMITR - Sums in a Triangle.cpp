#include <bits/stdc++.h>
using namespace std;
#define MAX 102
int m[MAX][MAX],memo[MAX][MAX],n;
int dp(int i,int j){
	if(i==n||m[i][j]==-1)return 0;
	if(memo[i][j])return memo[i][j];
	return memo[i][j]=m[i][j]+max(dp(i+1,j),dp(i+1,j+1));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			memset(memo,0,sizeof(memo));
			memset(m,-1,sizeof(m));
			cin>>n;
			for(int i=0;i<n;i++){
				for(int j=0;j<=i;j++){
					cin>>m[i][j];
				}
			}
			cout << dp(0,0)<<"\n";	
		}
	}
