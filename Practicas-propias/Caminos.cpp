#include <bits/stdc++.h>
using namespace std;
unsigned long long n,c,memo[32][32];
unsigned long long dp(int i,int j){
	if(i==n&&j==c)return 1;
	if(i>n||j>c)return 0;
	if(memo[i][j])return memo[i][j];
	return memo[i][j]=dp(i+1,j)+dp(i,j+1);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c;
		cout << dp(0,0)<<"\n";
	}
