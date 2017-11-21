#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,memo[1002];
int dp(int i){
	if(i>=n)return 0;
	if(memo[i])return memo[i];
	return memo[i]=min(a+dp(i+1),b+dp(i+m));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m>>a>>b;
		cout << dp(0)<<"\n";
	}
