#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool ok;
ll x,y,n;
set<ll>S;
map<ll,bool>memo;
map<pair<ll,ll>,bool>dp;
void dfs(int i,int j){
	if(j==y){
		memo[i]=true;
		return;
	}
	pair<ll,ll>aux=make_pair(i,j);
	if(dp[aux])return;
	dp[aux]=true;
	if(i%2==0){
		dfs(i/2,j+1);
	}
	if(i%3==0){
		dfs(i/3,j+1);
	}
	dfs(i*3,j+1);
	dfs(i*2,j+1);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>x>>y;
		dfs(x,0);
		while(cin>>n){
			if(memo[n]){
				ok=true;
				S.insert(n);
			}
		}
		if(!ok)cout << 0<<"\n";
		else {
			for(set<ll>::iterator it=S.begin();it!=S.end();++it){
				cout << *it<<" ";
			}
		}
	}
