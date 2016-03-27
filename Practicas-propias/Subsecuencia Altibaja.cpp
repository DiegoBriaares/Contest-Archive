#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
int v[MAX],n,memo[MAX][MAX][2];
int dp(int i,int p,int sb){
	if(i==n)return 0;
	if(memo[i][p][sb])return memo[i][p][sb];
	if(sb==0){
		if(v[i]<p){
			return memo[i][p][sb]=max(1+dp(i+1,v[i],1),dp(i+1,p,sb));
		}
			return memo[i][p][sb]=dp(i+1,p,sb);
	}
	else {
		if(v[i]>p){
			return memo[i][p][sb]=max(1+dp(i+1,v[i],0),dp(i+1,p,sb));
		}
		return memo[i][p][sb]=dp(i+1,p,sb);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		cout << max(dp(0,(v[0]+1),0),dp(0,(v[0]-1),1))<<"\n";
	}
