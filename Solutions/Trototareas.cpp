#include <bits/stdc++.h>
using namespace std;
int n,s;
pair<int,int> v[502];
int memo[502][102];
int dp(int i,int k){
	if(k<=0)return 0;
	if(i==n)return (1<<30);
	if(memo[i][k])return memo[i][k];
	return memo[i][k]=min(dp(i+1,k),dp(i+1,k-v[i].first)+v[i].second);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>s;
		for(int i=0;i<n;i++){
			cin>>v[i].first>>v[i].second;
		}
		cout << dp(0,s)<<"\n";
	}
