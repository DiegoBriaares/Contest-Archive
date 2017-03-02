#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
int r;
int n,e,t;
bool memo[MAX];
vector<int>v[MAX];
void dfs(int nodo,int c){
	if(c>=t)return;
	r++;
	for(int i=0;i<v[nodo].size();i++){
		if(!memo[v[nodo][i]]){
			memo[v[nodo][i]]=true;
			dfs(v[nodo][i],c+1);
		}
	}
}
	int main(){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>e>>t;
		for(int i=0;i<e;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		memo[n]=true;
		dfs(n,0);
		cout << r-1<<"\n";
	}
