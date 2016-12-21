#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
int n,m;
int v[MAX];
int memo[MAX][MAX];
int dp(int i,int k){
	if(i==n&&k==0)return 0;
	if(k>m||i>=n||k<0)return -(1<<30);
	if(memo[i][k])return memo[i][k];
	memo[i][k]=dp(i+(k==0?1:k),0);
	memo[i][k]=max(memo[i][k],dp(i+1,k+1)+v[i]);
	return memo[i][k];
}
	int main(){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		cout << dp(0,0)<<"\n";	
	}
