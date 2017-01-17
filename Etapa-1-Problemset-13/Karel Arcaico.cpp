#include <bits/stdc++.h>
using namespace std;
#define MAX 102
string v;
int memo[MAX][MAX][2];
int dp(int i,int n,int pos){
	if(n<0)return -(1<<30);
	if(i>=v.size()){
		return ((n%2==1)?-(1<<30):0);
	}
	if(memo[i][n][pos])return memo[i][n][pos];
	int x=(pos?1:-1);
	if(v[i]=='F'){
		return memo[i][n][pos]=max(dp(i+1,n-1,pos^1),dp(i+1,n,pos)+x);
	}
	else {
		return memo[i][n][pos]=max(dp(i+1,n,pos^1),dp(i+1,n-1,pos)+x);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n,u;
		cin>>u;
		cin>>v;
		cin>>n;
		cout << max(dp(0,n,0),dp(0,n,1))<<"\n";	
	}
