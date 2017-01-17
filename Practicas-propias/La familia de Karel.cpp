#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int n;
int res[MAX];
int raiz,idx,f;
vector<int>sons[MAX];
void dfs(int nodo,int lvl){
	if(nodo==f)idx=lvl+1;
	res[lvl]++;
	for(int i=0;i<sons[nodo].size();i++){
		dfs(sons[nodo][i],lvl+1);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>f;
		for(int i=1;i<=n;i++){
			int j;
			cin>>j;
			if(j==i)raiz=i;
			else if(j){
				sons[j].push_back(i);
			}
		}
		dfs(raiz,1);
		cout << res[idx]<<"\n";
	}
