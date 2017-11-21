#include <bits/stdc++.h>
using namespace std;
#define MAX 10000002
int n;
int k;
int c;
int r[MAX];
int memo[MAX];
int tree[MAX];
void dfs(int nodo,int idx){
	if(nodo>n)return;
	c++;
	r[idx]=tree[nodo];
	dfs((nodo*2),(idx*2));
	dfs((nodo*2)+1,(idx*2)+1);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>tree[i];
			memo[tree[i]]=i;
		}
		cin>>k;
		dfs(memo[k],1);
		for(int i=1;i<=c;i++)cout << r[i]<<" ";
	}
