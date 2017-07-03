#include <bits/stdc++.h>
using namespace std;
#define MAX 50002
int n;
string str;
int v[MAX];
int memo[MAX][MAX][MAX];
int dp(int i,int j,int c,int cost){
	if(i==j&&v[i]!=c)return 1;
	if(i>=j)return 0;
	if(memo[i][j][c])return memo[i][j][c];
	memo[i][j][c]=10000;
	if(v[i]==c)return memo[i][j][c]=dp(i+1,j,c,cost);
	for(int k=i;k<=j;k++){
		if(v[k]!=c&&v[k]==v[i])memo[i][j][c]=min(memo[i][j][c],dp(i+1,k-1,v[i],cost+1)+dp(k+1,j,c,cost+1)+1);
	}
	return memo[i][j][c];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>str;
		n=str.size();
		for(int i=0;i<n;i++){
			v[i+1]=(str[i]-'A')+1;
		}
		cout << dp(1,n,0,0)<<"\n";
	}
