#include <bits/stdc++.h>
using namespace std;
#define MAX 300002
#define ll long long
#define INF 999999999999999
ll res;
ll n,m,k;
ll v[MAX];
bool memo[MAX];
vector<int>edg[MAX];
void dfs(int nodo){
	if(memo[nodo])return;
	memo[nodo]=true;
	k=min(k,v[nodo]);
	for(int i=0;i<edg[nodo].size();i++){
		dfs(edg[nodo][i]);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			edg[x].push_back(y);
			edg[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			k=INF;
			if(!memo[i]){
				dfs(i);
				res+=k;
			}
		}
		cout << res<<"\n";
	}
