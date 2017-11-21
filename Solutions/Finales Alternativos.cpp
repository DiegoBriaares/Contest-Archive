#include <bits/stdc++.h>
using namespace std;
#define MAX 514
char v[MAX][35];
int p[MAX][2];
int n,k,r[MAX];
void dfs(int i,int j){
	if(i==0)return;
	r[j]=i;
	if(i==k){
		cout << j+1<<"\n";
		for(int u=0;u<=j;u++){
			cout << v[r[u]]<<"\n";
		}
		exit(0);
	}
	dfs(p[i][0],j+1);
	dfs(p[i][1],j+1);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			scanf("\"%[^\"]\" %d %d\n", v[i], &p[i][0], &p[i][1]);
		}	
		dfs(1,0);
	}
