#include <bits/stdc++.h>
using namespace std;
#define MAX 2502
char v[MAX*2];
int memo[MAX][MAX*2];
int mi;
int dp(int i,int m){
	if(i>=m)return 0;
	if(i+1==m){
		if(v[i]!=v[m])return 1;
	}
	if(memo[i][m])return memo[i][m];
	if(v[i]==v[m])return memo[i][m]=dp(i+1,m-1);
	return memo[i][m]=1+min(dp(i+1,m),dp(i,m-1));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n,i,j,k,g,h;
		cin>>n;
		cin>>v;
		mi=n;
		cout <<dp(0,n-1)<<"\n";
	}
