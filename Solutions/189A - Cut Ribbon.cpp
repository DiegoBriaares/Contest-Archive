#include <bits/stdc++.h>
using namespace std;
#define MAX 4002
int memo[MAX][MAX],n,a,b,c;
int dp(int s,int j){
	if(s==n)return 0;
	if(s>n)return -(1<<25);
	if(memo[s][j])return memo[s][j];
	return memo[s][j]=max(max(1+dp(s+a,j+1),1+dp(s+b,j+1)),1+dp(s+c,j+1));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>a>>b>>c;
		cout << dp(0,0)<<"\n";
	}
