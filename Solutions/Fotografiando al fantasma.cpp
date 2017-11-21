#include <bits/stdc++.h>
using namespace std;
#define MAX 1012
#define mp make_pair
int n,m,f;
int v[MAX];
bool vis[MAX];
int memo[MAX][MAX];
int dist[MAX][MAX];
vector<int>edg[MAX];
void bfs(int nodo){
	memset(vis,false,sizeof(vis));
	queue<pair<int,int> >cola;
	cola.push(mp(nodo,1));
	while(!cola.empty()){
		pair<int,int> now=cola.front();
		cola.pop();
		if(vis[now.first])continue;
		vis[now.first]=true;
		for(int i=0;i<edg[now.first].size();i++){
			if(!dist[nodo][edg[now.first][i]])dist[nodo][edg[now.first][i]]=now.second;
			if(!vis[edg[now.first][i]])cola.push(mp(edg[now.first][i],now.second+1));
		}
	}
	dist[nodo][nodo]=0;
}
int dp(int i,int nodo){
	if(i>f)return 0;
	if(memo[i][nodo])return memo[i][nodo];
	memo[i][nodo]=dp(i+1,nodo);
	if(dist[v[nodo]][v[i]]<=(i-(nodo==0?1:nodo))){
		memo[i][nodo]=max(memo[i][nodo],1+dp(i+1,i));
	}
	return memo[i][nodo];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			x++,y++;
			edg[x].push_back(y);
			edg[y].push_back(x);
		}
		cin>>f;
		if(!n){
			cout << "0\n";
			return 0;
		}
		if(!f){
			cout << "1\n";
			return 0;
		}
		if(!m){
			cout << "1\n";
			return 0;
		}
		for(int i=1;i<=f;i++){
			cin>>v[i];
			v[i]++;
		}
		for(int i=1;i<=n;i++){
			bfs(i);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&dist[i][j]==0)dist[i][j]=(1<<30);
			}
		}
		v[0]=1;
		int res=dp(1,0);
		if(res<0)res=0;
		cout << res<<"\n";
	}
