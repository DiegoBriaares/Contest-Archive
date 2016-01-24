#include <bits/stdc++.h>
using namespace std;
#define MAX 202
int v[MAX],n,memo[MAX][MAX][MAX];
int dp(int i,int as,int de){
	if(i>n)return 0;
	if(memo[i][as][de])return memo[i][as][de];
	memo[i][as][de]=(1<<20);
	if((as==0||v[i]>v[as])&&(de==0||v[i]<v[de]))return memo[i][as][de]=min(min(dp(i+1,i,de),dp(i+1,as,i)),1+dp(i+1,as,de));
	else if(as==0||v[i]>v[as])return memo[i][as][de]=min(dp(i+1,i,de),1+dp(i+1,as,de));
	else if(de==0||v[i]<v[de])return memo[i][as][de]=min(dp(i+1,as,i),1+dp(i+1,as,de));
	else return memo[i][as][de]=1+dp(i+1,as,de);
}

	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		while(cin>>n){
			if(n==-1)return 0;
			memset(memo,0,sizeof(memo));
			for(int i=1;i<=n;i++)cin>>v[i];
			cout << dp(1,0,0)<<"\n";
		}
	}
