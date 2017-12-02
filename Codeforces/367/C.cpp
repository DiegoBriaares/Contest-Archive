#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
#define INF 99999999999999999
ll res;
ll n,q;
bool ok;
ll v[MAX];
ll memo[MAX][3];
pair<string,string> arr[MAX];
ll dp(int i,bool p){
	if(i==n){
		ok=true;
		return 0;
	}
	if(memo[i][p]!=-1)return memo[i][p];
	memo[i][p]=(INF);
	if(!p){
		if(arr[i].first>=arr[i-1].first)memo[i][p]=dp(i+1,false);
		if(arr[i].second>=arr[i-1].first)memo[i][p]=min(memo[i][p],v[i]+dp(i+1,true));
	}
	else {
		if(arr[i].first>=arr[i-1].second)memo[i][p]=dp(i+1,false);
		if(arr[i].second>=arr[i-1].second)memo[i][p]=min(memo[i][p],v[i]+dp(i+1,true));
	}
	return memo[i][p];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<n;i++){
			cin>>arr[i].first;
			arr[i].second=arr[i].first;
			reverse(arr[i].second.begin(),arr[i].second.end());
		}
		memset(memo,-1,sizeof(memo));
		ll res=dp(1,false);
		memset(memo,-1,sizeof(memo));
		res=min(res,dp(1,true)+v[0]);
		if(!ok||res==INF)cout << "-1\n";
		else cout << res<<"\n";
	}
