#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
long long v[MAX],memo[MAX][MAX];
long long dp(int i,int j,int d){
	if(i>j)return 0;
	if(memo[i][j])return memo[i][j];
	return memo[i][j]=max((v[i]*d)+dp(i+1,j,d+1),(v[j]*d)+dp(i,j-1,d+1));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n;
		cin>>n;
		for(int i=0;i<n;i++)cin>>v[i];
		cout << dp(0,n-1,1)<<"\n";
	}
