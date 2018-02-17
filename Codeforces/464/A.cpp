#include <bits/stdc++.h>
using namespace std;
#define MAX 301002
#define ll long long
#define MOD 1000000007
ll n,k;
ll v[MAX];
set<ll>dif;
ll dfs(int nodo,int p){
	if(p==0)return nodo;
	dif.insert(nodo);
	return dfs(v[nodo],p-1);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		for(int i=1;i<=n;i++){
			dif.clear();
			int nodo=dfs(i,3);
			if(dif.size()!=3)continue;
			if(nodo==i){
				cout << "YES\n";
				return 0;
			}
		}
		cout << "NO\n";
	}
