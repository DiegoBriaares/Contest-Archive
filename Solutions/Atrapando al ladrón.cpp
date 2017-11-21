#include <bits/stdc++.h>
using namespace std;
#define MAX 20002
#define mp make_pair
int n,m,f;
int v[MAX];
bool vis[MAX];
int dist[2][MAX];
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
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			edg[x].push_back(y);
			edg[y].push_back(x);
		}
		cin>>f;
		for(int i=0;i<f;i++){
			cin>>v[i];
		}
		bfs(0);
		for(int i=1;i<n;i++)if(dist[0][i]==0)dist[0][i]=(1<<30);
		for(int i=0;i<f;i++){
			if(dist[0][v[i]]<=i){
				cout << i<<"\n";
				return 0;
			}
		}
		cout << "-1\n";
	}
