#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
int n;
int in,r,fin;
bool memo[MAX];
vector<int>edg[MAX];
void dfs(int nodo,int i){
	if(memo[nodo])return;
	memo[nodo]=true;
	if(i>r){
		r=i;
		in=nodo;
	}
	for(int j=0;j<edg[nodo].size();j++){
		dfs(edg[nodo][j],i+1);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			edg[a].push_back(b);
			edg[b].push_back(a);
		}
		dfs(1,0);
		memset(memo,false,sizeof(memo));
		r=0;
		dfs(in,0);
		cout << r<<"\n";
	}
