#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define MOD 1000000007
#define ll long long
ll n,k;
ll v[MAX];
bool ok;
void dfs(int x){
	if(x==0){
		ok=true;
		return;
	}
	if(x<0)return;
	dfs(x-3);
	dfs(x-7);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			ok=false;
			int x;
			cin>>x;
			dfs(x);
			if(ok)cout << "YES\n";
			else cout << "NO\n";
		}
		
	}
