#include <bits/stdc++.h>
using namespace std;
#define MAX 24
int memo[(1<<22)],n,v[MAX][MAX];
int dp(int x,int y){
	if(x==(1<<(n))-1)return 0;
	if(memo[x])return memo[x];
	int r=-(1<<30);
	for(int i=0;i<n;i++){
		if((x&(1<<i)))continue;
		int uso=x;
		uso|=(1<<i);
		r=max(r,dp(uso,y+1)+v[y][i]);
	}
	return memo[x]=r;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i,j,k,g,h;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>v[i][j];
		}
	}
	cout << dp(0,0)<<"\n";
}
