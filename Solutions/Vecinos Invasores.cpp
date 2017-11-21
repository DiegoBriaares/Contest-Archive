#include <bits/stdc++.h>
using namespace std;
#define MAX 52
int v[MAX],n,memo[MAX],memo2[MAX];
int dp(int i){
	if(i>=n-1)return 0;
	if(memo[i])return memo[i];
	return memo[i]=max(v[i]+dp(i+2),dp(i+1));
}
int dp2(int i){
	if(i>=n)return 0;
	if(memo2[i])return memo2[i];
	return memo2[i]=max(v[i]+dp2(i+2),dp2(i+1));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++)cin>>v[i];
		cout << max(dp2(1),dp(0))<<"\n";
	}
