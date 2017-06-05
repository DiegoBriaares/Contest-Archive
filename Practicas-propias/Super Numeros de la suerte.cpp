#include <bits/stdc++.h>
using namespace std;
#define MAX 7
#define ll long long
ll n;
map<ll,bool>memo;
vector<ll>v;
void dfs(int i,int j,ll pot,ll k){
	if(i<MAX&&i==j&&!memo[k]){
		memo[k]=true;
		v.push_back(k);
	}
	if(i==0&&j==0)return;
	if(j){
		dfs(i,j-1,pot*10,k+(pot*7));
	}
	if(i){
		dfs(i-1,j,pot*10,k+(pot*4));
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		dfs(MAX,MAX,1,0);
		sort(v.begin(),v.end());
		cin>>t;
		while(t--){
			cin>>n;
			if(n==0){
				cout << "0\n";
				continue;
			}
			int idx=(upper_bound(v.begin(),v.end(),n)-v.begin());
			while(idx>0&&v[idx-1]>=n)idx--;
			cout << v[idx]<<"\n";
		}
	}
