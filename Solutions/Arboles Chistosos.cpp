#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
int t;
int n,q;
int v[MAX];
int in[MAX];
int bit[2*MAX];
int fin[MAX];
bool memo[MAX];
int parity[MAX];
vector<int>sons[MAX];
void update(int i,int x){
	while(i<2*MAX){
		bit[i]+=x;
		i+=(i&-i);
	}
}
int query(int i){
	int r=0;
	while(i>0){
		r+=bit[i];
		i-=(i&-i);
	}
	return r;
}
void dfs(int nodo,int p){
	if(memo[nodo])return;
	memo[nodo]=true;
	in[nodo]=++t;
	parity[nodo]=p;
	for(int i=0;i<sons[nodo].size();i++){
		if(!memo[sons[nodo][i]]){
			dfs(sons[nodo][i],-p);
		}
	}
	fin[nodo]=++t;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			sons[a].push_back(b);
			sons[b].push_back(a);
		}
		dfs(1,1);
		while(q--){
			int op,a,b;
			cin>>op;
			if(op==1){
				cin>>a>>b;
				update(in[a],b*parity[a]);
				update(fin[a]+1,-b*parity[a]);
			}
			else {
				cin>>a;
				cout << v[a]+query(in[a])*parity[a]<<"\n";
			}
		}
	}
