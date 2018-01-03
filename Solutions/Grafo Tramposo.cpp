#include <bits/stdc++.h>
using namespace std;
#define MAX 3102
#define lk second.first
#define rk second.second
#define INF 10000000
int n,m;
int res;
bool ok;
bool memo[MAX];
vector<pair<int,int> >inits;
vector<pair<int,pair<int,int> > >edg[MAX];
void dfs(int nodo,int ini,int fin){
	if(ok)return;
	if(nodo==n){
		ok=true;
		return;
	}
	if(memo[nodo])return;
	memo[nodo]=true;
	for(int i=0;i<edg[nodo].size();i++){
		if(edg[nodo][i].lk<=ini&&fin<=edg[nodo][i].rk)dfs(edg[nodo][i].first,ini,fin);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int x,y,a,b;
			cin>>x>>y>>a>>b;
			edg[x].push_back(make_pair(y,make_pair(a,b)));
			edg[y].push_back(make_pair(x,make_pair(a,b)));
			if(x==n||y==n||x==1||y==1)inits.push_back(make_pair(a,b));
		}
		for(int i=0;i<m;i++){
			int in=inits[i].first,fin=inits[i].second,la=-1;
			while(in<=fin){
				int mid=(in+fin)/2;
				ok=false;
				dfs(1,inits[i].first,mid);
				memset(memo,false,sizeof(memo));
				if(ok){
					la=mid;
					in=mid+1;
				}
				else fin=mid-1;
			}
			if(la!=-1)res=max(res,(la-inits[i].first)+1);
		}
		if(res==0)cout << "Oh, vamos!\n";
		else cout << res<<"\n";
	}
