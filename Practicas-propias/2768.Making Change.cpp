#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
int memo[MAX][12],n,v[12];
int dp(int m,int i){
	if(m==0)return 0;
	if(i==n||m<0)return (1<<20);
	if(memo[m][i])return memo[m][i];
	return memo[m][i]=min(1+dp(m-v[i],i),dp(m,i+1));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int c;
		cin>>c>>n;
		for(int i=0;i<n;i++)cin>>v[i];
		cout << dp(c,0);
	}
