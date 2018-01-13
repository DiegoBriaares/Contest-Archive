#include <bits/stdc++.h>
using namespace std;
#define MAX 3102
#define ll long long
#define INF 99999999999999999
ll n,k;
ll v[MAX];
ll memo[MAX][MAX];
bool vis[MAX][MAX];
ll dp(int i,int j){
	if(i>n){
		if(j==0)return 0;
		return INF;
	}
	if(vis[i][j])return memo[i][j];
	vis[i][j]=true;
	//Meter a Nieves.
	memo[i][j]=dp(i+1,j)+((k-j)*v[i])-(j*v[i]);
	//Meter al Ethan.
	if(j>0)memo[i][j]=min(memo[i][j],dp(i+1,j-1)+((-1+i+j-k)*v[i])-((n-i-j+1)*v[i]));
	return memo[i][j];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		sort(v+1,v+n+1);
		cout << dp(1,k)<<"\n";
	}
