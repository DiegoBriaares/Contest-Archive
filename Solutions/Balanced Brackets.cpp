#include <bits/stdc++.h>
using namespace std;
#define MAX 702
int n,k;
int v[MAX];
int b[MAX];
int memo[MAX][MAX];
int dp(int i,int j){
	if(i>=j)return 0;
	if(memo[i][j])return memo[i][j];
	memo[i][j]=dp(i+1,j);
	for(int h=i+1;h<=j;h++){
		if(b[i]==b[h]-k){
			memo[i][j]=max(memo[i][j],dp(i+1,h-1)+dp(h+1,j)+v[i]+v[h]);
		}
	}
	return memo[i][j];
}
	int main (){
		ios_base::sync_with_stdio();
		cin.tie(0);
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		cout << dp(0,n-1)<<"\n";
	}
