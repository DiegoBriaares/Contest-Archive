#include <bits/stdc++.h>
using namespace std;
#define MAX 5002
#define ll long long
ll n,k;
ll v[MAX];
int dp[MAX][MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		while(cin>>n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)dp[i][j]=0;
		}
			for(int i=0;i<n;i++){
				cin>>v[i];
			}
			for(int i=n-1;i>=0;i--){
				for(int j=i+1;j<n;j++){
					if(v[i]!=v[j])dp[i][j]=max(dp[i][j],max(dp[i+1][j],dp[i][j-1]));
					else dp[i][j]=max(dp[i][j],dp[i+1][j-1]+1);
				}
			}
			cout << dp[0][n-1]<<"\n";
		}
	}
