#include <bits/stdc++.h>
using namespace std;
int n,k,memo[10001][7][101];
int dp(int i,int s,int x){
	if(s==n&&x==k)return 1;
	if(s>=n||x>=k||i>100||s+i*i>n)return 0;
	if(memo[s][x][i])return memo[s][x][i];
	return memo[s][x][i]=dp(i,s+i*i,x+1)+dp(i+1,s,x);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		cout << dp(1,0,0)<<"\n";
	}
