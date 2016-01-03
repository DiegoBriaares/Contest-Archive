#include <bits/stdc++.h>
using namespace std;
#define p pair <int,int>
int n,memo[7][10002];
vector<p> v[7];
int dp(int i,int m){
	if(m<0)return 0;
	if(i>6)return (1<<30);
	if(memo[i][m])return memo[i][m];
	int mi=0;
	for(int j=0;j<v[i].size();j++){
		if(m>=v[i][j].first){
			mi=max(mi,min(v[i][j].second,dp(i+1,m-v[i][j].first)));
		}
	}
	return memo[i][m]=mi;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int i,j,k,g,h;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>j>>g>>h;
			v[j].push_back(p(g,h));
		}
		cout << dp(1,k);
	}
