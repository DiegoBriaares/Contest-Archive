#include <bits/stdc++.h>
using namespace std;
int n,c,k,memo[6][6][30];
bool v[6][6];
char m[6][6];
int dp(int i,int j,int s){
	if(i==0&&j==c-1&&s<=k)return 1;
	if(i>=n||j>=c||i<0||j<0||m[i][j]=='T'||s>k)return 0;
	if(v[i][j])return 0;
	//if(memo[i][j][s])return memo[i][j][s];
	v[i][j]=true;
	memo[i][j][s]=dp(i+1,j,s+1)+dp(i-1,j,s+1)+dp(i,j+1,s+1)+dp(i,j-1,s+1);
	v[i][j]=false;
	return memo[i][j][s];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c>>k;
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++)cin>>m[i][j];
		}
		cout << dp(n-1,0,1)<<"\n";
	}
